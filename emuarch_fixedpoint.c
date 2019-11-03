int mul_fp(int a, int b){
	long val = a;
	val *= b;
	return val >> 16;
}

int div_fp(int a, int b){
	long val = a << 16;
	return val / b;
}