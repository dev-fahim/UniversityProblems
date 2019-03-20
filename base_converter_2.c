#include <stdio.h>

int val(char c) { 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
    	printf("%d\n", 'B');
        return (int)c - 'A' + 10; 
} 

int main(){
	printf("%d\n", val('B'));
	return 0;
}