#include "common.h"

void dg_echo(int sockfd,SA *pcliaddr,socklen_t clilen);

int main(int argc,char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr,cliaddr;
    setbuf(stdout,NULL);
    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(56057);

    bind(sockfd,(SA *)&servaddr,sizeof(servaddr));
    dg_echo(sockfd,(SA *)&cliaddr,sizeof(cliaddr));
}

void dg_echo(int sockfd,SA *pcliaddr,socklen_t clilen)
{
    int n;
    //int bufsize;
    //int pack_num;
    socklen_t len;
    char mesg[MAXLINE];

    while(1)
    {
        len = clilen;
        n = recvfrom(sockfd,mesg,MAXLINE,0,pcliaddr,&len);
        mesg[n] = 0;
        printf("%s",mesg);
    }
}

