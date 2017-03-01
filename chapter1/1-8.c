/*************************************************************************
#	> File Name: 1-8.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 01 Mar 2017 01:08:52 AM PST
 ************************************************************************/

#include<stdio.h>
#include <errno.h>
int main(int argc, char* argv[])
{
	fprintf(stderr, "EACCES:%s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}

