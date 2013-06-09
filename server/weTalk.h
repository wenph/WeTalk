
typedef struct client_struct
{
    struct sockaddr client_sockaddr;
    struct client_struct *next;
}client_t;

int hasOrNotClient(struct sockaddr *psockaddr);

