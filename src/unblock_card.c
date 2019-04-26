#include "atm.h"

void unblock_card(FILE *fp) {
	char number_card[17];
	card *crd;

	fscanf(fp, "%s", number_card);
	crd = search_card(number_card);
	if (crd) {
		strcpy(crd->status, "ACTIVE");
		crd->block = 0;
	}
}
