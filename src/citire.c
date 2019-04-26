#include "atm.h"

void citire() {
	FILE	*fp;
	char	buff[255];

	fp = fopen("input.in", "r");
	fscanf(fp, "%s", buff);
	NR_MAX_CARDURI = atoi(buff);
	while (fscanf(fp, "%s", buff) == 1) {
		if (!strcmp(buff, "add_card"))
			init_card(fp); 
		else if (!strcmp(buff, "delete_card"))
			delete_card(fp);
		else if (!strcmp(buff, "show")) {
			if ((char)fgetc(fp) == '\n')
				afisare();
			else {
				fscanf(fp, "%s", buff);
				afisare_card(buff);
			}
		} else if (!strcmp(buff, "insert_card"))
			insert_card(fp);
		else if (!strcmp(buff, "cancel"))
			cancel(fp);
		else if (!strcmp(buff, "unblock_card"))
			unblock_card(fp);
		else if (!strcmp(buff, "pin_change"))
			pin_change(fp);
		else if (!strcmp(buff, "balance_inquiry"))
			balance_inquiry(fp);
		else if (!strcmp(buff, "recharge"))
			recharge(fp);
		else if (!strcmp(buff, "cash_withdrawal"))
			cash_withdrawal(fp);
		else if (!strcmp(buff, "transfer_funds"))
			transfer_funds(fp);
		else if (!strcmp(buff, "reverse_transaction"))
			reverse_transaction(fp);
	}
	fclose(fp);
}
