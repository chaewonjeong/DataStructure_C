//<스택의 괄호 검사를 해주는 프로그램>
//입력 수식의 괄호가 올바른지 검사한다

//단순히 여는 괄호와 닫는 괄호의 개수 비교만으로는 부족함.
//스택을 이용하여 검사

//여는 괄호는 스택에 push한다.

//[수식이 올바른지 검사하는 조건]
//닫는 괄호가 나오면 스택에서 pop한 후, pop한 여는 괄호와 닫는 괄호가 같은 유형이어야 한다.
//마지막에 스택에 남는 괄호가 없어야 한다.

#include <stdio.h>
#include <string.h>

//배열을 이용한 스택 구현
/*===============================================================*/
#define MAX_CAPACITY 100 //스택의 최대 크기

char stack[MAX_CAPACITY]; //char를 타입으로 하는 스택
int top = -1; //처음스택은 비어있다.

int isEmpty() { //스택이 비었는지 검사
	return top == -1;
}

int isFull() {  //스택이 가득 찼는지 검사
	return top == MAX_CAPACITY-1;
}

void push(char ch) { //스택에 새로운 자료를 삽입
	if(isFull()) {
		return;
	}
	top++;
	stack[top] = ch;
}

char pop() {  //스택의 top에 있는 데이터를 스택에서 제거하고 반환
	if(isEmpty()) {
		printf("스택이 비었습니다.");
	} else {
		char tmp = stack[top];
		top--;
		return tmp;
	}
}

char peek() {  //스택의 top부분의 값을 반환
	if(isEmpty()) {
		printf("스택이 비었습니다.");
	} else {
		return stack[top];
	}
}

/*===============================================================*/



char OPEN[] = "([{";
char CLOSE[] = ")]}";

int isCorrectParentheses(char *formula);  //수식을 입력받아서 괄호가 정상적으로 입력되었는지 확인하는 함수
int isOpen(char ch);  //입력받은 수식에서 여는괄호인지 검사하는 함수
int isClose(char ch);  //입력받은 수식에서 닫는 괄호인지 검사하는 함수 




int main() {
	char formula[100]; //수식을 입력받는 문자열
	printf("수식을 입력하시오.\n");
	printf("$ : ");
	scanf("%s", formula);
	if(isCorrectParentheses(formula)) {
		printf("%s는 올바른 수식입니다.\n", formula);
	}
	else {
		printf("%s는 잘못된 수식입니다.\n", formula);
	}
}


int isCorrectParentheses(char *formula) {
	int isCorrect = 1;
	int index = 0;
	while(isCorrect && (index < strlen(formula))){
		char ch = formula[index];
		
		if(isOpen(ch)>-1){ //여는괄호가 나오면 스택에 push한다.
			push(ch);
		}
		else if(isClose(ch)>-1){
			if(isEmpty()){ //스택은 비었는데 닫는 괄호가 나왔다면 잘못된 수식이다.
				isCorrect = 0;
				break;
			}
			
			char topCh = pop(); 
			if(isOpen(topCh) != isClose(ch)) { //pop한 괄호랑 수식의 닫는 괄호가 다르면 잘못된 수식이다.
				isCorrect = 0;
			}
		}
		index++;
	}
	return (isCorrect == 1 && isEmpty() == 1); //반복문이 끝났을때 수식은 올바르고 스택은 비어있어야한다
}


int isOpen(char ch) {
	for(int i = 0 ; i < strlen(OPEN); i++){
		if(OPEN[i] == ch)
			return i; 
			//배열의 인덱스를 반환하여 입력된 괄호가 어떤 괄호인지 구별할 수 있도록 해준다.
			//소괄호는 0, 대괄호는 1, 중괄호는 2를 반환한다 
			//OPEN[] = "([{"
	}
	return -1; //입력된 문자가 괄호가 아닐경우 -1을 반환한다.
}


int isClose(char ch) {
	for(int i = 0; i < strlen(CLOSE); i++){
		if(CLOSE[i] == ch)
			return i;
	}
	return -1;
}













