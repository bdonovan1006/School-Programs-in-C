
/*Brian Donovan
* 915106202
* 2/3/17
* Lab 2
*/

// gcc -o demo donovan_Paycheck.c


#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

	int eNum;
	double hSal, wkTime, oTime, netP, otP, regP;

	puts("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");

	puts("\tEnter Employee Number: ");
	scanf("%d", &eNum);

	if (eNum <= 0) {
		puts("\tThis is not a valid Employee Number.\n\tPlease run the program again");
		puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
		exit(0);
	}

	printf("\n\tEnter Hourly Salary: ");
	scanf("%lf", &hSal);

	if (hSal <= 0) {
		puts("\tThis is not a valid hourly salary amount.\n\tPlease run the program again");
		puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
		exit(0);
	}
	printf("\n\tEnter Weekly Time: ");
	scanf("%lf", &wkTime);

	if (wkTime <= 0) {
		puts("\tThis is not a valid weekly time.\n\tPlease run the program again");
		puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
		exit(0);
	}

	oTime = wkTime - 40;
	if (oTime < 0) {
		oTime = 0;
	}
	regP = (wkTime - oTime) * hSal;
	otP = oTime * hSal * 1.5;
	netP = otP + regP;



	puts("\t===============");
	printf("\tEmployee #: %d\n", eNum);
	printf("\tHourly Salary: %.2lf\n", hSal);
	printf("\tWeekly Time: %.2lf\n", wkTime);
	printf("\tRegular Pay: $%.2lf\n", regP);
	printf("\tOvertime Pay: $%.2lf\n", otP);
	printf("\tNet Pay: $%.2lf\n", netP);
	puts("\t===============");

	puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
	exit(0);
}


