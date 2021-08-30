/*=======================================================*/
#include <stdio.h>


//포인터, 배열 예제
int calculateSum_1(int arr[]){
	int sum = 0;
	for(int i = 0; i < 10; i++){
		sum += arr[i];
	}
	return sum;
}

int calculateSum_2(int * arr){
	int sum = 0;
	for(int i = 0; i < 10; i++){
		//pointer arithmetic (포인터 연산)
		sum += *(arr+i);
	}
	return sum;
}
	

int main(void) {
	int num[10];
	
	for(int i = 0 ; i < 10; i++){
		num[i] = i;
	}
	
	int result = calculateSum_1(num);
	printf("sum 1 : %d\n", result);
	
	result = calculateSum_2(num);
	printf("sum 2 : %d\n", result);
	
}





/*=======================================================*/

//동적 메모리 할당
/*변수를 선언하는 대신 프로그램의 요청으로 메모리를 할당할 수 있다. 이것을 동적 메모리 할당(dynamic memory allocation)이라고 부른다.
malloc 함수를 호출하여 동적메모리 할당을 요청하면 요구하는 크기의 메모리를 할당하고 그 시작 주소를 반환한다.*/
#include<stido.h>
#include<stdlib.h>

int main(void) {
	int *p;
	p = (int *)malloc(4*sizeof(int));
	if(p == NULL) {
		printf("Error");
	}
	//malloc으로 할당 받은 메모리는 보통의 배열처럼 사용한다.
	
	
	//동적으로 할당된 배열은 공간이 부족할 경우 더 큰 배열을 할당하여 사용할 수 있다.
	int * array = (int *)malloc(4*sizeof(int)); //16byte
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	
	//만약 공간이 부족하다면
	int * tmp = (int *)malloc(8*sizeof(int));
	int i;
	for(i = 0; i < 4; i++){
		tmp[i] = array[i];
	}
	
	array = tmp;
	
	for(int i = 4 ; i < 8; i++){
		array[i] = i + 1;
	}
	
	for(int i = 0 ; i < 8; i++){
		printf("%d ", array[i]);
	}
	
	//이러한 경우 garbage가 생긴다.
	
}
/*=======================================================*/










