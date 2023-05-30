#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1
#define SIZE 32

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
int validate_card(int card[], int size);

int main(void)
{
	int card[NUM_DIGITS];
  /* use visa to store the credit card number from stdin */
  char visa[SIZE + 1];


	fgets(visa, SIZE + 1, stdin);
	convert_card(card, visa, NUM_DIGITS);
	return 0;
}

/**
 * Validates card
 * @param card[] card array
 * @param num[] num array
 * @param num_digits size of array
 */
void convert_card(int card[], char num[], int num_digits)
{
	int i;
	int val;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

	print_card(card, NUM_DIGITS);
	val = validate_card(card, NUM_DIGITS);

	switch(val){

		case VALID:
			printf("\n");
			printf("VALID\n");
			break;

		case INVALID:
			printf("\n");
			printf("INVALID\n");
			break;
	}
}

/**
 * prints card
 * @param card[] array 
 * @param size size of array
 * @return validate status
 */
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d",card[i]);
}

/**
 * Validates card
 * @param card array index value
 * @param size size of array
 * @return validate status
 */
int validate_card(int card[], int size){

	int first, last;
	int add_buff = 0;
	int validate;

for(int i = 0; i < size; i+=2){

	card[i] = card[i] * 2;

	if(card[i] > 9){

		last = card[i] % 10;
		first = card[i] / 10;
		card[i] = first + last; 

	}
}

for(int j = 0; j < size; j++ ){

	add_buff = card[j] + add_buff;

}

validate = add_buff % 10;

if(validate != 0){
	validate = -1;
}

return validate;

}
