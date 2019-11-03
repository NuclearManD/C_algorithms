gcc -c fp_test.c -o fp_test.o -Wall -Wextra -Werror -O3
as emuarch_fixedpoint.S -o emuarch_fixedpoint.o
gcc fp_test.o emuarch_fixedpoint.o -o fp_test