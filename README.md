# Push Swap

This project is about sorting a stack by using a limited number of movements that swap elements between stacks.

## The Program

The main objective of the push_swap is to print to the standard otuput the instructions required to sort the stack to the left, which must be given as the program's argument. Each instruction must be followed by a line break. The stack A must be sorted from its lowest element at the top, while stack to the right must be empty.

### Movements

- sa : swap a - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- sb : swap b - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do - nothing if B is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- ra : rotate a - shift up all elements of stack A by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack B by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

### Allowed external functions

- read
- write
- malloc
- free
- exit
- ft_printf

## How to run

### Prerequisites

Install libperl

#### Ubuntu

```sh
sudo apt install -y libipc-run3-perl
```

#### Fedora

```sh
sudo dnf install -y perl-IPC-Run3
```

### Compilation

Compile the program with:

```sh
make
```

### Execution

Execute the program with:

```bash
$ARG="1 5 3 2 4 7 8 6"; ./push_swap $ARG
```

## Testing the program

You can check the program execution using two methods

### Raw test runner

You can execute the test runner with:

```sh
perl runner.pl 100
perl runner.pl 100 --checker
perl runner.pl 100 --count
```

### Graphical test runner

Execute:

```sh
ARG="1 3 2 4"; python3 pyviz.py $ARG
```

Alternatively mock data can be used to test the program.

```sh
python3 pyviz.py `perl -e "use List::Util 'shuffle'; print join(' ', shuffle(0..(100 - 1)))"`
```

## Links and References

- [Arcticle push swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Push Swap tester](https://github.com/laisarena/push_swap_tester)
- [Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [aroque's project](https://github.com/AdrianWR/push_swap)
