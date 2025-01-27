
#include <iostream>
#include <type_traits>

template<int N>
struct Fatorial {
    static constexpr int value = N * Fatorial<N - 1>::value;
};

template<>
struct Fatorial<0> {
    static constexpr int value = 1;
};

int main() {
    constexpr int resultado = Fatorial<5>::value; 
    std::cout << "Fatorial de 5 e: " << resultado << std::endl;
    return 0;
}
