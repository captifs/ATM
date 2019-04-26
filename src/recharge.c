#include "atm.h"

void recharge(FILE *fp) {
	char card_number[17];
	char suma[20];
	card *crd;

	fscanf(fp, "%s %s", card_number, suma);
	crd = search_card(card_number);
	if (crd) {
		crd->history = add_history(crd->history);
		if (suma[strlen(suma)-1] == '0') {
			crd->balance += atoi(suma);
			fprintf(FPW, "%d\n", crd->balance);
		} else {
			fprintf(FPW, "The added amount must be multiple of 10\n");
			crd->history->succes = 0;
		}
		crd->history->operation = (char *)malloc(27+strlen(suma));
		strcpy(crd->history->operation, "recharge ");
		strcat(crd->history->operation, card_number);
		strcat(crd->history->operation, " ");
		strcat(crd->history->operation, suma);
	}
}
