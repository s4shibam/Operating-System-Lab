// Q. To write some data on the standard output device (by default � monitor)

#include <stdio.h>
#include <unistd.h>

int main()
{
	// This contains number of bytes read
	int count; 	

	// 1			--> The file descriptor (stdout)
	// "Hello Linux!\n"	--> The data
	// 13			--> The count of characters in the data
	count = write(1, "Hello Linux!\n", 13);

	printf("Total bytes written: %d.\n", count);
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 01_Write.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Hello Linux!                                                                                                         
	Total bytes written: 13.
	s4shibam@SHIBAM:~/OS$
*/
