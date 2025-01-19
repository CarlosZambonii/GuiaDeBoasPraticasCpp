#include <iostream>
using namespace std;

class Mae{
    public:
    virtual void menssagem(){
        cout<<"eu sou a mae "<< endl;
    }
};

class Filha : public Mae{
    public:
    void menssagem(){
        cout<<"eu sou a filha "<< endl;
    }
};

class Neta : public Mae{
    public:
    void menssagem(){
        cout<<"eu sou a neta "<< endl;
    }
};
void responde (Mae *m){
    m->menssagem();
}

int main(){
    Mae m;
    Filha f;
    Neta n;

    m.menssagem();
    f.menssagem();
    n.menssagem();

    cout<<endl<< "---------------------"<< endl;

    responde(&m);
    responde(&f);
    responde(&n);

    return 0;
}
