
# Move Semantics e Rvalue References

Move Semantics e Rvalue References são recursos avançados do C++ que permitem a otimização do desempenho e a transferência de recursos ao invés de sua cópia.

---

## Código de Exemplo

```cpp
#include <iostream>
#include <vector>
#include <string>

class Resource {
public:
    Resource(const std::string& name) : name(name) {
        std::cout << "Recurso alocado: " << name << std::endl;
    }

    ~Resource() {
        std::cout << "Recurso liberado: " << name << std::endl;
    }

    Resource(const Resource&) = delete;
    Resource& operator=(const Resource&) = delete;

    Resource(Resource&& other) noexcept : name(std::move(other.name)) {
        std::cout << "Recurso movido: " << name << std::endl;
    }

    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            std::cout << "Recurso atribuído via move: " << name << std::endl;
        }
        return *this;
    }

private:
    std::string name;
};

Resource createResource(const std::string& name) {
    return Resource(name);
}

int main() {
    std::cout << "Criando recurso r1:" << std::endl;
    Resource r1 = createResource("Recurso1");

    std::cout << "\nCriando recurso r2 e movendo r1 para r2:" << std::endl;
    Resource r2 = std::move(r1);

    std::cout << "\nEncerrando o programa." << std::endl;

    return 0;
}
```

---

## Explicação do Código

1. **Classe `Resource`:**
   - Proíbe a cópia (constructores e operadores de atribuição estão deletados).
   - Permite movimentação (com `std::move` no construtor e operador de atribuição).

2. **Função `createResource`:**
   - Cria e retorna uma instância temporária da classe `Resource`.

3. **Uso de `std::move`:**
   - Move a instância `r1` para `r2`, evitando a cópia.

---

## Benefícios do Move Semantics

1. **Desempenho:**
   - Reduz cópias desnecessárias de grandes objetos.
   
2. **Reaproveitamento de Recursos:**
   - Permite transferir recursos como memória alocada entre objetos.

3. **Eficiente:**
   - Essencial para trabalhar com classes que gerenciam recursos como arquivos e memória.

---

## Boas Práticas

1. **Implemente construtores de movimento para classes que gerenciam recursos.**
2. **Combine o uso de `std::move` e semânticas de movimento para evitar cópias desnecessárias.**
3. **Sempre use `noexcept` em construtores e operadores de movimento.**
4. **Evite usar objetos movidos após um movimento.**
