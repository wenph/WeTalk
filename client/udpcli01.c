#include "common.h"

void dg_cli(FILE *fp,int sockfd,SA *pservaddr,socklen_t servlen);

int main(int argc,char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if(argc != 2)
    {
        printf("usage: udpcli <ServerIPaddress>\n");
        exit(0);
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(56056);
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

    dg_cli(stdin,sockfd,(SA *)&servaddr,sizeof(servaddr));

    exit(0);
}

void dg_cli(FILE *fp,int sockfd,SA *pservaddr,socklen_t servlen)
{
    int n;
    char sendline[MAXLINE],recvline[MAXLINE + 1];
    int i,sendpacknum = 0;
    //char sendline[DGLEN];

    while(fgets(sendline,MAXLINE,fp) != NULL)
    {
        //printf("sockfd:%d\n",sockfd);
        sendto(sockfd,sendline,strlen(sendline),0,pservaddr,servlen);
        //n = recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
        //recvline[n] = 0;
        //fputs(recvline,stdout);
    }
}
