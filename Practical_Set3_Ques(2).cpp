#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	//Child process
	pid = fork();
	if(pid<0){
		printf(stderr,"Fork Failed");
		return 1;
	}
	else if (pid==0){
		exceclp("/bin/ls","ls",NULL);
	}
	else{
		printf("Parent process.")
	}
	return 0;
}
