#include "atm.h"
void cash_withdrawal(FILE *fp) {
	char card_number[17];
	char suma[20];
	card *crd;

	fscanf(fp, "%s %s", card_number, suma);
	crd = search_card(card_number);
	if (crd) {
		crd->history = add_history(crd->history);
		if (suma[strlen(suma)-1] == '0') {
			if (atoi(suma) > crd->balance) {
				crd->history->succes = 0;
				fprintf(FPW, "Insufficient funds\n");
			} else {
				crd->balance -= atoi(suma);
				fprintf(FPW, "%d\n", crd->balance);
			}
		} else {
			fprintf(FPW, "The requested amount must be multiple of 10\n");
			crd->history->succes = 0;
		}
		crd->history->operation = (char *)malloc(34+strlen(suma));
		strcpy(crd->history->operation, "cash_withdrawal ");
		strcat(crd->history->operation, card_number);
		strcat(crd->history->operation, " ");
		strcat(crd->history->operation, suma);
	}
}
