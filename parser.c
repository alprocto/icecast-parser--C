/*
    Copyright 2012 Andrew Proctor
	alprocto@gmail.com
 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int num,char *command[]) {
  char current[100];
  char date[11];
  char time[9];
  char type[4];
  int listeners;
  char n[3]="now";
  FILE * input;
  FILE * output;
int i;
double j = 0; 
  input = fopen(command[1], "r");
  output = fopen(command[2], "w");

time[8]='\0';
date[10]='\0';


while (j<100000000){
fscanf (input, "%s", current);

j++;


if(current[1]=='\0'){
if(current[0]=='\0'){
break;}
}

	if(current[0]=='['){
		for(i=0;i<10;i++){
			date[i]=current[i+1];
		}
	}
	if(current[8]==']'){
		for(i=0;i<8;i++){
			time[i]=current[i];
	}}
	if(current[2]>='A'){
		if(current[2]<='Z'){
			for(i=0;i<4;i++)
				type[i]=current[i];
		}
	}
	if(strcmp(current, "listener")==0){
		fscanf (input, "%s", current);
		while (current[0] != n[0]) {
			fscanf (input, "%s", current);
		}
		fscanf (input, "%i", &listeners);

		fprintf (output, "%s\t %s\t %d\n",date,time,listeners);
	
	}
	current[2]='\0';
	current[8]='\0';
	current[1]='\0';
	current[0]='\0';
}
	
fclose (input);
fclose (output);
printf ("Done!\n");
return EXIT_SUCCESS;
}

