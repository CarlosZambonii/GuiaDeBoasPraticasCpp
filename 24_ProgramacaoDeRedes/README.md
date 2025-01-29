# Programação de Redes em C++

A programação de redes em C++ permite comunicação entre dispositivos através de protocolos como TCP e UDP. A biblioteca **Boost.Asio** é amplamente usada para lidar com operações assíncronas de rede.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Resolver o endereço do servidor
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("example.com", "80");

        // Criar um socket e conectar ao servidor
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Enviar uma requisição HTTP GET
        std::string request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
        boost::asio::write(socket, boost::asio::buffer(request));

        // Ler a resposta do servidor
        std::array<char, 1024> response;
        boost::system::error_code error;
        while (size_t len = socket.read_some(boost::asio::buffer(response), error)) {
            std::cout.write(response.data(), len);
        }

        if (error != boost::asio::error::eof) {
            throw boost::system::system_error(error);
        }
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
```

---

## Explicação do Código

1. **Criando um `io_context`**  
   - É o principal gerenciador de operações assíncronas.

2. **Resolvendo o endereço do servidor**  
   - `tcp::resolver` traduz um nome de domínio para um endereço IP.

3. **Criando um socket e conectando ao servidor**  
   - `boost::asio::connect()` estabelece uma conexão com o servidor.

4. **Enviando uma requisição HTTP GET**  
   - O código envia uma requisição simples para obter a página inicial do site.

5. **Lendo e imprimindo a resposta**  
   - O loop recebe os dados do servidor e imprime na tela.

---

## Benefícios da Programação de Redes em C++

1. **Baixo nível e alto desempenho**  
   - C++ permite controle preciso sobre a comunicação de rede.

2. **Bibliotecas poderosas como Boost.Asio**  
   - Facilita operações assíncronas e manuseio de redes.

3. **Escalabilidade**  
   - Aplicações de redes eficientes podem lidar com milhares de conexões simultâneas.

---

## Boas Práticas

- **Use manipulação assíncrona quando necessário**  
- **Gerencie erros corretamente** para evitar falhas inesperadas  
- **Evite bloqueios desnecessários** ao lidar com múltiplas conexões  

---

## Saída Esperada

A resposta do servidor HTTP será exibida no terminal, mostrando o HTML da página solicitada.

