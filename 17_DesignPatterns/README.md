
# Design Patterns em C++

Os Design Patterns são soluções reutilizáveis para problemas comuns de design em software. Eles ajudam a criar código mais organizado, flexível e de fácil manutenção.

---

## Código de Exemplo

O código demonstra dois padrões de design fundamentais em C++:

1. **Singleton Pattern:** Garante que uma classe tenha apenas uma instância e fornece um ponto global de acesso a ela.
2. **Factory Pattern:** Fornece uma interface para criar objetos sem especificar suas classes concretas.

### Código Singleton e Factory

```cpp
#include <iostream>
#include <memory>
using namespace std;

// Singleton Pattern
class Singleton {
    // ...
};

// Factory Pattern
class Produto {
    // ...
};

int main() {
    // Uso do Singleton
    Singleton& singleton = Singleton::getInstance();
    singleton.mostrarMensagem();

    // Uso do Factory
    unique_ptr<Produto> produto1 = Fabrica::criarProduto('A');
    if (produto1) produto1->exibirProduto();

    return 0;
}
```

---

## Explicação dos Padrões

### **Singleton Pattern**
- **Descrição:** Garante que uma classe tenha uma única instância acessível globalmente.
- **Vantagem:** Controle centralizado de recursos.
- **Exemplo no Código:**
  - A classe `Singleton` possui um construtor privado e uma instância estática única.
  - O método `getInstance` cria e retorna a instância única.

### **Factory Pattern**
- **Descrição:** Cria objetos sem expor a lógica de criação ao cliente.
- **Vantagem:** Desacopla a lógica de criação da lógica de uso.
- **Exemplo no Código:**
  - A classe `Fabrica` contém o método `criarProduto` para instanciar produtos do tipo `A` ou `B`.

---

## Benefícios dos Design Patterns

1. **Manutenção Fácil:** Reduz a complexidade e melhora a legibilidade do código.
2. **Reutilização de Código:** Evita repetição ao reutilizar soluções.
3. **Flexibilidade:** Facilita modificações e extensões no futuro.

---

## Boas Práticas ao Usar Design Patterns

1. **Não Use Excessivamente:** Aplique padrões apenas onde necessário.
2. **Entenda o Problema:** Certifique-se de que o padrão escolhido resolve o problema específico.
3. **Combine Padrões:** Em projetos complexos, é comum usar múltiplos padrões juntos.

---

## Saída do Código

```plaintext
Este é o padrão Singleton em ação!
Produto A criado.
Produto B criado.
```

---
