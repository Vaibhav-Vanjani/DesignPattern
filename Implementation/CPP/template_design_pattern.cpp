#include <iostream>
using namespace std;

class Pipeline{
  public:
    virtual void step1()=0;
    virtual void step2()=0;
    virtual void step3()=0;
    virtual void step4(){
        cout<<"this is general main Pipeline step4"<<endl;
    }

    void template_method(){
        step1();
        step2();
        step3();
        step4();        
    }
};

class Apipeline : public Pipeline{
    public:
    void step1() override{
        cout<<"this is A Pipeline step1"<<endl;
    }
    
    void step2() override{
        cout<<"this is A Pipeline step2"<<endl;
    }
   
    void step3() override{
        cout<<"this is A Pipeline step3"<<endl;
    }
   
    void step4() override{
        cout<<"this is A Pipeline step4"<<endl;
    }
};

class Bpipeline : public Pipeline{
    public:
    void step1() override{
        cout<<"this is B Pipeline step1"<<endl;
    }
    
    void step2() override{
        cout<<"this is B Pipeline step2"<<endl;
    }
   
    void step3() override{
        cout<<"this is B Pipeline step3"<<endl;
    }
};




int main(){

    Pipeline* pipeline = new Apipeline();
    pipeline->template_method();

    cout<<"------------------"<<endl;

    Pipeline* pipeline2 = new Bpipeline();
    pipeline2->template_method();

    delete pipeline;
    delete pipeline2;
    

    return 0;
}