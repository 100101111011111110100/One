#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4
void choice(int *a);
void minimum (const int grade[][EXAMS],int pupils, int tests);
void maximum(const int grade[][EXAMS],int pupils, int tests);
void average(const int grade[][EXAMS],int pupils,int test);
void printArray(const int grades[][EXAMS],int pupils, int tests);

int main ( ){
    const int studentGrades[STUDENTS][EXAMS]={
    { 77,68, 86,73},
    {96,87,89,78},
    {70,90,86,81}
    };
    void (*menu[4])(const int grade[][EXAMS], int, int)= {printArray,minimum,maximum,average};
    int student,answer;
    do{
        choice(&answer);
        (*menu[answer])(studentGrades,STUDENTS,EXAMS);
    } while (answer!=4);
    //puts("\n(= ◕ ᆽ  ◕ =)");
	puts(" ");
    return 0;
}
void choice(int *a){
    void clr();
    puts("Choose : ");
    char *c[5]={"Output an array of ratings","Find the minimum score","Find the maximum score","Output the average score for all tests","Exit for program"};
    for (int i = 0; i < 5; i++)
    {
        printf("%3d  %s",i,c[i]);
        puts(" ");
    }
    printf("Enter yout choose : ");
    scanf("%d",a);
    if(*a<=-1||*a>=5){
        clr();
        choice(a);
    }
}
void clr(){
	int c;
	while((c=getchar())!='\n'&&c!=EOF)
	;
}
void minimum (const int grade[][EXAMS],int pupils, int tests){
    int i,j,lowGrade=100;
    for ( i = 0; i < pupils; i++)
    {
        for ( j = 0; j < tests; j++)
        {
            if(grade[i][j]<lowGrade)
            lowGrade=grade[i][j];
        }
    }
    printf("\nLowest grade is  %d\n",lowGrade);
    puts(" ");
}

void maximum(const int grade[][EXAMS],int pupils, int tests){
    int i,j,highGrade=0;
    for ( i = 0; i < pupils; i++)
    {
        for ( j = 0; j < tests; j++)
        {
            if(grade[i][j]>highGrade)
            highGrade=grade[i][j];
        }
    }
    printf("\nHighest grad is %d\n",highGrade);
    puts(" ");
}

void average(const int grade[][EXAMS],int pupils,int test){
    int i,j, total=0;
    for (j = 0; j < pupils; j++){
        for ( i = 0; i < test; i++){
        total+=grade[j][i];
        }
        printf("\nThe average grade for student %d is %.2f \n",j, (double)total/(double)test);
    }
}

void printArray(const int grades[][EXAMS],int pupils, int tests){
    int i,j;
    puts("The array is : ");
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
