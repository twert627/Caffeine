/* Caffeine is a direct superset of Ansi C [C89] */
/* Supports Ansi C comments */
/* And C++ comments */

#include <caffeine_std_io.h>;

#include "stdio.h";

int main(int argc, char **argv) {
  log("Calling C code...\n");
  c_loop(10);
  return 0;
}

int i, j;
void c_loop(i) {
  for (j = 0; j <= i; j++) {
    printf("%d\n", i);
  }
}