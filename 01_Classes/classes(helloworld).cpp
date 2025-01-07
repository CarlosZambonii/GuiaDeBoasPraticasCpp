#include <iostream>
using namespace std;

// Definição da classe Hello
class Hello { 
    public: 
        // Método que imprime uma mensagem de saudação na tela.
        void sayHelloWorld() const { // Use const para indicar que o método não modifica o estado do objeto.
            cout << "Hello World" << endl;
        }
};

int main() {
    // Criando uma instância da classe Hello.
    Hello hello;
    
    // Chamando o método da classe para exibir a mensagem.
    hello.sayHelloWorld();

    return 0;
}