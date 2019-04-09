#include<stdio.h>
int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if(a+b > c && c+b > a && a+c > b && a > 0 && b > 0 && c > 0){
        printf("This is a TRIANGLE\n");
    }else{
        printf("This is NOT a TRIANGLE\n");
    }
    return 0;
}
