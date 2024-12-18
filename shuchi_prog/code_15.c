#include <stdio.h>
#include <string.h>

// Define a union to store either marks or percentage
union StudentRecord {
    int marks[5];      // Array to store marks of 5 subjects
    float percentage;  // Store percentage
};

// Define a structure to store student details
struct Student {
    char name[50];
    int rollNumber;
    union StudentRecord record; // Union to store either marks or percentage
    int choice; // To store user's preference (1 for marks, 2 for percentage)
};

void inputStudentDetails(struct Student *student){
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    printf("Enter choice: ");
    scanf("%d", &student->choice);

    //Take user's choice if in percent or marks?
    if(student->choice==1){
        printf("Enter marks of 5 subjects: ");
        for(int i=0;i<5;i++){
            printf("Subject %d: ", i + 1);
            scanf("%d", &student->record.marks[i]);
        }
    } else if (student->choice==2){
        printf("Enter percentage: ");
        scanf("%f", &student->record.percentage);
    } else{
        printf("Invalid choice!\n");
    }

}

void printStudent(struct Student student){
    printf("\nStudent Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);

    // Based on user's choice, display marks or percentage
    if (student.choice == 1) {
        printf("Marks for 5 subjects:\n");
        for (int i = 0; i < 5; i++) {
            printf("Subject %d: %d\n", i + 1, student.record.marks[i]);
        }
    } else if (student.choice == 2) {
        printf("Percentage: %.2f\n", student.record.percentage);
    }
}

int main(){
    struct Student stud;
    inputStudentDetails(&stud);
    printStudent(stud);
}