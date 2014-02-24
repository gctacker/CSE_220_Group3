#include "common.h"
#include <stdio.h>

int main (int argc, const char *argv[])
{
	
    FILE *source_file = NULL;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];

	


	if(argc < 2)
	{
	  printf("you didnt provide an argument\n");
	  return 1;
	}
	
	init_lister(argv[1], source_name, date);
	source_file =  fopen(argv[1], "r");
	 


	
	while(get_source_line(source_file, source_name, date))
	{
		
	}
	
    fclose(source_file);
     return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file = NULL;

	strcpy(source_file_name, name);
	file = fopen("source_file_name", "r");
    	timer = time(NULL);
	sprintf(dte, "%s", ctime(&timer));
	 
	return file;
}



BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{

    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;    

    if (fgets(source_buffer,MAX_SOURCE_LINE_LENGTH,src_file)) 
    { 
	line_number++;			//increase line_number by 1
	sprintf(print_buffer, "%d %s", line_number, source_buffer);	//print format: line number, source line
	
	print_line(print_buffer, src_name, todays_date);	
		/*  xxMissing Code Here */




        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
