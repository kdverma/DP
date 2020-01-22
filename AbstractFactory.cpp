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