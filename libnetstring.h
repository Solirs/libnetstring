#ifndef LIBNETSTRING
#define LIBNETSTRING
#include <stdio.h>
#include <stdlib.h>

unsigned int lns_makenetstring(char str[], char* buf, size_t size){
	unsigned int index;
	index = sprintf(buf, "%ld", size);
	buf[index] = ':';
	index++;
	for (int i = 0; i < size; i++){
		buf[index] = str[i];
		index++;
	}
	buf[index] = ',';
	return index + 1;
}

void lns_printnetstring(char* buf, size_t bufsize){
	for (int i = 0; i < bufsize; i++){
		printf("%x ", buf[i]);
	}	
	printf("\n");
}

char* lns_getnetstring(char* buf){
	
	
	char size[4] = {0, 0, 0, 0};
	int index = 0;
	while (buf[index] != 58){
		size[index] = buf[index];
		index++;
	}

	index++;
	int sz = 0;
	sscanf(size, "%d", &sz);
	char* ret = malloc(sz + index + 1);	
	for (int i = 0; i < sz; i++){
		ret[i] = buf[index];
		index++;
	}
	return ret;
	
}
#endif
