
# Programação Orientada a Objetos Avançada (POO Avançada)

A Programação Orientada a Objetos Avançada utiliza conceitos mais sofisticados da POO, como:
- Polimorfismo avançado.
- Classes abstratas.
- Uso de `shared_ptr` para gerenciamento de memória.
- Composição para criar relacionamentos entre objetos.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

// Classe base abstrata (uso de POO Avançada)
class Pessoa {
protected:
    string nome;

public:
    Pessoa(const string& nome) : nome(nome) {}
    virtual ~Pessoa() {}

    // Método virtual puro (classe abstrata)
    virtual void apresentar() const = 0;

    // Método virtual com implementação padrão
    virtual void falar() const {
        cout << "Olá! Sou uma pessoa." << endl;
    }
};

// Classe derivada 1
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

// Classe derivada 2
class Professor : public Pessoa {
private:
    string disciplina;

public:
    Professor(const string& nome, const string& disciplina) : Pessoa(nome), disciplina(disciplina) {}

    void apresentar() const override {
        cout << "Eu sou o professor " << nome << " e ensino " << disciplina << "." << endl;
    }
};

// Exemplo de composição
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
```

---

## Explicação do Código

1. **Classe Base Abstrata:**
   - `Pessoa` é uma classe base abstrata que define métodos genéricos, como `apresentar` (virtual puro) e `falar`.

2. **Polimorfismo:**
   - Cada classe derivada (`Aluno`, `Professor`) implementa os métodos de forma personalizada.

3. **Gerenciamento de Memória:**
   - Uso de `shared_ptr` para criar objetos sem a necessidade de liberar manualmente a memória.

4. **Composição:**
   - A classe `Turma` agrega objetos do tipo `Pessoa` (ou suas derivadas) em um `std::vector`.

5. **Saída do Programa:**
   ```plaintext
   --- Apresentando membros da turma ---
   Eu sou o aluno Carlos e estudo Engenharia de Software.
   Estou animado para aprender mais sobre Engenharia de Software!
   Eu sou o aluno Eduardo e estudo Ciência da Computação.
   Estou animado para aprender mais sobre Ciência da Computação!
   Eu sou o professor Zamboni e ensino POO Avançada.
   ```

---

## Conceitos Demonstrados

1. **Classes Abstratas e Métodos Virtuais Puros:**
   - Permitem criar uma interface genérica para diferentes tipos de objetos.

2. **Polimorfismo:**
   - O método `apresentar` é sobrescrito em cada classe derivada, permitindo chamadas dinâmicas.

3. **Composição:**
   - A classe `Turma` demonstra como agregar diferentes objetos relacionados.

4. **Uso de `shared_ptr`:**
   - Simplifica o gerenciamento de memória e evita vazamentos.

---

## Boas Práticas

1. Use **métodos virtuais puros** para garantir que as classes derivadas implementem o comportamento necessário.
2. Utilize **smart pointers** para evitar vazamentos de memória.
3. Modularize seu código usando composição para agregar objetos relacionados.
4. Comente seu código para torná-lo mais legível e fácil de entender.
