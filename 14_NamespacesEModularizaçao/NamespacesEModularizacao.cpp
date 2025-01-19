
#include <iostream>

namespace Utilitarios {
    void exibirMensagem() {
        std::cout << "Mensagem do namespace Utilitarios." << std::endl;
    }

    namespace Interno {
        void exibirMensagemInterna() {
            std::cout << "Mensagem do namespace interno de Utilitarios." << std::endl;
        }
    }
}

namespace Calculo {
    int soma(int a, int b) {
        return a + b;
    }

    int multiplicacao(int a, int b) {
        return a * b;
    }
}

int main() {

    Utilitarios::exibirMensagem();
    Utilitarios::Interno::exibirMensagemInterna();

    std::cout << "Soma de 5 + 3: " << Calculo::soma(5, 3) << std::endl;
    std::cout << "Multiplicacao de 5 * 3: " << Calculo::multiplicacao(5, 3) << std::endl;

    return 0;
}
