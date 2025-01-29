
# Programação Assíncrona e Futuros

A programação assíncrona permite que tarefas sejam executadas de forma não bloqueante, ou seja, o programa pode continuar executando enquanto uma tarefa em segundo plano é processada. Em C++, utilizamos as classes `std::async`, `std::future` e `std::promise` para implementar tarefas assíncronas.

---

## Código de Exemplo

### **Descrição do Exemplo**
No exemplo fornecido:
- Criamos uma função `operacaoDemorada` que simula uma operação que leva 3 segundos para ser concluída.
- Usamos `std::async` para executar essa função de forma assíncrona.
- Utilizamos `std::future` para obter o resultado da operação quando ela estiver concluída.

### **Funcionamento**
1. **Lançamento da Tarefa Assíncrona:**
   ```cpp
   std::future<int> resultado = std::async(std::launch::async, operacaoDemorada, 10);
   ```
   - `std::async` executa a função `operacaoDemorada` em uma thread separada.
   - O valor retornado pela função será armazenado em `resultado`.

2. **Monitoramento do Progresso:**
   ```cpp
   while (resultado.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
       std::cout << "Tarefa ainda em execução...\n";
   }
   ```
   - O método `wait_for` verifica se a tarefa foi concluída, mas sem bloquear a execução do programa principal.

3. **Obtenção do Resultado:**
   ```cpp
   int valor = resultado.get();
   ```
   - O método `get` bloqueia a execução até que o resultado esteja disponível.

---

## Saída Esperada
```
Iniciando uma tarefa assíncrona...
Enquanto a tarefa é processada, podemos executar outras coisas...
Tarefa ainda em execução...
Tarefa ainda em execução...
Resultado da operação: 100
```

---

## Benefícios da Programação Assíncrona
1. **Melhor Uso de Recursos:**
   - Executa múltiplas tarefas simultaneamente, utilizando melhor o processador.

2. **Interface Responsiva:**
   - Em programas com interface gráfica, evita que a interface congele durante a execução de operações demoradas.

3. **Flexibilidade:**
   - Permite monitorar o progresso e obter resultados conforme necessário.

---

## Boas Práticas
- Use `std::future` para capturar o resultado de tarefas assíncronas.
- Combine `std::async` com `std::thread` em cenários complexos.
- Sempre trate exceções geradas por tarefas assíncronas, pois podem causar problemas silenciosos no programa.

---
