#include <stdio.h>
#include <string.h>
#include "record.h"

void delete_record()
{
    FILE *file, *temp;
    Student info;
    int roll_no, found = 0;

    file = fopen("StudentRecord.txt", "r");
    temp = fopen("Temp.txt", "w");

    if (file == NULL || temp == NULL)
    {
        printf("Error Opening File\n");
        return;
    }

    printf("Enter Roll Number to Delete Record:\n");
    scanf("%d", &roll_no);

    while (fread(&info, sizeof(Student), 1, file))
    {
        if (info.roll_num == roll_no)
        {
            found = 1;
            continue; // Skip writing this record
        }
        fwrite(&info, sizeof(Student), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("StudentRecord.txt");
    rename("Temp.txt", "StudentRecord.txt");

    if (found)
    {
        printf("Record Deleted Successfully\n");
    }
    else
    {
        printf("No Record Found with Roll No: %d\n", roll_no);
    }
}
