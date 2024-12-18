#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char s[n];

    printf("Enter string length: ");
    scanf("%d", &n);
    printf("Enter a string: ");
    scanf("%s", s);

    // Reverse a string by swapping characters.
    // Iterates from the start of the string to the middle (`i < n/2`) and 
    // swaps the character at index `i` with the character at index `n - i - 1`. 
    // This continues until the middle of the string is reached.

    for(int i=0; ((i*2)<n); i++){
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }

    printf("%s", s);
    return 0;
}