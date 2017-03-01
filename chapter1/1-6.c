/*************************************************************************
#	> File Name: 1-6.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 01 Mar 2017 12:29:32 AM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	printf("hello wrold from process ID %ld \n", (long)getpid());
	return 0;
}
