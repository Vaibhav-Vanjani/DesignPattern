#include <iostream>
#include <vector>
using namespace std;

class ISubscriber;

class Ichannel{

    protected:
    string name;
    vector<ISubscriber*> subscriber_list;
    vector<string> video_list;
    public:
    
    virtual void notify() = 0;
    virtual void addVideo(string video_name) = 0;
    virtual string getNewVideo() = 0;
    virtual  string displayName() = 0;
    virtual void addSubscriber(ISubscriber* subscriber) = 0;
    virtual void removeSubscriber(ISubscriber* subscriber) = 0;
    virtual ~Ichannel(){}
};

class ISubscriber{
    protected:
    string name;
    
    public:
    virtual void subscribe(Ichannel* ytchannel) = 0;
    virtual void unsubscribe(Ichannel* ytchannel) = 0;
    virtual void update(Ichannel* ytchannel) = 0;
    virtual ~ISubscriber(){}
};

class Ytsubscriber : public ISubscriber{

    vector<Ichannel*> subscribed_yt_list;
    public:

    Ytsubscriber(string name){
        this->name = name;
    }

    void subscribe(Ichannel* ytchannel){
        int index_to_find = -1;
        for(int i=0;i<this->subscribed_yt_list.size();i++){
            if(this->subscribed_yt_list[i] == ytchannel){
                index_to_find = i;
                break;
            }
        }

        if(index_to_find == -1)
        {
            this->subscribed_yt_list.push_back(ytchannel);
            ytchannel->addSubscriber(this);
        }
    }
    
    void unsubscribe(Ichannel* ytchannel){
        int index_to_delete = -1;
        for(int i=0;i<this->subscribed_yt_list.size();i++){
            if(this->subscribed_yt_list[i] == ytchannel){
                index_to_delete = i;
                break;
            }
        }

        if(index_to_delete != -1){
            this->subscribed_yt_list.erase(this->subscribed_yt_list.begin()+index_to_delete);
            ytchannel->removeSubscriber(this);
        }
    }

    void update(Ichannel* ytchannel){
        cout<<this->name<<":: Notification ::"<<ytchannel->displayName()<<""<<ytchannel->getNewVideo()<<""<<endl;
    }

    ~Ytsubscriber() {
        for (auto ch : subscribed_yt_list) {
            ch->removeSubscriber(this);
        }
    }

};


class YtChannel : public Ichannel{

    public:

    YtChannel(string name){
        this->name = name;
    }

    string displayName(){
        return this->name;
    }

    void notify(){
        for(auto subscriber : this->subscriber_list){
            subscriber->update(this);
        }
    }

    void addVideo(string video_name){
         this->video_list.push_back(video_name);
         notify();
    }

    string getNewVideo(){
        if(!this->video_list.empty()){
            return this->video_list.back();
        }
        return "No New Video Uploaded";
    }

    void addSubscriber(ISubscriber* subscriber){
        int index_to_find = -1;
        for(int i=0;i<this->subscriber_list.size();i++){
            if(this->subscriber_list[i] == subscriber){
                index_to_find = i;
                break;
            }
        }
        if(index_to_find == -1)
        this->subscriber_list.push_back(subscriber);
    }

   void removeSubscriber(ISubscriber* subscriber){
       int index_to_delete = -1;
        for(int i=0;i<this->subscriber_list.size();i++){
            if(this->subscriber_list[i] == subscriber){
                index_to_delete = i;
                break;
            }
        }
        if(index_to_delete != -1)
        this->subscriber_list.erase(this->subscriber_list.begin()+index_to_delete);
    }

    ~YtChannel() {
    for (auto sub : subscriber_list) {
        sub->unsubscribe(this);
    }
    }

};


int main(){

    Ichannel* freeCodeCamp = new YtChannel("freeCodeCamp");
    ISubscriber* vaibhav = new Ytsubscriber("vaibhav");
    ISubscriber* ram = new Ytsubscriber("ram");
    ISubscriber* shyam = new Ytsubscriber("shyam");
    
    vaibhav->subscribe(freeCodeCamp);
    ram->subscribe(freeCodeCamp);
    freeCodeCamp->addVideo("thisNewVideo 1");

    vaibhav->unsubscribe(freeCodeCamp);
    freeCodeCamp->addVideo("thisNewVideo 2");

    delete freeCodeCamp;
    delete vaibhav;
    delete ram;
    delete shyam;
    
    return 0;
}