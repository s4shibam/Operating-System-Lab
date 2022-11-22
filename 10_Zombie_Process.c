// Q. Create an zombie process

/*
Note:
Zombie Process:
	A zombie is a process which has terminated but its entry still exists in the process table
	until the parent terminates normally or calls wait().
	Suppose you create a child process and the child finishes before the parent process does.
	If you run the ps command before the parent gets terminated the output of ps will show
	the entry of a zombie process(denoted by defunct).
	This happens because the child is no longer active but its exit code needs to be stored in case
	the parent subsequently calls wait.
*/
	
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int f;
	
	printf ("Before fork!\n");
	f = fork();	
	
	// The creation of the process was unsuccessful
	if (f < 0){
		
		printf ("Error occurred!\n");
	}
	
	// Child process
	else if (f == 0){
	
		
		printf ("This is Child Process!\n");
		printf ("Child: Child Process pid: %d\n", getpid());
		printf ("Child: Parent Process pid: %d\n", getppid());
	}
	
	// Parent process
	else {
	
		// Helps to avoid zombie process creation situation
		wait(NULL);
		
		// Parent process will be in sleep for 5 secs
		// Time needed to run ps command
		sleep(5);
		printf ("This is Parent Process!\n");
		printf ("Parent: Parent Process pid: %d\n", getpid());
		printf ("Parent: Child Process pid: %d\n", f);
	}
}

/*
	Output: [when Zombie process is created - wait() not called]
	
	s4shibam@SHIBAM:~/OS$ gcc 10_Zombie_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out &
	[1] 2617
	s4shibam@SHIBAM:~/OS$ Before fork!
	This is Child Process!
	Child: Child Process pid: 2618
	Child: Parent Process pid: 2617
	ps
	PID TTY          TIME CMD
	2202 tty1     00:00:00 bash
	2617 tty1     00:00:00 a.out
	2618 tty1     00:00:00 a.out <defunct>
	2619 tty1     00:00:00 ps
	s4shibam@SHIBAM:~/OS$ This is Parent Process!
	Parent: Parent Process pid: 2617
	Parent: Child Process pid: 2618
	^C
	[1]+  Done                    ./a.out
	s4shibam@SHIBAM:~/OS$
	
	** <defunct> denotes the Zombie Proces
*/

/*
	Output: [after avoiding Zombie process - wait() called]
	
	s4shibam@SHIBAM:~/OS$ gcc 10_Zombie_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out &
	[1] 2658
	s4shibam@SHIBAM:~/OS$ Before fork!
	This is Child Process!
	Child: Child Process pid: 2659
	Child: Parent Process pid: 2658
	ps
	PID TTY          TIME CMD
	2202 tty1     00:00:00 bash
	2658 tty1     00:00:00 a.out
	2660 tty1     00:00:00 ps
	s4shibam@SHIBAM:~/OS$ This is Parent Process!
	Parent: Parent Process pid: 2658
	Parent: Child Process pid: 2659
	^C
	[1]+  Done                    ./a.out
	s4shibam@SHIBAM:~/OS$
*/
