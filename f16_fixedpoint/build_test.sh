gcc -c fp_test.c -o fp_test.o -Wall -Wextra -Werror -O3
as f16_fixedpoint.S -o f16_fixedpoint.o
gcc fp_test.o f16_fixedpoint.o -o fp_test