/*************************************************************************
#	> File Name: 1-4.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: 2017年03月01日 星期三 00时08分40秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main()
{
	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) >0 )
	{
		if(write(STDOUT_FILENO,buf, n) != n)
			printf("  write  error \n");
	}
	if(n < 0)
	{
		printf("read error \n");
	}
	return 0;
}
