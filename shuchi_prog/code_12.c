#include <stdio.h>
#include <stdlib.h>

struct Students{
    int roll;
    char name[20];
    int marks;
};

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Students stud[n]; //Struct array declaration


    // Take inputs
    for(int i=0; i<n; i++){
        printf("Enter roll number of student %d: ", i+1);
        scanf("%d", &stud[i].roll);
        printf("Enter name of student %d: ", i+1);
        scanf("%s", stud[i].name);
        printf("Enter marks of student %d: ", i+1);
        scanf("%d", &stud[i].marks);
    }

    int maxiStud = 0; //Set the index for the highest marks initially to 0
    // iterate through it, find the highest marks index
    for(int i=0; i<n; i++){
        if(stud[i].marks > stud[maxiStud].marks){ //If any index higher marks, set the index to that
            maxiStud = i;
        }
    }

    printf("RollNo: %d\n", stud[maxiStud].roll);
    printf("name: %s\n", stud[maxiStud].name);
    printf("marks: %d\n", stud[maxiStud].marks);

    return 0;

}