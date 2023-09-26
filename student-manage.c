#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_STUDENTS 50

struct Student {
    char name[50];
    long long int id;
    float marks;
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

    printf("  Enter the student's marks: ");
    scanf("%f", &newStudent.marks);

    studentList[numStudents++] = newStudent;

    printf("  Student record added successfully!\n");
}

void displayStudents() {
    if (numStudents == 0) {
        printf("  No students in the record!\n");
        return;
    }

    printf("  Student List:\n");
    printf("  ===============================================\n");
    printf("  Name\t\tID Number\t\tMarks\n");
    printf("  -----------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("  %s\t\t%lld\t\t%.2f\n",studentList[i].name,studentList[i].id,  studentList[i].marks);
    }

    //printf("==================================\n");
}
void deleteStudent() {
    long long int idToDelete;
    int found = 0;

    if (numStudents == 0) {
        printf("  No students in the record!\n");
        return;
    }

    printf("  Enter the ID number of the student to delete: ");
    scanf("%lld", &idToDelete);

    // Find the student with the given roll number
    for (int i = 0; i < numStudents; i++) {
        if (studentList[i].id == idToDelete) {
            // Shift the elements to the left to overwrite the student to delete
            for (int j = i; j < numStudents - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            found = 1;
            break;
        }
    }

    if (found) {
        numStudents--;
        printf("  Student with roll number %lld deleted successfully!\n",idToDelete);
    } else {
        printf("  Student with roll number %lld not found!\n", idToDelete);
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
        printf("  2. Display Students\n");
        printf("  3. Delete Student\n");
        printf("  4. Exit\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
            deleteStudent();
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
