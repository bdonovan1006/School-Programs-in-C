/*
Brian Donovan
915106202
Lab 3 ATM
2/17/17
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define PIN 3014

double cBalance(double b);
double withdraw(double b, double dw);
double deposit(double b, double dd);
void cmo(void);
void receipt(void);

int main(int argc, char** argv) {

	double bal = 5000.00, dayd = 0, dayw = 0;
	int transC = 0, pinC = 0, psswd = 0, choice = 0, temp;
	bool done = 0;


	printf("Please enter your PIN number: ");
	scanf("%d", &psswd);
	while (psswd != PIN) 
	{
		if (psswd != PIN && pinC != 2) 
		{
			pinC++;
			puts("Incorrect PIN, try again");
		} else if (pinC == 2) 
		{
			puts("Final attempt used. Logging off");
			exit(0);
		}
		scanf("%d", &psswd);
	}
	
	do 
	{		
		puts("\nPlease choose an option: \n\t1 Balance \n\t2 Cash withdrawal \n\t3 Cash deposit \n\t4 Quit\n");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1:
			printf("Balance: $%.2lf", cBalance(bal));
			transC++;
			receipt();
			break;
		case 2:
			if (dayw < 1000)
			{			
				temp = withdraw(bal, dayw);
				dayw += temp;
				bal -= temp;
				transC++;
				receipt();
				break;
			} else {
				puts("You have exceeded your daily withdraw amount");
				break;
			}			
		case 3: 
			if (dayd < 10000){
				temp = deposit(bal, dayd);
				dayd += temp;
				bal += temp;
				transC++;
				receipt();
				break;
			} else {
				puts("You have exceeded your daily deposit amount");
				break;
			}						
		case 4:
			done = 1;
			break;		
		default: 
			puts("\nPlease make a valid selection\n");
		}		
	} while(!done);
	printf("\nThank you for using the ATM.\nYou made %d transactions\n",transC);
	exit(0);
}

double cBalance(double b) 
{
	 return (b);
}

double withdraw(double b, double dw) 
{	
	double with;
	bool check = 1; 
	puts("Enter amount to withdraw (Multiples of $20 only)");
	scanf("%lf", &with);
	while (check) 
	{
		if (b == 0)
		{
			puts("\nThere are no funds available");
			check = 0;
		} else if ((int)with % 20 != 0 || with < 0.0 || with > 1000.0 || with > b || (with + dw) > 1000 || with != (int)with) {	
			puts("Invalid amount, try again");
			scanf("%lf", &with);
			check = 1;		
		} else {
			check = 0;
		}		
	}
	return (with);
}

double deposit(double b, double dd) 
{
	double dep;
	bool check = 1;
	puts("Enter an amount to deposit: ");
	scanf("%lf", &dep);
	while (check) {
		
		if (dep < 0.0 || dep > 10000.0 || (dep + dd) > 10000.0 || dep != (int)dep)
		{
			puts("Invalid amount, try again");
			scanf("%lf", &dep);
			check = 1;
		} else {
			check = 0;		
		}
	}
	return (dep);
}

void receipt(void) {
	int ans;
	printf("\nWould you like a receipt? 1 for yes, 0 for no: ");
	scanf("%d", &ans);
}