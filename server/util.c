#include "common.h"
#include "weTalk.h"

extern client_t *Clients;

int buffercmp(char *a,char *b)//0 match 1 dismatch
{
    char *c;
    c = a + 4;
    char *d;
    d = b + 4;
    for(int i=0; i<4; i++)
    {
        if(*c == *d)
        {
            c++;
            d++;
            continue;
        }
        else
            return 1;
    }
    return 0;
}

int sockaddr_comepare(struct sockaddr *psockaddr)//0 match 1 dismatch
{
    struct client_struct *p;
    p = Clients;
    for(; p != NULL; p = p->next)
    {
        if(!buffercmp((char *)psockaddr,(char *)p))
	{
            printf("sockaddr_comepare match\n");
	    break;
	}
        else
	{
            printf("sockaddr_comepare dismatch\n");
	    continue;
	}
    }
    if(p != NULL)
        return 0;
    else
	return 1;
}

void addClients(void *new)
{
    client_t *p = (client_t *)new;
    p->next = Clients;
    Clients = p;
}

int hasOrNotClient(struct sockaddr *psockaddr)
{
    if(sockaddr_comepare(psockaddr))//has not this client
    {
        client_t *new;
        new = (client_t *)malloc(sizeof(struct client_struct));
        new->client_sockaddr = *psockaddr;
        struct sockaddr_in *in = (struct sockaddr_in *)(&(new->client_sockaddr));
        in->sin_port = ntohs(56057);
        new->next = NULL;
        addClients(new);
    }
    return 0;
}
