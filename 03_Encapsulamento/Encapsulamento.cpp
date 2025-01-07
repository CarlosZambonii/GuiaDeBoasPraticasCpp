#include <iostream>
using namespace std;

class Nome{
    private:
    int idade = 23;

    public:
        void nome(){
            cout<<"Carlos "<<endl;
        }
        int realIdade(){
            return idade;
        }
};
class Habilidades : public Nome{ //usando : consegue vincular uma classe com outra 
    public:
        void idiomas(){
            cout<<"Portugues Brasileiro "<< endl;
        }
};
int main(){
    Habilidades hab;
    cout<<"O nome dele e: ";
    hab.nome();
    cout<<"A habilidade dele e: ";
    hab.idiomas();
    cout<<"A idade dele e: "<< hab.realIdade();
}