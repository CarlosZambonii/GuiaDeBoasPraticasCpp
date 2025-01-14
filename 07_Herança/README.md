
# Herança em C++

Herança é um dos pilares da programação orientada a objetos. Ela permite que uma classe derive propriedades e comportamentos de outra classe, promovendo reutilização de código e extensibilidade.

---

## Código de Exemplo

```cpp
#include <iostream>
using namespace std;

class Nome {
    public:
        void nome() {
            cout << "Carlos Zamboni " << endl;
        }
};

class Habilidades : public Nome { 
    public:
        void idiomas() {
            cout << "Portugues Brasileiro " << endl;
        }
};

int main() {
    Habilidades hab;
    cout << "O nome dele e: ";
    hab.nome();
    cout << "A habilidade dele e: ";
    hab.idiomas();
}
```

---

## Explicação do Código

### **O que é herança?**
- Herança é o mecanismo que permite a criação de uma nova classe (`classe derivada`) baseada em uma classe existente (`classe base`).
- A classe derivada herda membros (atributos e métodos) da classe base, podendo adicionar novos ou sobrescrever existentes.

### **Como funciona o exemplo?**
1. **Classe `Nome`:**
   - Contém o método público `nome`, que exibe o nome do indivíduo.

2. **Classe `Habilidades`:**
   - Deriva da classe `Nome` usando a herança pública:
     ```cpp
     class Habilidades : public Nome
     ```
   - Isso significa que os membros públicos da classe base `Nome` serão públicos na classe derivada `Habilidades`.
   - Adiciona o método `idiomas` para exibir as habilidades linguísticas.

3. **Função `main`:**
   - Um objeto `hab` da classe `Habilidades` é criado.
   - O objeto `hab` pode acessar tanto o método `nome` da classe base quanto o método `idiomas` da própria classe.

4. **Saída do programa:**
   ```
   O nome dele e: Carlos Zamboni 
   A habilidade dele e: Portugues Brasileiro
   ```

---

## Tipos de Herança

1. **Herança Pública (`public`):**
   - Membros públicos da classe base continuam públicos na classe derivada.

2. **Herança Protegida (`protected`):**
   - Membros públicos e protegidos da classe base tornam-se protegidos na classe derivada.

3. **Herança Privada (`private`):**
   - Membros públicos e protegidos da classe base tornam-se privados na classe derivada.

---

## Boas Práticas com Herança

1. **Use herança somente quando for lógico:**
   - A relação deve ser clara. Exemplo: `Cachorro` é um tipo de `Animal`.

2. **Evite herança excessiva:**
   - Um excesso de níveis de herança pode tornar o código confuso e difícil de manter.

3. **Prefira composição quando possível:**
   - Em vez de herdar de uma classe, considere usar objetos dela como membros.

4. **Documente as hierarquias de classes:**
   - Explique as relações entre as classes para facilitar o entendimento do código.

5. **Evite herança múltipla:**
   - A herança múltipla pode introduzir ambiguidades.

---
