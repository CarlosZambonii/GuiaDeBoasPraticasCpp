
#include <iostream>
#include <memory> 
using namespace std;

class Singleton {
private:
    static unique_ptr<Singleton> instance; 
    Singleton() {} 

public:
    static Singleton& getInstance() {
        if (!instance) {
            instance = unique_ptr<Singleton>(new Singleton());
        }
        return *instance;
    }

    void mostrarMensagem() const {
        cout << "Este é o padrão Singleton em ação!" << endl;
    }
};

unique_ptr<Singleton> Singleton::instance = nullptr;

class Produto {
public:
    virtual void exibirProduto() const = 0;
    virtual ~Produto() = default;
};

class ProdutoA : public Produto {
public:
    void exibirProduto() const override {
        cout << "Produto A criado." << endl;
    }
};

class ProdutoB : public Produto {
public:
    void exibirProduto() const override {
        cout << "Produto B criado." << endl;
    }
};

class Fabrica {
public:
    static unique_ptr<Produto> criarProduto(char tipo) {
        if (tipo == 'A') {
            return make_unique<ProdutoA>();
        } else if (tipo == 'B') {
            return make_unique<ProdutoB>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    
    Singleton& singleton = Singleton::getInstance();
    singleton.mostrarMensagem();

    unique_ptr<Produto> produto1 = Fabrica::criarProduto('A');
    if (produto1) produto1->exibirProduto();

    unique_ptr<Produto> produto2 = Fabrica::criarProduto('B');
    if (produto2) produto2->exibirProduto();

    return 0;
}
