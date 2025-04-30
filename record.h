#ifndef STUDENT_H
#define STUDENT_H
//max reocrds to be stored
#define MAX_RECORDS 200
//printf colours
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;33m"
#define YELLOW  "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
//structure for each student 
typedef struct
{
    char first_name[20];
    char last_name[20];
    int roll_num;
    int class;
    char section;
    char add[20];
    float score;
} Student;
//structure for entire record
typedef struct
{
    Student records[MAX_RECORDS];
    int recordcount;
}StudentRecord;


//function prototype:
void add_student();
void display_record();
void search_student();
void delete_record();
void export_to_csv();

#endif
