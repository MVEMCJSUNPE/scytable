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

#include <stdio.h>
#include <stdlib.h>

const int cipherChar = 17424;
const int maxWords = 20;
const int maxWordSize = 25;
//const int 
//void readIn(file);

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


int convertTo2DArray(FILE* keys, char keyArray[maxWords][maxWordSize]) {
    char c = '-';
    int words = 0;
    int j = 0;
    while (fscanf(keys, "%c", &c) != EOF) {
	if (c == ' ') {
	    keyArray[words][j] = '\0';
	    ++words;
	    j = 0;
	}
	else {
	    keyArray[words][j] = c;
	    ++j;
	}
    }
    return words + 1;
}

/*
int length(FILE* keys) {
    int count = 0;
    while (!feof(keys)) {
    ++
	    }
*/

//Stage 1
void printWords(FILE* keys) {
    int i = 0;
    char c = '-';
    while (!feof(keys)) {
	fscanf(keys, "%c", &c);
	if (c == ' ') {
	    printf("\n");
	}
	else {
	    printf("%c", c);
	}
    }
}

//Stage 2
int readCipher(FILE* cipher, char cipherText[cipherChar]) {
    int i = 0;
    int j = 0;
    char c = '-';
    while (!feof(cipher)) {
	//if error shows up, might want to check here.
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
void promptUser(char cipherText[cipherChar], int* number) {
    int i = 0;
    printf("Please enter a number (1..132): \n");
    scanf("%d", number);
    while (cipherText[i] != '\0') {
	if ((i % *number == 0) ) {
	    printf("\n");
	    printf("%c", cipherText[i]);
	    ++i;
	}
	else {
	    printf("%c", cipherText[i]);
	    ++i;
	}
    }

//#include <stdio.h>
#include <stdlib.h>

const int cipherChar = 17424;
const int maxWords = 20;
const int maxWordSize = 25;
//const int 
//void readIn(file);

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


int convertTo2DArray(FILE* keys, char keyArray[maxWords][maxWordSize]) {
    char c = '-';
    int words = 0;
    int j = 0;
    while (fscanf(keys, "%c", &c) != EOF) {
	if (c == ' ') {
	    keyArray[words][j] = '\0';
	    ++words;
	    j = 0;
	}
	else {
	    keyArray[words][j] = c;
	    ++j;
	}
    }
    return words + 1;
}

/*
int length(FILE* keys) {
    int count = 0;
    while (!feof(keys)) {
    ++
	    }
*/

//Stage 1
void printWords(FILE* keys) {
    int i = 0;
    char c = '-';
    while (!feof(keys)) {
	fscanf(keys, "%c", &c);
	if (c == ' ') {
	    printf("\n");
	}
	else {
	    printf("%c", c);
	}
    }
}

//Stage 2
int readCipher(FILE* cipher, char cipherText[cipherChar]) {
    int i = 0;
    int j = 0;
    char c = '-';
    while (!feof(cipher)) {
	//if error shows up, might want to check here.
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
void promptUser(char cipherText[cipherChar], int* number) {
    int i = 0;
    printf("Please enter a number (1..132): \n");
    scanf("%d", number);
    while (cipherText[i] != '\0') {
	if ((i % *number == 0) ) {
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

//Stage 4
/*
void compareDiagonal(FILE* keys, char cipherText[cipherChar], int number) {
    int i = 0;
    char c = 
    int index = 0;
    while (index != -1) {
	index = positionOfCharInWord(cipherText, ' ', index + 1);
*/


int main(void) {
    //Creating keys file variable
    FILE* keys = NULL;
    keys = fopen("keys.txt", "r");
    if (keys == NULL) {
	printf("Could not open file keys.txt\n");
	return -1;
    }
    //Creating cipher file variable
    FILE* cipher = NULL;
    cipher = fopen("cipher.txt", "r");
    if (cipher == NULL) {
	printf("Could not open file cipher.txt\n");
	return -1;
    }
    char cipherText[cipherChar];
    int number = 0;
    int numWords = 0;
    char keyArray[maxWords][maxWordSize];
    numWords = convertTo2DArray(keys, keyArray);
    /*
    for (i = 0; i < 3; ++i) {
	printf("%s", keyArray[i]);
	printf("\n");
    }
    */
    //stage 1
    //printWords(keys);
    //stage 2
    //readCipher(cipher, cipherText);
    printf("numWords: %d", numWords);
    fclose(cipher);
    //stage 3
    //promptUser(cipherText, &number);
    fclose(keys);
    
}
