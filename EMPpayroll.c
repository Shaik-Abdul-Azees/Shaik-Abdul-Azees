#include <stdio.h>
#define MAX_EMPLOYEES 100
struct Employee {
    int id;
    char name[50];
    float hoursWorked;
    float payRate;
};
void inputEmployeeData(struct Employee* emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp->name); 
    printf("Enter Hours Worked: ");
    scanf("%f", &emp->hoursWorked);
    printf("Enter Pay Rate: ");
    scanf("%f", &emp->payRate);
}
float calculateSalary(struct Employee emp) {
    return emp.hoursWorked * emp.payRate;
}
int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numberOfEmployees, i;
    printf("Enter number of employees: ");
    scanf("%d", &numberOfEmployees);
    for (i = 0; i < numberOfEmployees; i++) {
        printf("\nEntering details for employee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
    }
    printf("\nEmployee Payroll Details:\n");
    printf("ID\tName\t\tSalary\n");
    printf("------------------------------------------\n");
    for (i = 0; i < numberOfEmployees; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, calculateSalary(employees[i]));
    }
    return 0;
}
