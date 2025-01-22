#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numeros = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::sort(numeros.begin(), numeros.end());
    std::cout << "Numeros ordenados: ";
    for (const auto& num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto it = std::find(numeros.begin(), numeros.end(), 5);
    if (it != numeros.end()) {
        std::cout << "Numero 5 encontrado na posicao: " << std::distance(numeros.begin(), it) << std::endl;
    } else {
        std::cout << "Numero 5 nao encontrado." << std::endl;
    }

    int soma = std::accumulate(numeros.begin(), numeros.end(), 0);
    std::cout << "Soma dos numeros: " << soma << std::endl;

    std::cout << "Numeros multiplicados por 2: ";
    std::for_each(numeros.begin(), numeros.end(), [](int& n) {
        n *= 2;
        std::cout << n << " ";
    });
    std::cout << std::endl;

    return 0;
}
