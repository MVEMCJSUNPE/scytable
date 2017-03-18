#include <stdio.h>
#include <stdlib.h>

const int cipherChar = 17424;
const int maxWords = 20;
const int maxWordSize = 25;

//stage 0
void header(void) {
    printf(
    "Welcome to the decoding program, where hidden messages are found inside of a text file.\n \n"
    "Author: Daniel Xu and Shehab Zalloum\n"
    "Program: #4, Secret\n" 
    "TA: Nianzu Ma, Wednesday, 4:00 P.M.\n" 
    "Mar 5, 2017\n" 
    );
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

int totalWordsKeys(char keys[maxWords][maxWordSize]) {
    int keyLength = 0;
    while (keys[keyLength][0] != '\0') {
	keyLength++;
    }
    return keyLength;
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
    printf("Before: last word: %c", keyArray[words][j]);
    keyArray[words][j - 1] = '\0';
    printf("After: last word: %c", keyArray[words][j - 2]);
    keyArray[words + 1][0] = '\0';
    return words + 1;
}


//Stage 1
void printWords(char keyArray[maxWords][maxWordSize]) {
    int i = 0;
    char c = '-';
    while (keyArray[i][0] != '\0') {
	printf("%s\n", keyArray[i]);
	++i;
    }
}

//Stage 2
void readCipher(FILE* cipher, char cipherText[cipherChar]) {
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
void promptUser(char cipherText[cipherChar], int* charLine) {
    int i = 0;
    printf("Please enter a number (1..132): \n");
    scanf("%d", charLine);
    while (cipherText[i] != '\0') {
	if ((i % *charLine == 0) ) {
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
void compareHorizontal(char keyArray[maxWords][maxWordSize], char cipherText[cipherChar], int charLine, int numWords) {
    int i = 0;
    int j = 0;
    int firstLetterIndex = 0;
    int wordIndex = 0;
    int value = 1;
    int count = 0;
    char c = '-';
    int matchIndex = 0;
    for (i = 0; i < numWords; ++i) {
	printf("i: %d\n", i);
	while (firstLetterIndex != -1) {
	    firstLetterIndex = positionOfCharInWord(cipherText, keyArray[i][0], firstLetterIndex + 1); 
	    printf("    firstLetterIndex: %d\n", firstLetterIndex);
	    wordIndex = firstLetterIndex;
	    while ((keyArray[i][j] != '\0') /*&& (value == 1)*/) {
		printf("        wordIndex: %d\n", wordIndex);
		value = value * (cipherText[wordIndex] == keyArray[i][j]);
		++j;
		++wordIndex;
		printf("            j: %d\n", j);
		printf("            value: %d\n", value);
	    }
	    if (value == 1) {
		printf("Found \"%s\" horizontally with table size %d at %d. Secret message: ", keyArray[i], charLine, firstLetterIndex);
		matchIndex = firstLetterIndex;
		while (count < 4) {
		    c = cipherText[matchIndex];
		    printf("%c", c);
		    ++matchIndex;
		    if (c == ' ') {
			++count;
		    }
		}
		count = 0;
		printf("\n");
	    }
	    value = 1;
	    j = 0;
	}
	firstLetterIndex = 0;
    }
}


void compareDiagonal(char keyArray[maxWords][maxWordSize], char cipherText[cipherChar], int charLine, int numWords) {
    int i = 0;
    int j = 0;
    int firstLetterIndex = 0;
    int wordIndex = 0;
    int value = 1;
    int count = 0;
    char c = '-';
    int matchIndex = 0;
    int column = 0;
    for (i = 0; i < numWords; ++i) {
	//printf("i: %d\n", i);
	while (firstLetterIndex != -1) {
	    firstLetterIndex = positionOfCharInWord(cipherText, keyArray[i][0], firstLetterIndex + 1); 
	    //printf("    keyArray[i][0]: %c\n", keyArray[i][0]);
	    wordIndex = firstLetterIndex;
	    while ((keyArray[i][j] != '\0') /*&& (value == 1)*/) {
		//printf("        wordIndex: %d\n", wordIndex);
		value = value * (cipherText[wordIndex] == keyArray[i][j]);
		++j;
		wordIndex = wordIndex + charLine + 1;
		//printf("            j: %d\n", j);
		//printf("            value: %d\n", value);
	    }
	    if (value == 1) {
		printf("Found \"%s\" diagonally with table size %d at %d. Secret message: ", keyArray[i], charLine, firstLetterIndex);
		matchIndex = firstLetterIndex;
		while (count < 4) {
		    c = cipherText[matchIndex];
		    printf("%c", c);
		    matchIndex = matchIndex + charLine + 1;
		    if (c == ' ') {
			++count;
		    }
		}
	    printf("\n");
	    }
	    value = 1;
	    j = 0;
	}
	firstLetterIndex = 0;
    }
}

void tryAllPossibleValues(char keyArray[maxWords][maxWordSize], char cipherText[cipherChar], int numWords) {
    int i = 13;
    compareHorizontal(keyArray, cipherText, i, numWords);
    for (i = 13; i < 132; ++i) {
	compareDiagonal(keyArray, cipherText, i, numWords);
    }
}

int main(void) {
    //Creating keys file pointer variable
    FILE* keys = NULL;
    keys = fopen("keys.txt", "r");
    if (keys == NULL) {
	printf("Could not open file keys.txt\n");
	return -1;
    }
    //Creating cipher file pointer variable
    FILE* cipher = NULL;
    cipher = fopen("cipher.txt", "r");
    if (cipher == NULL) {
	printf("Could not open file cipher.txt\n");
	return -1;
    }
    char cipherText[cipherChar];
    int charLine = 0;
    int numWords = 0;
    char userInput = 0;
    char keyArray[maxWords][maxWordSize];
    numWords = convertTo2DArray(keys, keyArray);
    /*
    //stage 0
    header();
    //stage 1
    printf("Read in %d keyWords, which are:\n", numWords);
    printWords(keyArray);
    //stage 2
    //Do NOT DO: Have readCipher return the number of characters and use that with %d in the printf statement below
    printf(
    "Read in cipherText characters.\n \n"
    "Choose from the following options:\n"     
    "   1. Display a particular sized table\n" 
    "   2. Find all matching key word phrases\n" 
    "   3. Place key word phrase into a datafile (not required for students)\n" 
    "   X. Exit the program\n" 
    "Enter your choice -> "
    );
    scanf("%c", &userInput);
    readCipher(cipher, cipherText);
    switch(userInput) {
	case '1':
	    //stage 3
	    promptUser(cipherText, &charLine);
	    compareHorizontal(keyArray, cipherText, charLine, numWords);
	    compareDiagonal(keyArray, cipherText, charLine, numWords);
	    break;
	case '2':
	    //stage 4
	    tryAllPossibleValues(keyArray, cipherText, numWords);
	    break;
	case 'x':
	    return 0;
	case 'X':
	    return 0;
	    break;
	default:
	    printf("You did not enter a valid input. Please try again.\n");
	    break;
    }
    */
    fclose(cipher);
    fclose(keys);
    
}
