
# Streams e Manipulação de Arquivos em C++

Streams e manipulação de arquivos em C++ permitem que você interaja com dados armazenados em arquivos de maneira eficiente. Com `std::ofstream` e `std::ifstream`, você pode criar, escrever e ler arquivos facilmente.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Criando e escrevendo em um arquivo
    std::ofstream arquivoSaida("dados.txt"); // Abre/cria o arquivo em modo de escrita
    if (arquivoSaida.is_open()) {
        arquivoSaida << "Linha 1: Aprendendo Streams e Arquivos em C++\n";
        arquivoSaida << "Linha 2: Manipulação de arquivos é essencial!\n";
        arquivoSaida.close(); // Fecha o arquivo
        std::cout << "Arquivo 'dados.txt' criado e escrito com sucesso.\n";
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }

    // Lendo o conteúdo do arquivo
    std::ifstream arquivoEntrada("dados.txt"); // Abre o arquivo em modo de leitura
    if (arquivoEntrada.is_open()) {
        std::string linha;
        std::cout << "\nConteúdo do arquivo 'dados.txt':\n";
        while (std::getline(arquivoEntrada, linha)) {
            std::cout << linha << '\n';
        }
        arquivoEntrada.close(); // Fecha o arquivo
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura.\n";
    }

    return 0;
}
```

---

## Explicação do Código

### **Escrita de Arquivos**
- **`std::ofstream`:** Usado para criar e escrever em arquivos. O método `is_open()` verifica se o arquivo foi aberto corretamente. O método `close()` fecha o arquivo após o uso.

### **Leitura de Arquivos**
- **`std::ifstream`:** Usado para abrir e ler arquivos. O método `getline()` lê o conteúdo linha por linha.

---

## Benefícios

1. **Armazenamento Persistente:** Salva dados para reutilização futura.
2. **Streams:** Simplifica a manipulação de arquivos.

---

## Boas Práticas

1. Sempre feche os arquivos com `close()` após usá-los.
2. Verifique se o arquivo foi aberto corretamente usando `is_open()`.
3. Use manipulação de exceções para lidar com erros de arquivos.

---
