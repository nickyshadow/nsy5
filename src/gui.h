#ifndef GUI_H__
#define GUI_H__
extern  char choices[128][128];
extern int n_choices;
void print_menu(WINDOW *menu_win, int highlight, char menu_context[128][128], int menu_size);
int	start_gui( void );
#endif /* GUI_H__ */
