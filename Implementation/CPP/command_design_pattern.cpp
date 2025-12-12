#include <iostream>
#include <vector>
using namespace std;


class Icommand{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Icommand(){}
};

class LightCommand : public Icommand{
    public:
    void execute(){
        cout<<"Light is turned ON ::"<<endl;
    }
    
    void undo(){
        cout<<"Light is turned OFF ::"<<endl;
    }
};

class FanCommand : public Icommand{
    public:
    void execute(){
        cout<<"Fan is turned ON ::"<<endl;
    }
    
    void undo(){
        cout<<"Fan is turned OFF ::"<<endl;
    }
};

class RemoteControl{
    protected:
    static int remote_control_button_size;
    vector<Icommand*> button_list;
    vector<bool> button_pressed;
    public:

    RemoteControl(){
        this->button_list.resize(remote_control_button_size,nullptr);
        this->button_pressed.resize(remote_control_button_size,false);
    }

    void setCommand(int index,Icommand* command){
        if(index>=0 && index<remote_control_button_size){
            button_list[index] = command;
        }
        else{
            cout<<"This command is invalid"<<endl;
        }
    }
  
    void pressButton(int index){
         if(index>=0 && index<remote_control_button_size){
            if(button_list[index] == nullptr){
                cout<<"Please set a command for this button !!"<<endl;
            }
            else{
                if(!button_pressed[index]){
                    button_pressed[index]=true;
                    button_list[index]->execute();
                }
                else{
                    button_pressed[index]=false;
                    button_list[index]->undo();
                }
            }
        }
        else{
            cout<<"This button is invalid"<<endl;
        }
    }

    ~RemoteControl(){
        for(auto it: button_list){
            delete it;
        }
    }
};

int RemoteControl::remote_control_button_size=2;

int main(){


    Icommand* light = new LightCommand();
    Icommand* fan = new FanCommand();

    RemoteControl* remote = new RemoteControl();

    remote->setCommand(0,light);
    remote->setCommand(1,fan);
    
    remote->pressButton(1);
    remote->pressButton(0);
    remote->pressButton(1);

    delete remote;

    return 0;
}