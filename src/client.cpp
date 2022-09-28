#include "public_content.h"
int main()
{
    int fd1=open(MY_FIFO1,O_WRONLY);
    if(fd1<0)
    {
	perror("open");
	return 2;
    }
    int fd2=open(MY_FIFO2,O_RDONLY);
    if(fd2<0)
    {
	perror("open");
	return 2;
    }
    while(1)
    {
	char buffer[256]={0};
	printf("please input your message: ");
	fflush(0);
	Msg msg;
	int s=read(0,buffer,sizeof(buffer)-1);
	if(s>0)
	{
	    buffer[s-1]='\0';
	    msg.type=1;
	    msg.getcur_and_pid();
	    strcpy(msg.content,buffer);
	    memcpy(buffer,&msg,sizeof(Msg));
	    write(fd1,buffer,sizeof(Msg));
	}
	memset(buffer,0,sizeof(buffer));
	s=read(fd2,buffer,sizeof(buffer)-1);
	if(s>0)
	{
	    memcpy(&msg,buffer,sizeof(Msg));
	    msg.print();
	}
	else if(s==0)
	{
	    printf("server quit...\n");
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

