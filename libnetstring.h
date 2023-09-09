#ifndef LIBNETSTRING
#define LIBNETSTRING
#include <stdio.h>
#include <stdlib.h>

typedef struct netstring{
	char* str;
	unsigned int len;
} netstring;

netstring lns_makenetstring(char str[], size_t size){
	char* buf = malloc(4);
	unsigned int index;
	index = sprintf(buf, "%ld", size);
	buf = realloc(buf, index + size + 2);
	buf[index] = ':';
	index++;
	for (int i = 0; i < size; i++){
		buf[index] = str[i];
		index++;
	}
	buf[index] = ',';
	
	netstring ret = {buf, index + 1};
	return ret;
}

void lns_printnetstring(char* buf, size_t bufsize){
	for (int i = 0; i < bufsize; i++){
		printf("%x ", buf[i]);
	}	
	printf("\n");
}

void lns_printnetstring_(netstring nsr){
	lns_printnetstring(nsr.str, nsr.len);
}

char* lns_getstring(char* buf){
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
// Method overload if you want to pass a netstring struct
char* lns_getstring_(netstring nsr){
	return lns_getstring(nsr.str);
}

int lns_getlen(char* buf){
	char size[4] = {0, 0, 0, 0};
	int index = 0;
	while (buf[index] != 58){
		size[index] = buf[index];
		index++;
	}

	index++;
	int sz = 0;
	sscanf(size, "%d", &sz);
	return sz;	
}

int lns_getlen_(netstring buf){
	return lns_getlen(buf.str);
}
#endif
