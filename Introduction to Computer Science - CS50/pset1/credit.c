#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <cs50.h>

int get_length_long_long(long long a);
int get_length_int(int a);
int step_one(long long cc);
int step_two(long long cc);
void check_card_type(long long cc);


int main(void) {
	long long cc_number = 0;
	int checksum = 0;

	cc_number = GetLongLong();

	checksum = step_one(cc_number) + step_two(cc_number);

	if ((checksum % 10) == 0) {
		check_card_type(cc_number);
	}

	else {
		printf("INVALID\n");
	}

	return 0;
}


// Returns the number of digits
// in a given long long
int get_length_long_long(long long a) {
	int length = 0;

	while (a != 0) {
		a /= 10;
		++length;
	}

	return length;
}


// Returns the number of digits
// in a given int
int get_length_int(int a) {
	int length = 0;

	while (a != 0) {
		a /= 10;
		length++;
	}

	return length;
}


// Multiplies every other digit by 2 (starting with the second-to-last digit), adds the products digits
// together, and finally returns the sum.
int step_one(long long cc) {
    int cc_length = 0, sum = 0;
    cc_length = get_length_long_long(cc);

	// Shortens the credit card number by 1 so the for loop has a starting point
	cc = (cc / 10);

	// This for-loop stores the last digit of "cc" in "digit". It then mulitplies "digit"
	// by 2 and checks if the product has two digits in it. 
	// If yes, it breaks the product into individual digits and adds each into "sum".
	// If no,  it adds the product into "sum".
	// The for-loop then removes the last two digits from "cc".
	for (int i = 0; i < (cc_length / 2); i++) {
		int digit = cc % 10;
		digit *= 2;
		if (get_length_int(digit) == 2) {

			for (int i = 0; i < 2; i++) {
				sum += (digit % 10);
				digit /= 10;

			}
		}

		else {
			sum += digit;
		}

		cc = (cc / 100);

	}

	return sum;
}


// Gets the sum of the other digits not used in step_one
int step_two(long long cc) {
	int cc_length = 0, sum = 0;
    cc_length = get_length_long_long(cc);

	for (int i = 0; i < (cc_length / 2) + 1; i++) {
		int digit = cc % 10;

		sum += digit;
		cc = (cc / 100);	
	}	

	return sum;
}


//Checks which bank the card belongs to
void check_card_type (long long cc) {
	int cc_length = 0;
	long long first_digit = 0;
	cc_length = get_length_long_long(cc);
    
    first_digit = cc;
    while (first_digit > 10) {
        first_digit /= 10;
    }
    
	if ((cc_length == 15) && ((cc >= 340000000000000) && (cc < 350000000000000)) || ((cc >= 370000000000000) && (cc < 380000000000000))) {
		printf("AMEX\n");
	}

	else if ((cc_length == 16) && ((cc >= 5100000000000000) && (cc < 5600000000000000))) {
		printf("MASTERCARD\n");
	}
	
	else if (((cc_length == 13) || (cc_length == 16)) && (first_digit == 4)) {
	    printf("VISA\n");
	}

	else {
		printf("INVALID\n");
	}
}