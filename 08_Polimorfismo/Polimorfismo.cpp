#include <iostream>
using namespace std;

class Pessoa{
    public:
    int num(){
        return 10;
    }
    int num(int num){
        return num;
    }
};
class Turma : public Pessoa{
    public:
    int num(){
        return 50;
    }
    int num(int num){
        return num;
    }
};

int main(){
    Pessoa p;
    Turma t;
    cout<<"num() de Pessoa e: "<< p.num()<< endl;
    cout<<"num(int num) de Pessoa e: "<< p.num(256)<< endl;
    cout<<"num() de Turma e: "<< t.num()<< endl;
    cout<<"num(int num) de  Turma e: "<< t.num(128)<< endl;
}
