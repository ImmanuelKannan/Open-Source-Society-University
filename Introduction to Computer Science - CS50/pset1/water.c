#include <stdio.h>

int minutes_to_bottles(int minutes);

int main(void) {
	int c, minutes;

		printf("Minutes: ");
		scanf("%i", &minutes);
		printf("Bottles: %i\n", minutes_to_bottles(minutes));

}

int minutes_to_bottles(int minutes) {
	int ounces, bottles;

	ounces = minutes * 192;
	bottles = ounces / 16;

	return bottles;
}