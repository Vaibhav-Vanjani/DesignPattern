#include <iostream>
#include <vector>
using namespace std;

class FileSystemItem{
    public:
    virtual ~FileSystemItem(){}
    virtual void ls()=0;
    virtual FileSystemItem* cd(string file)=0;
    virtual void openAll()=0;
    virtual string getName()=0;
};

class File : public FileSystemItem{
    string file_name;
    string file_size;
    public:

    File(string file_name,string file_size){
        this->file_name=file_name;
        this->file_size=file_size;
    }

    string getName(){
        return this->file_name;
    }

    void ls(){
        cout<<getName()<<endl;
    }

    FileSystemItem* cd(string file){
        return nullptr;
    }

    void openAll(){
        cout<<getName()<<endl;
    }
};

class Folder : public FileSystemItem{
    string folder_name;
    vector<FileSystemItem*> fileSystemItem_list;
    public:

    Folder(string folder_name){
        this->folder_name=folder_name;
    }

    void add(FileSystemItem* file){
        fileSystemItem_list.push_back(file);
    }

    string getName(){
        return "+" + this->folder_name;
    }

    void ls(){
        for(auto fileItem : fileSystemItem_list){
            cout<<fileItem->getName()<<endl;
        }
    }

    FileSystemItem* cd(string file){
        for(auto fileItem : fileSystemItem_list){
            bool isFolder = false;
            string fileName = fileItem->getName();
            for(auto it: fileName){
                if(it == '+'){
                    isFolder = true;
                }
            }

            if(isFolder){
                fileName = fileName.replace(0,1,"");
            }

            if(fileName == file){
                return fileItem;
            }
        }
        return nullptr;
    }

    void openAll(){
         for(auto fileItem : fileSystemItem_list){
            bool isFolder = false;
            string fileName = fileItem->getName();
            
            for(auto it: fileName){
                if(it == '+'){
                    isFolder = true;
                }
            }

            if(isFolder){
                cout<<fileName<<endl;
            }
            
            fileItem->openAll();
          }
    }
};




int main(){

    Folder* root = new Folder("root");
    root->add(new File("1.txt","1"));
    root->add(new File("2.txt","1"));

    Folder* core = new Folder("core");
    root->add(core);
    core->add(new File("3.txt","1"));

    root->ls();
    cout<<"-----------"<<endl;

    root->openAll();
    cout<<"-----------"<<endl;
    
    core->ls();
    cout<<"-----------"<<endl;

    core->openAll();
    cout<<"-----------"<<endl;
    
    delete root;

    return 0;
}