/*
 * ============================================================================
 * Name        : main.c
 * Author      : ABHI
 * Version     :
 * Copyright   : Your copyright notice
 * Description : Hello World in C, Ansi-style
 *
 * Title: Assignment 1 - Student Registration System
 * Course: CST8234 - C Langauage
 * Term: Sumer 2020
 *
 *
 *
 * Team
 *	 	 student #1: <<<Abhi patel (pate0789)>>>
 *	 	 student #2: <<<Vraj Patel(pate0787)>>>
 *
 * Status:
 *  	 	 Requirement #1: {complete}
 *	 	 	 Requirement #2: {complete}
 *	 	 	 Requirement #3: {complete}
 *	 	 	 Requirement #4: {complete}
 *	 	 	 Requirement #5: {complete}
 * 	 	 	 Requirement #6: {complete}
 *	 	 	 Requirement #7: {complete}
 *	 	 	 Requirement #8: {complete}
 *
  *============================================================================
 **/

//#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper/helper.h"


#define MAX_COURSE_CODE (7 + 1)

/**************************************************************************
 * Main
 **************************************************************************/

int main(void) {

//TODO: https://wiki.eclipse.org/CDT/User?FAQ#Eclipse_console_does_not_show_output_on_windows
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int r, studentregister, length, l, newstudentidregistration,
			studentdroploop, coursedroploop, registerastudent ,
			breakpointstudentregister , subcoursecode,
			breakpointcourseregister , addcoursecode , studentregisterid
					, breakpointstudentid , registercoursecode ,
			breakpointregistercourse ;

	char g[10];
	char z5[10];
	// creating the first option of the program of number of students registering
	printf("Welcome to the Student Registration System (SRC)\n\n");

	printf("How many student would to like to registered:");
	int nstudent;
	scanf("%d", &nstudent);
	int studentid[nstudent];
	for (int index = 0; index < nstudent; index++) {
		int q = index + 1;
		do {
			do {
				//also providing student id to each student in below method by storing them in their own array
				printf("please enter student ID for student %d:", q);
				scanf("%d", &studentid[index]);
			} while ((studentid[index] < 9999));
		} while (studentid[index] > 100000);
	}
	printIntArray(studentid, nstudent);
//now creating second method asking user that no. of courses the user want to enroll for the students
	printf("How many courses are you offering :");
	int ncourse;
	scanf("%d", &ncourse);
	char *courseid[ncourse];
	for (int indexc = 0; indexc < ncourse; indexc++) {

		int q = indexc + 1;
// providing students their choice of course with the course code

		printf("please enter courses code for course %d:", q);

		//courseid[indexc] = (char*) malloc(10);

		courseid[indexc] = malloc(MAX_COURSE_CODE * sizeof(char));
		scanf("%s", courseid[indexc]);
		length = strlen(courseid[indexc]);

		while (length != 7) {
			printf("The ID entered is not 7-digits long, try again: ");
			scanf("%s", courseid[indexc]);
			length = strlen(courseid[indexc]);
		}
	}
	// storing courses provided to students to be stored in their own array
	printStringArray(courseid, ncourse);
	int array[nstudent][ncourse];
	initilaize2DArray((int*) array, nstudent, ncourse);
	// creating do while loop so that we can prompt user to choose one option out of three actions mentioned below
	do {

//int array[ab][b];
		//  print2DArray((int *)array, ab, b);
		printf("Please choose one of the following ctions: \n\n");
		printf("1- Register a student in acourse\n");
		printf("2- Drop a student's course\n");
		printf("3- Print registration table\n");
		printf("4- Quit\n");
		printf("Please enter action number: ");

		scanf("%d", &r);
		if (r == 1) {
//creating do while loop method to register a student in this one of three actions so that if it does not register than it can throw an error message of invalid
			do {
				printf("\nPlease enter student ID: ");
				scanf("%d", &studentregister);
				for (l = 0; l < nstudent; l++) {
					if (studentregister == studentid[l]) {
						registerastudent = l;
						breakpointstudentregister = 1;
						break;
					} else {
						breakpointstudentregister = 0;
					}

				}
				if (breakpointstudentregister == 0) {
					printf("Error: Student ID %d not found. Try again",
							studentregister);
				}
			} while (breakpointstudentregister == 0);
			//creating do while loop method to provide course code a student in this one of three actions so that if it does not register than it can throw an error message of invalid
			do {
				printf("Please enter course code:");

				scanf("%s", g);
				for (subcoursecode = 0; subcoursecode < ncourse;
						subcoursecode++) {
					if (strcmp(g, courseid[subcoursecode]) == 0) {
						addcoursecode = subcoursecode;
						breakpointcourseregister = 1;
						//printf("%d", addcoursecode);
						break;
					} else {
						breakpointcourseregister = 0;
					}
				}
				if (breakpointcourseregister == 0) {
					printf("Error: course code %s not found. Try again\n", g);

				}

			} while (breakpointcourseregister == 0);
			//  scanf("%c");
			array[registerastudent][addcoursecode] = 1;
			print2DArray((int*) array, nstudent, ncourse);
			//	printf("[ [ 1 , -1 ] ] ");
// creating method to drop a student those are already registered by making use of their student id and course id
//void printStringArray(char *array[], size_t lengt)
		} else if (r == 2) {
			//creating do while loop method to drop a student by using student id so that if it does not drop student  than it can throw an error message of invalid
			do {
				printf("\nPlease enter student ID: ");
				scanf("%d", &newstudentidregistration);
				for (studentdroploop = 0; studentdroploop < nstudent;
						studentdroploop++) {
					if (newstudentidregistration
							== studentid[studentdroploop]) {
						studentregisterid = studentdroploop;
						breakpointstudentid = 1;
						//	printf("%d", studentregisterid);
						break;
					} else {
						breakpointstudentid = 0;
					}
				}
				if (breakpointstudentid == 0) {
					printf("Error: course code %d not found. Try again\n",
							newstudentidregistration);
				}

			} while (breakpointstudentid == 0);
			//creating do while loop method to drop a student by using course id so that if it does not drop student  than it can throw an error message of invalid
			do {
				printf("Please enter course code:");

				scanf("%s", z5);
				for (coursedroploop = 0; coursedroploop < ncourse;
						coursedroploop++) {
					if (strcmp(z5, courseid[coursedroploop]) == 0) {
						registercoursecode = coursedroploop;
						breakpointregistercourse = 1;
						//	printf("%d", registercoursecode);
						break;
					} else {
						breakpointregistercourse = 0;
					}
				}
				if (breakpointregistercourse == 0) {
					printf(
							"Error: course code %s not found. Try again\n",
							z5);
				}

			} while (breakpointregistercourse == 0);
			array[studentregisterid][registercoursecode] = 0;
			print2DArray((int*) array, nstudent, ncourse);

		} else if (r == 3) {
			print2DArray((int*) array, nstudent, ncourse);
		} else if (r == 4) {
			printf("Exit....  ");
		} else {
			printf("Try again....");
		}
	} while (r != 4);

	return 0;

}
