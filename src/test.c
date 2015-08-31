#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iwlib.h>

char ssidlist[128][128];
int accessPointCount;
char y5interface[] = "wlp4s0";
wireless_scan_head  head;
wireless_scan        *result;
iwrange             range;
int                 sock;
int nsy5_init(void);
int nsy5_strSplit(char *src, char*** des);
void nsy5_parseSSID(void);
void main(void) {
    char *str;
    char *strList[128];
    str = malloc(100*128);
   
    /* Traverse the results */
    nsy5_init();
    nsy5_parseSSID();
    //printf("%s\n",strList[1]);
    exit(0);
}
int nsy5_init(void)
{
    /* open socket to kernal */
    sock = iw_sockets_open();
    /* Get some meta data go use for sacnning*/
    if( iw_get_range_info(sock, y5interface, &range)<0) {
        printf("Error durring iw_get_range_infor. Aborting.\n");
        exit(2);
    }

    /* Scanning */
    if (iw_scan(sock, y5interface, range.we_version_compiled, &head) < 0) {
        printf("Error during iw_can. Aborting.\n");
        exit(2); 
    }
}
int nsy5_strSplit(char *src, char*** des)
{
    char *tmp_str;
    tmp_str = strdup(src);
    printf("%s",tmp_str);
    free(tmp_str);
    return 0;
}
void nsy5_parseSSID(void)
{
    int length;
    int i =0;    

    result = head.result;
    while (NULL != result) {
        strcpy(ssidlist[i], result->b.essid);
        strcat(ssidlist[i],"\n");
        result = result->next;
        i++;
    }
    accessPointCount = i+1;

    printf("%s\n",ssidlist[0]);
    printf("%s\n",ssidlist[1]);
    printf("%s\n",ssidlist[2]);
    
}
