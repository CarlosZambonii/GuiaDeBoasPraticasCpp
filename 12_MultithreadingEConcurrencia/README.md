# Multithreading e Concorrência em C++

Multithreading e concorrência são conceitos essenciais para otimizar o desempenho de aplicações modernas. Eles permitem executar múltiplas tarefas simultaneamente, utilizando melhor os recursos do sistema.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <thread>
#include <vector>

void tarefa(int id) {
    std::cout << "Thread " << id << " iniciada.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " finalizada.\n";
}

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(tarefa, i + 1);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Todas as threads finalizaram.\n";
    return 0;
}
```

---

## Explicação do Código

### **O que é Multithreading?**
Multithreading permite a execução simultânea de várias "threads" dentro de um programa. Uma thread é a menor unidade de execução que o sistema operacional pode gerenciar.

### **Como funciona o exemplo?**
1. **Função `tarefa`:**
   - Representa a tarefa executada por cada thread, identificada por um `id`.

2. **Criação de Threads:**
   - Um vetor `std::vector<std::thread>` é usado para gerenciar as threads.
   - A função `emplace_back` cria e inicia uma nova thread que executa `tarefa`.

3. **Sincronização com `join`:**
   - Após a criação, `join` garante que todas as threads completem sua execução antes que o programa principal termine.

4. **Saída do programa:**
   - A saída exibirá as threads iniciando e finalizando em ordem não determinística:
   ```plaintext
   Thread 1 iniciada.
   Thread 2 iniciada.
   Thread 3 iniciada.
   Thread 4 iniciada.
   Thread 1 finalizada.
   Thread 2 finalizada.
   Thread 3 finalizada.
   Thread 4 finalizada.
   Todas as threads finalizaram.
   ```

---

## Benefícios do Multithreading

1. **Melhor Utilização de CPU:**
   - Executa múltiplas tarefas ao mesmo tempo, aumentando a eficiência.

2. **Desempenho Melhorado:**
   - Ideal para aplicações que podem dividir tarefas em partes independentes.

3. **Responsividade:**
   - Melhora a experiência do usuário em aplicações que processam dados extensivamente.

---

## Boas Práticas com Multithreading

1. **Evite Condições de Corrida:**
   - Use mecanismos de sincronização, como `std::mutex`, para evitar acessos simultâneos a dados compartilhados.

2. **Use o Número Correto de Threads:**
   - Evite criar mais threads do que o número de núcleos disponíveis no processador.

3. **Trate Exceções Dentro de Threads:**
   - Garanta que as exceções não causem o encerramento inesperado do programa principal.

4. **Prefira Ferramentas de Alto Nível:**
   - Utilize bibliotecas como `std::async` ou `std::future` quando possível.

5. **Teste Cuidadosamente:**
   - Erros em programas multithread são frequentemente intermitentes e difíceis de reproduzir.

---
