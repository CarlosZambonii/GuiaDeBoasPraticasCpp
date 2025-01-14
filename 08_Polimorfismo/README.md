
# Polimorfismo em C++

Polimorfismo é um conceito fundamental na programação orientada a objetos que permite que métodos com o mesmo nome se comportem de forma diferente, dependendo do contexto em que são usados.

---

## Código de Exemplo

```cpp
#include <iostream>
using namespace std;

class Pessoa {
    public:
        int num() {
            return 10;
        }
        int num(int num) {
            return num;
        }
};

class Turma : public Pessoa {
    public:
        int num() {
            return 50;
        }
        int num(int num) {
            return num;
        }
};

int main() {
    Pessoa p;
    Turma t;
    cout << "num() de Pessoa e: " << p.num() << endl;
    cout << "num(int num) de Pessoa e: " << p.num(256) << endl;
    cout << "num() de Turma e: " << t.num() << endl;
    cout << "num(int num) de Turma e: " << t.num(128) << endl;
}
```

---

## Explicação do Código

### **O que é Polimorfismo?**
Polimorfismo significa "muitas formas". Em C++, pode ser realizado de duas maneiras:
1. **Polimorfismo em tempo de compilação:** Acontece quando a decisão de qual método será chamado é feita durante a compilação, como na sobrecarga de métodos.
2. **Polimorfismo em tempo de execução:** Acontece quando a decisão de qual método será chamado é feita durante a execução, geralmente com o uso de funções virtuais.

### **Como funciona o exemplo?**
1. **Classe `Pessoa`:**
   - Define dois métodos chamados `num`:
     - Um sem parâmetros, que retorna o número fixo `10`.
     - Outro que aceita um parâmetro `int` e o retorna.

2. **Classe `Turma`:**
   - Deriva da classe `Pessoa` e redefine os métodos `num` para fornecer comportamentos diferentes:
     - O método sem parâmetros retorna `50`.
     - O método com parâmetros retorna o número fornecido.

3. **Função `main`:**
   - Cria um objeto `p` da classe `Pessoa` e um objeto `t` da classe `Turma`.
   - Demonstra o uso de métodos polimórficos, chamando-os nos dois objetos.
   - Exibe a saída correspondente.

4. **Saída do programa:**
   ```
   num() de Pessoa e: 10
   num(int num) de Pessoa e: 256
   num() de Turma e: 50
   num(int num) de Turma e: 128
   ```

---

## Tipos de Polimorfismo

1. **Sobrecarga de Métodos (Compile Time):**
   - O mesmo nome de método pode ter diferentes assinaturas dentro de uma classe.
   - Exemplo no código: `num()` e `num(int num)`.

2. **Sobrescrita de Métodos (Run Time):**
   - Uma classe derivada pode sobrescrever métodos de uma classe base.
   - Exemplo no código: `num()` na classe `Turma` substitui o método da classe `Pessoa`.

---

## Boas Práticas com Polimorfismo

1. **Use polimorfismo para simplificar código:**
   - Ajuda a tornar o código mais flexível e fácil de entender.

2. **Prefira funções virtuais para polimorfismo em tempo de execução:**
   - Use a palavra-chave `virtual` na classe base.

3. **Evite sobrecarregar métodos com assinaturas ambíguas:**
   - Certifique-se de que os métodos sobrecarregados têm parâmetros distintos para evitar confusão.

4. **Documente o comportamento esperado:**
   - Explique como os métodos polimórficos devem ser usados.

---
