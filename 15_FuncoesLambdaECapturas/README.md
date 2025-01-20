
# Funções Lambda e Capturas em C++

Funções lambda são funções anônimas definidas diretamente no local onde são usadas. Elas são úteis para operações rápidas e reutilizáveis, especialmente em contextos de programação funcional.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    // Lambda simples para exibir os números
    auto exibir = [](int n) {
        std::cout << "Número: " << n << '\n';
    };

    // Chamando a lambda para cada elemento do vetor
    std::for_each(numeros.begin(), numeros.end(), exibir);

    // Captura por valor
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
```

---

## Explicação do Código

1. **Definição de Lambda:**
   - Uma lambda é definida como `[](parametros) { corpo }`.
   - Exemplo: `[](int n) { std::cout << n; }`.

2. **Captura por Valor `[valor]`:**
   - Uma cópia da variável é usada dentro da lambda.
   - No exemplo: `[multiplicador](int n)` usa o valor de `multiplicador`.

3. **Captura por Referência `[&variavel]`:**
   - A variável original é usada e modificada dentro da lambda.
   - No exemplo: `[&soma](int n)` altera diretamente o valor de `soma`.

4. **Aplicação:**
   - `std::for_each` utiliza lambdas para percorrer o vetor e realizar operações específicas.

---

## Saída do Programa

```
Número: 1
Número: 2
Número: 3
Número: 4
Número: 5

Resultados multiplicados por 3:
3
6
9
12
15

Soma total dos números: 15
```

---

## Boas Práticas com Lambdas

1. **Usar lambdas para simplificar código curto:**
   - Evite usá-las em lógicas complexas que dificultem a legibilidade.

2. **Definir capturas explicitamente:**
   - Use `[=]` para capturar todas as variáveis por valor.
   - Use `[&]` para capturar todas as variáveis por referência.
   - Especifique capturas individuais sempre que possível para evitar efeitos colaterais.

3. **Usar lambdas com STL:**
   - Combine lambdas com algoritmos da STL, como `std::for_each`, `std::transform` e `std::sort`.

4. **Evitar alterações desnecessárias:**
   - Sempre que possível, capture por valor para garantir a segurança do código.

---

## Vantagens das Lambdas

1. **Reutilização em Código Funcional:**
   - Lambdas tornam o código mais modular e reutilizável.

2. **Eliminação de Funções Anônimas Verbosas:**
   - Substituem funções globais que só são usadas localmente.

3. **Melhor Legibilidade:**
   - A lógica está onde é necessária, sem a necessidade de funções externas.

---
