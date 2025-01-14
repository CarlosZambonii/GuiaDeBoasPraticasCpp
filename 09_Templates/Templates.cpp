#include <iostream>

template <class T>
class Stack{
    public:
    void pilha(T array, int max){
        int i= {0};

        while (i< max)
        {
            std::cout<<"Os elementos do array sao: "<< array[i]<< "\n";
            ++i;
        }
    }
};

int main(){
    Stack <const std::string*> s;
    //char marray[] = {'A', 'B', 'C', 'D'};
      std::string marray[] = {"Bola", "Carro", "Sapato","Dado"};
    int max = sizeof(marray)/ sizeof(marray[0]);
    std::string * pmarray = marray;
    s.pilha( marray , max);

    return 0;
}
