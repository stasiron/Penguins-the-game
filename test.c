#include <stdio.h>
#include <stdlib.h>

#define GREEN   "\033[32m";


int main(){
    printf("test");
    printf("%s test", GREEN);
	printf("%s%35.35s< 0>", CYAN,"");  
    return 0;
}