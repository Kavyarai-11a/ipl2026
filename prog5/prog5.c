#include<stdio.h>
union decision {
unsigned char flags;
struct field {
unsigned int your_choice:1; /* tobe computed */
unsigned int your_mothers_choice:1;
unsigned int your_fathers_choice:1;
unsigned int socially_acceptable:1;
unsigned int financially_viable:1;
unsigned int do_you_aptitude:1;
unsigned int do_you_likeit:1;
unsigned int decision:1; /* to be computed */
}s;
};
union decision input();
void make_decision(union decision *d);
void print_decsion(union decision d);
void print_conclusion_based_on_flags( union decision d);
int main()
{
    union decision d;
    d = input();
    make_decision(&d);
    print_decsion(d);
    print_conclusion_based_on_flags(d);
}
union decision input()
{
    union decision d;
    char a,b,c,i,e,f,g;
    printf("Enter your choice:");
    scanf(" %c",&a);
    d.s.your_choice = a - '0';
    printf("Enter your mothers choice:");
    scanf(" %c",&b);
    d.s.your_mothers_choice = b - '0';
    printf("Enter your fathers choice:");
    scanf(" %c",&c);
    d.s.your_fathers_choice = c - '0';
    printf("Enter socially acceptable:");
    scanf(" %c",&i);
    d.s.socially_acceptable = i - '0';
    printf("Enter financially viable:");
    scanf(" %c",&e);
    d.s.financially_viable = e - '0';
    printf("Enter do you aptitude:");
    scanf(" %c",&f);
    d.s.do_you_aptitude = f - '0';
    printf("Enter do you likeit:");
    scanf(" %c",&g);
    d.s.do_you_likeit = g - '0';
    return d;
}
void make_decision(union decision *d)
{
    int count =0;
    count += (*d).s.your_choice;
    count += (*d).s.your_mothers_choice;
    count += (*d).s.your_fathers_choice;
    count += (*d).s.socially_acceptable;
    count += (*d).s.financially_viable;
    count += (*d).s.do_you_aptitude;
    count += (*d).s.do_you_likeit;
    printf("%d\n",count);
    if(count>=5)
    {
        (*d).s.decision = 1;
    }
    else
    {
        (*d).s.decision = 0;
    }
    
}
void print_decsion(union decision d)
{
    if(d.s.decision == 1)
    {
        printf("You can do it\n");
    }
    else
    {
        printf("You should not do it\n ");
    }
    printf("==========Final decision==========\n");
    printf("Your Choice: %s\n",d.s.your_choice ? "YES" : "NO");
    printf("Your Mother's Choice: %s\n",d.s.your_mothers_choice ? "YES" : "NO");
    printf("Your Father's Choice: %s\n",d.s.your_fathers_choice ? "YES" : "NO");
    printf("Is it socially acceptable? : %s\n",d.s.socially_acceptable ? "YES" : "NO");
    printf("Is it financially acceptable? : %s\n",d.s.financially_viable ? "YES" : "NO");
    printf("Do you have aptitude? : %s\n",d.s.do_you_aptitude ? "YES" : "NO");
    printf("Do you like it? : %s\n",d.s.do_you_likeit ? "YES" : "NO");
    printf("Your Final Decision: %s\n", d.s.decision ? "YES" : "NO");
    
}
void print_conclusion_based_on_flags( union decision d)
{
    int temp = d.flags;
    int score = 0;
    while(temp)
    {
        if((temp & 1) == 1)
        {
            score++;
        }
        temp = temp >> 1;
    }
     printf("\nFlags Positive Count: %d\n", score);
    if(score==8){
        printf("Perfect!");
    }
    else if(score>=4){
        printf("Do It!");
    }
    else if(score>2){
        printf("Think carefully");
    }
    else{
        printf("Poor decision");
    }
}