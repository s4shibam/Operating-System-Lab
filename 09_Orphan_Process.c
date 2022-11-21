// Q. Create an orphan process (Use sleep() in child process)

/*
Note:
Orphan Process:
	An orphan process is a process whose parent has finished.
	Suppose P1 and P2 are two process such that P1 is the parent process and
	P2 is the child process of P1. Now, if P1 finishes before P2 finishes,
	then P2 becomes an orphan process.
	The following programs we will see how to create an orphan process.
*/
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
	
		// Child process will be in sleep for 5 secs 
		// in the meantime execution of the parent process will be completed.
		// Thus child process will become Orphan (parent has finished already)
		sleep(5);
		printf ("This is Child Process!\n");
		printf ("Child: Child Process pid: %d\n", getpid());
		printf ("Child: Parent Process pid: %d\n", getppid());	// It will print incorrect pid (parent process has terminated)
	}
	
	// Parent process
	else {
	
		sleep(2);	// Time to run "ps" command 
		printf ("This is Parent Process!\n");
		printf ("Parent: Parent Process pid: %d\n", getpid());
		printf ("Parent: Child Process pid: %d\n", f);
	}
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 9_Orphan_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Before fork!
	This is Parent Process!
	Parent: Parent Process pid: 2025
	Parent: Child Process pid: 2026
	s4shibam@SHIBAM:~/OS$ This is Child Process!
	Child: Child Process pid: 2026
	Child: Parent Process pid: 1
	^C
	s4shibam@SHIBAM:~/OS$ 
	
*/

/*
	Output: [using ps command]
	
	s4shibam@SHIBAM:~/OS$ gcc 9_Orphan_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out &
	[1] 2342
	s4shibam@SHIBAM:~/OS$ Before fork!
	ps
	PID TTY          TIME CMD
	2202 tty1     00:00:00 bash
	2342 tty1     00:00:00 a.out
	2343 tty1     00:00:00 a.out
	2344 tty1     00:00:00 ps
	s4shibam@SHIBAM:~/OS$ This is Parent Process!
	Parent: Parent Process pid: 2342
	Parent: Child Process pid: 2343
	ps
	PID TTY          TIME CMD
	2202 tty1     00:00:00 bash
	2343 tty1     00:00:00 a.out
	2345 tty1     00:00:00 ps
	[1]+  Done                    ./a.out
	s4shibam@SHIBAM:~/OS$ This is Child Process!
	Child: Child Process pid: 2343
	Child: Parent Process pid: 1
	^C
	s4shibam@SHIBAM:~/OS$  
*/
