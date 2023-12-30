#include <stdio.h>
#include <string.h>

void * mem_cpy(void * s1,const void *s2,size_t n);
void * mem_move(void *s1, const void *s2,size_t n);
void *mem_cmp(const void *s1,const void *s2,size_t n);
int result=0;

int main(){
    char c1[]="hello world !";
    char c2[5]="HelLo";
    int *ptr;
    ptr=mem_cmp(c1,c2,3);
    printf("mem_cmp is %d",*ptr);
    //puts(c2);
    puts(" ");
    return 0;
}

void * mem_cpy(void *s1, const void *s2,size_t n){
    char * c1=(char *)s1;
    const char * c2=(char *)s2;
    while (n--)
        *c1++=*c2++;
    
    return c1;
}

void * mem_move(void *s1, const void *s2,size_t n){
    if(s1==NULL||s2==NULL)
        return NULL;
    char *c1 =(char *)s1;
    const char *c2 =(char *)s2;
    char string[1000]="";
    char * s_ptr=string;
    printf("c1 is %s\n",c1);
    while (n--){
        //puts("Hello world");
        printf("%c || %c || %ld\n",*s_ptr,*c2,n);
        *s_ptr=*c2++;
        *c1++=*s_ptr++;
    }
    printf("c1 is %s\n",c1);
    return c1;
}

void *mem_cmp(const void *s1,const void *s2,size_t n){
    
    void *r=&result;
    const char *i=(char *)s1;
    const char *j=(char *)s2;
    if (i==NULL||j==NULL||n==0){
        return NULL;
    }
    for (size_t x = 0; x < n; x++){
        result = *(i+x)==*(j+x);
        printf("*(i+x)==*(j+x) is %d || result is %d\n",*(i+x)==*(j+x),result);
        switch (result)
        {
        case 1:
            result =0;
            break;
        default:
            if(*(i+x)>*(j+x)){
                printf("*(i+x)==*(j+x) is %d \n",*(i+x)==*(j+x));
                result = *(i+x)>*(j+x);
                return r;
            }else if (*(i+x)<*(j+x))
            {
                result = *(i+x)<*(j+x);
                return r;
            }
            break;
        }
    } 
    return r;
}