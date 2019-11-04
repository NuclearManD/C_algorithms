gcc -c fp_test.c -o fp_test.o -Wall -Wextra -Werror -O3
gcc -c f16_math.c -O3 -o f16_math.o
as f16_fixedpoint.S -o f16_fixedpoint.o
gcc fp_test.o f16_fixedpoint.o f16_math.o -O3 -o fp_test