/*************************************************************************
#	> File Name: 3-11.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 02 Mar 2017 12:47:07 AM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> // atoi()
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int val;

	if(argc != 2)
	{
		printf("usage: 3-11 <descriptor#>");
		return 1;
	}

	if((val = fcntl(atoi(argv[1]), F_GETFL ))<0)
	{
		printf("fcntl error for fd %d\n", atoi(argv[1]));
		return 2;
	}

	switch( val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("write read\n");
			break;
		default:
			printf("unknow access mode \n");
			break;
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblockint");
	if(val & O_SYNC)
		printf(",synchronous writes");

#if !defined(_POSIX_C_SOURCE)&&defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if(val & O_FSYNC)
		printf(",synchronous writes");
#endif
	putchar('\n');
	return 0;
}
