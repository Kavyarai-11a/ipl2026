#include<stdio.h>
typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;
void seek_position(int n,int arr[],Employee employees[],const char*filename);
void read_details(int m,int arr[],Employee employees[],const char* filename);
int main(){
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid number of employees.\n");
        return 0;
    }
    Employee employees[n];
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter details of employee %d:\n", i);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    seek_position(n, arr,employees, "employees.txt");
    int m;
    printf("Enter the index of the employee whose details you want to display: ");
    scanf("%d", &m);
    if(m<0||m>n)
    {
        printf("Invalid index.\n");
        return 0;
    }
    read_details(m,arr,employees, "employees.txt");
    return 0;
}
void seek_position(int n,int arr[],Employee employees[],const char*filename){
    FILE *fp=fopen("employees.txt","w");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    for(int i=0; i<n; i++) 
    {
    fprintf(fp, "%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    arr[i+1] = ftell(fp);   
    }
    fclose(fp);
}
void read_details(int m,int arr[],Employee employees[],const char* filename){
    FILE *fp=fopen(filename,"r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fseek(fp, arr[m], SEEK_SET);
    fscanf(fp, "%d %s %f", &employees[m].id, employees[m].name, &employees[m].salary);
    fclose(fp);
    printf("Employee details at index %d:\n", m);
    printf("ID: %d\n", employees[m].id);
    printf("Name: %s\n", employees[m].name);
    printf("Salary: %.2f\n", employees[m].salary);
}
