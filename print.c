#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    bool length = false;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print[], date_to_print[]);
	line_count = 1;
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        char save_ch = line[MAX_PRINT_LINE_LENGTH-1];
	line[MAX_PRINT_LINE_LENGTH-1] = "/0";
	length = true;
    }
    if (save_chp)
    {
        printf("%s", &line[]);
    }
    
    if (length)
    {
        line[MAX_PRINT_LINE_LENGTH-1] = save_ch;
	length = false;
    }
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    
    printf("/f");
    printf("%s %s",  &source_name[], &date[]);
    page_number++;
}
