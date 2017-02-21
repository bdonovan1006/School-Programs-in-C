/*Brian Donovan
* 915106202
* 2/3/17
* Lab 2
*/

// gcc -o demo donovan_Paycheck.c


#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv) {

	int quant;
	double price, cost, disc, discAmt, total;

	puts("Welcome to \"Temple\" store \n");
	printf("\tEnter item price: ");
	scanf("%lf", &price);

	if (price <= 0) {
		puts("\tThis is not a valid price.\n\tPlease run the program again");
		puts("\nThank you for using \"Temple\" store");
		exit(0);
	}
	printf("\tEnter quantity: ");
	scanf("%d", &quant);

	if (quant <= 0) {
		puts("\tThis is not a valid quantity.\n\tPlease run the program again");
		puts("\nThank you for using \"Temple\" store");
		exit(0);
	} else {
		cost = (price * quant);
		if (quant > 0 && quant < 50) {
			disc = 0.00;		
		} else if (quant > 49 && quant < 100) {
			disc = 10.00;
		} else if (quant > 99 && quant < 150) {
			disc = 15.00;
		} else {
			disc = 25.00;
		}

		discAmt = (disc / 100) * cost;
		total = (cost - discAmt);
	} 

	printf("\n\tThe item price is: %.2lf\n", price);
	printf("\tTthe order is: %d item(s)\n", quant);
	printf("\tThe cost is: %.2lf\n", cost);
	printf("\tThe discount is: %.2lf%%\n", disc);
	printf("\tThe discount amount is: $%.2lf\n", discAmt);
	printf("\tThe total is: $%.2lf\n", total);	

	puts("\nThank you for using \"Temple\" store");
	exit(0);
}


