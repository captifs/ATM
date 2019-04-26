#include "atm.h"

card *search_previos_card(char number[17]) {
	int poz = suma_card_number(number) % NR_MAX_CARDURI;
	card *card_aux;
	lsc *lsc_aux = LSC;

	while (poz-- && lsc_aux)
		lsc_aux = lsc_aux->next;
	if (!lsc_aux || !lsc_aux->card)
		return (NULL);
	card_aux = lsc_aux->card;
	while (card_aux->next && strcmp(card_aux->next->card_number, number))
		card_aux = card_aux->next;
	if (card_aux->next)
		return (card_aux);
	return NULL;
}

lsc *search_first_card(char number[17]) {
	lsc *lsc_aux = LSC;

	while (lsc_aux) {
		if (lsc_aux->card && !strcmp(lsc_aux->card->card_number, number))
			return lsc_aux;
		lsc_aux = lsc_aux->next;
	}
	return NULL;
}

card *search_card(char number[17]) {
	int poz = suma_card_number(number) % NR_MAX_CARDURI;
	card *card_aux;
	lsc *lsc_aux = LSC;

	while (poz-- && lsc_aux)
		lsc_aux = lsc_aux->next;
	if (!lsc_aux)
		return (NULL);
	card_aux = lsc_aux->card;
	while (card_aux && strcmp(card_aux->card_number, number))
		card_aux = card_aux->next;
	return (card_aux);
}
