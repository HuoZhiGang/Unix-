#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main()
{
	int fd;
	if((fd = creat("file.hole", 666)) < 0)
	{
		printf("creat error\n");
		return 1;
	}
	if(write(fd, buf1, 10) != 10)
	{
		printf("buf1 write error\n");
		return 2;
	}
	if(lseek(fd, 1000*1024*1024, SEEK_SET) == -1)
	{
		printf("lseek error");
		return 3;
	}
	// offset now = 16384
	//

	if(write(fd, buf2, 10)!=10)
	{
		printf("buf2 write error\n");
		return 4;
	}

	return 0;
}
