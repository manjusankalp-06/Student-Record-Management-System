#include <stdio.h>
#include "record.h"

void export_to_csv()
{
    FILE *bin_file = fopen("StudentRecord.txt", "rb");
    FILE *csv_file = fopen("StudentRecord.csv", "w");

    if (bin_file == NULL || csv_file == NULL)
    {
        printf("Error opening file(s).\n");
        return;
    }

    Student info;

    // CSV Header
    fprintf(csv_file, "First Name,Last Name,Roll No,Class,Section,Address,Score\n");

    while (fread(&info, sizeof(Student), 1, bin_file))
    {
        if (info.roll_num <= 0 || info.class <= 0 || info.section < 'A' || info.section > 'Z')
        {
            continue; // skip invalid/corrupted records
        }

        fprintf(csv_file, "%s,%s,%d,%d,%c,%s,%.2f\n",
                info.first_name, info.last_name,
                info.roll_num, info.class, info.section,
                info.add, info.score);
    }

    fclose(bin_file);
    fclose(csv_file);

    printf(GREEN "Student records successfully exported to StudentRecord.csv\n" RESET);
}
