// Q. To read data from the standard input device and write it on the screen

#include <stdio.h>
#include <unistd.h>

int main ()
{
	// This contains number of bytes read
	int len;	
	
	// Read maximum 50 bytes from standard input device (0 --> stdin)
	// & store in buffer (ch)
	char ch[50];
	len = read (0, ch, 50);	
	
	// Write "len" bytes from the buffer on screen
	write (1, ch, len);
	printf ("\nTotal bytes written: %d.\n", len);
}

/*
 	Output:
 	
 	s4shibam@SHIBAM:~/OS$ gcc 2_read.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Hello Dear Linux!
	Hello Dear Linux!
	
	Total bytes written: 18.
	s4shibam@SHIBAM:~/OS$
*/
