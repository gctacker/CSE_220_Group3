#include "common.h"
#include <stdio.h>

int main (int argc, const char *argv[])
{
	
    FILE *source_file = NULL;
    char source_name[MAX_FILE_NAME_LENGTH];		//source_name array size = 32
    char date[DATE_STRING_LENGTH];			// data array size =26

	


	if(argc < 2)  					//test if argument count is less than 2 (name of prog= argv[1]
	{
	  printf("you didnt provide an argument\n");
	  return 1;
	}
	
	init_lister(argv[1], source_name, date);	//calls init_lister arg variable array 1, source_name, and date
	source_file =  fopen(argv[1], "r");		//opens to read arg variable array 1 to source_file
	if(source_file == NULL)				//test to make sure a file was opened
	{
	printf("you didnt provide a valid file\n");	
	return 1;	
	}
	 


	
	while(get_source_line(source_file, source_name, date))	//loop the function to get read lines
	{
		
	}
	
    fclose(source_file);					// close the file when done with it
     return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file = NULL;

	strcpy(source_file_name, name);				//copyies source file name into name
	file = fopen("source_file_name", "r");			//open source_file_name to read
    	timer = time(NULL);					//get the time
	sprintf(dte, "%s", ctime(&timer));			//print format of dte: string of variable timer
	 
	return file;						//returns to file
}



BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{

    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];		//set buffer array size to 256 + 9
    char source_buffer[MAX_SOURCE_LINE_LENGTH];			//set source_buffer array size to 256
    static int line_number = 0;    				//set line number to 0

    if (fgets(source_buffer,MAX_SOURCE_LINE_LENGTH,src_file)) //reads a max of 256 characters from src_file to source_buffer
    { 
	line_number++;					      //increase line_number by 1
	sprintf(print_buffer, "%d %s", line_number, source_buffer);	//print format: line number, source line
	
	print_line(print_buffer, src_name, todays_date);		//pass the data to print_line to be sent to the screen
		




        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}//end of get_source_line
