#include <iostream>

constexpr long int fib(int n){
    return (n <= 1) ? n : fib(n-1) + fib(n-2);
}

int main(){
    long int z= fib(30);
    std::cout<<"O numero fibonnaci de 30 e: "<< z <<"\n";
    return 0;
}
