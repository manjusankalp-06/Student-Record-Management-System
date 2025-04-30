#include<stdio.h>
#include<stdlib.h>//inbuilt headerfile
#include "record.h"

int main()
{
    int choice;

    StudentRecord studentrecord;
    studentrecord.recordcount = 0;

    //initialize(&studentrecord);

    printf("-----------------------------------WELCOME TO STUDENT RECORD-----------------------------------\n");

    do
    {
        printf("=====STUDENT DATABASE MANAGEMENT SYSTEM=====\n");
        printf("1. Add Student Record\n");
        printf("2. Student Record\n");
        printf("3. Search Student\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch(choice)
        {
            case 1: //addind student details:
            add_student();
            break;

            case 2: //Display Student Record
            display_record();
            break;

            case 3: //Searching Student record
            search_student();
            break;

            case 4: //Deleting student record
            delete_record();
            break;

            case 5: //Save and exit
            printf(".......Exiting from the Student Record.......\n");
            exit(0);
            break;
            
            default:
            printf("Entered an Invalid Number \nPlease Enter a Valid Number:\n");
            break;            
        }
        export_to_csv();
    }
    while(choice != 7);

    return 0;
}

