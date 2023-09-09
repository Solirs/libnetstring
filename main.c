#include "libnetstring.h"
#include <string.h>

struct student{
	int average;
	char* name;
};

int main(){
	char b[2];
	b[0] = (char) 100;
	
	b[1] = (char) 2;
	char* c = malloc(20);
	unsigned int a = lns_makenetstring(b, c, 2); 
	lns_printnetstring(c, a);
	char* axa = lns_getnetstring(c);



	free(c);
	free(axa);
	return 0;
}
