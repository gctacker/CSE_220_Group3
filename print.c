//Christine Malong: Tin2x
//Gregory Tacker: gctacker

#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;			//line_count = 50
    bool length = FALSE;
    
    if (++line_count > MAX_LINES_PER_PAGE)			//test the number of lines on the page, line_count > 50
    {
        print_page_header(source_name_to_print, date_to_print); //go to page header to make a new page
	line_count = 1;						//restarts line count to 1 for new page
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 			//test the length of the string, length of string > 80
    {
        char save_ch = line[MAX_PRINT_LINE_LENGTH-1];		//save the character at the max lenght spot
	line[MAX_PRINT_LINE_LENGTH-1] = '\0';			//put null terminator in the max length spot
	length = TRUE;						//set boolean to true to restore value after it prints
    }
        
	printf("%s", line);					//print the line to the screen no tests to be done, a line will always be printed
    
    if (length)
    {
        line[MAX_PRINT_LINE_LENGTH-1] = save_ch;		//if boolean is true restore the value and jump to a new line
	length = FALSE;
	printf("\n");
    }
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    
    printf("\f");					//print a new page
    printf("%s %s",  &source_name[0], &date[0]);	//print the name and date to the top of a screen
    page_number++;					//increase the page number
}
