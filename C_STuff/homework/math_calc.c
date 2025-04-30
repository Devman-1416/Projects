//Devin Combs
#include <stdio.h>
float calc_add (float n1, float n2);
float calc_sub (float n1, float n2);
float calc_mul (float n1, float n2);
float calc_div (float n1, float n2);

int main(){
	float num1, num2, ans;
	char operate;
	
	// Get input
	printf("Enter two number formula: ");
	scanf("%f%c%f", &num1, &operate, &num2);
	
	//Do Math
		switch(operate)
	{
		case '+':
			ans = calc_add(num1,num2);
			printf("\nAnswer is %f",ans);
			break;
			
		case '-': 
			ans = calc_sub(num1,num2);
			printf("\nAnswer is %f",ans);
			break;
			
		case '/': 
			if (num2 == 0) {
			ans = 0;
			printf("Dont break the program, you cant divide by %f!",ans);
		
			}
			
			else {
			ans = calc_div(num1,num2);
			printf("\nAnswer is %f",ans);
			}
			break;
	
		case '*': 
			ans = calc_mul(num1,num2);
			printf("\nAnswer is %LLf",ans);
			break;
			
		default:
			printf("Invalid operator");
					
	}
	return 0;
}

float calc_add (float n1, float n2){
	float ans = n1 + n2;
	return ans;
}

float calc_sub (float n1, float n2){
	float ans = n1 - n2;
	return ans;
}

float calc_mul (float n1, float n2){
	float ans = n1 * n2;
	return ans;
}

float calc_div (float n1, float n2){
	float ans = n1 / n2;
	return ans;
}
