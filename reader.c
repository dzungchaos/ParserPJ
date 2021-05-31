/*
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdio.h>
#include "reader.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

FILE* inputStream;
int lineNo, colNo;
int currentChar;

int readChar(void) {
    currentChar = getc(inputStream);
    colNo++;
    if (currentChar == '\n') {
        lineNo++;
        colNo = 0;
    }
    return currentChar;
}

int openInputStream(char* fileName) {
    inputStream = fopen(fileName, "rt");
    if (inputStream == NULL)
        return IO_ERROR;
    lineNo = 1;
    colNo = 0;
    readChar();
    return IO_SUCCESS;
}

void closeInputStream() {
    fclose(inputStream);
}
