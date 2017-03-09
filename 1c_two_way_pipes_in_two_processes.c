#include<stdio.h>
#include<stdlib.h>
main()
{
   
int pipe1[2],pipe2[2],n,pid; 
char buff[100],buff2[100]; 
pipe(pipe1);
pipe(pipe2);
pid=fork();
if(pid==0){
printf("\nChild Process");
close(pipe1[1]);
n=read(pipe1[0],buff,sizeof(buff));
 printf("\n size of the data%d",n); 
printf("\n data :%s",buff);

//second pipe data here
close(pipe2[0]);
write(pipe2[1],"--Data from child in pipe 2--",35);


}
else{
printf("\nParent Process");
close(pipe1[0]);
write(pipe1[1],"Data from parent in Pipe 1",30);

//second pipe data here
close(pipe2[1]);
n=read(pipe2[0],buff2,sizeof(buff2));
 printf("\n size of the data%d",n); 
printf("\n data :%s",buff2);


}


}

