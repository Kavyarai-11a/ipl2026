#include<stdio.h>
void Bit_display(int num);
int Bit_count(int num);
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    Bit_display(n);
    int count = Bit_count(n);
    printf("%d",count);
}
void Bit_display(int num)
{
    int total_bits=sizeof(int)*8;
    for(int i=total_bits-1;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
}
int Bit_count(int num)
{
    int total_bits=sizeof(int)*8;
    int count = 0;
    for(int i=total_bits-1;i>=0;i--)
    {
        if((num>>i)&1)
        {
            count++;
        }
        
    }
    return count;
}