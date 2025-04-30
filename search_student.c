#include <stdio.h>
#include <string.h>
#include "record.h"

void search_student()
{
    FILE *file;
    Student info;
    int roll_no, found = 0;

    file = fopen("StudentRecord.txt", "r");

    if (file == NULL)
    {
        printf("Student Record Not Found\n");
        return;
    }

    printf("Enter the Roll Number to Search:\n");
    scanf("%d", &roll_no);

    while (fread(&info, sizeof(Student), 1, file))
    {
        if (info.roll_num == roll_no)
        {
            found = 1;
            printf("\nStudent Found:\n");
            printf("Student Name: %s %s\n", info.first_name, info.last_name);
            printf("Roll.No: %d\n", info.roll_num);
            printf("Class: %d %c\n", info.class, info.section);
            printf("Address: %s\n", info.add);
            printf("Score: %.2f\n", info.score);
            break;
        }
    }

    if (!found)
    {
        printf("No Record Found with Roll No: %d\n", roll_no);
    }

    fclose(file);
}
