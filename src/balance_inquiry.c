#include "atm.h"

void balance_inquiry(FILE *fp) {
	char card_number[17];
	card *crd;

	fscanf(fp, "%s", card_number);
	crd = search_card(card_number);
	if (crd) {
		fprintf(FPW, "%d\n", crd->balance);
		crd->history = add_history(crd->history);
		crd->history->operation = (char *)malloc(sizeof(char) * 33);
		strcpy(crd->history->operation, "balance_inquiry ");
		strcat(crd->history->operation, card_number);
	}
}
