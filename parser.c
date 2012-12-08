
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ( int file_file_loc, char *file_loc[] ) {
  char date_input[100];
  char date[11];
  char time[9];
  char type[4]="WARN";
  char source_input[15];
  char trash[20];
  int listeners;
  char n[3]="now";
  FILE * input;
  FILE * output;
  input = fopen( file_loc[1], "r");
  output = fopen( file_loc[2], "w");
  fscanf (input, "%s", date_input);
  date[0]=date_input[0];
while (fscanf (input, "%s", time) != EOF) {
	fscanf (input, "%s", type);
	fscanf (input, "%s", source_input);
	
	if(strcmp(source_input, "source/source.c")){
		fscanf (input, "%s", trash);
		while (trash[0] != n[0]) {
			fscanf (input, "%s", trash);
		}
		fscanf (input, "%i", &listeners);

		fprintf (output, "%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c\t %d\n",date_input[1],date_input[2],date_input[3],date_input[4],date_input[5],date_input[6],date_input[7],date_input[8],date_input[9],date_input[10],time[0],time[1],time[2],time[3],time[4],time[5],time[6],time[7],listeners);
	}
	
	
	if (fscanf (input, "%s", date_input) == EOF){
	fclose (input);
fclose (output);
printf ("Done!");
return EXIT_SUCCESS;
}
	
	while (date_input[0] != date[0]) {
		if (fscanf (input, "%s", date_input) == EOF){
	fclose (input);
fclose (output);
printf ("Done!");
return EXIT_SUCCESS;
}
		}
		
	
}

fclose (input);
fclose (output);
printf ("Done!");
return EXIT_SUCCESS;
}

