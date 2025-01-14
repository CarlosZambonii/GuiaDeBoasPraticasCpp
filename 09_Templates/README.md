
# Templates em C++

Templates são uma funcionalidade poderosa do C++ que permite a criação de funções e classes genéricas. Eles tornam o código mais reutilizável e eficiente, permitindo trabalhar com diferentes tipos de dados sem precisar reescrever a lógica.

---

## Código de Exemplo

```cpp
#include <iostream>

template <class T>
class Stack {
    public:
        void pilha(T array, int max) {
            int i = {0};

            while (i < max) {
                std::cout << "Os elementos do array sao: " << array[i] << "\n";
                ++i;
            }
        }
};

int main() {
    Stack<const std::string*> s;
    std::string marray[] = {"Bola", "Carro", "Sapato", "Dado"};
    int max = sizeof(marray) / sizeof(marray[0]);
    std::string* pmarray = marray;
    s.pilha(marray, max);

    return 0;
}
```

---

## Explicação do Código

### **O que são Templates?**
Templates permitem criar código genérico que funciona com diferentes tipos de dados. Eles são amplamente usados para:
- Funções genéricas (funções template).
- Classes genéricas (classes template).

### **Como funciona o exemplo?**
1. **Definição de um Template:**
   - `template <class T>` define um template genérico que usa `T` como um tipo de dado.

2. **Classe `Stack`:**
   - Possui um método `pilha` que aceita um array de tipo genérico `T` e o tamanho máximo do array.

3. **Função `main`:**
   - Um objeto da classe `Stack` é criado com o tipo `const std::string*`.
   - Um array de strings é declarado e passado ao método `pilha` para exibição de seus elementos.

4. **Saída do programa:**
   ```
   Os elementos do array sao: Bola
   Os elementos do array sao: Carro
   Os elementos do array sao: Sapato
   Os elementos do array sao: Dado
   ```

---

## Benefícios dos Templates

1. **Reutilização de Código:**
   - Um único template pode trabalhar com diferentes tipos de dados.

2. **Flexibilidade:**
   - Evita duplicação de código ao usar tipos diferentes para a mesma lógica.

3. **Eficiente:**
   - As instâncias de template são geradas apenas para os tipos usados, otimizando o desempenho.

---

## Boas Práticas com Templates

1. **Escolha nomes significativos para os parâmetros de tipo:**
   - Use nomes como `T` (tipo), `U` (outro tipo), ou algo mais descritivo.

2. **Evite lógica complexa em templates:**
   - Mantenha o código genérico simples e focado no propósito principal.

3. **Documente claramente as restrições de tipo:**
   - Esclareça os tipos esperados para os parâmetros do template.

4. **Teste com diferentes tipos:**
   - Garanta que seu template funciona corretamente com diversos tipos de dados.

---
