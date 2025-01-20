
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    auto exibir = [](int n) {
        std::cout << "Número: " << n << '\n';
    };

    std::for_each(numeros.begin(), numeros.end(), exibir);

    int multiplicador = 3;
    auto multiplicar = [multiplicador](int n) {
        return n * multiplicador;
    };

    std::cout << "\nResultados multiplicados por " << multiplicador << ":\n";
    for (int n : numeros) {
        std::cout << multiplicar(n) << '\n';
    }

    int soma = 0;
    auto somar = [&soma](int n) {
        soma += n;
    };

    std::for_each(numeros.begin(), numeros.end(), somar);
    std::cout << "\nSoma total dos números: " << soma << '\n';

    return 0;
}
