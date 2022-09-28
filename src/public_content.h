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
    	printf("received type %d message\n",(int)type);
    	printf("specific content: %s\n",content);
    }
};
