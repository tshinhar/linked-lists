#include "List.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void str_to_lower(char* str) {
	int i = 0;
	for (; i < (int)strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}

int prosses_input(char* user_input, Node** head_pointer) {
	Node* head = *head_pointer;
	str_to_lower(user_input);
	char* command = strtok(user_input, " \n");
	char* first_node_value = strtok(NULL, " \n");
	char* second_node_value = strtok(NULL, " \n");
	if (strcmp(command, "add_start") == 0) {
		*head_pointer = add_to_list_start(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "add_end") == 0) {
		*head_pointer = add_to_list_end(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "add_after") == 0) {
		*head_pointer = add_after_specific_node(head, atoi(second_node_value), atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "index") == 0) {
		print_node_at_index(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "del") == 0) {
		*head_pointer = delete_by_index(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "print") == 0) {
		print_list(head);
		return 0;
	}
	if (strcmp(command, "exit") == 0) {
		return 1;
	}
	return 0;
}