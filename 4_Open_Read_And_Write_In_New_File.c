// Q. Write a program using open() system call to read data from (max 50 char)
// an existing file “Text1.txt” and write them into non-existing file “Text2.txt”

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (){
	
	int len, fd, fd1;
	char ch[50];
	
	// Opens test.txt in read mode and
	// the file descriptor is saved in integer fd
	fd = open("Text1.txt", O_RDONLY);	
	
	// The value of the file descriptor is printed.
	printf("The file descriptor of the file is: %d\n", fd); 
	
	// Read maximum 50 characters from the file pointed by file descriptor fd
	// and save them in buffer (ch)
	len = read(fd, ch, 50);
	
	// New file is created in write only mode and
	// the file descriptor is saved in integer fd1
	// Pipe symbol (|) is used to separate O_WRONLY and O_CREAT
	fd1 = open("Text2.txt", O_WRONLY | O_CREAT, 0642);

	// Write in the Text2.txt file from the buffer
	write(fd1, ch, len); 
	printf("\nTotal bytes written: %d.\n", len);
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 4_Open_Read_And_Write_In_New_File.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	The file descriptor of the file is: 3
	Total bytes written: 23.
	s4shibam@SHIBAM:~/OS$ 
*/
