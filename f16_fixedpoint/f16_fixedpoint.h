#ifndef EMUARCH_FIXEDPOINT_H
# define EMUARCH_FIXEDPOINT_H
# define FP_TO_FLOAT(x) (x)/65536.0f
# define FLOAT_TO_FP(x) (int)((x)*65536)

int mul_fp(int a, int b);
int div_fp(int a, int b);

#endif
