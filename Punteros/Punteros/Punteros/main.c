#include <stdio.h>
#include <stdlib.h>

void procesa_saldo(float *p)
{
	if (*p > 100)
		*p = *p + 50;
	else
		*p = *p + 5;
}

int main() {
	float saldo = 124;
	float *p;
	float *q;

	p = &saldo;
	procesa_saldo(p);
	q = (float*)malloc(sizeof(float));
	*q = *p;

	if (saldo > 150)
		saldo = saldo * 1.2;
	printf("%f %f %f", saldo, *p, *q);

	return 0;
}