// Q. Write a program using open() system call to read data from (max 50 char)
// the standard input device and append them into existing file �Text3.txt�

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

	int len, fd, fd1;
	char ch[50];
	char append[50];

	// Read maximum 50 bytes from standard input device (0 --> stdin)
	// & store in buffer (ch)
	len = read(0, append, 50);

	printf("Total bytes read: %d.\n", len);

	// Existing file is opened in append mode and
	// the file descriptor is saved in integer fd
	// Pipe symbol (|) is used to separate O_WRONLY and O_APPEND
	fd = open("Text3.txt", O_WRONLY | O_APPEND);

	// Append in the Text3.txt file from the buffer
	write(fd, append, len);
	printf("\nTotal bytes appended: %d.\n", len);
}

/*
	Output:

	s4shibam@SHIBAM:~/OS$ gcc 5_Open_Read_And_Append_In_Existing_File.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	This is the appended line!
	Total bytes read: 27.

	Total bytes appended: 27.
	s4shibam@SHIBAM:~/OS$
*/
