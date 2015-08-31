#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
FILE *in_stream;
#define Y5_LIST_CMD ("iwlist %s scanning | grep SSID")
void main(void)
{
    setuid(0);    
    char str[1000];
    sprintf(str,Y5_LIST_CMD,"wlp4s0");
    in_stream = popen(str,"r");
    fgets(str,100,in_stream);
    printf("%s",str);
    system("iwlist wlp4s0 scanning | grep SSID");
}

