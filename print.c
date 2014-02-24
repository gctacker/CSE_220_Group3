#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    bool length = FALSE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(&source_name_to_print[0], &date_to_print[0]);
	line_count = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        char save_ch = line[MAX_PRINT_LINE_LENGTH-1];
	line[MAX_PRINT_LINE_LENGTH-1] = '\0';
	length = TRUE;
    }
    if (save_chp)
    {
        printf("%s", &line[0]);
    }
    
    if (length)
    {
        line[MAX_PRINT_LINE_LENGTH-1] = save_ch;
	length = FALSE;
    }
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    
    printf("%s", "/f");
    printf("%s %s",  &source_name[0], &date[0]);
    page_number++;
}
