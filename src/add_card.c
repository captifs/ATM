#include "atm.h"

int suma_card_number(char *nr) {
	int sum=0, i=0;

	while (nr[i]) {
		sum += ((int)nr[i]-'0');
		i++;
	}
	return sum;
}

int exist_card(char number_card[17]) {
	lsc *aux;
	card *list;
	int poz = suma_card_number(number_card) % NR_MAX_CARDURI;
	int i=0;

	if (!LSC)
		return 0;
	aux = LSC;
	while (i < poz && aux->next) {
		aux = aux->next;
		i++;
	}
	if (i != poz)
	while(i<poz) {
		aux->next = (lsc *)malloc(sizeof(lsc));
		aux = aux->next;
		aux->card = NULL;
		aux->next = NULL;
		i++;
	}
	list = aux->card;
	while (list) {
		if (!strcmp(list->card_number, number_card))
			return (1);
		list = list->next;
	}
	return (0);
}

card *add_card(int poz) {
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
	if (i != poz)
	while(i<poz) {
		aux->next = (lsc *)malloc(sizeof(lsc));
		aux = aux->next;
		aux->card = NULL;
		aux->next = NULL;
		i++;
	}
	if (!aux->card) {
		aux->card = (card *)malloc(sizeof(card));
		aux->card->next = NULL;
	} else {
		crd = aux->card;
		aux->card = (card *)malloc(sizeof(card));
		aux->card->next = crd;
	}
	return (aux->card);
}

void init_card(FILE *fp) {
	char number_card[17], pin[5], exp_data[6], cvv[4];
	int poz;
	card *card;

	fscanf(fp, "%s", number_card);
	fscanf(fp, "%s", pin);
	fscanf(fp, "%s", exp_data);
	fscanf(fp, "%s", cvv);
	if (exist_card(number_card)) {
		fprintf(FPW, "The card already exists\n");
		return ;
	}
	if (NR_CARD >= NR_MAX_CARDURI)
		redimens();
	NR_CARD++;
	poz = suma_card_number(number_card) % NR_MAX_CARDURI;
	card = add_card(poz);
	strcpy(card->card_number, number_card);
	strcpy(card->pin, pin);
	strcpy(card->first_pin, pin);
	strcpy(card->exp_data, exp_data);
	strcpy(card->cvv, cvv);
	card->balance = 0;
	strcpy(card->status, "NEW");
	card->block = 0;
	card->history = NULL;
}
