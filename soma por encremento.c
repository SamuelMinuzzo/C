#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_rec(int *num1, int num2){
    if(num1==0){
        return num2;
    }else if(num2==0){
        return *num1;
    }else if(num2 == 1){
        return *num1 = *num1 + 1;
    }else if(num2 % 2 == 0){
        soma_rec(num1, num2/2);
        soma_rec(num1, num2/2);
    }else{
        soma_rec(num1, (num2+1)/2);
        soma_rec(num1, (num2-1)/2);
    }
    return *num1;
}

int main() {
    int n, *v, num1,num2,i;

    scanf("%d",&n);
    v = malloc(sizeof(int)*n);

    for(i = 0; i < n; i++){
       scanf("%d %d",&num1,&num2);
        v[i]=soma_rec(&num1,num2);
    }

    for(i = 0; i < n; i++)
        printf("%d\n",v[i]);

    return 0;
}
