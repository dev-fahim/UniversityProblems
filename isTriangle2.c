#include<stdio.h>
int main()
{
    float a, b, c, min1, min2, max;
    scanf("%f%f%f", &a, &b, &c);
    if(a > 0 && b > 0 && c > 0) {
        if(a>b&&a>c) {
            min1 = b;
            min2 = c;
            max = a;
        }else if(b>a&&b>c) {
            min1 = a;
            min2 = c;
            max = b;
        }else if(c>a&&c>b) {
            min1 = a;
            min2 = b;
            max = c;
        }
        if(min1+min2>max) {
            printf("This is a TRIANGLE\n");
        }else{
            printf("This is not a TRIANGLE\n");
        }
    }else{
        printf("This is not a TRIANGLE\n");
    }
    return 0;
}
