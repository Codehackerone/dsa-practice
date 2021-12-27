#include<iostream>

int toh(int n){
   if(n==0){
    return 0;
   }
   return toh(n-1) + 1 + toh(n-1);
}

void printSteps(int n, char s, char d, char h){
   if(n==0){
    return;
   }
    printSteps(n-1,s,h,d);
    printf("Moving disk %d from %d to %d",n,s,d);
    printSteps(n-1,h,d,s);
}

int main(){
  int n;
  printf("Enter no of disks: ");
  scanf("%d",&n);
  printSteps(n,'A','C','B');
  return 0;
}
