
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
