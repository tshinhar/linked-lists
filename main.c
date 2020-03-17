#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "input_prossesing.h"



#define MAX_LINE_LENGTH	100

int main() {
	char user_input[MAX_LINE_LENGTH];
	int exit_flag = 0;
	Node* head = NULL;
	while (exit_flag != 1) {
		fgets(user_input, MAX_LINE_LENGTH, stdin);
		exit_flag = prosses_input(user_input, &head);
	}
	return 0;
}