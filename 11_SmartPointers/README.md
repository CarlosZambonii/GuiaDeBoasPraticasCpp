
## Smart Pointers Explicados

Os smart pointers são classes da biblioteca padrão (`std::unique_ptr`, `std::shared_ptr`, e `std::weak_ptr`) que encapsulam ponteiros brutos e gerenciam automaticamente o ciclo de vida do objeto apontado.

### Tipos de Smart Pointers

1. **unique_ptr**:
   - Gerencia um único recurso.
   - A transferência de propriedade é possível usando `std::move`.
   - Exemplo:
     ```cpp
     unique_ptr<Recurso> recurso = make_unique<Recurso>("Recurso Único");
     recurso->exibir();
     ```

2. **shared_ptr**:
   - Permite várias referências ao mesmo recurso.
   - O recurso é desalocado quando a última referência é destruída.
   - Exemplo:
     ```cpp
     shared_ptr<Recurso> recursoCompartilhado = make_shared<Recurso>("Recurso Compartilhado");
     cout << recursoCompartilhado.use_count();
     ```

3. **weak_ptr**:
   - Aponta para um recurso gerenciado por `shared_ptr`, mas não aumenta sua contagem de referência.
   - Útil para evitar ciclos de referência.
   - Exemplo:
     ```cpp
     weak_ptr<Recurso> recursoFraco = recursoCompartilhado;
     if (auto recurso = recursoFraco.lock()) {
         recurso->exibir();
     }
     ```

## Benefícios dos Smart Pointers

- **Evita vazamentos de memória**: Recursos são automaticamente desalocados.
- **Segurança**: Previne o uso de ponteiros nulos ou inválidos.
- **Flexibilidade**: Facilita a passagem de objetos entre funções ou classes.

## Saída Esperada

```plaintext
=== Usando unique_ptr ===
Recurso Recurso Único alocado.
Usando recurso: Recurso Único
Recurso Recurso Único desalocado.

=== Usando shared_ptr ===
Recurso Recurso Compartilhado alocado.
Contagem de referências: 2
Contagem de referências após sair do escopo interno: 1
Recurso Recurso Compartilhado desalocado.

=== Usando weak_ptr ===
Recurso Recurso Principal alocado.
Usando recurso: Recurso Principal
Recurso ainda existe? 1
Recurso ainda existe após reset? 0
Recurso Recurso Principal desalocado.
```

## Dicas de Boas Práticas

- Use `unique_ptr` quando o recurso pertence a apenas uma entidade.
- Prefira `make_unique` e `make_shared` para criar smart pointers, pois eles são mais seguros e eficientes.
- Evite usar `shared_ptr` desnecessariamente, pois ele tem maior overhead.
- Utilize `weak_ptr` para evitar ciclos de referência entre `shared_ptr`.

