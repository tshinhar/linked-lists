#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"
#include "input_prossesing.h"



#define MAX_LINE_LENGTH	100

int main() {
	char user_input[MAX_LINE_LENGTH];
	scanf("%s", user_input);
	for (int i = 0; i < strlen(user_input); i++) {
		user_input[i] = tolower(user_input[i]);
	}
	int exit_flag = 0;
	Node* head = NULL;
	while (exit_flag != 1) {
		exit_flag = prosses_input(user_input, head);
		scanf("%s", user_input);
		for (int i = 0; i < strlen(user_input); i++) {
			user_input[i] = tolower(user_input[i]);
		}
	}
}
#endif