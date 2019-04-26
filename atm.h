#ifndef ATM_H
# define ATM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_history {
	int		succes;
	char	*operation;
	struct s_history	*next;
} history;

typedef struct s_card {
	char	card_number[17];
	char	pin[5];
	char	first_pin[5]; // pinul initial
	char	exp_data[6];
	char	cvv[4];
	int		balance;
	char	status[7];
	int		block; // if is blocked (3)
	history *history;
	struct s_card	*next;
} card;

typedef struct s_lsc {
	card	*card;
	struct s_lsc	*next;
} lsc;

int NR_MAX_CARDURI;
int NR_CARD;
lsc *LSC;
FILE *FPW;

// citire.c
void citire();

// afisare.c
void afisare();
void afisare_card(char nr[17]);

// search_card.c
card *search_previos_card(char number[17]);
lsc *search_first_card(char number[17]);
card *search_card(char number[17]);

//add_card.c
int suma_card_number(char *nr);
void init_card(FILE *fp);

// add_history.c
history *add_history(history *first);
history *delete_history(history *first, char *oper);

// delete_card.c
void delete_card(FILE *fp);
void delete_all_history(history *first);

// insert_card.c
void insert_card(FILE *fp);

// cancel.c
void cancel(FILE *fp);

// unblock_card.c
void unblock_card(FILE *fp);

// pin_change.c
void pin_change(FILE *fp);

// balance_inquiry.c
void balance_inquiry(FILE *fp);

// recharge.c
void recharge(FILE *fp);

// cash_withdrawal.c
void cash_withdrawal(FILE *fl);

// transfer_funds.c
void transfer_funds(FILE *fp);

// reverse_transaction.c
void reverse_transaction(FILE *fp);

// redimens.c
void redimens();

#endif
