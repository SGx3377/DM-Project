// Code for Josephus Problem using Modular Arithmetic And Recursion
#include<stdio.h>

int josephus(int n,int k){
    if(n==1){
        return 1;
    }
    else{
        return (josephus(n-1,k)+k-1)%n+1;
    }
}

int main(){
    int n,k;
    printf("Enter the number of people in circle: ");
    scanf("%d",&n);
    printf("Enter the elimination step: ");
    scanf("%d",&k);
    int last = josephus(n,k);
    printf("The survivor is: %d\n",last);
    return 0;
}