/*
 * main.c
 * student database using likedlist
 *  Created on: Feb 26, 2024
 *      Author: fadye
 */
#include "stdio.h"
#include <stdlib.h>
#include "stdint.h"
struct Sdata {
	int ID;
	char name[40];
	float height;

};

struct SStudent {
	struct Sdata student;
	struct SStudent *Pnext_student;
};

struct SStudent *gp_head = NULL;
void add_student(){
	//check if list empty ===yes
	struct SStudent *Pnew_student;
	struct SStudent *Plast_student;
	if (gp_head==NULL)
	{
		Pnew_student= (struct SStudent *) malloc(sizeof(struct SStudent));
		gp_head=Pnew_student;
	}
	//no
	else{
		// navigate to the last student
		Plast_student=gp_head;//make plast points on the first student address
		while(Plast_student->Pnext_student)
			Plast_student=Plast_student->Pnext_student;
		//create new record
		Pnew_student= (struct SStudent *) malloc(sizeof(struct SStudent));
		Plast_student->Pnext_student=Pnew_student;
	}
	// make the pnext of the new student points on the null
	Pnew_student->Pnext_student=NULL;
	// fill the record
	char temp[40];
	printf("\nEnter the new student ID : ");
	scanf("%d",Pnew_student->student.ID);
	Pnew_student->student.ID=atoi(temp);
	printf("\nEnter the new student name : ");
	gets(Pnew_student->student.name);
	printf("\nEnter the new student height : ");
	gets(temp);
	Pnew_student->student.height= atof(temp);

}
int delete_student(){
	struct SStudent *Pselected_student=gp_head;
	struct SStudent *Pprevious_student=NULL;
	unsigned int selected_id;
	printf("Enter student id to be deleted : ");
	scanf("%d",&selected_id);
	while(Pselected_student){//as long as it exist and != null loop iterates
		//if id selected found
		if(Pselected_student->student.ID==selected_id){
			//selected id is not the first student
			if(Pprevious_student)
			{
				Pprevious_student->Pnext_student=Pselected_student->Pnext_student;
			}
			//selected student id is of the first
			else{
				gp_head=Pselected_student->Pnext_student;
			}
			free(Pselected_student);
			return 1;

		}
		Pprevious_student=Pselected_student;
		Pselected_student=Pselected_student->Pnext_student;

	}
	printf("Entered id does not exist");
	return 0;
}
void view_all_student(){
	struct SStudent *Pcurrent_student=gp_head;
	if(gp_head==NULL){
		printf("Error !!! empty list");
	}
	else{
		while(Pcurrent_student)//check if list is emtpy & to stop at end of list
			{
			printf("Student ID: %d\n\n",Pcurrent_student->student.ID);
			printf("Student Name: %s\n\n",Pcurrent_student->student.name);
			printf("Student height: %.2f\n\n",Pcurrent_student->student.height);
			Pcurrent_student=Pcurrent_student->Pnext_student;
		}
	}
}
void delete_all(){
	struct SStudent *Pdelete=gp_head;
	struct SStudent *Pnext_delete=NULL;
	if(gp_head==NULL){
			printf("Error !!! empty list");
		}
		else{
			while(Pdelete)//check if list is emtpy & to stop at end of list
				{
				Pnext_delete=Pdelete->Pnext_student;
				free(Pdelete);
				Pdelete=Pnext_delete;
			}
			gp_head=NULL;
		}
}
int main(){
	while(1){
		char temp[10];
	printf("=================================");
	printf("\n\tEnter a choice from the following: ");
	printf("\n\t1: Add a Student: ");
	printf("\n\t2: Delete a Student by ID: ");
	printf("\n\t3: View all students: ");
	printf("\n\t4: Delete all students: ");
	printf("\n\t Enter option: ");

	gets(temp);
	printf("================================");

	switch (atoi(temp)) {
		case 1:
				add_student();

				break;
		case 2:
				delete_student();

				break;
		case 3:
				view_all_student();

				break;
		case 4:
				delete_all();

				break;
		default:
			printf("wrong answer!!");
			break;
	}
	return 0;
}
}
