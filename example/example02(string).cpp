/*=======================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	//C 언어는 문자열을 생성하는 편리한 방법을 제공한다.
	char str[] = "hello";  //string array
	char * str2 = "hello"; //string literal : 수정 불가능
	
	printf("%s\n", str);
	printf("%s\n", str2);
	
	str[0] = 'x';  //수정 가능
	//*(str2+1) = 'x'; //수정 불가능
	printf("%s\n", str);
	printf("%s\n", str2);
}

/*=======================================================*/
//문자열들의 저장
//여러개의 단어들을 포인터를 이용하여 저장해보자.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100;

char * strdupEx(char *s) {
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p,s);	
	return p;
}


int main(void){
	char * words[100];
	int n = 0; //number 0f string
	char buffer[BUFFER_SIZE];
	
	//strcpy vs strdup
	
	while(scanf("%s", buffer) != EOF) {
		words[n] = strdupEx(buffer);
		n++;
	}
	
	for(int i = 0 ; i < n; i++){
		printf("%d\n", words[i]);
	}
}
/*=======================================================*/









