
# Debugging e Profiling em C++

Este tópico aborda duas técnicas essenciais para o desenvolvimento de software eficiente e funcional:

1. **Debugging**: Processo de identificação e correção de erros em um programa.
2. **Profiling**: Técnica para medir o desempenho do código e identificar gargalos.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <vector>
#include <chrono>

// Função para simular um processamento lento
void processamentoLento() {
    std::vector<int> v(1'000'000, 0);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i * i;
    }
    std::cout << "Processamento lento concluído!\n";
}

int main() {
    // DEBUGGING: Mensagens simples para acompanhar o programa
    std::cout << "Início do programa\n";

    try {
        auto inicio = std::chrono::high_resolution_clock::now();

        processamentoLento();

        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;

        // PROFILING: Medindo o tempo de execução
        std::cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    std::cout << "Fim do programa\n";
    return 0;
}
```

---

## Explicação do Código

### Debugging
- O `std::cout` é usado para imprimir mensagens no terminal, ajudando a entender o fluxo do programa.
- Ferramentas como **GDB** (GNU Debugger) podem ser usadas para inspecionar variáveis, definir breakpoints, etc.

### Profiling
- Usamos o `std::chrono` para medir o tempo de execução de uma função ou bloco de código.
- O resultado ajuda a identificar partes do código que podem ser otimizadas.

---

## Ferramentas para Debugging e Profiling

1. **Debugging:**
   - GDB (GNU Debugger).
   - Depuradores integrados em IDEs como Visual Studio, CLion ou VS Code.

2. **Profiling:**
   - Valgrind (com a ferramenta Callgrind).
   - gprof (GNU Profiler).
   - Perf (Linux).

---

## Benefícios do Debugging e Profiling

1. **Código mais confiável:**
   - Encontrar e corrigir erros reduz falhas no programa.

2. **Melhoria de desempenho:**
   - Identificar gargalos ajuda a otimizar o código para rodar mais rápido.

3. **Manutenção mais fácil:**
   - Um código bem testado e otimizado é mais fácil de manter e escalar.
