
/*
 *      More comfortable version of Mario.c
 */


#include <stdio.h>

int main(void) {
	int height;

	/*
	 *	This do-while loop asks for the desired height and 
	 *  whether or not its higher than 0 and less than 23
	 */	

	do {
		printf("Height: ");
		scanf("%i", &height);
	}

	while (height < 0 || height > 23);



	for (int i = 0; i < height; i++) {

		for (int j = 0; j < height - i - 1; j++) {
			printf(" ");
		}

		for (int k = 0; k <= i; k++) {
			printf("#");
		}

		printf("  ");

		for (int l = 0; l <= i; l++) {
			printf("#");
		}

		printf("\n");
	}
	
}
