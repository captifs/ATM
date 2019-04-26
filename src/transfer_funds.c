#include "atm.h"

void transfer_funds(FILE *fp) {
	card *sour;
	card *dest;
	char number[17];
	char suma[20];

	fscanf(fp, "%s", number);
	sour = search_card(number);
	fscanf(fp, "%s %s", number, suma);
	dest = search_card(number);
	if (sour && dest) {
		sour->history = add_history(sour->history);
		if (suma[strlen(suma)-1] == '0') {
			if (atoi(suma) > sour->balance) {
				sour->history->succes = 0;
				fprintf(FPW, "Insufficient funds\n");
			} else {
				sour->balance -= atoi(suma);
				dest->balance += atoi(suma);
				fprintf(FPW, "%d\n", sour->balance);
			}
		} else {
			sour->history->succes = 0;
			fprintf(FPW, "The transferred amount must be multiple of 10\n");
		}
		sour->history->operation = (char *)malloc(50+strlen(suma));
		strcpy(sour->history->operation, "transfer_funds ");
		strcat(sour->history->operation, sour->card_number);
		strcat(sour->history->operation, " ");
		strcat(sour->history->operation, dest->card_number);
		strcat(sour->history->operation, " ");
		strcat(sour->history->operation, suma);
		if (sour->history->succes) {
			dest->history = add_history(dest->history);
			dest->history->operation =
					(char *)malloc(strlen(sour->history->operation) + 1);
			strcpy(dest->history->operation, sour->history->operation);
		}
	}
}
