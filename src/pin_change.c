#include "atm.h"

int is_pin(char pin[5]) {
	for (int i = 0; i < 4; i++)
		if (pin[i] < '0' || pin[i] > '9')
			return 0;
	return 1;
}

void pin_change(FILE *fp) {
	char card_number[17], pin[255];
	card *crd;

	fscanf(fp, "%s %s", card_number, pin);
	crd = search_card(card_number);
	crd->history = add_history(crd->history);
	if (strlen(pin) == 4 && is_pin(pin)) {
		strcpy(crd->pin, pin);
		strcpy(crd->status, "ACTIVE");
	} else {
		fprintf(FPW, "Invalid PIN\n");
		crd->history->succes = 0;
	}
	crd->history->operation = (char *)malloc(sizeof(char)*(29+strlen(pin)));
	strcpy(crd->history->operation, "pin_change ");
	strcat(crd->history->operation, card_number);
	strcat(crd->history->operation, " ");
	strcat(crd->history->operation, pin);
}
