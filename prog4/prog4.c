#include<stdio.h>
typedef struct
{
    unsigned int a: 1;
    unsigned int b: 5;
    signed int c: 7;
    signed int d: 8;
}Numbers;
int main()
{
    Numbers n;
    int w,x,y,z;
    printf("Enter a 2 positive and 2 negative numbers:");
    scanf("%d %d %d %d",&w,&x,&y,&z);
    n.a=w;
    printf("%d ",n.a);
    n.b=x;
    printf("%d ",n.b);
    n.c=y;
    printf("%d ",n.c);
    n.d=z;
    printf("%d\n",n.d);
    //printf("%d %d %d %d",n.a,n.b,n.c,n.d);
    return 0;


}