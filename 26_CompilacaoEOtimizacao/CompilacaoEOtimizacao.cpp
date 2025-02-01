#include <iostream>

inline int soma(int a, int b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    std::cout << "Soma: " << soma(x, y) << std::endl;
    return 0;
}
