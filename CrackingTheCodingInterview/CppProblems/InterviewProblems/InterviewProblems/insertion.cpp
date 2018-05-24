#include "insertion.h"

#include <iostream>
#include <cmath>

using namespace bitmanipulation;

void Insertion::runTestCases(){
  int result = insertion(0b10000000000, 0b10011, 2, 6);
  if (result == 0b10001001100)
    cout << "It Worked!";
  else
    cout << "It didn't";
}

void Insertion::singleTest(){
  cout << "Running one test!";
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 5 Question 1 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int Insertion::insertion(int N, int M, int i, int j) {
  int mLen = j - i + 1; // the length of M in bits
  int clearMask = pow(2, mLen) - 1; // A mask the number of 1s in M
  clearMask = ~(clearMask << i); //A mask with 0s in the spot where M will insert into N, and the others are 1s
  N = N & clearMask; // Put those 0s into N at the right spot
  int mShifted = M << i;
  
  int result = N | mShifted;
  return result;
}