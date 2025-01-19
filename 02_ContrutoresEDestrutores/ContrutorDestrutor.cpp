#include <iostream>
#include <ncurses.h>
using namespace std;

class Qualquer{
    public:
        Qualquer (){
            initscr();
        }

        void funcao1(){
            printw("funcao 1");
            refresh();
        }

        void funcao2(){
            move(3,20)
            printw("funcao 2");
            
        }

        ~Qualquer(){ 
        getch();
        endwin();
        }
};

int main(){
    Qualquer q;

    q.funcao1();
    q.funcao2();

    return 0;
}
