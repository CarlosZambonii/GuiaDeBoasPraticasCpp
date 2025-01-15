
# Tratamento de Exceções em C++

O tratamento de exceções em C++ permite capturar e lidar com erros que ocorrem em tempo de execução de maneira estruturada. Ele evita que o programa termine de forma inesperada e fornece uma maneira de gerenciar situações excepcionais.

---

## Código de Exemplo

```cpp
#include <iostream> 

void funcao(int* ptr, int x) {
    if (ptr == NULL || x == 0) {
        throw ptr; // Lança uma exceção se o ponteiro for nulo ou x for zero
    } else {
        std::cout << "O ponteiro e: " << *ptr << " e o numero e: " << x << '\n';
    }
}

int main() {
    int num = 10;
    int* ponteiro = &num;

    try {
        funcao(ponteiro, num);  // Chamada válida
        funcao(ponteiro, 48);  // Chamada válida
        funcao(ponteiro, 0);   // Lança uma exceção
    } catch (...) {
        std::cerr << "Erro identificado" << '\n'; // Captura qualquer exceção
    }
    
    return 0;
}
```

---

## Explicação do Código

1. **Lógica da Função `funcao`:**
   - Verifica se o ponteiro é nulo (`NULL`) ou se `x` é igual a zero.
   - Lança uma exceção usando `throw` caso a condição seja verdadeira.
   - Caso contrário, imprime os valores do ponteiro e da variável.

2. **Bloco `try`:**
   - As chamadas à função `funcao` são testadas dentro do bloco `try`.
   - Caso uma exceção seja lançada, o controle do programa passa para o bloco `catch`.

3. **Bloco `catch`:**
   - O bloco `catch` captura qualquer exceção lançada pelo `throw`.
   - Neste exemplo, usamos `catch(...)` para capturar qualquer tipo de exceção.

4. **Saída Esperada:**
   ```
   O ponteiro e: 10 e o numero e: 10
   O ponteiro e: 10 e o numero e: 48
   Erro identificado
   ```

---

## O que são `try` e `catch`?

- **`try`:** Um bloco que contém código que pode lançar uma exceção.
- **`catch`:** Um bloco que captura e lida com exceções lançadas no bloco `try`.

---

## Boas Práticas para Tratamento de Exceções

1. **Evite usar exceções para controle de fluxo normal:**
   - Use exceções apenas para erros inesperados ou situações excepcionais.

2. **Seja específico nos blocos `catch`:**
   - Evite capturar todas as exceções com `catch(...)` a menos que necessário.

3. **Documente suas exceções:**
   - Informe quais exceções podem ser lançadas por funções específicas.

4. **Garanta limpeza de recursos:**
   - Use RAII (Resource Acquisition Is Initialization) para gerenciar recursos e evitar vazamentos.

5. **Evite lançar exceções em destrutores:**
   - Lançar exceções em destrutores pode causar comportamento indefinido.

---

