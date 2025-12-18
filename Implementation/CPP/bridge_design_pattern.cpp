#include <iostream>
using namespace std;

class Car{
    public:
    virtual void drive()=0;
    virtual ~Car(){}
};

class Engine{
    public:
    virtual void start()=0;
    virtual void stop()=0;
    virtual ~Engine(){}
};

class Suv : public Car{
    Engine* engineType;
    public:
    Suv(Engine* engineType){
        this->engineType=engineType;
    }

    void drive() override{
        this->engineType->start();
        cout<<"::: Driving SUV :::"<<endl;
        this->engineType->stop();
    }
};

class Verna : public Car{
    Engine* engineType;
    public:
    Verna(Engine* engineType){
        this->engineType=engineType;
    }

    void drive() override{
        this->engineType->start();
        cout<<"::: Driving Verna :::"<<endl;
        this->engineType->stop();
    }
};

class Sedan : public Car{
    Engine* engineType;
    public:
    Sedan(Engine* engineType){
        this->engineType=engineType;
    }

    void drive() override{
        this->engineType->start();
        cout<<"::: Driving Sedan :::"<<endl;
        this->engineType->stop();
    }
};

class EngineA : public Engine{
    public:

    void start() override{
        cout<<":: Engine A started ::"<<endl;
    }

    void stop() override{
        cout<<":: Engine A stopped ::"<<endl;
    }
};

class EngineB : public Engine{
    public:

    void start() override{
        cout<<":: Engine B started ::"<<endl;
    }

    void stop() override{
        cout<<":: Engine B stopped ::"<<endl;
    }
};

class EngineC : public Engine{
    public:

    void start() override{
        cout<<":: Engine C started ::"<<endl;
    }

    void stop() override{
        cout<<":: Engine C stopped ::"<<endl;
    }
};
int main(){

    Car* suvA = new Suv(new EngineA());
    Car* suvB = new Suv(new EngineB());
    Car* sedanA = new Sedan(new EngineA());
    
    suvA->drive();
    suvB->drive();
    sedanA->drive();

    delete suvA;
    delete suvB;
    delete sedanA;
    

    return 0;
}