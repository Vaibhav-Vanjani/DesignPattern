#include <iostream>
using namespace std;

class A{
    public:
    void load(){
        cout<<"A :: Loaded"<<endl;
    }
};

class B{
    public:
    void load(){
        cout<<"B :: Loaded"<<endl;
    }
};

class C{
    public:
    void load(){
        cout<<"C :: Loaded"<<endl;
    }
};

class D{
    public:
    void load(){
        cout<<"D :: Loaded"<<endl;
    }
};

class E{
    public:
    void load(){
        cout<<"E :: Loaded"<<endl;
    }
};

class ComputerFacadeSystem{
    A a;
    B b;
    C c;
    D d;
    E e;
    public:
    void loadComputer(){
        // talks to a complex subsystem
        a.load();
        b.load();
        c.load();
        d.load();
        e.load(); 
        cout<<"Computer started successfully !!";
    }
};

int main(){
    ComputerFacadeSystem* computerFacadeSystem = new ComputerFacadeSystem();
    computerFacadeSystem->loadComputer();
    return 0;
}