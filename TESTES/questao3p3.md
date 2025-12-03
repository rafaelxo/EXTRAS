Implemente o método boolean buscarVeiculo(Veiculo veiculo) para pesquisar veículos em uma estrutura composta por três níveis T1, T2 e T3.

T1 é a tabela hash principal (tamanho tam1). O índice de inserção é obtido por: int hashT1(String placa) - método da própria classe para obter o índice inicial T1 (já implementado). int rehashT1(String placa) para resolver colisões (ambos já implementados).

Se não houver colisão, o ve´culo é armazenado diretamente em T1. Caso contrário: Se o tipo for "carro", redireciona para T2. Se o tipo for "moto", redireciona para T3.

T2 (carros): tabela hash que usa hashT2(String chassi) (também já implementado). Cada posição contém uma árvore binária de busca, em que cada nó representa o primerio caractere da placa. Cada nó possui: Ponteiros esq e dir para os filhos; Ponteiros inicio e fim de uma lista encadeada de veículos com mesma letra inicial. Essa lista possui célula cabeça e os veículos são inseridos ao final.

T3 (motos): tabela hash que usa: int hashT3(String chassi) para obter o índice inicial. Caso não seja possível inserir diretamente, os veículos são armazenados em uma lista encadeade ordenada por placa, sem célula cabeça.
