// Q. Write a program using open() system call to read data from (max 50 char)
// an existing file “Text1.txt” and print them on screen.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>

int main (){
	
	int len, fd;
	char ch[50];
	
	// Opens test.txt in read mode and
	// the file descriptor is saved in integer fd
	fd = open("Text1.txt", O_RDONLY);	
	
	// The value of the file descriptor is printed.
	printf("The file descriptor of the file is: %d\n", fd); 
	
	// Read maximum 50 characters from the file pointed by file descriptor fd
	// and save them in buffer (ch)
	len = read(fd, ch, 50);

	// Write on the screen from the buffer
	write(1, ch, len); 
	printf("\nTotal bytes written: %d.\n", len);
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 3_Open_And_Read_Existing_File.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	The file descriptor of the file is: 3
	This is Text1.txt file.
	Total bytes written: 23.
	s4shibam@SHIBAM:~/OS$
*/
