#include "atm.h"

void reverse_transaction(FILE *fp) {
	card *sour;
	card *dest;
	char number[17];
	char suma[20];
	char *oper;

	fscanf(fp, "%s", number);
	sour = search_card(number);
	fscanf(fp, "%s %s", number, suma);
	dest = search_card(number);
	if (sour && dest) {
		if (dest->balance < atoi(suma)) {
			fprintf(FPW, "The transaction cannot be reversed\n");
		} else {
			sour->balance += atoi(suma);
			dest->balance -= atoi(suma);
			oper = (char *)malloc(50+strlen(suma));
			strcpy(oper, "transfer_funds ");
			strcat(oper, sour->card_number);
			strcat(oper, " ");
			strcat(oper, dest->card_number);
			strcat(oper, " ");
			strcat(oper, suma);
			dest->history = delete_history(dest->history, oper);
			free(oper);
			sour->history = add_history(sour->history);
			sour->history->operation = (char *)malloc(55+strlen(suma));
			strcpy(sour->history->operation, "reverse_transaction ");
			strcat(sour->history->operation, sour->card_number);
			strcat(sour->history->operation, " ");
			strcat(sour->history->operation, dest->card_number);
			strcat(sour->history->operation, " ");
			strcat(sour->history->operation, suma);
		}
	}
}
