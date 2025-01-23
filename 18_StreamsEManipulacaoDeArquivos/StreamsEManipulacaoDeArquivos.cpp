
#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ofstream arquivoSaida("dados.txt"); 
    if (arquivoSaida.is_open()) {
        arquivoSaida << "Linha 1: Aprendendo Streams e Arquivos em C++\n";
        arquivoSaida << "Linha 2: Manipulação de arquivos é essencial!\n";
        arquivoSaida.close(); 
        std::cout << "Arquivo 'dados.txt' criado e escrito com sucesso.\n";
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }

    
    std::ifstream arquivoEntrada("dados.txt"); 
    if (arquivoEntrada.is_open()) {
        std::string linha;
        std::cout << "\nConteúdo do arquivo 'dados.txt':\n";
        while (std::getline(arquivoEntrada, linha)) {
            std::cout << linha << '\n';
        }
        arquivoEntrada.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura.\n";
    }

    return 0;
}
