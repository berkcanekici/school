#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h> 

void menu();
void led_status(int status);
void flash_led(void);
void square_number(int number);
void button_press(void);
void delay(int number_of_seconds);

// Arduino Com
int connection();
unsigned char serialRead();
void serialReadString(void);
int serialWrite(char data[]);

// Variables & Flags
int globalLedStatus = 0;
char szBuff[99];
HANDLE hserial;
int numberFlag = 0;

int main()
{
    int con = connection();

    if (con == 0) {
        printf("==== CONNECTION FAILED ==== \n");
        
        return EXIT_FAILURE;
    }

    printf("==== CONNECTION SUCCESSFUL ==== \n");

	menu();

	return 0;
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void menu(void)
{
	int select, square;

	printf("WELCOME TO ARDUINO LAB\n");
	printf("STUDENT NAME: BERKCAN EKICI\n");
	printf("PLEASE SELECT FROM THE FOLLOWING\n");
	printf("MENU:\n");

	do {
		printf("(1) TURN ON LED ON ARDUINO\n");
		printf("(2) TURN OFF LED ON ARDUINO\n");
		printf("(3) FLASH ARDUINO LED 3 ITEMS\n");
		printf("(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
		printf("(5) BUTTON PRESS COUNTER\n");
		printf("(0) EXIT\n");
		printf("\n> PLEASE SELECT: ");
		scanf("%d", &select);

		switch (select) {
			case 1:
				led_status(1);
				break;
			case 2:
				led_status(0);
				break;
			case 3:
				flash_led();
				break;
			case 4:
				printf("~> Enter a number please: ");
				if (scanf("%d", &square))
					square_number(square);
				else
					printf("~> Just enter numbers :) \n\n ");
				break;
			case 5:
				button_press();
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

/**
 * Led on/off Function
 *
 * @param int status (0 or 1)
 */
void led_status(int status)
{
	if (status == globalLedStatus)
		printf("Secilen islem su anda zaten gecerli \n");

	if (status == 1) {
		serialWrite("1:on");
		globalLedStatus = status;
	}
	else if (status == 0) {
		serialWrite("1:off");
		globalLedStatus = status;
	}
	else
		printf("UNDIFENED STATUS! PLEASE SELECT JUST 0 or 1 \n");
}

/**
 * Flash Led function 3 on/off
 */
void flash_led(void)
{
	serialWrite("3:flash");
}

/**
 * Square number function
 */
void square_number(int number)
{
    char squareBuff[99];

    sprintf(squareBuff, "4:%d\n", number);
	
	serialWrite(squareBuff);
	
	printf("Arduino ~> Square: ");
	
	serialReadString();
}

void button_press(void)
{
	serialWrite("5:count");
	
	printf("Button click count: ");
	
	serialReadString();
}

/**
 * Arduino Serail (COM) Connection Function
 */
int connection()
{
	DCB PortDCB;
    hserial = CreateFile("COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);

    if (hserial == INVALID_HANDLE_VALUE)
        return 0;

    PortDCB.DCBlength = sizeof(DCB);

    if (GetLastError() == ERROR_FILE_NOT_FOUND) {
        printf(" COM baglantinizi kontrol ediniz \n");
        return 0;
    }

    if (!GetCommState(hserial, &PortDCB))     
        return 0;

    PortDCB.BaudRate = 9600;       
    PortDCB.ByteSize = 8;      
    PortDCB.Parity = NOPARITY;  
    PortDCB.StopBits = ONESTOPBIT; 

    if (!SetCommState(hserial, &PortDCB))   
        return 0;

    return 1;
}

/**
 * Serial Read function
 */
unsigned char serialRead()
{
    DWORD okunan = 0;  
    unsigned char Harf;
    int i;

    while(okunan == 0)
        ReadFile(hserial,&Harf,1,&okunan,NULL);	

    return Harf;
}

void serialReadString(void)
{
	int i, j;
    char serialChar;
    char serialString[99];

    for (i = 0;; i++) {
        serialChar = serialRead();
        
        if (serialChar == '|')
            break;

        serialString[i] = serialChar;
    }
    
    for (j = 0; j < i; j++)
        printf("%c", serialString[j]);

    printf("\n");
}

/**
 * Serial Write function
 * 
 * @param char data[]
 */
int serialWrite(char data[])
{
	DWORD okunan = 0;

	sprintf(szBuff, "%s\n", data);

	if (!WriteFile(hserial, szBuff, strlen(szBuff), &okunan, NULL)) {
		printf("\n ==== Port Yazma hatasi! ==== \n");
		return 1;
	}
	
    return 0;
}
