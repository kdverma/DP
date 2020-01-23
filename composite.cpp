#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//common interface to be used for individual object and composite object
class IData
{
    public:
    virtual void doubleClick() = 0;
}; /*we can  not create object for abstract class but creating "*" type i.e. vector<IData *> folder; is possible. also below is possible
for (IData *data : folder) 
data->doubleClick()*/

//Implement interface for Individual Object
class Files : public IData
{
private:
    string name;

public:
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void doubleClick()
    {
        cout << this->getName() << " file is opened" << endl;
    }
};

//Implement Interface for composite object
class Folder : public IData
{
private:
    string name;
    vector<IData *> folder;

public:
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void add(IData *data)  //can be a folder or file
    {
        folder.push_back(data);
    }

    void doubleClick()
    {
        cout << this->getName() << " folder is opened" << endl;
        for (IData *data : folder)
            data->doubleClick();
    }
};

//Client pgm
int
main()
{
    Folder *f1 = new Folder();
    f1->setName("tmp");

    Folder *f2 = new Folder();
    f2->setName("var");

    Folder *f3 = new Folder();
    f3->setName("opt");

    Files *files1 = new Files();
    files1->setName("app.log");

    Files *files2 = new Files();
    files2->setName("app.tar");

    Files *files3 = new Files();
    files3->setName("music.mp3");

    Files *files4 = new Files();
    files4->setName("snap.jpeg");

    f1->add(files1);
    f2->add(files2);

    f3->add(f2);
    f3->add(files3);
    f3->add(files4);

    cout << "\n\nshowing content for folder 1\n"; 
    f1->doubleClick();

    cout << "\n\nshowing content for folder 2 \n";
    f2->doubleClick();

    cout << "\n\nshowing content for folder 3\n";
    f3->doubleClick();
    return 0;
}

/*When to use composite design pattern
1. 
/*

/*Steps to use composite design pattern
1. 
*/