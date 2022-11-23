// Q. Transfer message from program1 to read & display by program2 using Message Queue.

// program2 --> 19_Message_Queue_Data_Transfer_P2.c (Receiver)
// program1 --> 19_Message_Queue_Data_Transfer_P1.c (Sender)

// **Note: A message queue is a linked list of messages stored within the kernel and identified by a message queue identifier.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>

struct msgBuf
{
    long int msgType;
    char msgData[20];
} msg;

int main()
{
    printf("P1: Enter message: ");
    scanf("%s", msg.msgData);

    int msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    msg.msgType = 1;

    printf("P1: Message ID: %d.\n", msgid);

    // -1 means the message queue is not created
    if (msgid == -1)
    {
        printf("Error in creating queue.\n");
        exit(0);
    }

    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("P1: Message sent successfully!\n");
}

/*
    Output:


*/