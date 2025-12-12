#include <iostream>
using namespace std;

class Ireport{
    public:
    virtual void getJsonData(string data)=0;
    virtual ~Ireport(){}
};

class XMLProvider{
    public:
    string getXMLData(string data){
        return "<user> <name>" + data + "</name> </user>";
    }
};

class XMLProviderAdapter : public Ireport{
    XMLProvider* xmlProvider;
    public:
    XMLProviderAdapter(){
        this->xmlProvider = new XMLProvider();
    }

    void getJsonData(string data) override{
        string xmlContent = xmlProvider->getXMLData(data);
        cout<<(xmlContent+":: JSON Data");
    }
   
    ~XMLProviderAdapter(){
        delete xmlProvider;
    }
};


int main(){

    Ireport* report = new XMLProviderAdapter();

    report->getJsonData("getJSOn");

    delete report;

    return 0;
}