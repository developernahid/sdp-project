#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STUDENTS 50
int ID=0;
struct Student
{
    char name[50];
    long long int id;
    float marks[5];
    float cg;
    int section;
};

struct Student studentList[MAX_STUDENTS];
int numStudents = 0;

// check ID already exists in the array
bool isStudentIDExist(long long int studentID)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (studentList[i].id == studentID)
        {
            return true; // ID already exists
        }
    }
    return false; // ID doesn't exist
}

void addStudent()
{
    if (numStudents >= MAX_STUDENTS)
    {
        printf("  Error: Maximum number of students reached!\n");
        return;
    }

    struct Student newStudent;

    printf("  Enter the student's name: ");
    scanf("%s", newStudent.name);

    // Loop until a unique ID is entered
    do
    {
        printf("  Enter the student's ID number: ");
        scanf("%lld", &newStudent.id);

        if (isStudentIDExist(newStudent.id))
        {
            printf("  Error: Student with ID %lld already exists. Enter a unique ID.\n", newStudent.id);
        }

    } while (isStudentIDExist(newStudent.id));

    printf("  Enter the student's Section: ");
    scanf("%d", &newStudent.section);

    studentList[numStudents++] = newStudent;

    printf("  Student record added successfully!\n");
}

void addMarks()
{
    if (numStudents == 0)
    {
        printf("  No students in the record!\n  Add Student then you can enter mark.");
        return;
    }

    int markedStudentCount = 0;
    printf("  Enter subject marks for all students:\n");
    for (int i = 0; i < numStudents; i++)
    {
        long long int studentID = studentList[i].id;
        bool alreadyMarked = false;

        for (int j = 0; j < markedStudentCount; j++)
        {
            if (studentList[j].id == studentID)
            {
                alreadyMarked = true;
                break;
            }
        }

        if (!alreadyMarked)
        {
            printf("  Student ID: %lld\n", studentList[ID].id);
            printf("  Enter marks for 5 subjects:\n");

            for (int j = 0; j < 5; j++)
            {
                printf("  Subject %d: ", j + 1);
                scanf("%f", &studentList[ID].marks[j]);

                // Limit marks to 100
                if (studentList[ID].marks[j] > 100)
                {
                    studentList[ID].marks[j] = 100;
                    printf("  Marks cannot exceed 100. Adjusted to 100.\n");
                }
            }

            // Calculate CGPA based on marks and apply CGPA mapping
            float sum = 0;
            for (int j = 0; j < 5; j++)
            {
                sum += studentList[ID].marks[j];
            }
            float cgpa = sum / 5;

            if (cgpa >= 80)
            {
                studentList[ID].cg = 4.00;
                printf("  CGPA: A+\n");
            }
            else if (cgpa >= 75)
            {
                studentList[ID].cg = 3.75;
                printf("  CGPA: A\n");
            }
            else if (cgpa >= 70)
            {
                studentList[ID].cg = 3.50;
                printf("  CGPA: A-\n");
            }
            else if (cgpa >= 65)
            {
                studentList[ID].cg = 3.25;
                printf("  CGPA: B+\n");
            }
            else if (cgpa >= 60)
            {
                studentList[ID].cg = 3.00;
                printf("  CGPA: B\n");
            }
            else if (cgpa >= 55)
            {
                studentList[ID].cg = 2.75;
                printf("  CGPA: B-\n");
            }
            else if (cgpa >= 50)
            {
                studentList[ID].cg = 2.50;
                printf("  CGPA: C+\n");
            }
            else if (cgpa >= 45)
            {
                studentList[ID].cg = 2.25;
                printf("  CGPA: C\n");
            }
            else if (cgpa >= 40)
            {
                studentList[ID].cg = 2.00;
                printf("  CGPA: C-\n");
            }
            else
            {
                studentList[ID].cg = 0.00;
                printf("  CGPA: F\n");
            }
            ID++;
            markedStudentCount++;
            break;
        }
        else
        {
            printf("  Student ID %lld has already been marked. Skipping to the next student.\n", studentID);
        }
    }

    printf("  Subject marks and CGPA updated for all marked students!\n");
}

//////

void displayStudents()
{
    if (numStudents == 0)
    {
        printf("  No students in the record!\n  Please Add student first!!");
        return;
    }

    printf("  Student List:\n");
    printf("  ============================================\n");
    printf("  Name\t\tID Number\tSection\t  CGPA\n");
    printf("  ---------------------------------------------\n");

    for (int i = 0; i < numStudents; i++)
    {
        printf("  %s\t\t%lld\t\t%d\t  %.2f\n",studentList[i].name,studentList[i].id,studentList[i].section,studentList[i].cg);
    }

    printf("  ============================================\n");
}

void searchByID()
{
    long long int sid;
    int found = 0;
    if (numStudents == 0)
    {
        printf("  No students in the record!\n  Add Student before search.");
        return;
    }
    printf("  Enter ID:");
    scanf("%lld:",&sid);
    for (int i = 0; i < numStudents; i++)
    {
        if (sid==studentList[i].id)
        {
            printf("  ===================================================\n");
            printf("  Student name:  %s     Section:  %d   CGPA: %.2f \n",studentList[i].name,studentList[i].section,studentList[i].cg);
            printf("  ===================================================\n");
            found = 1;
            break;
        }

    }

    if (found==0)
    {
        printf("  Student ID %lld not found!\n  Enter valid id please!!\n", sid);
    }
}


void deleteStudent()
{
    long long int idToDelete;
    int found = 0;

    if (numStudents == 0)
    {
        printf("  No students in the record!\n");
        return;
    }

    printf("  Enter the ID number of the student to delete: ");
    scanf("%lld", &idToDelete);

    // Find the student with the given roll number
    for (int i = 0; i < numStudents; i++)
    {
        if (studentList[i].id == idToDelete)
        {
            // Shift the elements to the left to overwrite the student to delete
            for (int j = i; j < numStudents - 1; j++)
            {
                studentList[j] = studentList[j + 1];
            }
            found = 1;
            break;
        }
    }

    if (found)
    {
        numStudents--;
        printf("  Student ID %lld deleted successfully!\n",idToDelete);
    }
    else
    {
        printf("  Student ID %lld not found!\n", idToDelete);
    }
}


int main()
{
    int choice;

    do
    {
        printf("\n\n\n");
        printf("\n  Student Management System\n");
        printf("  =========================\n");

        printf("\n  Option:\n");
        printf("  1. Add Student\n");
        printf("  2. Display Students\n");
        printf("  3. Search Student by ID\n");
        printf("  4. Add Students marks\n"); // New option
        printf("  5. Delete Student\n");
        printf("  6. Exit\n");
        printf("  Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("  Invalid choice!! Please try again\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;  // Skip the rest of the loop and restart
        }

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchByID();
            break;
        case 4:
            addMarks();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            printf("  Exiting...\n");
            break;
        default:
            printf("  Invalid choice! Please try again.\n");
        }
    }
    while (choice != 6);

    return 0;
}
