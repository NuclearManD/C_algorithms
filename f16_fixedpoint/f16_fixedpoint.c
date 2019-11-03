/*
	Unoptimized source for f16_fixedpoint.S (which is optimized)
*/

int mul_fp(int a, int b){
	long val = a;
	val *= b;
	return val >> 16;
}

int div_fp(int a, int b){
	long val = a;
	return (val << 16) / b;
}