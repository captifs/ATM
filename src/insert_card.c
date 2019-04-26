#include "atm.h"

void insert_card(FILE *fp) {
	char number[17];
	char pin[255];
	card *crd;

	fscanf(fp, "%s", number);
	crd = search_card(number);
	if (crd) {
		fscanf(fp, "%s", pin);
		crd->history = add_history(crd->history);
		if (crd->block > 2) {
			fprintf(FPW,
				"The card is blocked. Please contact the administrator.\n");
			crd->history->succes = 0;
		} else if (strcmp(crd->pin, pin)) {
			fprintf(FPW, "Invalid PIN\n");
			crd->history->succes = 0;
			if (++crd->block > 2) {
				fprintf(FPW,
					"The card is blocked. Please contact the administrator.\n");
				strcpy(crd->status, "LOCKED");
			}
		} else if (!strcmp(crd->pin, crd->first_pin) &&
					strcmp(crd->status, "ACTIVE"))
			fprintf(FPW, "You must change your PIN.\n");

		if (crd->history->succes)
			crd->block = 0;
		crd->history->operation = (char *)malloc(30 + strlen(pin));
		strcpy(crd->history->operation, "insert_card ");
		strcat(crd->history->operation, number);
		strcat(crd->history->operation, " ");
		strcat(crd->history->operation, pin);
	}
}
