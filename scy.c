#include <stdio.h>
#include <stdlib.h>

const int characters = 17424;
//const int 
//void readIn(file);
int promptUser(char array[characters]) {
    int number = 0;
    printf("Please enter a number (1..132): \n");
    scanf("%d", &number);
    printf("userInput: %d\n", number);
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


int main(void) {
    char cipherText[characters];
    FILE* keys = NULL;
    keys = fopen("keys.txt", "r");
    if (keys == NULL) {
        printf("Could not open file keys.txt\n");
	      return -1;
    }
    for (i = 0; i < 25; i++) {
	    
    }

    promptUser();

}
