#include <iostream>
#include <memory>
using namespace std;


class Flyable{
    public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class NoFlyAbility : public Flyable{
    public: 
    void fly(){
        cout<<"this robot cant fly"<<endl;
    }
};

class JetFly : public Flyable{
    public: 
    void fly(){
        cout<<"this is a jet fly impl"<<endl;
    }
};

class Talkable{
    public:
    virtual void talk() = 0;
    virtual ~Talkable() = default;
};

class NoTalk : public Talkable{
    public: 
    void talk(){
        cout<<"this is a No Talk impl"<<endl;
    }
};


class SpiderTalk : public Talkable{
    public: 
    void talk(){
        cout<<"this is a jet fly impl"<<endl;
    }
};

class Walkable{
    public:
    virtual void walk() = 0;
    virtual ~Walkable() = default;
};

class ThreeLegWalk : public Walkable{
    public: 
    void walk(){
        cout<<"this is a ThreeLegWalk walk impl"<<endl;
    }
};

class NoWalk : public Walkable{
    public: 
    void walk(){
        cout<<"this is a Nowalk walk impl"<<endl;
    }
};

class Robot{
    unique_ptr<Walkable> w;
    unique_ptr<Talkable> t;
    unique_ptr<Flyable> f;
    public:
    Robot(unique_ptr<Walkable> w, unique_ptr<Talkable> t,unique_ptr<Flyable> f){
       this->w = move(w);
       this->t = move(t);
       this->f = move(f);
    }

    void roboWalk(){
        if(this->w){
            return this->w->walk();
        }
    }

    void roboTalk(){
        if(this->t){
            return this->t->talk();
        }
    }

    void roboFly(){
        if(this->f){
            return this->f->fly();
        }
    }
};


int main(){

    unique_ptr<Robot> r = make_unique<Robot>(make_unique<NoWalk>(),make_unique<NoTalk>(),make_unique<JetFly>());
    r->roboFly();
    r->roboTalk();
    r->roboWalk();

    return 0;
}