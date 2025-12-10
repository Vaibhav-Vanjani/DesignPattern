#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car{

protected:
    string model; 
    string color;
    string engine;
    string name;
    int speed;
public:
    Car(string name,string model,string color,string engine){
        this->name = name;
        this->model = model;
        this->color = color;
        this->engine = engine;
    }

    virtual void accelerate() = 0;
    virtual void accelerate(int speed) = 0;
    virtual void brake() = 0;
    virtual void display() = 0;
    
    void startEngine(){
        cout<<"Car Engine :: start"<<endl;
    }
    
    void endEngine(){
        cout<<"Car Engine :: end"<<endl;
    }  
};

class SuperCar : public Car
{
    public:
    SuperCar(string name,string model,string color,string engine) : Car(name,model,color,engine){
    }

    void accelerate(){
        cout<<"hi i am "<<this->name<<" accelerating with +20 km/hr"<<endl;
    }
    
    void accelerate(int speed){
        cout<<"hi i am "<<this->name<<" accelerating with +"<<speed<<"km/hr"<<endl;
    }
    
    void brake(){
        cout<<"hi i am "<<this->name<<" brake with -20 km/hr"<<endl;
    }  

    void display(){
        cout<<" name: "<<name<<" model: "<<model<<" color: "<<color<<" engine: "<<engine<<endl;
    }  
};

class ManualCar : public Car
{
    public:
    ManualCar(string name,string model,string color,string engine) : Car(name,model,color,engine){
    }

    void accelerate(){
        cout<<"hi i am "<<this->name<<" accelerating with +40 km/hr"<<endl;
    }
    
    void accelerate(int speed){
        cout<<"hi i am "<<this->name<<" accelerating with +"<<speed<<"km/hr"<<endl;
    }
    
    void brake(){
        cout<<"hi i am "<<this->name<<" brake with -40 km/hr"<<endl;
    }

    void display(){
        cout<<" name: "<<this->name<<" model: "<<this->model<<" color: "<<this->color<<" engine: "<<this->engine<<endl;
    }  
};


int main() {
    Car* superCar = new SuperCar("super tesla","super model","blue","super engine");
    superCar->startEngine();
    superCar->accelerate();
    superCar->accelerate(80);
    superCar->brake();
    superCar->endEngine();

    Car* manualCar = new ManualCar("super tesla","super model","blue","super engine");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate(80);
    manualCar->brake();
    manualCar->endEngine();
    
    
}
