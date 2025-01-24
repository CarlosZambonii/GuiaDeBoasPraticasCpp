
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;

public:
    Pessoa(const string& nome) : nome(nome) {}
    virtual ~Pessoa() {}

    virtual void apresentar() const = 0;

    virtual void falar() const {
        cout << "Olá! Sou uma pessoa." << endl;
    }
};

class Aluno : public Pessoa {
private:
    string curso;

public:
    Aluno(const string& nome, const string& curso) : Pessoa(nome), curso(curso) {}

    void apresentar() const override {
        cout << "Eu sou o aluno " << nome << " e estudo " << curso << "." << endl;
    }

    void falar() const override {
        cout << "Estou animado para aprender mais sobre " << curso << "!" << endl;
    }
};

class Professor : public Pessoa {
private:
    string disciplina;

public:
    Professor(const string& nome, const string& disciplina) : Pessoa(nome), disciplina(disciplina) {}

    void apresentar() const override {
        cout << "Eu sou o professor " << nome << " e ensino " << disciplina << "." << endl;
    }
};

class Turma {
private:
    vector<shared_ptr<Pessoa>> membros;

public:
    void adicionarMembro(shared_ptr<Pessoa> pessoa) {
        membros.push_back(pessoa);
    }

    void apresentarTodos() const {
        cout << "--- Apresentando membros da turma ---" << endl;
        for (const auto& membro : membros) {
            membro->apresentar();
            membro->falar();
        }
    }
};

int main() {
    auto aluno1 = make_shared<Aluno>("Carlos", "Engenharia de Software");
    auto aluno2 = make_shared<Aluno>("Eduardo", "Ciência da Computação");
    auto professor = make_shared<Professor>("Zamboni", "POO Avançada");

    Turma turma;
    turma.adicionarMembro(aluno1);
    turma.adicionarMembro(aluno2);
    turma.adicionarMembro(professor);

    turma.apresentarTodos();

    return 0;
}
