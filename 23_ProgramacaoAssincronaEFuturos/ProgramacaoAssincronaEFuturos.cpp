
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int operacaoDemorada(int numero) {
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    return numero * numero; 
}

int main() {
    std::cout << "Iniciando uma tarefa assíncrona...\n";

    std::future<int> resultado = std::async(std::launch::async, operacaoDemorada, 10);

    std::cout << "Enquanto a tarefa é processada, podemos executar outras coisas...\n";

    while (resultado.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
        std::cout << "Tarefa ainda em execução...\n";
    }

    int valor = resultado.get();
    std::cout << "Resultado da operação: " << valor << "\n";

    return 0;
}
