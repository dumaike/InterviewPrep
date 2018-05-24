#include "flipbittowin.h"

#include <iostream>
#include <bitset>

using namespace bitmanipulation;

void FlipBitToWin::runTestCases(){
  singleTest(0b1);
  singleTest(0b101);
  singleTest(0b10101);
  singleTest(0b1101110111);
}

void FlipBitToWin::singleTest(int input){
  cout << "On binary input " << std::bitset<32>(input) << " the max is " << flipBitToWin(input) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 5 Question 3 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int FlipBitToWin::flipBitToWin(int input){
  vector<int> contiguousBitVector = vector<int>();

  int bitCheck = 1 << 30;
  
  int contiguousBitCount = 0;
  while (bitCheck != 0){
    int bitAnd = input & bitCheck;
    if (bitAnd != 0){
      contiguousBitCount++;
    } else {
      contiguousBitVector.push_back(contiguousBitCount);
      contiguousBitCount = 0;
    }

    bitCheck = bitCheck >> 1;
  }
  contiguousBitVector.push_back(contiguousBitCount);

  int maxSoFar = 0;
  for (int i = 0; i < contiguousBitVector.size() - 1; ++i){
    int leftAndRightSum = contiguousBitVector[i] + contiguousBitVector[i+1];
    if (leftAndRightSum > maxSoFar) {
      maxSoFar = leftAndRightSum;
    }
  }
  
  return maxSoFar + 1;
}