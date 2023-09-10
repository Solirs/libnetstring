#include "libnetstring.h"
#include <string.h>
typedef struct student {
	int average;
	char* name;
} student;

void helloworldtest(){
	char b[13] = "hello world!";
	netstring a = lns_makenetstring(b, strlen(b)); 
	char* axa = lns_getstring(a);
	
	lns_printnetstring(a);
	printf("%s\n", axa);
	printf("%d\n", lns_getlen(a));

	/*
	 * Expected output:
	 * 31 32 3a 68 65 6c 6c 6f 20 77 6f 72 6c 64 21 2c
	 * hello world!
	 * 12
	*/
	
	free(axa);
	free(a.str);	
}
void structtest(){
	student std;
	std.average = 18;
	std.name = "Marianne";
	char* b = malloc(sizeof(student));
	memcpy(b, &std, sizeof(student));
	
	netstring a = lns_makenetstring(b, sizeof(student));
	char* axa = lns_getstring(a);
	
	student abc;
	memcpy(&abc, axa, sizeof(student));
	
	printf("%s\n", abc.name);
	printf("%d\n", abc.average);
	
	/*
	 * Expected output:
	 * Marianne
	 * 18
	*/	
	free(b);
	free(axa);
	free(a.str);
	
}

void recursivetest(){
	char b[13] = "hello world!";
	netstring a = lns_makenetstring(b, strlen(b)); 
	char* axa = lns_getstring(a);	
	
	netstring c = lns_makenetstring(a.str, a.len); 
	lns_printnetstring(c);
	char* axc = lns_getstring(c);
	printf("%s\n", axc);
		
	/* 
	 * Expected output:
	 * 31 36 3a 31 32 3a 68 65 6c 6c 6f 20 77 6f 72 6c 64 21 2c 2c 
	 * 12:hello world!,
	*/
	free(axc);
	free(axa);
	free(a.str);
	free(c.str);
}
int main(){
	helloworldtest();
	structtest();
	recursivetest();
	return 0;
}
