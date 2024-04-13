#include <stdio.h>

#define SIZE 1000

int reserve(int *j_ptr,int c);
int main(){
	int j=0,i=50030;
	printf("j is %p\n",&j);
	reserve(&j,i);
	printf("j is %d",j);
	puts(" ");
	return 0;
}

int reserve(int *j_ptr,int c){
	printf("j_ptr is %d\n",*j_ptr);
	printf("j_ptr is %p\n",j_ptr);
	if (c/1000==50){
		if (c%1000+1>SIZE-(*j_ptr+20))
			return 2;
	*j_ptr=*j_ptr+(c%1000)+1;
	*j_ptr=10;
	}else
		return 0;
	return 1;
}
/*int main(){
	int j=13;
	puts("====");
	printf("o is %c\n",j);
	puts("====");
	j='\0';
	printf("\\0 is %d",j);

	return 0; 
}
int main(){
	double memory[SIZE]={0};
	char  *text_ptr[SIZE]={0};
	int j;
	char text[SIZE]="";
	char *t_ptr;
	int i,k=0;
	char a[]={0};
	/*while ((i=getchar())!=EOF && i!='\n'){
		a[j++]=i;
	}
	for ( ; k <=j; k++){
		printf("%c",a[k]);
	}
	
	printf("Enter the string: \n");
	t_ptr=gets(text);
	printf("2) %s \n",text);
	
	printf("Please enter the number : ");
	("%d",&j);
	while ((i=getchar())!=EOF && i!='\n')
		;
	
	t_ptr=fgets(text,j,stdin);
	if(t_ptr){
		printf("2) %s \n",text);
	}
	text_ptr[0]=text;
	text_ptr[1]="IZI";
	printf("3) %s \n",text_ptr[0]);
	printf("4) %s \n",text_ptr[1]);
	puts("0");
	return 0;
}

int add(int *m1,int *m2,int i);
int main(){
    int j=12;
    int m=5;
    int * m_ptr;
    m_ptr=&m;
    int p=add(&j,m_ptr,4);
    printf(" \np is  %d \n",p);
    printf(" \nj is  %d \n",j);
    puts(" ");
    return 0;
}

int add(int *m1,int *m2,int i){
	//printf("\n%d\n",i);
	int j=*m1;
	switch(i){
		case 0:
			j+=*m2;
			break;
		case 1:
			j-=*m2;
			break;
		case 2:
			if (!(*m2)){
				return 1;
			}
			j/=*m2;
			break;
		case 3:
			j*=*m2;
			break;
		case 4:
			j=j%*m2;
			//printf(" \nj is  %d \n",j);
			break;
		default:
			break;
	}
	if(j<=-9999||j>=9999){
		return 2;
	}
	*m1=j;
	//printf(" \nj is  %d \n",*m1);
	return 0;
}
*/