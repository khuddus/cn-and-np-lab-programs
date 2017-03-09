#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#include<stdio.h>
#include<unistd.h>

#include<string.h>

main() {

    int msqid, l;

    struct {
        long mtype;
        char fname[20];

    } msgbuf;

    msqid = msgget((key_t) 10, IPC_CREAT | 0666);
    printf("%d\n",msqid);
    printf("Enter file name");
    scanf("%s", msgbuf.fname);
    msgsnd(msqid, &msgbuf, sizeof (msgbuf), 0);
}

