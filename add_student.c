#include "record.h"
#include <stdio.h>

void add_student() {
    Student info;
    char next;

    FILE *file;//file pointer

    do {
        file = fopen("StudentRecord.txt", "ab");  // append in binary mode
        if(file == NULL) {
            fprintf(stderr, "Can't open file!\n");//stderr-error message
            return;
        }

        getchar();  // clear input buffer
        printf("Enter First Name: ");
        scanf("%[^\n]", info.first_name);
        getchar();
        printf("Enter Last Name: ");
        scanf("%[^\n]", info.last_name);
        getchar();
        printf("Enter Roll Number: ");
        scanf("%d", &info.roll_num);
        printf("Enter Class: ");
        scanf("%d", &info.class);
        getchar();
        printf("Enter Section: ");
        scanf("%c", &info.section);
        getchar();
        printf("Enter Address: ");
        scanf("%[^\n]", info.add);
        printf("Enter Score: ");
        scanf("%f", &info.score);

        fwrite(&info, sizeof(Student), 1, file);
        fclose(file);

        printf("Record added successfully.\n");
        printf(CYAN "Do you want to add another record? (y/n):\n"RESET);
        printf(YELLOW "ENter Your choice: \n" RESET);
        getchar();
        scanf("%c", &next);
        printf(GREEN "Student Record Added Successfully!\n" RESET);


    } while(next == 'y' || next == 'Y');
}
