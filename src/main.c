#include "atm.h"

int main() {
	LSC = NULL;
	NR_CARD = 0;
	FPW = fopen("output.out", "w");
	citire();
	fclose(FPW);
	return (0);
}
