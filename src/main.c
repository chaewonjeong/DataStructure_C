#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // <- white space 문자인지 검사하는 isspace 함수를 제공

#define LINE_SIZE 80

int readLineWithCompression(char compressed[], int limit) {
	int ch, i = 0;
	while((ch = getchar()) != '\n'){
		if(i < limit-1 && (!isspace(ch) || (i > 0 && !isspace(compressed[i-1]))))
			compressed[i++] = ch;
	}
	if(i > 0 && isspace(compressed[i-1])){
		i--;
	}
	compressed[i] = '\0';
	return i;
}

int main(void) {
	char line[LINE_SIZE];
	
	while(1){
		printf("$ ");
		int len = readLineWithCompression(line,LINE_SIZE);
		printf("%s:%d\n", line, len);
	}
	
}