#include <stdio.h>
#include <string.h>

// Function to compare two strings lexicographically (from scratch)
int compareStrings(const char *str1, const char *str2) {
    int i = 0;
    
    // Compare characters one by one
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1; // str1 is lexicographically smaller
        } else if (str1[i] > str2[i]) {
            return 1; // str1 is lexicographically greater
        }
        i++;
    }
    
    // If one string ends before the other, the shorter string is considered smaller
    if (str1[i] == '\0' && str2[i] != '\0') {
        return -1; // str1 is lexicographically smaller
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        return 1; // str1 is lexicographically greater
    }
    
    return 0; // Both strings are equal
}

// Bubble Sort function that sorts an array of strings
void bubbleSort(char arr[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (compareStrings(arr[j], arr[j+1]) > 0) {
                // Swap the strings if they are in the wrong order
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

// Function to print the array of strings
void printArray(char arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n;

    // Get the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Declare an array of strings
    char arr[n][100];

    // Input the strings
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    // Perform the bubble sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Strings in lexicographical order:\n");
    printArray(arr, n);

    return 0;
}
