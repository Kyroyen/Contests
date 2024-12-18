#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    // Initialize the largest and second-largest variables
    int largest, secondLargest;
    largest = secondLargest = -1;

    // Traverse the array to find the largest and second-largest elements
    for (int i = 0; i < n; i++) {
        if (a[i] >= largest) {
            secondLargest = largest; // Update second-largest
            largest = a[i];        // Update largest
        } else if (a[i] >= secondLargest && a[i] < largest) {
            secondLargest = a[i];  // Update second-largest
        }
    }

    printf("Second largest is: %d", secondLargest);
    return 0;
}