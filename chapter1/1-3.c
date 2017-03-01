/*************************************************************************
#	> File Name: 1-3.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: 2017年02月28日 星期二 23时53分36秒
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc, char *argv[] )
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2)
	{
		printf("usage:ls directory_name");
		return 1;
	}

	if( (dp = opendir(argv[1]))== NULL )
		printf("can't open %s", argv[1]);
	while( (dirp = readdir(dp))!= NULL)
		printf("%s\n",dirp->d_name);
	closedir(dp);

	return 0;
}
