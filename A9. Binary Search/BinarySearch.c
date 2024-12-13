#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
    int rollno;
    char name[100];
    double percentage;
} Student;

void initStudents(Student students[])
{

    char *names[10] = {"Bhushan", "Neha", "Pooja", "Vijay", "Ajay", "Vishal", "Shubham", "Pavan", "Divya", "Disha"};

    for (int i = 0; i < MAX; i++)
    {
        students[i].rollno = i + 1;
        strcpy(students[i].name, names[i]);
        students[i].percentage = 100.0;
    }
}

void displayStudent(Student students[])
{
    printf("\nDisplaying Students : \n\n");

    for (int i = 0; i < MAX; i++)
    {

        printf("\tRoll No : %d\n", students[i].rollno);
        printf("\tName : %s\n", students[i].name);
        printf("\tPercentage : %f\n\n", students[i].percentage);
    }
    printf("\n");
}

void BinarySearch(Student students[], int rollno)
{
    if (rollno > MAX || rollno <= 0)
    {
        printf("\n\nInvalid Roll No\n\n");
        return;
    }
    int mid = MAX / 2;
    int found = -1;
    if (rollno == mid)
    {
        found = mid;
    }
    else if (rollno < mid)
    {
        for (int i = 0; i < mid; i++)
        {
            if (i == rollno)
            {
                found = i;
            }
        }
    }
    else if (rollno > mid)
    {
        for (int i = mid+1; i <= MAX; i++)
        {
            if (i == rollno)
            {
                found = i;
            }
        }
    }
    found--;
    if (found >= 0){
        printf("\n\nStudent Found!\n\n");
        printf("\tRoll No : %d\n", students[found].rollno);
        printf("\tName : %s\n", students[found].name);
        printf("\tPercentage : %f\n\n", students[found].percentage);
    }else{
        printf("\n\nSomething Wents Wrong...\n\n");
    }
}

void menu(){
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

    int ch = 0;

    do{
        menu();
        scanf("%d",&ch);
        if (ch == 1){
            displayStudent(students);
        }else if(ch == 2){
            int roll;
            printf("\n\nEnter Roll Number To Search : ");
            scanf("%d",&roll);
            BinarySearch(students,roll);
        }else if(ch == 3){

        }else{
            printf("\n\nInvalid Choice.\n\n");
        }
        
    } while (ch != 3);
    return 0;
}
