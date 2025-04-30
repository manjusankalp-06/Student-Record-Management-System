#include <stdio.h>
#include <string.h>
#include "record.h"

void display_record()
{
    FILE *file;
    Student info;
    int record_count = 0;

    file = fopen("StudentRecord.txt", "r");

    printf("=============== STUDENT RECORD ===============\n");

    if (file == NULL)
    {
        printf("Student Record Not Found\n");
        return;
    }

    printf(">>> Student Record Found <<<\n");

    printf("------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-15s | %-15s | %-7s | %-7s | %-7s | %-20s | %-6s |\n",
           "No", "First Name", "Last Name", "Roll No", "Class", "Section", "Address", "Score");
    printf("------------------------------------------------------------------------------------------\n");

    while (fread(&info, sizeof(Student), 1, file))
    {
        // Basic validation (example): non-zero roll number and printable section
        if (info.roll_num <= 0 || info.class <= 0 || info.section < 'A' || info.section > 'Z')
        {
            continue; // Skip invalid/corrupted records
        }

        printf("| %-3d | %-15s | %-15s | %-7d | %-7d | %-7c | %-20s | %-6.2f |\n",
               ++record_count, info.first_name, info.last_name,
               info.roll_num, info.class, info.section, info.add, info.score);
    }

    printf("------------------------------------------------------------------------------------------\n");

    fclose(file);
}
