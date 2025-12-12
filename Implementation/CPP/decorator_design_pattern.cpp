#include <iostream>
using namespace std;

class Icharacter{
    public:
    virtual string getAbility() = 0;
    virtual ~Icharacter(){}
};

class Idecorator : public Icharacter{
    protected:
    Icharacter* character;
    public:
    virtual ~Idecorator() {
        delete character; // delete wrapped object
    }
};

class Mario : public Icharacter{
    public:
    string getAbility(){
        return "Mario ability ::";
    }
};

class HeightUpDecorator : public Idecorator{
    public:
    
    HeightUpDecorator(Icharacter* character){
        this->character = character;
    }

    string getAbility(){
        return this->character->getAbility() + "+Height Up ";
    }
};

class GunUpDecorator : public Idecorator{
    public:
    GunUpDecorator(Icharacter* character){
        this->character = character;
    }

    string getAbility(){
        return this->character->getAbility() + "+Gun Up ";
    }
};

class BombUpDecorator : public Idecorator{
    public:

    BombUpDecorator(Icharacter* character){
        this->character = character;
    }


    string getAbility(){
        return this->character->getAbility() + "+Bomb Up ";
    }
};



int main(){

   Icharacter* mario = new Mario();
   cout<<mario->getAbility()<<endl;

   mario = new HeightUpDecorator(mario);
   cout<<mario->getAbility()<<endl;

   mario = new GunUpDecorator(mario);
   cout<<mario->getAbility()<<endl;

   mario = new BombUpDecorator(mario);
   cout<<mario->getAbility()<<endl;

   delete mario;


    return 0;
}