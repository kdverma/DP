class GlobalClass
{
    int m_value;
    static GlobalClass *s_instance;
    GlobalClass(int v = 0)
    {
        m_value = v;
    }
  public:
    int get_value()
    {
        return m_value;
    }
    void set_value(int v)
    {
        m_value = v;
    }
    static GlobalClass *instance()
    {
        return s_instance ? s_instance : (s_instance = new GlobalClass);
    }
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
GlobalClass *GlobalClass::s_instance = 0;

int main()
{
  cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
  GlobalClass::instance()->set_value(1);
  cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';

}

/*
Why to use :
1. Ensure a class has only one instance, and provide a global point of access to it.
2. Encapsulated "just-in-time initialization" or "initialization on first use".
*/

/*
STEPS:
1. Define a private static attribute/object in the "single instance" class.
2. Define a public static accessor member function in the class.
3. Do "lazy initialization" (creation on first use) in the accessor function.
4. Define all constructors to be protected or private.
5. Clients may only use the accessor function to manipulate the Singleton.
*/

/*NOTE 
Deleting a Singleton class/instance is a non-trivial design problem. See "To Kill A Singleton" by John Vlissides for a discussion.
*/