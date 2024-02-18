#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum (const int grade[][EXAMS],int pupils, int tests);
int maximum(const int grade[][EXAMS],int pupils, int tests);
double average(const int setofGrades[],int test);
void printArray(const int grades[][EXAMS],int pupils, int tests);

int main ( ){
    const int studentGrades[STUDENTS][EXAMS]={
    { 77,68, 86,73},
    {96,87,89,78},
    {70,90,86,81}
    };
    int student;
    puts("The array is : ");
    printArray(studentGrades,STUDENTS,EXAMS);
    printf("\n Lowest grade for student %d is %d \n",
        minimum(studentGrades,STUDENTS,EXAMS),
        maximum(studentGrades,STUDENTS,EXAMS)
    );
    for (student = 0; student < STUDENTS; student++){
        printf("The average grade for student %d is %.2f \n",student, average(studentGrades[student],EXAMS));
    }
    
    puts("\n(= ◕ ᆽ  ◕ =)");
	return 0;
}

int minimum (const int grade[][EXAMS],int pupils, int tests){
    int i,j,lowGrade=100;
    for ( i = 0; i < pupils; i++)
    {
        for ( j = 0; j < tests; j++)
        {
            if(grade[i][j]<lowGrade)
            lowGrade=grade[i][j];
        }
    }
    return lowGrade;
}

int maximum(const int grade[][EXAMS],int pupils, int tests){
    int i,j,highGrade=0;
    for ( i = 0; i < pupils; i++)
    {
        for ( j = 0; j < tests; j++)
        {
            if(grade[i][j]>highGrade)
            highGrade=grade[i][j];
        }
    }
return highGrade;
}

double average(const int setofGrades[],int test){
    int i, total=0;
    for ( i = 0; i < test; i++)
    {
        total+=setofGrades[i];
    }
    return (double)total/test;
}

void printArray(const int grades[][EXAMS],int pupils, int tests){
    int i,j;
    printf("%s","                 [0]  [1]  [2]  [3]");
    for ( i = 0; i < pupils; i++)
    {
        printf("\nstudentGrades[%d] ",i);
        for ( j = 0; j < tests; j++)
        {
            printf("%-5d",grades[i][j]);
        }
    }
}
