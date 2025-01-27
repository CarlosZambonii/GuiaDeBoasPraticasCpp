
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

int main() {

    auto quadrado = [](int x) { return x * x; };
    std::cout << "Quadrado de 5: " << quadrado(5) << std::endl;

    std::vector<int> numeros = {1, 2, 3, 4, 5};
    std::vector<int> quadrados(numeros.size());
    std::transform(numeros.begin(), numeros.end(), quadrados.begin(), quadrado);

    std::cout << "Quadrados dos elementos: ";
    for (const auto& q : quadrados) {
        std::cout << q << " ";
    }
    std::cout << std::endl;

    auto soma = [](int a, int b) { return a + b; };
    int total = std::accumulate(numeros.begin(), numeros.end(), 0, soma);
    std::cout << "Soma dos elementos: " << total << std::endl;

    std::vector<int> filtrados;
    std::copy_if(numeros.begin(), numeros.end(), std::back_inserter(filtrados), [](int x) { return x > 2; });

    std::cout << "Elementos maiores que 2: ";
    for (const auto& f : filtrados) {
        std::cout << f << " ";
    }
    std::cout << std::endl;

    return 0;
}
