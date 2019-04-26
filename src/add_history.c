#include "atm.h"

history *delete_history(history *first, char *oper) {
	history *second, *del;

	if (!strcmp(first->operation, oper) && first->succes == 1) {
		second = first->next;
		free(first->operation);
		free(first);
		return second;
	} else {
		second = first;
		while (second->next) {
			if (!strcmp(second->next->operation, oper) && second->succes==1) {
				del = second->next;
				second->next = del->next;
				free(del->operation);
				free(del);
				return first;
			}
			second = second->next;
		}
	}
	return NULL;
}

history *add_history(history *first) {
	history *nw;

	nw = (history *)malloc(sizeof(history));
	nw->next = first;
	nw->succes = 1;
	nw->operation = NULL;
	return (nw);
}
