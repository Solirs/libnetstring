#include "libnetstring.h"
#include <string.h>

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
int main(){
	helloworldtest();

	return 0;
}
