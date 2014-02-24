#include "common.h"

int main (int argc, const char *argv[])
{
	
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
	
	if(argc < 2)
	{
	  printf("you didnt provide an argument\n");
	  return 1;
	}	

	/*sprintf(&source_name[0], "%s", argv[1]);*/
	/*source_name[0]= argv[1];*/

	

	*source_file = *init_lister(argv[1], source_name, date);
	
	while(get_source_line(source_file, source_name, date))
	{
		
	}
	
    fclose(source_file);
   /* xxMissing Code Here */
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;


    	timer = time(NULL);
	sprintf(&dte[0], "%s", ctime(&timer)); 
	file = fopen(name, "r");
	
	
    
    /* xxMissing Code Here */
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
	if(TRUE)
	{
	  printf("%s\n", todays_date);
	}

    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;    

if(TRUE)
	{
	  printf("%d\n", line_number);
	}	

    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL) 
    {


	line_number++;
	sprintf(print_buffer, "%d %s", line_number, &source_buffer[0]);
	print_line(print_buffer, src_name, todays_date);
		/*  xxMissing Code Here */




        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
