#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t cPID = fork();

	if(cPID < 0)
	{
		perror("fork() error");
		exit(-1);
	} 
	if(cPID != 0)
	{
		printf("I'm the parent proces: %d, The child process is: %d\n",getpid(),cPID);
		sleep(10);
		printf("Child: %d, was a zombie\n", cPID);
	}
	else{
		printf("I'm the child %d, my parent is %d\n",getpid(), getppid());
		exit(0);
	}
	return 0;
}