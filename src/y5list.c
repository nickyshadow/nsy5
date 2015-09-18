#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iwlib.h>
#include "y5list.h"
char ssidlist[128][128];
int accessPointCount;
char y5interface[] = "wlp4s0";
wireless_scan_head  head;
wireless_scan        *result;
iwrange             range;
int                 sock;

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
void nsy5_parseSSID( char list[128][128], int *count)
{
    int length;
    int i =0;    

    result = head.result;
    while (NULL != result) {
        strcpy(list[i], result->b.essid);
        strcat(list[i],"\n");
        result = result->next;
        i++;
    }
    accessPointCount = i+1;
    *count = accessPointCount;
    printf("%s",list[0]);
    printf("%s",list[1]);
    printf("%s",list[2]);
    return; 
}
