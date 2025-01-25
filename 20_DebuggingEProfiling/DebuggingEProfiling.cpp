
#include <iostream>
#include <vector>
#include <chrono>

void processamentoLento() {
    std::vector<int> v(1'000'000, 0);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i * i;
    }
    std::cout << "Processamento lento concluído!\n";
}

int main() {

    std::cout << "Início do programa\n";

    try {
        auto inicio = std::chrono::high_resolution_clock::now();

        processamentoLento();

        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;

        std::cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    std::cout << "Fim do programa\n";
    return 0;
}
