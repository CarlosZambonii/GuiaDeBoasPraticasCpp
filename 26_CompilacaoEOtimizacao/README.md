# Compilação e Otimização em C++

A compilação e otimização são etapas fundamentais para melhorar o desempenho de programas em C++. Isso envolve técnicas como uso de `inline`, otimizações do compilador e flags de compilação.

---

## Código de Exemplo

```cpp
#include <iostream>

inline int soma(int a, int b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    std::cout << "Soma: " << soma(x, y) << std::endl;
    return 0;
}
```

---

## Explicação do Código

1. **Uso da palavra-chave `inline`**  
   - Funções `inline` eliminam a sobrecarga de chamadas de função, reduzindo tempo de execução.

2. **Otimizações do Compilador**  
   - O compilador pode aplicar otimizações agressivas, reduzindo o tamanho do código.

3. **Flags de Compilação**  
   - `-O2` ou `-O3` para otimizações de velocidade.  
   - `-march=native` para instruções otimizadas para a arquitetura do processador.

---

## Boas Práticas

1. **Evite otimizações prematuras**  
   - Meça o desempenho antes de aplicar otimizações.

2. **Use ferramentas de profiling**  
   - Ferramentas como `gprof`, `perf` ou `valgrind` ajudam a identificar gargalos.

3. **Experimente diferentes níveis de otimização**  
   - Teste `-O2`, `-O3` e `-Ofast` para avaliar impactos.

---
