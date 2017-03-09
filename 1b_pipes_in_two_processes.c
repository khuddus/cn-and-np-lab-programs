#include<stdio.h>
#include<stdlib.h>
main()
{

int pipefd[2],n,pid; 
char buff[100]; 
pipe(pipefd);
pid=fork();
if(pid==0){
printf("\nChild Process");
close(pipefd[1]);
n=read(pipefd[0],buff,sizeof(buff));
 printf("\n size of the data%d",n); 
printf("\n data :%s",buff);

}
else{
printf("\nParent Process");
close(pipefd[0]);
write(pipefd[1],"Data from parent",30);


}


}

