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
void compareHorizontal(char keyArray[maxWords][maxWordSize], char cipherText[cipherChar], int numWords) {
    int i = 0;
    int j = 0;
    int firstLetterIndex = 0;
    int wordIndex = 0;
    int value = 1;
    int count = 0;
    char c = '-';
    for (i = 0; i < numWords; ++i) {
	while (index != -1) {
	    firstLetterIndex = positionOfCharInWord(cipherText, keyArray[i][0], firstLetterIndex + 1); 
	    wordIndex = firstLetterIndex;
	    while (keyArray[i][j] != '\0') {
		value = value * (cipherText[index] == keyArray[i][j]);
		++j;
		++wordIndex;
		printf("wordIndex: %d\n", wordIndex);
	    }
	    if (value == 1) {
		while (count < 3) {
		    c = cipherText[index];
		    //printf("%c", c);
		    ++index;
		    if (c == ' ') {
			++count;
		    }
		}
	    }
	}
    }
}

/*
void compareDiagonal(char keyArray[maxWords][maxWordSize], char cipherText[cipherChar], int charLine, int numWords) {
    int i = 0;
    int j = 0;
    int index = 0;
    int value = 1;
    int count = 0;
    char c = '-';
    for (i = 0; i < numWords; ++i) {
	while (index != -1) {
	    index = positionOfCharInWord(cipherText, keyArray[i][0], index + 1); 
	    while (keyArray[i][j] != '\0') {
		value = value * (cipherText[index] == keyArray[i][j]);
		++j;
		index;
	    }
	if (value == 1) {
	    while (count < 3) {
		if (c == ' ') {
		    c = cipherText[index];
		    printf("%c", c);
		    ++index;
		    ++count;
		}
		else {
		    c = cipherText[index];
		    printf("%c", c);
		    ++index;
		}

	    }
	}
	}
    }
}
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
    int charLine = 0;
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
    printWords(keys);
    //stage 2
    readCipher(cipher, cipherText);
    fclose(cipher);
    //stage 3
    promptUser(cipherText, &charLine);
    compareHorizontal(keyArray, cipherText, numWords);
    fclose(keys);
    
}
