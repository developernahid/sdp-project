#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_STUDENTS 50

struct Student {
    char name[50];
    long long int id;
    float marks;
    int section;
};

struct Student studentList[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("  Error: Maximum number of students reached!\n");
        return;
    }

    struct Student newStudent;

    printf("  Enter the student's name: ");
    scanf("%s", newStudent.name);

    printf("  Enter the student's ID number: ");
    scanf("%lld", &newStudent.id);

    printf("  Enter the student's Section: ");
    scanf("%d",&newStudent.section);

    printf("  Enter the student's marks: ");
    scanf("%f", &newStudent.marks);

    studentList[numStudents++] = newStudent;

    printf("  Student record added successfully!\n");
}
void searchBySection(){
    int sec;
    printf("Enter section:");
    scanf("%d:",&sec);
    for (int i = 0; i < numStudents; i++)
    {
        if (sec==studentList[i].section)
        {
            printf(" Student name: %s ID %lld Marks %.2lf \n",studentList[i].name,studentList[i].id,studentList[i].marks);
        }
        else
        {
            printf("You enter invalid section!! Enter a correct section\n");
        }
    }
}
void searchByID(){
        long long int sid;
    printf("Enter section:");
    scanf("%lld:",&sid);
    for (int i = 0; i < numStudents; i++)
    {
        if (sid==studentList[i].id)
        {
            printf(" Student name: %s Section %d Marks %.2lf \n",studentList[i].name,studentList[i].section,studentList[i].marks);
        }
        
    }
}

int main() {
    system("color 0B");
    int choice;

    printf("\n  Student Management System\n");
    printf("  =========================\n");

    do {
        printf("\n  Menu:\n");
        printf("  1. Add Student\n");
        printf("  2. Search Student by Section\n");
        printf("  3. Search Student by ID\n");
        printf("  4. Exit\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchBySection();
             break;
               case 3:
                searchByID();
             break;
            case 4:
                printf("  Exiting...\n");
                break;
            default:
                printf("  Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
