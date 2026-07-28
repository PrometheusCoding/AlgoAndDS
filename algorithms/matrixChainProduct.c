#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printOptimalMCPSplit(int i, int j, int numOfMatrix, int parenthesesSplit[numOfMatrix][numOfMatrix]){

    int splitPoint = parenthesesSplit[i][j];
    if (i == j){
        printf("M_%d", i+1);
        return;
    } else {

        if (i == splitPoint){
            printOptimalMCPSplit(i, splitPoint, numOfMatrix, parenthesesSplit);
        } else {
            printf("(");
            printOptimalMCPSplit(i, splitPoint, numOfMatrix, parenthesesSplit);
            printf(")");
        }
        
        if (j == splitPoint+1){
            printOptimalMCPSplit(splitPoint+1, j, numOfMatrix, parenthesesSplit);        
        } else {
                printf("(");
                printOptimalMCPSplit(splitPoint+1, j, numOfMatrix, parenthesesSplit);
                printf(")");
            }

    }

}

int MCP(int numOfMatrix, int* dimOfMatrices){

    // Matrix A_i+1 has dimensions dimOfMatrices[i] x dimOfMatrices[i+1]
    // where i is from 0...numOfMatrix

    int numOfMatrixCalculations[numOfMatrix][numOfMatrix];
    int parenthesesSplit[numOfMatrix][numOfMatrix];

    for (int iter = 0; iter<numOfMatrix; iter++){
        numOfMatrixCalculations[iter][iter] = 0;
        parenthesesSplit[iter][iter] = -1;
    }

    for (int lengthOfChain = 1; lengthOfChain < numOfMatrix; lengthOfChain++){

        for (int iterOne = 0; iterOne<numOfMatrix-lengthOfChain; iterOne++){ // iterOne is start point 

            int lastMatrixIndex = iterOne + lengthOfChain;
            int multiplyFirstAndLastDim = dimOfMatrices[iterOne] * dimOfMatrices[lastMatrixIndex + 1];
            numOfMatrixCalculations[iterOne][lastMatrixIndex] = 10000000;

            for (int iterTwo = iterOne; iterTwo < lastMatrixIndex; iterTwo++){ // iterTwo is split point
                int potentialNumOfMults = numOfMatrixCalculations[iterOne][iterTwo] + multiplyFirstAndLastDim*dimOfMatrices[iterTwo+1] + numOfMatrixCalculations[iterTwo+1][lastMatrixIndex];
                if (numOfMatrixCalculations[iterOne][lastMatrixIndex] > potentialNumOfMults){
                    numOfMatrixCalculations[iterOne][lastMatrixIndex] = potentialNumOfMults;
                    parenthesesSplit[iterOne][lastMatrixIndex] = iterTwo;
                }
            }

        }

    }

    printOptimalMCPSplit(0, numOfMatrix-1, numOfMatrix, parenthesesSplit);
    return numOfMatrixCalculations[0][numOfMatrix-1];
}

int main(){

    int dims[] = {30, 35, 15, 5, 10, 20, 25};
    int numOfMatrix = 6;
    int result = MCP(numOfMatrix, dims);
    printf("%d\n", result);

    int dimsTwo[] = {10, 20, 30, 40};
    int numOfMatrixTwo = 3;
    int resultTwo = MCP(numOfMatrixTwo, dimsTwo);
    printf("%d\n", resultTwo);

    return 0;
}
