    #include <iostream>
    #include <memory>
    using namespace std;


    class Burger{
        public:
        virtual void display()=0;
        virtual ~Burger()=default;
    };

    class StandardWheatBurger : public Burger{
        public:
        void display(){
            cout<<"this is a Standard Wheat burger"<<endl;
        }
    };

    class StandardBurger: public Burger{
        public:
        void display(){
            cout<<"this is a Standard burger"<<endl;
        }
    };

    class PremiumWheatBurger : public Burger{
        public:
        void display(){
            cout<<"this is a premium Wheat burger"<<endl;
        }

    };

    class PremiumBurger: public Burger{
        public:
        void display(){
            cout<<"this is a premium burger"<<endl;
        }
    };

    class BurgerFactoy{
        public: 
        virtual unique_ptr<Burger> orderType(const string &type)=0;
    };

    class SinghBurgerFactory : public BurgerFactoy{
        public:

        unique_ptr<Burger> orderType(const string &type){
            if(type == "standard"){
                return make_unique<StandardWheatBurger>();
            }
            else if(type == "premium"){
                return make_unique<PremiumWheatBurger>();
            }
            else{
                return nullptr;
            }
        }
    };

    class KingBurgerFactory : public BurgerFactoy{
        public:

        unique_ptr<Burger> orderType(const string &type){
            if(type == "standard"){
                return make_unique<StandardBurger>();
            }
            else if(type == "premium"){
                return make_unique<PremiumBurger>();
            }
            else{
                return nullptr;
            }
        }
    };


    int main(){

        unique_ptr<BurgerFactoy> bgFactory = make_unique<SinghBurgerFactory>();
        unique_ptr<Burger> bg = move(bgFactory->orderType("ds"));
        if(bg){ 
            bg->display();
        }
        else{
            cout<<"Order type is not supported";
        }
        return 0;
    }