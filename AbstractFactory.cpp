#include <iostream>
#include <string>
#include <memory>
using namespace std;

//Creating the Abstract Products
class ISmartDevice
{
public:
    virtual std::string Name() = 0;
};


class IDumbDevice
{
public:
    virtual std::string Name() = 0;
};


//Creating the Concrete Products
class Asha : public IDumbDevice
{
public:
    std::string Name()
    {
        return "Asha";
    }
};

class Guru : public IDumbDevice
{
public:
    std::string Name()
    {
        return "Guru";
    }
};

class GalaxyS2 : public ISmartDevice
{
public:
    std::string Name()
    {
        return "GalaxyS2";
    }
};

class Lumia : public ISmartDevice
{
public:
    std::string Name()
    {
        return "Lumia";
    }
};

//Creating the Abstract Factory
class APhoneFactory
{    
public:
    enum PHONE_FACTORIES
    {
        SAMSUNG,
        NOKIA
    };

    virtual ISmartDevice* GetSmart() = 0;
    virtual IDumbDevice* GetDumb() = 0;

    static APhoneFactory* CreateFactory(PHONE_FACTORIES factory);    
};

//Creating the Concrete Factories
class SamsungFactory : public APhoneFactory
{
public:
    ISmartDevice* GetSmart()
    {
        return new GalaxyS2();
    }

    IDumbDevice* GetDumb()
    {
        return new Guru();
    }
};

class NokiaFactory : public APhoneFactory
{
public: 
    ISmartDevice* GetSmart()
    {
        return new Lumia();
    }

    IDumbDevice* GetDumb()
    {
        return new Asha();
    }
};

APhoneFactory* APhoneFactory::CreateFactory(PHONE_FACTORIES factory)
{
    if(factory == PHONE_FACTORIES::SAMSUNG)
    {
        return new SamsungFactory();
    }
    else if(factory == PHONE_FACTORIES::NOKIA)
    {
        return new NokiaFactory();
    }
}



//Client Program

int main(int argc, char* argv[])
{
    APhoneFactory *factory = APhoneFactory::CreateFactory(APhoneFactory::PHONE_FACTORIES::SAMSUNG);

    cout << "Dumb phone from Samsung: " << factory->GetDumb()->Name() << "\n";
    delete factory->GetDumb(); //USe of smart pointer will get rid of these delete
    cout << "Smart phone from Samsung: " << factory->GetSmart()->Name() << "\n";
    delete factory->GetSmart(); //USe of smart pointer will get rid of these delete
    delete factory;
    getchar();

    factory = APhoneFactory::CreateFactory(APhoneFactory::PHONE_FACTORIES::NOKIA);
    cout << "Dumb phone from Nokia: " << factory->GetDumb()->Name() << "\n";
    delete factory->GetDumb(); //USe of smart pointer will get rid of these delete
    cout << "Smart phone from Nokia: " << factory->GetSmart()->Name() << "\n";    
    delete factory->GetSmart(); //USe of smart pointer will get rid of these delete
    getchar();

    return 0;
}

/*
When to use Abstract Factory Pattern:
1. Abstract factory pattern in useful when the client needs to create objects which are somehow related.
    If we need to create the family of related or dependent objects, then we can use Abstract Factory Pattern.

2. This pattern is particularly useful when the client doesn't know exactly what type to create.
    As an example, let's say a Showroom exclusively selling cellphones gets a query for the smart phones made by Samsung.
    Here we don't know the exact type of object to be created (assuming all the information for a phone is wrapped in 
    the form of a concrete object). But we do know that we are looking for smart phones that are manufactured by Samsung.
    This information can actually be utilized if our design has Abstract factory implementation.

Steps for Abstract design pattern:
Create as Below :
    a. AbstractFactory: declares an interface for operations that create abstract products
    b. ConcreteFactory: implements the operations to create concrete product objects
    c. AbstractProduct: declares an interface for a type of product object
    d. Product: defines a product object to be created by the corresponding concrete factory implements the AbstractProduct interface
    e. Client: main program : uses interfaces declared by AbstractFactory and AbstractProduct classes