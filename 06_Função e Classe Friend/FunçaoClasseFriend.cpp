#include <iostream>
using namespace std;

class Casa{
    public:
    string comp = "123";

    protected:
    char essid[5] = {'H','o', 'm', 'e', '\0'};

    private:
    string passwrd = "abc" + comp;

    friend class Vizinho;

};

class Vizinho{
    public:
    void controller(){
        Casa c;
        cout<<"A Rede e: " << c.essid<< endl;
        cout<<"A Senha e: " << c.passwrd;
    }
};

int main(){
    Vizinho v;
    v.controller();
    return 0;
}