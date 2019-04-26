#include "atm.h"

card *dublicate(card *old) {
	card *new;

	new = (card *)malloc(sizeof(card));
	strcpy(new->card_number, old->card_number);
	strcpy(new->pin, old->pin);
	strcpy(new->first_pin, old->first_pin);
	strcpy(new->exp_data, old->exp_data);
	strcpy(new->cvv, old->cvv);
	new->balance = old->balance;
	strcpy(new->status, old->status);
	new->block = old->block;
	new->history = old->history;
	new->next = NULL;
	return new;
}

void add_lsc(card *new, int poz) {
	lsc *aux;
	card *crd;
	int i=0;

	if (!LSC) {
		LSC = (lsc *)malloc(sizeof(lsc));
		LSC->card = NULL;
		LSC->next = NULL;
	}
	aux=LSC;
	while (i < poz && aux->next) {
		aux = aux->next;
		i++;
	}
	while(i<poz) {
		aux->next = (lsc *)malloc(sizeof(lsc));
		aux = aux->next;
		aux->card = NULL;
		aux->next = NULL;
		i++;
	}
	if (!aux->card) {
		aux->card = dublicate(new);
	} else {
		crd = aux->card;
		aux->card = dublicate(new);
		aux->card->next = crd;
	}
}

void redimens() {
	lsc *aux, *aux2;
	card *crd, *crd2;

	NR_MAX_CARDURI *= 2;
	aux = LSC;
	LSC = NULL;
	while (aux) {
		crd = aux->card;
		while (crd) {
			add_lsc(crd, suma_card_number(crd->card_number) % NR_MAX_CARDURI);
			crd2 = crd;
			crd = crd->next;
			free(crd2);
		}
		aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
}
