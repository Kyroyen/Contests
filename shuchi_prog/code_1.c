#include <stdio.h>
#include <stdlib.h>

int power(int x, int n){
    // multiply x, n times to get value of x^n
    int ans = 1;
    for(int i=0; i<n; i++){
        ans *= x;
    }
    return ans;
}

int digits(int x){
    // count the number of digits in x
    int count = 0;
    while(x > 0){
        x /= 10;
        count++;
    }
    return count;
}

int calculate_armstrong_value(int x){
    // calculate the value of sum x^digits(x)
    int n = digits(x);
    int sum = 0;
    while(x>0){
        int last_digit = x%10;
        sum += power(last_digit, n);
        x /= 10;
    }

    return sum;
}

int main(){
    int num;
    scanf("%d", &num);
    int armstrong_value = calculate_armstrong_value(num);
    printf("%d\n", armstrong_value);
    //compare values
    printf("%s", (armstrong_value==num)?"Is":"Is NOT");
    return 0;
}