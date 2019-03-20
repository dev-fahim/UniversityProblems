// C Program to convert any base to any given base 
#include <stdio.h> 
#include <string.h> 

int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 

int toDeci(char *str, int base) 
{ 
    int len = strlen(str); 
    int power = 1; // Initialize power of base 
    int num = 0;  // Initialize result 
    int i; 

    for (i = len - 1; i >= 0; i--) 
    { 
        if (val(str[i]) >= base) 
        { 
           printf("\nInvalid Number \n"); 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
} 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; /* should be temp */
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; // should be temp 
    } 
} 

char* fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    strev(res); 
  
    return res; 
}

char* base_converter(char number[100], int number_base, int converted_base){
    int decimal_number = toDeci(number, number_base);
    char res[100];
    return fromDeci(res, converted_base, decimal_number);
}
  
int main() 
{ 
    int base, converted_base;
    char number[100];

    printf("\nEnter inputed number: ");
    scanf("%s", number);
    printf("Inputed number's base: ");
    scanf("%d", &base);
    printf("Converted number's base: ");
    scanf("%d", &converted_base);

    printf("\n%s (base %d) => %s (base %d) \n\n", number, base, base_converter(number, base, converted_base), converted_base);

    return 0; 
}
