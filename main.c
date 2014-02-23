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
		looped = get_source_line(*source_file, source_name[], *date[]);
	}
	
    fclose(source_file);
   /* xxMissing Code Here */
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    struct tm * timei;

	time(&timer);
	timei = localtime(&timer);
	*dte = timei;
	file = fopen(source_file_name[], "r");
	
    
    /* xxMissing Code Here */
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
	    
    if (fgets(source_buffer[], MAX_SOURCE_LINE_LENGTH, src_file) != null) 
    {
	line_number++;
	sprintf(print_buffer[], "%d %s", line_number, source_buffer[]);
	print_line(print_buffer[], src_name[], todays_date[]);
		/*  xxMissing Code Here */
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
