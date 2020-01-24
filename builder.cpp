// Question: WHY Builder Design Pattern
// Answer  : Because i want to build an object(plane) and it is compossed of complex 
//           objects(body, engine) step by step. especially sequentially


#include <iostream>
using namespace std;

// Your end product 
class Plane{
    string _plane;
    string _body;
    string _engine;
public:
    Plane(string planeType):_plane{planeType} {}
    void setEngine(string type) { _engine = type; }
    void setBody(string body)   { _body = body;   }
    string getEngine()          { return _engine; }
    string getBody()            { return _body;   }
    
    void show() {
    	cout << "Plane Type: " <<_plane << endl
    		 << "Body Type: " <<_body << endl
    		 << "Engine Type: "<<_engine << endl << endl;
    }
};

// PlaneBuilder Abstract Class
// Means all builders should have atleast these methods
class PlaneBuilder{
protected:
    Plane *_plane;
public:
    virtual void getPartsDone() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    //virtual ~PlaneBuilder(){}
    Plane* getPlane(){ return _plane; }
};

// PlaneBuilder concrete class
// knows only how to build Propeller Plane
class PropellerBuilder: public PlaneBuilder {
public:
    void getPartsDone() { _plane = new Plane("Propeller Plane"); }
    void buildEngine()  { _plane->setEngine("Propeller Engine");   }
    void buildBody()    { _plane->setBody("Propeller Body");   }
    //~PropellerBuilder(){delete _plane;}
};

// PlaneBuilder concrete class
// Knows only how to build Jet Plane
class JetBuilder: public PlaneBuilder {
public:
    void getPartsDone() { _plane = new Plane("Jet Plane"); }
    void buildEngine()  { _plane->setEngine("Jet Engine");   }
    void buildBody()    { _plane->setBody("Jet Body");   }
    //~JetBuilder(){delete _plane;}
};

// Defines steps and tells to the builder that build in given order.
class Director{
    PlaneBuilder *builder;
public:
    Plane* createPlane(PlaneBuilder *builder) {
        builder->getPartsDone();
        builder->buildBody();
        builder->buildEngine();
        return builder->getPlane();
    }
};

int main() {
	
    Director dir;
    JetBuilder jb;
    PropellerBuilder pb;

	Plane *jet = dir.createPlane(&jb);
	Plane *pro = dir.createPlane(&pb);
	
	jet->show();
	pro->show();
    
    delete jet;
    delete pro;

	return 0;
}

/*STEPS
1. Create class for end product
2. create an abstract class that will define the build process i.e. method/functions to build end product. 
    All builders/type_of_product should have atleast these methods define in abstract class
3. create concreate classes for type of end product i.e. Jet or civilian plane.
4. Create a director: Defines steps and tells to the builder that build in given order.
5. client program : dir, object of concrete classes created, create plane through director
*/