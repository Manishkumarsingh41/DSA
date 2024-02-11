#include<stdio.h>

int square (int n){
    printf("%d Byte\n", sizeof(int));
    printf("%d Byte\n", sizeof(n));
    return n*n;
}
main(){
    int num;
    printf("Enter a Number:");
    scanf("%d", &num);
    int value = square(num);
    printf("%d", value);
}