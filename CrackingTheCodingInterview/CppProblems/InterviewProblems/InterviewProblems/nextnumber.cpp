#include "nextnumber.h"

#include <iostream>
#include <bitset>

using namespace bitmanipulation;

void NextNumber::runTestCases(){
  singleTest(0b01);
  singleTest(0b10);
  singleTest(0b0111);
  singleTest(0b101);
  singleTest(0b11011);
  singleTest(0b00100);
  //Fail case
  singleTest(0b001111100);
}

void NextNumber::singleTest(int input){
  pair<int,int> efficientResult = nextLargestNumber(input);
  pair<int,int> bruteResult = nextLargestNumberBruteForce(input);
  cout << "On binary input " << std::bitset<32>(input) << " the next smaller is " << std::bitset<32>(efficientResult.first) <<
    " and the next bigger is " << std::bitset<32>(efficientResult.second);

  if (efficientResult.first == bruteResult.first && efficientResult.second == bruteResult.second)
    cout << " PASSED" << endl;
  else
    cout << " FAILED" << endl;

  cout << "-------------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 5 Question 4 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
pair<int,int> NextNumber::nextLargestNumber(int input){
  pair<int,int> returnNumber = pair<int,int>(NOT_FOUND, NOT_FOUND);

  //First find smaller number
  int firstDigitMask = 1;
  int secondDigitMask = 1 << 1;
  int deltaAmount = firstDigitMask;
  for (int i = 0; i < 10; ++i){
    //If digits are 10
    if (((~input & firstDigitMask) != 0) && ((input & secondDigitMask) != 0)){
      returnNumber.first = input - deltaAmount;
      break;
    }

    deltaAmount *= 2;
    firstDigitMask *= 2;
    secondDigitMask *= 2;
  }

  //Find the larger number
  firstDigitMask = 1;
  secondDigitMask = 1 << 1;
  deltaAmount = 1;
  for (int i = 0; i < 10; ++i){
    //If digits are 01
    if (((input & firstDigitMask) != 0) && ((~input & secondDigitMask) != 0)){
      returnNumber.second = input + deltaAmount;
      break;
    }

    deltaAmount *= 2;
    firstDigitMask *= 2;
    secondDigitMask *= 2;
  }

  return returnNumber;
}

//A brute force version to check against (maxing out at 1024)
pair<int,int> NextNumber::nextLargestNumberBruteForce(int input){
  int origBitCount = getTotalBitCount(input);
  
  pair<int, int> returnPair = pair<int,int>(NOT_FOUND, NOT_FOUND);
  //Find smaller number
  int curNumber = input;
  while (curNumber > 0){
    curNumber--;
    if (getTotalBitCount(curNumber) == origBitCount){
      returnPair.first = curNumber;
      break;
    }
  }

  //Find larger number
  curNumber = input;
  while (curNumber < 1024){
    curNumber++;
    if (getTotalBitCount(curNumber) == origBitCount){
      returnPair.second = curNumber;
      break;
    }
  }

  return returnPair;
}

int NextNumber::getTotalBitCount(int input){
  int bitMask = 1;
  int totalBits = 0;
  for (int i = 0; i < 11; ++i){
    int maskedInput = input & bitMask;
    if (maskedInput != 0)
      totalBits++;

    bitMask = bitMask << 1;
  }

  return totalBits;
}