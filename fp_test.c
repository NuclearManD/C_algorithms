#include "emuarch_fixedpoint.h"
#include <stdio.h>

void ptest(float a, float b){
	printf("%f -> %i\n", a, FLOAT_TO_FP(a));
	printf("%f -> %i\n", b, FLOAT_TO_FP(b));
	printf("%f / %f = %f\n", a, b, FP_TO_FLOAT(div_fp(FLOAT_TO_FP(a), FLOAT_TO_FP(b))));
	printf("%f * %f = %f\n", a, b, FP_TO_FLOAT(mul_fp(FLOAT_TO_FP(a), FLOAT_TO_FP(b))));
	printf("%f + %f = %f\n", a, b, FP_TO_FLOAT(FLOAT_TO_FP(a) + FLOAT_TO_FP(b)));
	printf("%f - %f = %f\n\n", a, b, FP_TO_FLOAT(FLOAT_TO_FP(a) - FLOAT_TO_FP(b)));
}

int main(void){
	ptest(3.14159f, 1);
	ptest(805, 21);
	ptest(31, 0.012f);
}
