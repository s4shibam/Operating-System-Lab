// Q. Create a child process using fork() and then use sleep() in parent process

#include <stdio.h>
#include <unistd.h>

int main()
{
	int f;
	
	printf ("Before fork!\n");
	f = fork();	
	
	// The creation of the process was unsuccessfull
	if (f < 0){
		
		printf ("Error occured!\n");
	}
	
	// Child process
	else if (f == 0){
	
		
		printf ("This is Child Process!\n");
		printf ("Child: Child Process pid: %d\n", getpid());
		printf ("Child: Parent Process pid: %d\n", getppid());
	}
	
	// Parent process
	else {
	
		// Parent process will be in sleep for 5 secs 
		// in the meantime execution of the child process will be completed
		sleep(5);
		printf ("This is Parent Process!\n");
		printf ("Parent: Parent Process pid: %d\n", getpid());
		printf ("Parent: Child Process pid: %d\n", f);
	}
	
	// This part will be executed by both child & parent 
	printf ("This is common!\n");
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 8_Sleep_In_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Before fork!
	This is Child Process!
	Child: Child Process pid: 2154
	Child: Parent Process pid: 2153
	This is common!
	This is Parent Process!
	Parent: Parent Process pid: 2153
	Parent: Child Process pid: 2154
	This is common!
	s4shibam@SHIBAM:~/OS$
*/
