#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    bool looper;

	source_file = *init_lister(*argv[]);
	looped = get_source_line(*source_file, source_name[],date[]);
	while(looped)
	{
		looped = get_source_line(*source_file, source_name[],date[]);
	}
	
    
   /* Missing Code Here */
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;

	file = fOpen(source_file_name[], "r");
	
    
    /* Missing Code Here */
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    
    if (1) //This is missing a condition
    {
		/*  Missing Code Here */
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
