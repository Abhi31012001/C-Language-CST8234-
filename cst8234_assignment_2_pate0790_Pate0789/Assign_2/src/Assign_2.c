/*
 * Title: Assignment 2 - Student Registration System
 * w/ Linked List, Ansi-sytle
 * Course: CST8234 - C Language
 * Term: Summer 2020
 *
 * Team:
 * Student #1: <<< MeetKumar Patel (Pate0790) >>>
 * Student #2: <<< Abhi Patel (Pate0789) >>>
 *
 * Status:
 * 			Requirement #1: {complete}
 * 			Requirement #2: {complete}
 * 			Requirement #3: {complete}
 * 			Requirement #4: {complete}
 *			Requirement #5: {complete}
 *			Requirement #6: {complete}
 * 			Requirement #7: {complete}
 * 			Requirement #8: {complete}
 * 			Requirement #9: {complete}
 * 			Requirement #10: {complete}
 * 			Requirement #11: {complete}
 */

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include <string.h>
//#include "Node.c"

char* getString(char *printString) {
	char *checkstr = malloc(sizeof(char) * 835);
	if (checkstr == NULL) {
		perror("Name has to be less than 20 char \n");
		return NULL;
	}
	printf(printString);
	scanf("%s", checkstr);

	checkstr = realloc(checkstr, sizeof(char) * (strlen(checkstr) + 1));

	return checkstr;
}

int main(int argc, const char *argv[]) {
	//TODO: https://wiki.eclipse.org/CDT/User/FAQ#Eclipse_console_does_not_show_output_on_Windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	/*A poimter to the first element of the list*/
	node_t *head = NULL;

	//Variables
	int num_cha = 123, num_stud = 6, loopf1, loopl1, loopf2, loopf3, loopl3,
			loopl2;
	student_t students[num_stud];
	char num_char[num_cha];

	printf("First, you will enter 3 students names that will be added to start of the list\n");
	for (loopf1 = 0; loopf1 < 3; loopf1++) {
		sprintf(num_char, "Please enter first name for student %d: ",
				(loopf1 + 1));
		students[loopf1].first_N = getString(num_char);

		sprintf(num_char, "Please enter Last name of student %d: ",
				(loopf1 + 1));
		students[loopf1].last_N = getString(num_char);
		addToStart(&head, &students[loopf1]);

	}
	printList(head);
	printf("Then, you will enter 3 students names that will be added to the end of the list \n");
	for (loopl1 = 0; loopl1 < 3; loopl1++) {
		sprintf(num_char, "Please enter first name for student %d: ",
				(loopl1 + 1));
		students[loopl1 + 3].first_N = getString(num_char);

		sprintf(num_char, "Please enter Last name of student %d: ",
				(loopl1 + 1));
		students[loopl1 + 3].last_N = getString(num_char);
		addToEnd(&head, &students[loopl1 + 3]);
	}
	printList(head);

	printf("Then, you will remove the first 3 students in the list\n");
	for (loopf2 = 0; loopf2 < 3; loopf2++) {
		removeFromStart(&head);

	}
	printList(head);
	printf("Then, you will remove the last 3 students in the list\n");
	for (loopl2 = 0; loopl2 < 3; loopl2++) {
		removeLast(&head);

	}
	printList(head);
	printf("By now, your list should be empty, so you will enter 3 more students\n");
	for (loopf3 = 0; loopf3 < 3; loopf3++) {
		sprintf(num_char, "Please enter first name for student %d: ",
				(loopf3 + 1));
		students[loopf3].first_N = getString(num_char);
		sprintf(num_char, "Please enter last name for student %d: ",
				(loopf3 + 1));
		students[loopf3].last_N = getString(num_char);
		addToEnd(&head, &students[loopf3]);

	}
	printList(head);
	printf("Finally, you will delete the second student in the list only\n");
	removeByIndex(&head, 2);
	printList(head);
	for (loopl3 = 0; loopl3 < 6; loopl3++) {
		free(students[loopl3].first_N);
		free(students[loopl3].last_N);

	}
	removeFromStart(&head);
	removeFromStart(&head);
	printf("Program ended with exit code: 0");
	return EXIT_SUCCESS;

}

