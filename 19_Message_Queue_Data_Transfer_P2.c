// Q. Transfer message from program1 to read & display by program2 using Message Queue.

// program2 --> 19_Message_Queue_Data_Transfer_P2.c (Receiver)
// program1 --> 19_Message_Queue_Data_Transfer_P1.c (Sender)

// **Note: A message queue is a linked list of messages stored within the kernel and identified by a message queue identifier.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgBuf
{
    long int msgType;
    char msgData[20];
} msg;

int main()
{
    int msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    printf("P2: Message ID: %d.\n", msgid);

    msgrcv(msgid, &msg, sizeof(msg), msg.msgType, 0);

    printf("P2: Message received!\n");
    printf("P2: Message : %s\n", msg.msgData);

    msgctl(msgid, IPC_RMID, 0);
}

/*
    Output:


*/