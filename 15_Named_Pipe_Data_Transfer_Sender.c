// Q. Transfer message from program1 to read by program2 (Named Pipe)

// program1 --> 15_Named_Pipe_Data_Transfer_Sender.c (Sender)
// program2 --> 15_Named_Pipe_Data_Transfer_Receiver.c (Receiver)

// **Note: This program or transfer will work only if both the sender and receiver is available

// Sender
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int res;
	char sMsg[50] = "This data has been transferred via nPipe1";
	
	// Create named pipe
	res = mkfifo("nPipe1", 0777);
	printf ("Named pipe created successfully!\n");
	
	// Open named pipe
	res = open("nPipe1", O_WRONLY);
	
	// Write message
	write(res, sMsg, sizeof(sMsg));
	printf ("Sender: Message sent from process pid: %d.\n", getpid());
}


/*
	Output: 
	
	s4shibam@SHIBAM:~/OS$ gcc 15_Named_Pipe_Data_Transfer_Sender.c -o send.out
	s4shibam@SHIBAM:~/OS$ gcc 15_Named_Pipe_Data_Transfer_Receiver.c -o receive.out
	s4shibam@SHIBAM:~/OS$ ./send.out & ./receive.out
	[1] 832
	Named pipe created successfully!
	Sender: Message sent from process pid: 832.
	Receiver: Message received to process pid: 833.
	Receiver says: This data has been transferred via nPipe1
	[1]+  Done                    ./send.out
	s4shibam@SHIBAM:~/OS$ 
*/
