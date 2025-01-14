
# Encapsulamento em C++

Encapsulamento é um dos pilares da programação orientada a objetos. Ele é usado para proteger os dados de uma classe, permitindo que sejam acessados apenas por métodos específicos.

---

## Código de Exemplo

```cpp
#include <iostream>
using namespace std;

class Nome {
    private:
        int idade = 23; // Propriedade privada, acessível apenas dentro da classe

    public:
        void nome() {
            cout << "Carlos" << endl;
        }

        int realIdade() {
            return idade; // Método público para acessar a propriedade privada
        }
};

class Habilidades : public Nome { // Herança pública
    public:
        void idiomas() {
            cout << "Portugues Brasileiro " << endl;
        }
};

int main() {
    Habilidades hab;
    cout << "O nome dele é: ";
    hab.nome();
    cout << "A habilidade dele é: ";
    hab.idiomas();
    cout << "A idade dele é: " << hab.realIdade();
}
```

---

## Explicação do Código

### **Encapsulamento**
Encapsulamento é o conceito de restringir o acesso direto aos dados de uma classe. Em C++, isso é alcançado utilizando os seguintes modificadores de acesso:
- **`private`**: Membros privados só podem ser acessados dentro da própria classe.
- **`protected`**: Membros protegidos podem ser acessados por classes derivadas.
- **`public`**: Membros públicos podem ser acessados de qualquer lugar.

No exemplo:
- O atributo `idade` é declarado como `private`.
- O método `realIdade` é usado para acessar o valor de `idade`.

### **Herança**
A classe `Habilidades` herda publicamente da classe `Nome`, o que significa que todos os membros públicos e protegidos de `Nome` estão acessíveis em `Habilidades`.

Exemplo:
```cpp
class Habilidades : public Nome {
    public:
        void idiomas() {
            cout << "Portugues Brasileiro " << endl;
        }
};
```

No programa principal, um objeto de `Habilidades` pode usar os métodos herdados de `Nome`:
```cpp
hab.nome();       // Método herdado de Nome
hab.idiomas();    // Método definido em Habilidades
hab.realIdade();  // Método herdado de Nome
```

### **Exibição**
A saída do programa é:
```
O nome dele é: Carlos  
A habilidade dele é: Portugues Brasileiro 
A idade dele é: 23
```

---

## Boas Práticas

1. **Use modificadores de acesso apropriados** para proteger os dados internos da classe.
2. **Forneça métodos de acesso (getters e setters)** para manipular atributos privados, garantindo controle e validação.
3. **Evite expor diretamente atributos protegidos ou privados** para reduzir o acoplamento.
4. **Prefira a herança pública apenas quando a relação "é um" for verdadeira**. Use composição para relações mais flexíveis.
5. **Mantenha a lógica de encapsulamento simples** para facilitar o entendimento do código.

---
