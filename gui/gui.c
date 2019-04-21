#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE 1024

char x[7][17] = {
	"   ____  ____   ",
	"  |_  _||_  _|  ",
	"    \\ \\  / /    ",
	"     > `' <     ",
	"   _/ /'`\\ \\_   ",
	"  |____||____|  ",
	"                "
};
char o[7][17] = {
	"      ____      ",
	"    .'    `.    ",
	"   /  .--.  \\   ",
	"   | |    | |   ",
	"   \\  `--'  /   ",
	"    `.____.'    ",
	"                "
};
char empty[7][17] = {
	"                ",
	"                ",
	"                ",
	"                ",
	"                ",
	"                ",
	"                "
};


	//	Example look of grid
	/*                Tura Przeciwnika                  
    *----------------*----------------*----------------*
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
    *----------------*----------------*----------------*
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
    *----------------*----------------*----------------*
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
	|                |                |                |
    *----------------*----------------*----------------*
	*/

const char * addSignLine(int lineIndex, char argument){
	if(argument == 'x'){
		return x[lineIndex];
	}
	else if(argument == 'o'){
		return o[lineIndex];
	}
	else if(argument == 'e'){
		return empty[lineIndex];
	}
	else
		return "error";
}

int printResult(char *argv[]){
	
	/*if (argc != 11){
		printf("Wrong amount of arguments");
		return -1;
	}*/
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	char result[26][60];
	char buffer[BUFFSIZE] = {0};
	snprintf(buffer, BUFFSIZE-1, "                  %s                 \n", argv[0]);
	strcpy(result[0], buffer);
	strcpy(result[1], "*----------------*----------------*----------------*\n");
	strcpy(result[9], "*----------------*----------------*----------------*\n");
	strcpy(result[17], "*----------------*----------------*----------------*\n");
	strcpy(result[25], "*----------------*----------------*----------------*\n");
	for(int j=0; j<7; j++){
		char buffer[BUFFSIZE] = {0};
		snprintf(buffer, BUFFSIZE-1, "|%s|%s|%s|\n", 
			addSignLine(j, *argv[1]), 
			addSignLine(j, *argv[2]), 
			addSignLine(j, *argv[3]));
		strcpy(result[2+j], buffer);
	}
	for(int j=0; j<7; j++){
		char buffer[BUFFSIZE] = {0};
		snprintf(buffer, BUFFSIZE-1, "|%s|%s|%s|\n", 
			addSignLine(j, *argv[4]), 
			addSignLine(j, *argv[5]), 
			addSignLine(j, *argv[6]));
		strcpy(result[10+j], buffer);		
	}
	for(int j=0; j<7; j++){
		char buffer[BUFFSIZE] = {0};
		snprintf(buffer, BUFFSIZE-1, "|%s|%s|%s|\n", 
			addSignLine(j, *argv[7]), 
			addSignLine(j, *argv[8]), 
			addSignLine(j, *argv[9]));
		strcpy(result[18+j], buffer);		
	}
	
	for(int i=0; i<26; i++){
		printf("%s", result[i]);
	}
	return 0;
}