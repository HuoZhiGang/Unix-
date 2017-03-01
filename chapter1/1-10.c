/*************************************************************************
#	> File Name: 1-7.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 01 Mar 2017 12:33:40 AM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#define MAXLINE 4096 

static void  sig_int(int); // our signal-catching function

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT, sig_int) == SIG_ERR)
	{
		printf("signal error");
		return 4;
	}
	printf("%%");// printf prompt (printf requires %% to print %)
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0'; // replace new line witg null

		if ((pid = fork()) < 0)
		{
			printf("fork error\n");
			return 1;
		}
		else if(pid == 0)
		{// child 
			execlp(buf, buf , NULL);
			printf("couldn't execute: %s \n", buf);
			return 2;
		}

		if( (pid = waitpid(pid, &status, 0) < 0))
		{// father

			printf("waitpid error");
			return 3;
		}
		printf("%% ");

	}
	return 0;
}

void sig_int(int signo)
{
	printf("interrupt\n %%");
}
