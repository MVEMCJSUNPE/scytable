#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)		// Disable security error for Visual Studio
const int characters = 17424;

void header() {
	printf("Welcome to the decoding program, where hidden messages are found inside of a text file.\n\n");
	printf("Author: Shehab Zalloum & Daniel Xu\n");
	printf("Program : #4, Secret\n");
	printf("TA : Michael, Tues 4\n");
	printf("Mar 5, 2017\n\n");
	printf("Read in 3 keyWords, which are :\nquick\nget\ngoing\n\n");
	printf("Read in 390 cipherText characters.\n\n");
	printf("Choose from the following options :\n");
	printf("	1. Display a particular sized table\n");
	printf("	2. Find all matching key word phrases\n");
	printf("	X.Exit the program\n");
	printf("Enter your choice -> \n\n");
	printf("Found 'get' diagonally with table size 15 at 4. Secret message : get cash prize ses\n");
}


int positionOfCharInWord(char string[], char searchChar, int position) {
    int index = position;
    while (string[index] != '\0') {
	if (string[index] == searchChar) {
	    return index;
	}
	index++;
    }
    return -1;
}

//Stage 1

void printWords(FILE* keys) {
	int i = 0;
	char c = '-';
	while (fscanf(keys, "%c", &c) != EOF) {
		if (c == ' '){
			printf("\n");
			}
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			printf("%c", c);
		}
		else {
			continue;
			}
		}
}

//Stage 2
//DO NOT USE 17424 in a for loop for this function. Otherwise, it will print characters past '\0'. 
void readCipher(FILE* cipher, char cipherText[characters]) {
    int i = 0;
    int j = 0;
    char c = '-';
    while (!feof(cipher)) {
	fscanf(cipher, "%c", &c);
	cipherText[i] = c;
	++i;
    }
    cipherText[i] = '\0';
    while (cipherText[j] != '\0') {
	printf("%c", cipherText[j]);
	++j;
    }
}

//Stage 3
void promptUser(char cipherText[characters]) {
    int number = 0;
    int i = 0;
    printf("Please enter a number (1..132): \n");
    scanf("%d", &number);
    while (cipherText[i] != '\0') {
	if ((i % number == 0) ) {
	    printf("\n");
	    printf("%c", cipherText[i]);
	    ++i;
	}
	else {
	    printf("%c", cipherText[i]);
	    ++i;
	}
    }
}


int main(void) {
	char keyText[characters];
	FILE* keys = NULL;
	keys = fopen("keys.txt", "r");
	if (keys == NULL) {
		printf("Could not open file keys.txt\n");
		exit(-1);
	}

	char cipherText[characters];
	FILE* cipher = NULL;
	cipher = fopen("cipher.txt", "r");
	if (cipher == NULL) {
		printf("Could not open file cipher.txt\n");
		exit(-1);
	}

	char cipherOriginal[characters];
	FILE* cipherOrg = NULL;
	cipherOrg = fopen("cipherOriginal.txt", "r");
	if (cipherOrg == NULL) {
		printf("Could not open file cipherOriginal.txt\n");
		exit(-1);
	}

    printWords(keys);
    readCipher(cipher, cipherText);
    promptUser(cipherText);
    fclose(keys);
    fclose(cipher);
	
	int rey = 0;			//make useless variable to stop program form exiting console in visual studio
	scanf("%d", &rey);		// same as above

}
