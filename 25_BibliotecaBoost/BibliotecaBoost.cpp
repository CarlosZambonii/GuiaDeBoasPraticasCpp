#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

int main() {
    std::string texto = "Biblioteca Boost em C++";
    boost::to_upper(texto);
    std::cout << "Texto em maiúsculas: " << texto << std::endl;

    std::vector<std::string> palavras;
    boost::split(palavras, texto, boost::is_any_of(" "));

    std::cout << "Palavras separadas:" << std::endl;
    for (const auto& palavra : palavras) {
        std::cout << palavra << std::endl;
    }

    return 0;
}