#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class Singleton{

    static Singleton* instance;
    // static mutex mtx;
    Singleton(){
        cout<<"Singleton Constructor called::"<<endl;
    }
    public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            // lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Singleton();
                return instance;
            }
        }
         return instance;
    }

    static void destroy(){
        delete instance;
        instance = nullptr;
    }
};

Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx;

int main(){

    Singleton* singletonObj = Singleton::getInstance();
    Singleton* singletonObj2 = Singleton::getInstance();

    if(singletonObj2 == singletonObj){
        cout<<"SAME::This is same instance"<<endl;
    }
    else{
        cout<<"DIFFERENT::This is different instance"<<endl;
    }

    Singleton::destroy();

    return 0;
}