#include "../includes/my_putchar.h" // ma lib

void my_putchar(char c) {
  write(1, &c, 1);
}