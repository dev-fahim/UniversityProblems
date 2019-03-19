// C Program to convert decimal to any given base 
#include <stdio.h> 
#include <string.h> 

int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
  
// Function to convert a number from given base 'b' 
// to decimal 
int toDeci(char *str, int base) 
{ 
    int len = strlen(str); 
    int power = 1; // Initialize power of base 
    int num = 0;  // Initialize result 
    int i; 
  
    // Decimal equivalent is str[len-1]*1 + 
    // str[len-1]*base + str[len-1]*(base^2) + ... 
    for (i = len - 1; i >= 0; i--) 
    { 
        // A digit in input number must be 
        // less than number's base 
        if (val(str[i]) >= base) 
        { 
           printf("Invalid Number"); 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
} 
// To return char for a value. For example '2' 
// is returned for 2. 'A' is returned for 10. 'B' 
// for 11 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
  
// Utility function to reverse a string 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
  
// Function to convert a given decimal number 
// to a base 'base' and 
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
  
    // Reverse the result 
    strev(res); 
  
    return res; 
} 
  
// Driver program 
int main() 
{ 
    int inputNum, base = 6; 
    char res[100]; 
    char str[100];  
    printf("Please enter desired input (in Base6): ");
    scanf("%s", str);
    inputNum = toDeci(str, base);
    printf("\n");
    printf("Let me calculate!!! It's a 'Piece of Cake'!!! \n");
    printf("\n");
    printf("\t %s is in Base-2: %s\n", str, fromDeci(res, 2, inputNum));
    printf("\t %s is in Base-10: %s\n", str, fromDeci(res, 10, inputNum));
    printf("\t %s is in Base-8: %s\n", str, fromDeci(res, 8, inputNum));
    printf("\t %s is in Base-16: %s\n", str, fromDeci(res, 16, inputNum));
    printf("\t %s is in Base-7: %s\n", str, fromDeci(res, 7, inputNum));
    printf("\n");
    printf("Thank you!!!\n");
    return 0; 
}
