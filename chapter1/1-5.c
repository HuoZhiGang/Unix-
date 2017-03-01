/*************************************************************************
#	> File Name: 1-5.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 01 Mar 2017 12:24:11 AM PST
 ************************************************************************/

#include<stdio.h>

int main()
{
	int c;
	while((c = getc(stdin)) != EOF)
		if(putc(c, stdout) == EOF)
			printf("putc error\n");

	if(ferror(stdin))
		printf("input error\n");
	return 0;
}

