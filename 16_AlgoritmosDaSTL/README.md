# Algoritmos da STL (Standard Template Library) em C++

A Standard Template Library (STL) fornece uma série de algoritmos prontos que tornam o desenvolvimento mais eficiente. Esses algoritmos são usados com contêineres como `std::vector`, `std::list`, entre outros.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numeros = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // Algoritmo sort - Ordenação
    std::sort(numeros.begin(), numeros.end());
    std::cout << "Numeros ordenados: ";
    for (const auto& num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Algoritmo find - Busca
    auto it = std::find(numeros.begin(), numeros.end(), 5);
    if (it != numeros.end()) {
        std::cout << "Numero 5 encontrado na posicao: " << std::distance(numeros.begin(), it) << std::endl;
    } else {
        std::cout << "Numero 5 nao encontrado." << std::endl;
    }

    // Algoritmo accumulate - Soma dos elementos
    int soma = std::accumulate(numeros.begin(), numeros.end(), 0);
    std::cout << "Soma dos numeros: " << soma << std::endl;

    // Algoritmo for_each - Aplicar função a cada elemento
    std::cout << "Numeros multiplicados por 2: ";
    std::for_each(numeros.begin(), numeros.end(), [](int& n) {
        n *= 2;
        std::cout << n << " ";
    });
    std::cout << std::endl;

    return 0;
}
```

---

## Explicação do Código

### Principais Algoritmos Utilizados

1. **`std::sort`:**
   - Ordena os elementos de um contêiner em ordem crescente.
   - Exemplo: `std::sort(numeros.begin(), numeros.end());`

2. **`std::find`:**
   - Localiza um elemento no contêiner e retorna um iterador para ele.
   - Exemplo: `std::find(numeros.begin(), numeros.end(), 5);`

3. **`std::accumulate`:**
   - Retorna a soma (ou outro tipo de agregação) dos elementos de um contêiner.
   - Exemplo: `std::accumulate(numeros.begin(), numeros.end(), 0);`

4. **`std::for_each`:**
   - Aplica uma função ou lambda a cada elemento de um contêiner.
   - Exemplo: `std::for_each(numeros.begin(), numeros.end(), [](int& n) { n *= 2; });`

---

## Saída do Programa

```
Numeros ordenados: 1 1 2 3 3 4 5 5 5 6 9 
Numero 5 encontrado na posicao: 6
Soma dos numeros: 44
Numeros multiplicados por 2: 2 2 4 6 6 8 10 10 10 12 18 
```

---

## Benefícios dos Algoritmos da STL

1. **Eficiência:**
   - Algoritmos otimizados e amplamente testados.
2. **Redução de Código:**
   - Elimina a necessidade de implementar lógica básica manualmente.
3. **Generalidade:**
   - Pode ser usado com diferentes tipos de contêineres.

---

## Boas Práticas

- **Evite reinventar a roda:**
  - Sempre procure por algoritmos na STL antes de implementar o seu próprio.
- **Compreenda os requisitos dos iteradores:**
  - Alguns algoritmos requerem iteradores específicos como `RandomAccessIterator`.
- **Teste com diferentes tamanhos de dados:**
  - Verifique a eficiência do algoritmo com grandes conjuntos de dados.

---
