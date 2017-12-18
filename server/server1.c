#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpainet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int port = atof(argv[1]);
    int size = 1024;
    char c;
    int rerrror = 0;
    char *webpage;
    if((fp = fopen(argv[2], "r")) != NULL)
    {
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[i] = c;
            i++;
            if (c == EOF)
            {
                if (feof(fp) == 0)
                {
                    rerrror = 1;
                    break;
                }
            }
        }
    }
    else
    {
        fp = fopen("404.html", "r");
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[i] = c;
            i++;
        }
    }
    if (rerror == 1)
    {
        fp = fopen("403.html", "r");
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[i] = c;
            i++;
        }
    }
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_len = sizeof(client_addr);
    int fd_server, fd_client;
    char buf[2048];
    int on = 1;
    fd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_server < 0)
    {
        perror("socket");
        exit(1);
    }
    setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons (8080);
    if (bind(fd_server, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        close(fd_server);
        exit(1);
    }
    if (listen(fd_server, 10) == -1)
    {
        perror("listen");
        close(fd_server);
        exit(1);
    }
    while(1)
    {
        fd_client = accept(fd_server, (struct sockaddr *) &client_addr, sin_len);
        if (fd_client == -1)
        {
            perror("Connection failed!\n");
            continue;
        }
        printf("Connection succeeded!\n");
        if (!fork())
        {
            close(fd_server);
            memset(buf, 0, 2048);
            read(fd_client, buf, 2047);
            printf("%s\n", buf);
            write(fd_client, webpage, sizeof(webpage) - 1);
            close(fd_client);
            printf("Closing!\n");
            exit(0);
        }
        close(fd_client);
    }
    return 0;
}