#include <iostream>
using namespace std;

class Iimage{
    public:
    virtual void display()=0;
    virtual ~Iimage(){}
};

class RealImage : public Iimage{
    public:
    RealImage(){
        cout<<"Expensive operation::: Loading from disk ::"<<endl;
    }

    void display() override{
        cout<<"displaying real image"<<endl;
    }        
};

class ImageProxy : public Iimage{
    RealImage* realImage = nullptr;
    public:

    ImageProxy(){
        cout<<"Loading Light weight Image Proxy"<<endl;
    }

    void display() override{
        if(!realImage){
            realImage = new RealImage();
        }
        realImage->display();
    }   

    ~ImageProxy(){
        delete realImage;
    }
};



int main(){
    
    Iimage* imageProxy = new ImageProxy();

    imageProxy->display();

    delete imageProxy;

    return 0;
}