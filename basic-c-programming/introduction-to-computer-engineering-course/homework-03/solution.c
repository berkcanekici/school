/*##########################################################################*/
/* ­­­­­­­­­                       HW_03  ver_1.0.0                                  */
/*                         BERKCAN EKICI                                    */
/*                    berkcan_ekici_171044015.c                             */
/* ­­­­­­­­­                                                                         */
/* Created on 20/11/2019 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/* The purpose of this program is to perform certain arithmetic operations. */                               																		
/* The Program is written in the form of functions.                         */
/*                                                                          */
/* Notes                                                                    */
/* ­­­­­                                                                         */
/* This file is prepared and compressed in Ubuntu 18.04.1 LTS               */
/* Comments may be seem as corrupted on Windows OS.                         */
/* Compiled and tested with GCC.                                            */
/*                                                                          */
/*##########################################################################*/

/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                               Includes                                   */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
#include<stdio.h>
/*							Function Prototypes								*/
void menu(void);
void add_Numbers(void);
void sub_Numbers(void);
void mul_Numbers(void);
void div_Numbers(void);
void pow_Numbers(void);
void avg_Numbers(void);
void max_Numbers(void);

int main()
{
	menu();
	return 0;
}

void menu(void)
{	
	int select;

	printf("WELCOME TO GTU CALCULATOR MACHINE\n");
	printf("STUDENT NAME: BERKCAN EKICI\n");
	printf("PLEASE SELECT FROM THE FOLLOWING\n");
	printf("MENU:\n");

	do {
		printf("\n");
		printf("(1) ADD TWO NUMBERS\n");
		printf("(2) SUBTRACT TWO NUMBERS\n");
		printf("(3) MULTIPLY TWO NUMBERS\n");
		printf("(4) DIVIDE TWO NUMBERS\n");
		printf("(5) TAKE THE NTH POWER OF A NUMBER\n");
		printf("(6) FIND AVERAGE OF NUMBERS INPUTTED\n");
		printf("(7) FIND THE MAXIMUM OF NUMBERS INPUTTED\n");
		printf("(0) EXIT\n");
		printf("\n");
		printf("PLEASE SELECT\n");
		scanf("%d", &select);
	
		switch(select) {
			case 1:
					add_Numbers();
					break;
			case 2:
					sub_Numbers();
					break;
			case 3:
					mul_Numbers();
					break;
			case 4:
					div_Numbers();
					break;
			case 5:
					pow_Numbers();
					break;
			case 6:
					avg_Numbers();
					break;
			case 7:
					max_Numbers();
					break;
			case 0:
					printf("\nProgram terminated by user. Goodbye!\n");
					break;
			default:
					printf("\nOops! False selection. Please check menu.\n");
					break;
		}
	} while (select != 0);
}

//This function adds two numbers.
void add_Numbers(void)
{
	float number1, number2, sum = 0;
	
	printf("Please enter the first number:\n");
	scanf("%f", &number1);

	printf("Please enter the second number:\n");
	scanf("%f", &number2);
	
	sum = number1 + number2;
	printf("Sum : %.2f\n", sum);
}

//This function performs substraction.
void sub_Numbers(void)
{
	float number1, number2, sum = 0;
	
	printf("Please enter the first number:\n");
	scanf("%f", &number1);

	printf("Please enter the second number:\n");
	scanf("%f", &number2);
	
	sum = number1 - number2;
	printf("Sum : %.2f\n", sum);
}

//This function performs multiply.
void mul_Numbers(void){
	float number1, number2, sum = 0;
	
	printf("Please enter the first number:\n");
	scanf("%f", &number1);
	
	printf("Please enter the second number:\n");
	scanf("%f", &number2);
	
	sum = number1 * number2;
	printf("Sum : %.2f\n", sum);
}

//This function performs division.
void div_Numbers(void){
	float number1, number2, sum = 0;
	
	printf("Please enter the first number:\n");
	scanf("%f", &number1);
	
	printf("Please enter the second number:\n");
	scanf("%f", &number2);
	
	sum = number1 / number2;
	printf("Sum : %.2f\n", sum);
}
//This function performs power operation.
void pow_Numbers(void){
	float number, exponent, sum = 1;
	int i;

	printf("Please enter the first number:\n");
	scanf("%f", &number);
	
	printf("Please enter the second number:\n");
	scanf("%f", &exponent);
	
	for (i = 0; i < exponent; i = i+1)
		sum = sum * number;

	printf("Sum : %.2f\n", sum);	
}

//This function calculates the average.
void avg_Numbers(void)
{
	float sum = 0, avg = 0, number = 0;
	char num[10];
	int count = 0;
	
	printf("(q) -> EXIT\n");
	//If the first letter of the value entered is 'q', the loop is stopped.
	do {
		printf("Enter the number:\n");
		scanf("%s", &num[0]);
		
		if (num[0] == 'q')
			break;
		
		sscanf(num, "%f", &number);
		
		sum = sum + number;
		count = count + 1;		
	} while (num[0]!='q');
	
	avg = sum / count;

	printf("Average of numbers : %.2f\n", avg);
}
//This function finds the largest number.
void max_Numbers(void)
{
	float number, max ;
	char num[10];
	
	printf("(q) -> EXIT\n");
	//If the first letter of the value entered is 'q', the loop is stopped.
	while (num[0] != 'q') {
		printf("Please enter the number: \n");
		scanf("%s", &num[0]);
		
		sscanf(num, "%f", &number);
		
		if (num[0] == 'q')
			break;
		if (max <= number)
			max = number;
	}
	
	printf("Max number: %.2f\n", max);
}