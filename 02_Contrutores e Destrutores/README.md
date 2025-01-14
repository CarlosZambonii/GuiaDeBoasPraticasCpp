
# Construtores e Destrutores em C++

Construtores e destrutores são partes essenciais de uma classe em C++. Eles ajudam a inicializar e limpar recursos quando objetos são criados e destruídos, promovendo a eficiência e segurança no gerenciamento de recursos.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <ncurses.h>
using namespace std;

class Qualquer {
    public:
        Qualquer() {  // Construtor chamado ao criar um objeto
            initscr();  // Inicializa o ncurses
        }

        void funcao1() {
            printw("funcao 1");  // Exibe texto na tela usando ncurses
            refresh();          // Atualiza a tela
        }

        void funcao2() {
            move(3, 20);        // Move o cursor para uma posição específica
            printw("funcao 2"); // Exibe texto na nova posição
        }

        ~Qualquer() {  // Destrutor chamado ao sair do escopo do objeto
            getch();   // Aguarda entrada do usuário antes de fechar a tela
            endwin();  // Finaliza o ncurses
        }
};

int main() {
    Qualquer q;  // Construtor é automaticamente chamado aqui

    q.funcao1(); // Chamada ao método funcao1
    q.funcao2(); // Chamada ao método funcao2

    return 0;    // Destrutor é automaticamente chamado ao sair do escopo
}
```

---

## Explicação do Código

### **Construtores**
Um **construtor** é uma função membro especial que é chamada automaticamente quando um objeto da classe é criado. Ele é usado para inicializar os membros ou configurar o ambiente necessário para o objeto.

#### Características:
1. **Mesmo nome da classe**: A função construtora deve ter o mesmo nome da classe.
2. **Sem tipo de retorno**: Nenhum tipo de retorno, nem mesmo `void`.
3. **Chamado automaticamente**: Não é necessário chamá-lo explicitamente.

No exemplo acima:
```cpp
Qualquer() {
    initscr();  // Inicializa a biblioteca ncurses
}
```
O construtor inicializa o ambiente ncurses para que as funções de impressão e manipulação de tela possam ser usadas.

---

### **Métodos**
Os métodos `funcao1` e `funcao2` demonstram como manipular texto usando ncurses:
- `printw`: Escreve texto na tela.
- `refresh`: Atualiza o conteúdo da tela.
- `move`: Move o cursor para uma posição específica antes de imprimir.

Exemplo:
```cpp
void funcao1() {
    printw("funcao 1");  // Escreve texto
    refresh();           // Atualiza a tela
}
```

---

### **Destrutores**
Um **destrutor** é uma função membro especial que é chamada automaticamente quando um objeto sai de escopo ou é explicitamente destruído. Ele é usado para liberar recursos alocados pelo objeto.

#### Características:
1. **Começa com `~`**: O nome é precedido por um til (`~`).
2. **Sem argumentos ou tipo de retorno**: Não pode receber parâmetros e não tem tipo de retorno.
3. **Chamado automaticamente**: É chamado quando o objeto sai do escopo ou é deletado.

No exemplo acima:
```cpp
~Qualquer() {
    getch();  // Aguarda entrada antes de fechar
    endwin(); // Finaliza o ncurses
}
```
O destrutor limpa o ambiente ncurses, garantindo que o terminal volte ao estado normal.

---

## Boas Práticas

1. **Inicialize sempre os membros necessários** no construtor para evitar comportamentos indefinidos.
2. **Use destrutores para liberar recursos** como memória alocada, arquivos abertos ou conexões de rede.
3. **Evite lógica complexa nos construtores e destrutores**, pois eles devem ser rápidos e previsíveis.
4. **Considere o uso de ponteiros inteligentes** para gerenciar recursos de forma automática (ex.: `std::unique_ptr`, `std::shared_ptr`).
5. **Evite exceções nos destrutores**, pois isso pode causar terminação inesperada do programa.

