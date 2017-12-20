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

int main()
{
    FILE *fp;
    fp = fopen("cfg.txt", "r");
    char *rport = malloc(1024 * sizeof(char));
    char *rindex = malloc(1024 * sizeof(char));
    char *p403 = malloc(1024 * sizeof(char));
    char *p404 = malloc(1024 * sizeof(char));
    int i = 0;
    int count = 7;
    char c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    while (c != ';')
    {
        rport[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 12;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    while (c != ';')
    {
        rindex[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 11;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    while (c != ';')
    {
        p403[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 11;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    while (c != ';')
    {
        p404[i] = c;
        i++;
        c = fgetc(fp);
    }
    int rerror = 0;
    char *webpage = malloc(1024 * sizeof(char));
    if((fp = fopen(rindex, "r")) != NULL)
    {
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n";
            i = 59;
            webpage[i] = c;
            i++;
            if (c == EOF)
            {
                if (feof(fp) == 0)
                {
                    rerror = 1;
                    break;
                }
            }
        }
    }
    else
    {
        fp = fopen(p404, "r");
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[i] = c;
            i++;
        }
    }
    if (rerror == 1)
    {
        fp = fopen(p403, "r");
        i = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            webpage[i] = c;
            i++;
        }
    }
    struct socket_addr_in server_addr, client_addr;
    int fd_server, fd_client;
    char buf[2048];
    socklen_t sin_len = sizeof(client_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons (atof(rport));
    fd_server = socket(AF_INET, SOCK_STREAM, 0);
    bind(fd_server, (struct socket_addr *) &server_addr, sizeof(server_addr));
    listen(fd_server, 10);
    while(1)
    {
        fd_client = accept(fd_server, (struct socket_addr *) &client_addr, sin_len);
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

