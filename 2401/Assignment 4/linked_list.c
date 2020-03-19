
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2019

 
 
 
 
 Copyright 2019 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// DEFINE



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
head - head of linked list
person - the data of the new person

output
head - head of linked list

return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL
2. person is not NULL

*/

ListNode *insertToList(ListNode **head, PersonInfo *person)
{
	// add code
   //
	ListNode *out = (ListNode *)malloc(sizeof(ListNode));
	out->person = *person;
	out->next = *head;
	*head = out;
	return *head;

}


/************************************************************************/
/*
Purpose: find the first node in the list with the input family name and insert a new node containing the 
person data into the list.

If there is no node that matches that given family name then the operation is considered a failure.  

Input
head - head of list
familyName - the family name that must be used to find the first matching recrod
person - the person record to insert into the list as new node


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

Assumptions:
familyName is not NULL
person is not NULL

*/


ListNode *insertAfter(ListNode *head, char *familyName, PersonInfo *person)
{
	// add code 
	if(head == NULL){
		return NULL;
	}
	ListNode *step = head;
	while(step->person.familyName != familyName){
		if(step->next == NULL){
			return NULL;
		}
		step = step->next;
	}
	
	ListNode *out = (ListNode *)malloc(sizeof(ListNode));
	out->person = *person;
	out->next = NULL;
	step->next = out;
	return out;
}


/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
person - person data that is stored in the list


return
0 if node was deleted
1 if node was not deleted or list is empty

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty
2. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteFromList(ListNode **head, PersonInfo *person)

{
	// add code
	if(*head == NULL){
		return 1;
	}
	ListNode *front = *head;
	*person = front->person;
	*head = front->next;
	free(front);
	if(head == NULL){
		return 1;
	}
	return 0;
}


/************************************************************************/

/*
Purpose: delete the first node with the matching family name
Input
head - the head of the list
familyName - family name of person

output
head - the head of the list
person - data of the person in the node


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

Assumptions
1. familyName is not NULL
2. Function has to be robuse enough to handle cases where head is NULL or the list is empty
3. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person)
{
	// add code 
	if(*head == NULL){
		return 1;
	}
	ListNode *prev;
	ListNode *select = *head;
	if(*select->person.familyName == *familyName){
		//printf("ehh");
		if(select->next == NULL){
			return 1;
		}
		*head = select->next;
		return 0;
	}
	while(*select->person.familyName != *familyName){
		printf("%-12s   %-12s\n", select->person.familyName, familyName);
		if(select->next == NULL){
			return 1;
		}
		prev = select;
		select = select->next;
	}
	*person = select->person;
	prev->next = select->next;
	return 0;
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list

input
head - the head of the list

output
head - the head of the list

return
none

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/


void deleteList(ListNode **head)
{
	// add code 
	*head = NULL;

}



/************************************************************************/
/*
Purpose: search for the first node with the matching familyName
Input
head - the head of the list
familyName - family name of person

Output
person - a copy of the person record in the node

return
a pointer to the node that was found.
NULL - if no node was found or list empty


Assumptions
1. familyName is not NULL
2. person can be NULL.  If person is NULL then no coping of the person record is required. 

*/


ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person)
{
	// add code 
	ListNode *select = head;
	//printf("%-12s %-12s\n", select->person.familyName, familyName);
	if(*select->person.familyName == *familyName){
		//printf("pass\n");
		return select;
	}
	while(*select->person.familyName != *familyName){
		//printf("welp\n");
		if(select->next == NULL){
			return NULL;
		}
		select = select->next;
	}
	return select;
}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head)
{
	// add code 
	ListNode *temp = head;
	while(temp != NULL){
		if(temp->person.empOrStudent == EMPLOYEE_TYPE){
			printf("%-16s %-16s %8d %4d %7.2f \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.emp.yearsOService, temp->person.emp.salary);
		}else{
			printf("%-16s %-16s %8d %5.2f %3d %3d \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.stu.gpa, temp->person.stu.numCompletedCourses, temp->person.stu.numRequiredCourses);
		}
		temp = temp->next;
	}

}

/************************************************************************/
/*
Purpose: prints all the students in the list

input
head - the head of the list

Output 
None

Return
None
*/


void printStudents(ListNode *head)
{
	//printf("Printing students...\n");
	//printf("%-16s\n", head->person.firstName);
	// add code 
	/*
	ListNode *temp = head;
	while(temp != NULL){
		if(temp->person.empOrStudent == STUDENT_TYPE){
			printf("%-16s %-16s %8d %5.2f %3d %3d \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.stu.gpa, temp->person.stu.numCompletedCourses, temp->person.stu.numRequiredCourses);
		printf("\n Passed\n");
		}
		printf(" ******* ");
		temp = temp->next;
	}
	*/
	ListNode *temp = head;
	while(temp != NULL){
		if(temp->person.empOrStudent == EMPLOYEE_TYPE){
		}else{
			printf("%-16s %-16s %8d %5.2f %3d %3d \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.stu.gpa, temp->person.stu.numCompletedCourses, temp->person.stu.numRequiredCourses);
		}
		temp = temp->next;
	}
}
/************************************************************************/
/*
Purpose: prints all the employees in the list

input
head - the head of the list

Output
None

Return
None
*/


void printEmployees(ListNode *head)
{
	//printf("Printing Employees...\n");
	//printf("%-16s\n", head->person.firstName);
	// add code 
	/*
	ListNode *temp = head;
	while(temp != NULL){
		if(temp->person.empOrStudent == EMPLOYEE_TYPE){
			printf("%-16s %-16s %8d %4d %7.2f \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.emp.yearsOService, temp->person.emp.salary);
		printf("\n Passed\n");
		}
		printf(" ******* ");
		temp = temp->next;
	}
	*/
	ListNode *temp = head;
	while(temp != NULL){
		if(temp->person.empOrStudent == EMPLOYEE_TYPE){
			printf("%-16s %-16s %8d %4d %7.2f \n", temp->person.firstName, temp->person.familyName, temp->person.id,
				temp->person.emp.yearsOService, temp->person.emp.salary);
		}else{}
		temp = temp->next;
	}
}


/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


unsigned int listSize(ListNode *head)
{
	// add code 
	unsigned int out = 0;
	ListNode *step = head;
	while(step != NULL){
		out++;
	}
	return out;
}




/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL


*/
int copyList(ListNode *head, ListNode **newListHead){
	ListNode *output;
	ListNode *step = head;
	if(step != NULL){
		output = step;
		step = step->next;
		output = output->next;
		printf("yaaah\n");
	}else{
		return 1;
	}
	while(step->next != NULL){
		output = step;
		step = step->next;
		output = output->next;
		printf("yeet\n");
	}
	output = step;
	output->next = NULL;
	**newListHead = *output;
	return 0;

}
/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL

*/
int copyListRecursive(ListNode *head, ListNode **newListHead)
{


}

/************************************************************************/
/*
Purpose: removes all the nodes that have student data from the list
input
head - the head of the list

output
head the modified list

return
0 if successful
1 if failed

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

int removeStudents(ListNode **head)

{

}

