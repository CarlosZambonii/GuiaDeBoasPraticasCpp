
# Programação Funcional em C++

A programação funcional é um paradigma que trata a computação como a avaliação de funções matemáticas, enfatizando o uso de funções puras, imutabilidade, e operações de alta ordem.

---

## Características da Programação Funcional

1. **Funções Puras:**
   - Não possuem efeitos colaterais e dependem apenas de seus argumentos.
2. **Imutabilidade:**
   - Dados não são modificados; em vez disso, novos dados são criados.
3. **Funções de Alta Ordem:**
   - Funções que recebem ou retornam outras funções.

---

## Código de Exemplo

```cpp
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
```

---

## Explicação do Código

1. **Função Lambda:**
   - Criada para calcular o quadrado de um número.
   - Sintaxe: `[capturas](parâmetros) { corpo }`.

2. **Transformação com `std::transform`:**
   - Aplica a função `quadrado` a cada elemento do vetor `numeros`.

3. **Acumulação com `std::accumulate`:**
   - Soma os elementos do vetor usando uma função personalizada.

4. **Filtragem com `std::copy_if`:**
   - Filtra elementos maiores que 2 e os armazena em outro vetor.

---

## Benefícios da Programação Funcional

1. **Código mais limpo e legível:**
   - Funções e operações declarativas simplificam a lógica.
2. **Menor propensão a erros:**
   - Funções puras e imutabilidade evitam efeitos colaterais.
3. **Facilidade de paralelismo:**
   - Funções puras são independentes, tornando o código mais apto para ser paralelizado.

---

## Boas Práticas

1. **Prefira Funções Puras:**
   - Evite modificar estados globais dentro de funções.
2. **Evite Efeitos Colaterais:**
   - Mantenha funções simples e independentes.
3. **Aproveite as Ferramentas da STL:**
   - Use algoritmos como `std::transform`, `std::accumulate`, e `std::copy_if`.

---

## Saída do Exemplo

```
Quadrado de 5: 25
Quadrados dos elementos: 1 4 9 16 25 
Soma dos elementos: 15
Elementos maiores que 2: 3 4 5
```
