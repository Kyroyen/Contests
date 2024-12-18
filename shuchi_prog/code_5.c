#include <stdio.h>

int main(){
    int n;
    printf("Enter the length:");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements:");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int moves;
    printf("\nEnter the move to right:");
    scanf("%d", &moves);

    //normalise moves to length of the array
    //if the length of array == no. of moves, this case is equal to taking no moves
    //only remainder required
    moves %= n; //Shorthand operator

    // Intial array: [1, 2, 3, 4, 5, 6]
    // moves = 3
    // [4, 5, 6] + [1, 2, 3]
    
    int temp[n];
    for (int i = 0; i < moves; i++) {
        temp[i] = a[n - moves + i];
    }

    // Shift the remaining elements to the right in the original array
    for (int i = n - 1; i >= moves; i--) {
        a[i] = a[i - moves];
    }

    // Copy the elements from temp back to the array
    for (int i = 0; i < moves; i++) {
        a[i] = temp[i];
    }

    for(int i=0; i<n; i++){
        printf("%d, ", a[i]);
    }

    return 0;
    
}