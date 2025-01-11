#include <iostream>
using namespace std;

class Nome{
    public:
        void nome(){
            cout<<"Carlos Zamboni "<<endl;
        }
};
class Habilidades : public Nome{ 
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
}