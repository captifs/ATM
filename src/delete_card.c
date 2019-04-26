#include "atm.h"

void delete_all_history(history *first) {
	history *aux;

	while (first) {
		aux = first;
		first = first->next;
		free(aux->operation);
		free(aux);
	}
}

void delete_card(FILE *fp) {
	char number_card[17];
	card *aux, *aux_del;
	lsc *first;

	NR_CARD--;
	fscanf(fp, "%s", number_card);
	aux = search_previos_card(number_card);
	if (aux) {
		aux_del = aux->next;
		aux->next = aux_del->next;
		delete_all_history(aux_del->history);
		free(aux_del);
	} else {
		first = search_first_card(number_card);
		if (first) {
			aux_del = first->card;
			first->card = aux_del->next;
			delete_all_history(aux_del->history);
			free(aux_del);
		}
	}
}
