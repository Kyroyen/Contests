#include <stdio.h>

int main(){
    int n;
    printf("Enter value of n:");
    scanf("%d", &n);

    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int dia1, dia2;
    dia1 = dia2 = 0;

    //Just iterate through both the diagonals
    for(int i=0;i<n;i++){
        dia1 += arr[i][i];
        dia2 += arr[i][n-i-1];
    }

    printf("Diagonal 1: %d \nDiagonal 2:%d", dia1, dia2);
    return 0;
}