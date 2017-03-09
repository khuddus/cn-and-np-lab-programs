#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#include<stdio.h>
#include<unistd.h>

#include<string.h>

main()
 {

    int msqid, l;

    struct
 {
        long mtype;
        char fname[20];

    } msgbuf;

    msqid = msgget((key_t) 10, IPC_CREAT | 0666);

 printf("%d\n",msqid);
   

    msgrcv(msqid, &msgbuf, sizeof (msgbuf), 0, 0);
    printf("\n Received filename %s \n", msgbuf.fname);
}

