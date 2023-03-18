#include <stdio.h>
#include <string.h>

struct student {
    char name[100];
    int age;
    char addr[100];
    char phone_num[12];
    float gpa;
};

int main() {
    struct student std[5];
    int i, j;
    struct student temp;
    
    // prompt the user to enter details for each student
    for (i = 0; i < 5; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(std[i].name, sizeof(std[i].name), stdin);
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &std[i].age);
        getchar(); // consume the newline character left by scanf
        printf("Enter the address of student %d: ", i + 1);
        fgets(std[i].addr, sizeof(std[i].addr), stdin);
        printf("Enter the phone number of student %d: ", i + 1);
        fgets(std[i].phone_num, sizeof(std[i].phone_num), stdin);
        printf("Enter the GPA of student %d: ", i + 1);
        scanf("%f", &std[i].gpa);
        getchar(); // consume the newline character left by scanf
        printf("\n");
    }
    
    // sort the students by GPA in descending order
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (std[i].gpa < std[j].gpa) {
                temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
    
    // display the sorted student details
    printf("Student Details (sorted by GPA in descending order):\n");
    for (i = 0; i < 5; i++) {
        printf("Name: %s", std[i].name);
        printf("Age: %d\n", std[i].age);
        printf("Address: %s", std[i].addr);
        printf("Phone Number: %s", std[i].phone_num);
        printf("GPA: %.2f\n", std[i].gpa);
        printf("\n");
    }
    
    return 0;
}

