#include "binarytostring.h"

#include <iostream>

using namespace bitmanipulation;

void BinaryToString::runTestCases(){
  singleTest(0.72);
  singleTest(0.01);
  singleTest(0.101);
  singleTest(0.64);
}

void BinaryToString::singleTest(double input){
  string output = binaryToString(input);
  cout << input << " converts to " << output << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 5 Question 2 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
string BinaryToString::binaryToString(double binary){
  double intPart;
  while (std::modf(binary, &intPart) != 0){
    binary *= 10; 
  }

  if (binary > INT_MAX) {
    return "ERROR";
  }

  int divisor = std::pow(2, 30);
  bool foundStartingBit = false;
  string returnString = "";
  while (divisor >= 1) {
    double divided = binary / divisor;
    if (divided < 2 && divided >= 1){
      foundStartingBit = true;
      returnString = returnString + "1";
      binary -= divisor;
    } else if (foundStartingBit) {
      returnString = returnString + "0";
    }

    divisor /= 2;
  }

  return "0." + returnString;
}