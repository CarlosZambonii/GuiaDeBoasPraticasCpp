
#include <iostream>
#include <memory> 
using namespace std;

class Recurso {
public:
    Recurso(const string& nome) : nome(nome) {
        cout << "Recurso " << nome << " alocado." << endl;
    }
    ~Recurso() {
        cout << "Recurso " << nome << " desalocado." << endl;
    }
    void exibir() {
        cout << "Usando recurso: " << nome << endl;
    }

private:
    string nome;
};

int main() {
    cout << "=== Usando unique_ptr ===" << endl;
    {
        unique_ptr<Recurso> recursoUnico = make_unique<Recurso>("Recurso Único");
        recursoUnico->exibir();
    } 

    cout << "\n=== Usando shared_ptr ===" << endl;
    {
        shared_ptr<Recurso> recursoCompartilhado1 = make_shared<Recurso>("Recurso Compartilhado");
        {
            shared_ptr<Recurso> recursoCompartilhado2 = recursoCompartilhado1;
            cout << "Contagem de referências: " << recursoCompartilhado1.use_count() << endl;
        }
        cout << "Contagem de referências após sair do escopo interno: " << recursoCompartilhado1.use_count() << endl;
    } 

    cout << "\n=== Usando weak_ptr ===" << endl;
    {
        shared_ptr<Recurso> recursoPrincipal = make_shared<Recurso>("Recurso Principal");
        weak_ptr<Recurso> recursoFraco = recursoPrincipal;

        if (auto recurso = recursoFraco.lock()) {
            recurso->exibir();
        }
        cout << "Recurso ainda existe? " << !recursoFraco.expired() << endl;

        recursoPrincipal.reset(); 
        cout << "Recurso ainda existe após reset? " << !recursoFraco.expired() << endl;
    }

    return 0;
}
