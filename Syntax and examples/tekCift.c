#include <stdio.h>
#include <stdbool.h>
bool isDouble(int num){
	if(num % 2 == 0) return true;
	else return false;
}
int main(){
	int num;
	printf("please enter the number : ");
	scanf("%d",&num);
 
	if (isDouble(num)) 
		printf("%d is Double\n",num);
	else 
		printf ("%d is Odd\n",num);
	return 0;
}
 