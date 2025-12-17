#include <iostream>
using namespace std;

class Ihandler{
   protected:
       Ihandler* next = nullptr;
   public:
    virtual void dispense(int amount)=0;
    void setHandler(Ihandler* next){
        this->next = next;
    }
    Ihandler* getNextHandler(){
        return this->next;
    }
    virtual ~Ihandler(){}
};

class ThousandRuppeeHandler : public Ihandler{
    int capacity;
    public:
    ThousandRuppeeHandler(int capacity){
        this->capacity = capacity;
    }

    void dispense(int amount) override{
        if(amount > (this->capacity*1000)){
            cout<<"Amount dispense by 1000 :: "<<this->capacity*1000<<endl;
            if(this->getNextHandler()){
                amount -= this->capacity*1000;
                this->getNextHandler()->dispense(amount);
                return ;
            }
            else{
                cout<<"Capacity Exceeded !! Please visit in some time !!"<<endl;
            }
        }
        else{
            cout<<"Amount dispense by 1000 :: Count of notes ::"<<amount/1000<<endl;
        }
    }    
};

class FiveHundredRuppeeHandler : public Ihandler{
    int capacity;
    public:
    FiveHundredRuppeeHandler(int capacity){
        this->capacity = capacity;
    }

    void dispense(int amount) override{
        if(amount > (this->capacity*500)){
            cout<<"Amount dispense by 500 :: "<<this->capacity*500<<endl;
            if(this->getNextHandler()){
                amount -= this->capacity*500;
                this->getNextHandler()->dispense(amount);
                return ;
            }
            else{
                cout<<"Capacity Exceeded !! Please visit in some time !!"<<endl;
            }
        }
        else{
            cout<<"Amount dispense by 500 :: Count of notes ::"<<amount/500<<endl;
        }
    }    
};


class TwoHundredRuppeeHandler : public Ihandler{
    int capacity;
    public:
    TwoHundredRuppeeHandler(int capacity){
        this->capacity = capacity;
    }

    void dispense(int amount) override{
        if(amount > (this->capacity*200)){
            cout<<"Amount dispense by 200 :: "<<this->capacity*200<<endl;
            if(this->getNextHandler()){
                amount -= this->capacity*200;
                this->getNextHandler()->dispense(amount);
                return ;
            }
            else{
                cout<<"Capacity Exceeded !! Please visit in some time !!"<<endl;
            }
        }
        else{
            cout<<"Amount dispense by 200 :: Count of notes ::"<<amount/200<<endl;
        }
    }    
};

class OneHundredRuppeeHandler : public Ihandler{
    int capacity;
    public:
    OneHundredRuppeeHandler(int capacity){
        this->capacity = capacity;
    }

    void dispense(int amount) override{
        if(amount > (this->capacity*100)){
            cout<<"Amount dispense by 100 :: "<<this->capacity*100<<endl;
            if(this->getNextHandler()){
                amount -= this->capacity*100;
                this->getNextHandler()->dispense(amount);
                return ;
            }
            else{
                cout<<"Capacity Exceeded !! Please visit in some time !!"<<endl;
            }
        }
        else{
            cout<<"Amount dispense by 100 :: Count of notes ::"<<amount/100<<endl;
        }
    }    
};


int main(){ 
    
    ThousandRuppeeHandler* thousandHandler = new ThousandRuppeeHandler(3);
    FiveHundredRuppeeHandler* fiveHundredHanlder = new FiveHundredRuppeeHandler(5);
    TwoHundredRuppeeHandler* twoHundredHandler = new TwoHundredRuppeeHandler(6);
    OneHundredRuppeeHandler* oneHundredHandler = new OneHundredRuppeeHandler(10);
    
    Ihandler* handler = thousandHandler;
    handler->setHandler(fiveHundredHanlder);
    fiveHundredHanlder->setHandler(twoHundredHandler);
    twoHundredHandler->setHandler(oneHundredHandler);
    handler->dispense(5000);

    delete handler;
    return 0;
}