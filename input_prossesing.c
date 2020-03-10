#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

int prosses_input(char* user_input, Node* head) {
	if (strcmp(user_input, "print") == 0) {
		print_list(head);
		return 0;
	}
	char* command = strtok(user_input, " ");
	char* first_node_value = strtok(NULL, " ");
	char* second_node_value = strtok(NULL, " ");
	if (strcmp(command, "add_start") == 0) {
		Node* new_node = create_new_node(atoi(first_node_value));
		head = add_to_list_start(head, new_node);
		return 0;
	}
	if (strcmp(command, "add_end") == 0) {
		Node* new_node = create_new_node(atoi(first_node_value));
		head = add_to_list_end(head, new_node);
		return 0;
	}
	if (strcmp(command, "add_after") == 0) {
		Node* new_node = create_new_node(atoi(first_node_value));
		head = add_after_specific_node(head, atoi(second_node_value), new_node);
		return 0;
	}
	if (strcmp(command, "index") == 0) {
		print_node_index(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "del") == 0) {
		head = delete_by_index(head, atoi(first_node_value));
		return 0;
	}
	if (strcmp(command, "exit") == 0) {
		return 1;
	}
}
#endif