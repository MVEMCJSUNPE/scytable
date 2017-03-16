#include <stdio.h>
#include <stdlib.h>

const int characters = 17424;

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
    while (!feof(keys)) {
	fscanf(keys, "%c", &c);
	if (c == ' ') {
	    printf("\n");
	}
	else {
	    printf("%c", c);
	    //Extra line printed for some reason
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
    FILE* keys = NULL;
    keys = fopen("keys.txt", "r");
    if (keys == NULL) {
        printf("Could not open file keys.txt\n");
	      return -1;
    }
    FILE* cipher = NULL;
    keys = fopen("cipher.txt", "r");
    if (cipher == NULL) {
        printf("Could not open file cipher.txt\n");
	      return -1;
    }
    char cipherText[characters];
    printWords(keys);
    readCipher(cipher, cipherText);
    promptUser(cipherText);
    fclose(keys);
    fclose(cipher);

}
