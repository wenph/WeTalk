#include "common.h"
#include "weTalk.h"

client_t *Clients = NULL;

void dg_echo(int sockfd,SA *pcliaddr,socklen_t clilen);
void weTalkSend(int sockfd,char *mesg,int n,socklen_t len);

int main(int argc,char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr,cliaddr;
    setbuf(stdout,NULL);
    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(56056);

    bind(sockfd,(SA *)&servaddr,sizeof(servaddr));
    dg_echo(sockfd,(SA *)&cliaddr,sizeof(cliaddr));
}

void dg_echo(int sockfd,SA *pcliaddr,socklen_t clilen)
{
    int n,m;
    struct sockaddr_in *cliaddr = (struct sockaddr_in *)pcliaddr;
    socklen_t len;
    char mesg[MAXLINE];
    char mesg2[MAXLINE];

    while(1)
    {
        len = clilen;

        n = recvfrom(sockfd,mesg,MAXLINE,0,pcliaddr,&len);
        mesg[n] = 0;
        printf("recvfrom [ipaddr:%s port:%u]:%s",inet_ntoa(cliaddr->sin_addr),ntohs(cliaddr->sin_port),mesg);
        hasOrNotClient(pcliaddr);
	m = snprintf(mesg2,MAXLINE,"[ipaddr:%s port:%u]:%s",inet_ntoa(cliaddr->sin_addr),ntohs(cliaddr->sin_port),mesg);
        weTalkSend(sockfd,mesg2,m,len);
    }
}

void weTalkSend(int sockfd,char *mesg,int n,socklen_t len)
{
    client_t *p = Clients;
    for(; p != NULL; p = p->next)
    {
        sendto(sockfd,mesg,n,0,(SA *)(&(p->client_sockaddr)),len);
    }
}

//gcc -std=c99 -o udpserv01.out udpserv01.c util.c
