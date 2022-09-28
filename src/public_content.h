#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<ctime>
#define MY_FIFO1  "./fifo1"
#define MY_FIFO2  "./fifo2"
struct Msg
{
    char type;
    char content[64]="";
    void print()
    {
	    printf("-------NEW-------\n");
	if(type==1)
	{
    		printf("\033[33m received TEXT message\n\033[0m");
		printf("\033[33m specific content: %s\n\033[0m",content);
	}
	else if(type==2)
	{

		printf("\033[32m received CONFRIMATION message\n\033[0m");
		printf("\033[32m specific content: %s\n\033[0m",content);
	}
	printf("-----------------\n");
    }
};
