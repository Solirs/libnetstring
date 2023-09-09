# libnetstring
Libnetstring is a simple header only C library for handling netstrings.  
To use it simply download libnetstring.h and #include it in your favourite source or header file.  

[netstring](https://en.wikipedia.org/wiki/Netstring) is a simple format for byte strings/arrays which prepends their length (see the [spec](https://cr.yp.to/proto/netstrings.txt)).  
Which can be useful for tasks such as TCP message framing.  

# Basic documentation
Netstrings are stored in a "netstring" struct along with their length.  
It contains the members "str" (the content) and len (the length of str, including ':' ',' and prepended length).  
```
typedef struct netstring{
	char* str;
	unsigned int len;
} netstring;
```

You can create a netstring from a char array using the lns_makenetstring function.  
```netstring lns_makenetstring(char str[], size_t size);```  

You can get a netstring's content with the lns_getstring(_) function.  
```char* lns_getstring(netstring nsr);```   
```char* lns_getstring_(char* buf);```  

Similarly, you can get its prepended length with lns_getlen(_).  
```int lns_getlen(char* buf);```  
```int lns_getlen_(netstring buf);```  

Example:  
```
void helloworldtest(){
	char b[13] = "hello world!";
	netstring a = lns_makenetstring(b, strlen(b)); 
	char* axa = lns_getstring(a);
	
	lns_printnetstring(a);
	printf("%s\n", axa);
	printf("%d\n", lns_getlen(a));
	free(axa);
	free(a.str);	
}
```
```
31 32 3a 68 65 6c 6c 6f 20 77 6f 72 6c 64 21 2c 
hello world!
12
```
