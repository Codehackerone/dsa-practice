#include <stdio.h>
#include <stdlib.h>

int toh(int n){
    if(n==0)return 0;
    return toh(n-1) + 1 + toh(n-1);
}

int main(){
    int n;    
    printf("Enter the number of towers: ");
    scanf("%d", &n);
    printf("The number of moves required is %d\n", toh(n));
    return 0;
}
