#include "atm.h"

void cancel(FILE *fp) {
	char number[17];
	card *crd;

	fscanf(fp, "%s", number);
	crd = search_card(number);
	if (crd) {
		crd->history = add_history(crd->history);
		crd->history->operation = (char *)malloc(sizeof(char)*24);
		strcpy(crd->history->operation, "cancel ");
		strcat(crd->history->operation, number);
	}
}
