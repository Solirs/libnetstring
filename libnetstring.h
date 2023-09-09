/*
 *  Copyright 2023 Solirs
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at

 *  http://www.apache.org/licenses/LICENSE-2.0

 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License. 
 * 
 * 	Written by Solirs (github.com/Solirs), if this was useful to you please send some love at my email or telegram ;).
 * 
*/

#ifndef LIBNETSTRING
#define LIBNETSTRING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct netstring{
	char* str;
	unsigned int len;
} netstring;

netstring lns_makenetstring(char* str, size_t size){
	char* buf = malloc(4);
	unsigned int index;
	index = sprintf(buf, "%ld", size);
	buf = realloc(buf, index + size + 2);
	buf[index] = ':';
	index++;
	memcpy(buf + index, str, size);
	index += size;
	buf[index] = ',';
	
	netstring ret = {buf, index + 1};
	return ret;
}

void lns_printnetstring_(char* buf, size_t bufsize){
	for (int i = 0; i < bufsize; i++){
		printf("%x ", buf[i]);
	}	
	printf("\n");
}

void lns_printnetstring(netstring nsr){
	lns_printnetstring_(nsr.str, nsr.len);
}

char* lns_getstring_(char* buf){
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
	memcpy(ret, buf + index, sz);
	return ret;	
}
// Method overload if you want to pass a netstring struct
char* lns_getstring(netstring nsr){
	return lns_getstring_(nsr.str);
}

int lns_getlen_(char* buf){
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

int lns_getlen(netstring buf){
	return lns_getlen_(buf.str);
}
#endif
