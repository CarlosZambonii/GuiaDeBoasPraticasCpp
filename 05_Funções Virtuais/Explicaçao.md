
# Funções Virtuais em C++

Funções virtuais em C++ permitem o polimorfismo, permitindo que a função correta seja chamada para um objeto, independentemente do tipo de ponteiro que a referencia. Isso é conseguido usando a palavra-chave `virtual`.

---

## Código de Exemplo

```cpp
#include <iostream>
using namespace std;

class Mae {
    public:
    virtual void menssagem() {
        cout << "eu sou a mae " << endl;
    }
};

class Filha : public Mae {
    public:
    void menssagem() {
        cout << "eu sou a filha " << endl;
    }
};

class Neta : public Mae {
    public:
    void menssagem() {
        cout << "eu sou a neta " << endl;
    }
};

void responde(Mae *m) {
    m->menssagem();
}

int main() {
    Mae m;
    Filha f;
    Neta n;

    m.menssagem();
    f.menssagem();
    n.menssagem();

    cout << endl << "---------------------" << endl;

    responde(&m);
    responde(&f);
    responde(&n);

    return 0;
}
```

---

## Explicação do Código

### **O que são Funções Virtuais?**
- Uma função virtual é definida em uma classe base usando a palavra-chave `virtual`.
- Permite que as classes derivadas sobrescrevam o comportamento dessa função.
- Quando uma função virtual é chamada por meio de um ponteiro para a classe base, o método da classe derivada será executado, garantindo o polimorfismo.

### **Como funciona o exemplo?**
1. A classe `Mae` define a função `menssagem` como virtual:
   ```cpp
   virtual void menssagem() {
       cout << "eu sou a mae " << endl;
   }
   ```

2. As classes derivadas `Filha` e `Neta` sobrescrevem a função:
   ```cpp
   void menssagem() {
       cout << "eu sou a filha " << endl;
   }
   ```
   ```cpp
   void menssagem() {
       cout << "eu sou a neta " << endl;
   }
   ```

3. No `main`, as funções são chamadas diretamente e por meio de um ponteiro:
   ```cpp
   responde(&m);
   responde(&f);
   responde(&n);
   ```
   - Aqui, o comportamento polimórfico ocorre devido à palavra-chave `virtual`.

### **Saída do Programa**
```
eu sou a mae
eu sou a filha
eu sou a neta

---------------------
eu sou a mae
eu sou a filha
eu sou a neta
```

---

## Boas Práticas

1. Sempre use funções virtuais para permitir comportamento polimórfico em hierarquias de classes.
2. Adicione o destrutor virtual em classes base se houver possibilidade de destruição dinâmica:
   ```cpp
   virtual ~Mae() {}
   ```
3. Minimize o uso de funções virtuais puras (`= 0`) quando não for necessário implementar um comportamento padrão na classe base.
4. Use ponteiros inteligentes para gerenciar o tempo de vida dos objetos e evitar vazamentos de memória.

---
