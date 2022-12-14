#include "public_content.h"
int main()
{
    if(access(MY_FIFO1,F_OK)&&mkfifo(MY_FIFO1,0666)<0)
    {
	perror("mkfifo");
    }
    if(access(MY_FIFO2,F_OK)&&mkfifo(MY_FIFO2,0666)<0)
    {
	perror("mkfifo");
    }
    int fd1=open(MY_FIFO1,O_RDONLY);
    if(fd1<0)
    {
	perror("open");
	return 2;
    }
    int fd2=open(MY_FIFO2,O_WRONLY);
    if(fd2<0)
    {
	perror("open");
	return 2;
    }
    while(1)
    {
	char buffer[256]={0};
	Msg msg;
	ssize_t s=read(fd1,buffer,sizeof(buffer)-1);
	if(s>0)
	{
	    memcpy(&msg,buffer,sizeof(Msg));
	    msg.print();

	    msg.type=2;
	    strcpy(msg.content,"successful!");
	    msg.getcur_and_pid();
	    
	    memset(buffer,0,sizeof(buffer));
	    memcpy(buffer,&msg,sizeof(Msg));
	    write(fd2,buffer,sizeof(Msg));
	    printf("sended confirmation message successfully\n");
	}
	else if(s==0)
	{
	    printf("client quit...\n");
	    break;
	}
	else
	{
	    perror("read");
	    break;
	}
    }
    close(fd1);
    close(fd2);
    return 0;
}

