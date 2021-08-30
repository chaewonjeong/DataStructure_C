/*=======================================================*/
//연습문제 1//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(void) {
	char buffer[BUFFER_SIZE];
	
	while(1){
		printf("$ ");
		//표준입력파일 : stdin 키보드로 부터 입력받는다.
		fgets(buffer,BUFFER_SIZE,stdin);
		//newLine charcter를 null charcter로 바꿔준다.
		buffer[strlen(buffer) - 1] = '\0';
		printf("%s:%ld\n", buffer, strlen(buffer));
	}
	//C언어는 gets, fgets와 같은 입출력 함수를 제공하나 활용에 제한이 있다.
	
}
/*=======================================================*/
//위의 문제를 해결하기 위해 c프로그래머는 라인을 읽는 함수를 직접 작성할 수 있다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int readLine(char str[], int limit) {
	int ch, i = 0;
	while((ch = getchar()) != '\n'){  //getchar의 반환값은 int다
		if(i < limit){
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

int main(void) {
	char buffer[BUFFER_SIZE];
	
	while(1){
		printf("$ ");
		int len = readLine(buffer,BUFFER_SIZE);
		printf("%s:%d\n", buffer, len);
	}
	
}
/*=======================================================*/
//연습문제 2 compress while reading//
//문장의 앞과 뒤에 붙은 공백문자들은 제거하고 단어 사이에 두개 이상의 연속된 공백문자들은 하나의 공백 문자로 대체하라.
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
/*=======================================================*/












