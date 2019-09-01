#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Person
{
public:
    //friend PersonFactory;
    Person(int id1, string name1)
    {
        id = id1;
        name = name1;
    }
    void display()
    {
        cout << "id = " << id << " name = " << name << endl;
    }

//private:
    int id;
    string name;
};

class PersonFactory
{
    public:
    static Person getStudent()
    {
        return {6,"kapil"}; 
    }

    static Person getTeacher()
    {
        return {0,"Babu Sir"};
    }
};

int main()
{
    auto p = PersonFactory::getStudent();
    //Person p1(3, "sdf");
    p.display();

    auto p1 = PersonFactory::getTeacher();
    p1.display();
    return 0;
}