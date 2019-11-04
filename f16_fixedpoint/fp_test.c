#include "f16_fixedpoint.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

long long current_timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void ptest(float a, float b){
	printf("%f -> %i\n", a, FLOAT_TO_FP(a));
	printf("%f -> %i\n", b, FLOAT_TO_FP(b));
	printf("e^%f = %f\n", a, FP_TO_FLOAT(e_x_fp(FLOAT_TO_FP(a))));
	printf("tanh%f = %f\n", a, FP_TO_FLOAT(tanh_fp(FLOAT_TO_FP(a))));
	printf("%f / %f = %f\n", a, b, FP_TO_FLOAT(div_fp(FLOAT_TO_FP(a), FLOAT_TO_FP(b))));
	printf("%f * %f = %f\n", a, b, FP_TO_FLOAT(mul_fp(FLOAT_TO_FP(a), FLOAT_TO_FP(b))));
	printf("%f + %f = %f\n", a, b, FP_TO_FLOAT(FLOAT_TO_FP(a) + FLOAT_TO_FP(b)));
	printf("%f - %f = %f\n\n", a, b, FP_TO_FLOAT(FLOAT_TO_FP(a) - FLOAT_TO_FP(b)));
}

float float_arr[8192];
int f16_arr[8192];

void f16_randop(int n){
	int o = 0;
	for (int i = 0; i < n; i++)
		o += tanh_fp(f16_arr[i % 8192]);
	printf("%i tanh_fp calls >%f\n", n, FP_TO_FLOAT(o));
}

void float_randop(int n){
	float o = 0;
	for (int i = 0; i < n; i++)
		o += tanh(float_arr[i % 8192]);
	printf("%i tanh calls >%f\n", n, o);
}

int main(void){
	long long timer;

	srand(time(NULL));
	for (int i = 0; i < 8192; i++)
		float_arr[i] = FP_TO_FLOAT(f16_arr[i] = (rand()%1441792) - 720896);

	ptest(-3.14159f, 1);
	ptest(-11, 1);
	ptest(1, 1);
	ptest(805, 21);
	ptest(31, 0.012f);//*/
	printf("%i\n", (rand()%1441792) - 720896);
	printf("Testing speed of f16...\n");
	timer = -current_timestamp();
	f16_randop(10000000);
	printf("> %lli ms\n", timer + current_timestamp());
	printf("Testing speed of float...\n");
	timer = -current_timestamp();
	float_randop(10000000);
	printf("> %lli ms\n", timer + current_timestamp());
}
