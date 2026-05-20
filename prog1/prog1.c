#include<stdio.h>
typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;
void read_details(int m,Employee employees[],const char* filename);
void delete_data(int n,int d,Employee employees[],const char* filename);
int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid number of employees.\n");
        return 0;
    }
    Employee employees[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter details of employee %d:\n", i);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    FILE *fp=fopen("employees.dat","wb");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    fwrite(employees, sizeof(Employee), n, fp);
    fclose(fp);
    int m;
    printf("Enter the index of the employee whose details you want to display: ");
    scanf("%d", &m);
    if(m<0||m>=n)
    {
        printf("Invalid index.\n");
        return 0;
    }
    read_details(m, employees, "employees.dat");
    printf("Employee details at index %d:\n", m);
    printf("ID: %d\n", employees[m].id);
    printf("Name: %s\n", employees[m].name);
    printf("Salary: %.2f\n", employees[m].salary);
    int d;
    printf("Enter the index of the employee whose details you want to delete: ");
    scanf("%d", &d);
    if(d<0||d>=n)
    {
        printf("Invalid index.\n");
        return 0;
    }
    delete_data(n, d, employees, "employees.dat");
    for(int i=0; i<n-1; i++)
    {
        printf("Employee details at index %d:\n", i);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
    }
    return 0;
}
void read_details(int m,Employee employees[],const char* filename){
    FILE *fp=fopen(filename,"rb");
    if(fp == NULL){
        printf("Error opening file.\n");
        return ;
    }
    fseek(fp,m*sizeof(Employee),SEEK_SET);
    fread(&employees[m],sizeof(Employee),1,fp);
    fclose(fp);
    
}
void delete_data(int n,int d,Employee employees[],const char* filename){
    FILE *fp=fopen(filename,"rb");
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    fread(employees, sizeof(Employee), d, fp);
    fseek(fp, (d+1)*sizeof(Employee), SEEK_SET);
    fread(&employees[d], sizeof(Employee), n-d-1, fp);
    fclose(fp);
    fp=fopen(filename,"wb");
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    fwrite(employees, sizeof(Employee), n-1, fp);
    fclose(fp);
}