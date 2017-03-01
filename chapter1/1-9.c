/*************************************************************************
#	> File Name: 1-9.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 01 Mar 2017 01:22:31 AM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("uid = %d , gid = %d \n", getuid(), getgid());
	return 0;
}
