/*
 ============================================================================
 Name 		 : Lab05.c
 Author		 : Abhi Patel (pate0789)
 Version 	 : Lab 5
 Description : File I/O in C, Ansi-style
 Status		 :

 	 	 	 Builds clean; no warning(s) 						: << true >>
 	 	 	 Requirement #1 - FileRead.txt in src/ 				: << complete >>
 	 	 	 Requirement #2 - Open FileRead.txt read (only)	    : << complete >>
 	 	 	 Requirement #3 - Open FileOut.txt write (only)	    : << complete >>
 	 	 	 Requirement #4 - Check file open for success 		: << complete >>
 	 	 	 Requirement #5 - Process FileRead.txt word-by-word : << complete >>
 	 	 	 Requirement #6 - Display total words and chars     : << complete >>

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, const char * argv[]) {

	//TODO: https://wiki.eclipse.org/CDT/User/FAQ#Eclipse_console_does_not_show_output_on_Windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int number_words = 0, number_chars = 0;
	char count[123];

	FILE *fileRead;
	fileRead = fopen("FileRead.txt", "r");
	FILE *fileOut;
	fileOut = fopen("FileOut.txt", "w");

	if (fileOut == NULL) {
		printf("Unable to open fileOut.txt\n");
		exit(EXIT_FAILURE);
	}
	if (fileRead == NULL) {
		printf("Unable to open fileRead.txt\n");
		exit(EXIT_FAILURE);
	} else {
		//do{
		while (fscanf(fileRead, "%s", count) != EOF) {
			printf("\nThe word I read from file_Read.txt -> %s ", count);
			fprintf(fileOut, "\nThe word I read from file_Read.txt -> %s ",
					count);

			number_words = number_words + 1;
			number_chars = number_chars + strlen(count);

		}
	//}while (fscanf(fileRead, "%s", count) != EOF);
		printf("\n\nTotal number of words in file			     : %d", number_words);
		printf("\nTotal number of characters in file (sans white-space): %d",
				number_chars);
	}
	return 0;
}
