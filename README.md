# Push Swap

## Allowed external functions

- read
- write
- malloc
- free
- exit
- ft_printf

## Todo List

[x] Parse program argv input
[] Normalize input arguments
[] Handle errors:
    [] Only accept numeric inputs

[] Fill one of the stacks with args (you can use linked list, double linked list or array)
[] Implement stack operations:
    []

[] Print stack movements in the terminal

## Links e Referências

- [Arcticle push swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Push Swap tester](https://github.com/laisarena/push_swap_tester)
- [Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [aroque's project](https://github.com/AdrianWR/push_swap)

## Algoritmo normalização

- Menor número da pilha -> 0
Condições:
- Alcance: -2147483648 <= x < 2147483647

### Como opera

O menor número recebe 0 e o maior número recebe (n - 1) sendo n o número de argumentos inseridos. Os números do intervalo recebem i.

Somatorio de i=0 até n - 1: 0, 1, 2, ..., n - 1

### Exemplo

input: 1 2 3
n = 3
normalizador -> input -> output

output: 0, ..., 2
