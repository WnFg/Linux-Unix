#ifndef GETSTRFROMINT
#define GETSTRFROMINT

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int check(char uid[], char s[], int len)
{
	int len1 = strlen(uid) - 1, len2 = len;
	int i, j;
	for(i = 0; i + len1 < len2; i++){
		for(j = 0; j <= len1; j++){
			if(uid[j] != s[i + j])
				break;
		}
		if(j == len1 + 1)
			return 1;
	}
	return 0;
}

char* getStrFromInt(int x)
{
	char* ans = (char*)malloc(100);
	int len = 0;
	while(x){
		ans[len++] = x%10 + '0';
		x /= 10;
	}
	ans[len] = '\0';
	int i;
	for(i = 0; i < len / 2; i++){
		char t = ans[i];
		ans[i] = ans[len - i - 1];
		ans[len - i - 1] = t;
	}
	return ans;
}

char* userNameFromId(uid_t uid)
{
	FILE* file = fopen("/etc/passwd", "r");
	char buf[1024];
	char* uid_str;
	uid_str = getStrFromInt(uid);
	char* userName = (char*)malloc(100);
	int i, j;
	
	while(fgets(buf, 1024, file) != NULL){
		j = 0;
		for(i = 2; i > 0; ){
			if(buf[j++] == ':')
				i--;
		}
		if(check(uid_str, buf + j, strlen(uid_str))){
			for(i = 0; buf[i] != ':'; i++)
				userName[i] = buf[i];
			fclose(file);
			return userName;
		}
	}
	fclose(file);
	return NULL;
}

#endif
