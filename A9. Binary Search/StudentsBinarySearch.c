#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

typedef struct
{
    int rollno;
    char name[100];
    double percentage;
} Student;

double generateRandomDouble(double min, double max)
{
    double scale = rand() / (double)RAND_MAX; // Scale between 0 and 1
    return min + scale * (max - min);         // Scale to [min, max]
}
void initStudents(Student students[])
{

    char *names[10] = {"Bhushan", "Neha", "Pooja", "Vijay", "Ajay", "Vishal", "Shubham", "Pavan", "Divya", "Disha"};

    for (int i = 0; i < MAX; i++)
    {
        students[i].rollno = i + 1;
        strcpy(students[i].name, names[i]);
        students[i].percentage = generateRandomDouble(30, 95);
    }
}

void displayPerticularStudent(Student student)
{
    printf("\tRoll No : %d\n", student.rollno);
    printf("\tName : %s\n", student.name);
    printf("\tPercentage : %.2f\n\n", student.percentage);
}

void displayStudent(Student students[])
{
    printf("\nDisplaying Students : \n\n");
    for (int i = 0; i < MAX; i++)
    {
        displayPerticularStudent(students[i]);
    }
    printf("\n");
}

void BinarySearch(int targetRollNo, int start, int end, Student students[])
{
    if (start > end)
    {
        printf("\n\nStudent With Roll No '%d' Is Not Found\n\n", targetRollNo);
        return;
    }
    int mid = (start + end) / 2;

    if (targetRollNo == students[mid].rollno){
        printf("\n\nStudent Found : \n\n");
        displayPerticularStudent(students[mid]);
    }
    else if (targetRollNo < students[mid].rollno)
    {
        BinarySearch(targetRollNo, start, mid - 1, students);
    }
    else if (targetRollNo > students[mid].rollno){
        BinarySearch(targetRollNo, mid + 1, end, students);
    }
}

void menu()
{
    // printf("\n\n\n\n");
    printf("\n1. Display All Students.\n");
    printf("\n2. Search For Student\n");
    printf("\n3. Exit.\n");
    printf("\nChoose Your Option ->");
}

int main(int argc, char const *argv[])
{
    Student students[MAX];
    initStudents(students);

    srand(time(0));

    int ch = 0;

    do
    {
        menu();
        scanf("%d", &ch);
        if (ch == 1)
        {
            displayStudent(students);
        }
        else if (ch == 2)
        {
            int roll;
            printf("\n\nEnter Roll Number To Search : ");
            scanf("%d", &roll);
            BinarySearch(roll, 0, MAX, students);
        }
        else if (ch == 3)
        {
        }
        else
        {
            printf("\n\nInvalid Choice.\n\n");
        }

    } while (ch != 3);
    return 0;
}
