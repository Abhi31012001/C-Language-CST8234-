/*
 ============================================================================
 Name        : Lab4.c
 Author      : Abhi Patel (pate0789)
 date		 : July 13, 2020

 Version     : Lab 4
 Copyright   : Your copyright notice
 Description : Structs in C, Ansi-style
 Status	     :
 Builds clean; no warning
 Requirement #1 - struct Student					: << true >>
 Requirement #2 - struct Course						: << complete >>
 Requirement #3 - typedef Course struct				: << complete >>
 Requirement #4 - Prompt for number of students		: << complete >>
 Requirement #5 - Prompt for student information 	: << complete >>
 Requirement #6 - Prompt for course information 	: << complete >>
 Requirement #7 - Display registration 				: << complete >>

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_CODE (7 + 1)

typedef struct {
	char *courseCode;
	char courseName[24];
} Course;

struct Student {
	char fname[19];
	char lname[19];
	int studentId;
	Course *courses;

};

//#define MAX_COURSE_CODE (7 + 1)
int main(void) {

	//TODO: https://wiki.eclipse.org/CDT/User/FAQ#Eclipse_console_does_not_show_output_on_Windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int MAX;
	printf("\nHow many students do you wish to enter =  ");
	scanf("%d", &MAX);
	struct Student arr_student[MAX];
	Course course[MAX];
	int i, length, j;

	for (i = 0; i < MAX; i++) {
		//printf("Enter Student #%d\n", i + 1);

		printf("Enter student #%d First Name: ", i + 1);
		//scanf("%s", arr_student[i].name);

		scanf("%s", arr_student[i].fname);

		printf("Enter student Last Name: ");
		//scanf("%s", arr_student[i].name);

		scanf("%s", arr_student[i].lname);

		do {
			do {
				//also providing student id to each student in below method by storing them in their own array
				printf("Enter student ID:  ");
				scanf("%d", &arr_student[i].studentId);
			} while ((arr_student[i].studentId < 9999));
		} while (arr_student[i].studentId > 100000);
		printf("Enter courses code: ");

		//courseid[indexc] = (char*) malloc(10);

		course[i].courseCode = malloc(MAX_COURSE_CODE * sizeof(char));
		scanf("%s", course[i].courseCode);
		length = strlen(course[i].courseCode);

		while (length != 7) {
			printf("The ID entered is not 7-digits long, try again: ");
			scanf("%s", course[i].courseCode);
			length = strlen(course[i].courseCode);
		}

		printf("Enter course Name: ");
		scanf("%s", course[i].courseName);
		printf("\n");
	}
	for (j = 0; j < MAX; j++) {

		arr_student[j].courses = &course[j];
		printf("Student Name: %s %s\n", arr_student[j].fname,
				arr_student[j].lname);
		printf("Student ID:   %d\n", arr_student[j].studentId);
		printf("Course Code:  %s\n", arr_student[j].courses->courseCode);
		printf("Course Name:  %s\n\n", arr_student[j].courses->courseName);

	}

	// signal to operating system program ran fine
	return 0;
}
