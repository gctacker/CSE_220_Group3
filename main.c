#include "common.h"
#include <stdio.h>

int main (int argc, const char *argv[])
{
	
    FILE *source_file = NULL;				
    char source_name[MAX_FILE_NAME_LENGTH];		//source_name array size = 32
    char date[DATE_STRING_LENGTH];			// data arrazy size = 26

	


	if(argc < 2)					//argument count <2
	{
	  printf("You didn't provide an argument\n");	
	  return 1;
	}
	
	init_lister(argv[1], source_name, date);	//calls init_lister arg varibale array 1, source_name, and date
	source_file =  fopen(argv[1], "r");		//opens to read arg varibale array 1 to source_file
	 


	
	while(get_source_line(source_file, source_name, date))
	{
		
	}
	
    fclose(source_file);
     return 0;
}//end of main
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file = NULL;

	strcpy(source_file_name, name);		//copies source_file_name into name
	file = fopen("source_file_name", "r");	//opens source_file_name to read
    	timer = time(NULL);			
	sprintf(dte, "%s", ctime(&timer));	//print format of dte: string of variable timer
	 
	return file;				//returns to file
}



BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{

    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];	//set print_buffer array size to 256 + 9
    char source_buffer[MAX_SOURCE_LINE_LENGTH];		//set source_buffer arrazy size to 256
    static int line_number = 0;    			//set line_number to 0

    if (fgets(source_buffer,MAX_SOURCE_LINE_LENGTH,src_file)) //reads a max of 256 lines from src_file to source_buffer
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
}//end of get_source_line
