#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <semaphore.h>
# include <sys/select.h>
# include <sys/sysctl.h>
# include <poll.h>
# include <strings.h>
# include <sys/ioctl.h>
# include <pthread.h>

#define SA struct sockaddr
#define MAXLINE 4096
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PROT_READ	0x1
#define PROT_WRITE	0x2
#define MAP_SHARED	0x01
#define PATH_MAX	1024

