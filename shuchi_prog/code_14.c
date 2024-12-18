#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *arr; //Notice how the array is declared, it's a pointer to the memory location, currently pointing nowhere
    float sum=0, avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //Allocate the space using malloc function
    //malloc returns a memory pointer of VOID type, 
    //hence, type casting into (int*) is required for arr;
    arr = (int*) malloc(n*sizeof(int));

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Add each element to sum
    }
    
    avg = sum / n;

    // Output the average
    printf("The average of the entered integers is: %.2f\n", avg);

    // Free the dynamically allocated memory using free()
    free(arr);

    return 0;
}