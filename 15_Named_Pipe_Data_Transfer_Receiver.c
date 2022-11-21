// Q. Transfer message from program1 to read by program2 (Named Pipe)

// program1 --> 15_Named_Pipe_Data_Transfer_Sender.c (Sender)
// program2 --> 15_Named_Pipe_Data_Transfer_Receiver.c (Receiver)
	
// **Note: This program or transfer will work only if both the sender and receiver is availale

// Receiver
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int res;
	char rMsg[50];
	
	// Open named pipe
	res = open("nPipe1", O_RDONLY);
	
	// Read message
	read(res, rMsg, sizeof(rMsg));
	
	printf ("Receiver: Message received to process pid: %d.\n", getpid());
	printf ("Receiver says: %s\n", rMsg);
}

/*
	Output: 
	s4shibam@SHIBAM:~/OS$ gcc 15_Named_Pipe_Data_Transfer_Sender.c -o send.out
	s4shibam@SHIBAM:~/OS$ gcc 15_Named_Pipe_Data_Transfer_Receiver.c -o receive.out
	s4shibam@SHIBAM:~/OS$ ./send.out & ./receive.out
	[1] 832
	Named pipe created succesfully!
	Sender: Message sent from process pid: 832.
	Receiver: Message received to process pid: 833.
	Receiver says: This data has been transferred via nPipe1
	[1]+  Done                    ./send.out
	s4shibam@SHIBAM:~/OS$ 
*/
