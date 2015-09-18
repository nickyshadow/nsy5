#include <ncurses.h>
#include "gui.h"
#include "y5list.h"
char    wifi_list[128][128];
int     wifi_count;
extern char choices[128][128];
extern int n_choices;
int main()
{  
    nsy5_init();
    nsy5_parseSSID( choices, &n_choices );
	start_gui();
} 

