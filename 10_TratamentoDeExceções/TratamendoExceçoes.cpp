#include <iostream>

void funcao(int * ptr, int x){
    if (ptr == NULL || x == 0)
    {
        throw ptr;
        //std:: cout<<"erro bizarro"<< '\n';
    }else{
        std::cout<<"o ponteiro e: "<< *ptr << " e o numero e: "<< x <<'\n';
    }
    
}

int main()
{
    int num = 10;
    int * ponteiro = &num;

    try
    {
        funcao(ponteiro,  num);
        funcao(ponteiro,  48);
        funcao(ponteiro,  12);
    }
    catch(...)
    {
        std::cerr << "Erro identificado" << '\n';
    }
    
    return 0;
}

