#include "sparsesearch.h"

#include "datastructureutils.h"

#include <iostream>

using namespace sortingandsearching;

void SparseSearch::runTestCases(){
  singleTest(vector<string>{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}, "ball");
  singleTest(vector<string>{"", "", "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}, "ball");
  singleTest(vector<string>{"", "", "at", "aut", "awen", "", "", "", "ball", "car", "", "", "dad", "", ""}, "dad");
  singleTest(vector<string>{"", "", "at", "aut", "awen", "", "", "", "ball", "car", "", "", "dad", "", ""}, "dac");
}

void SparseSearch::singleTest(const vector<string> &values, string find){
  cout << "The index of " << find << " in " << com::DataStructureUtils::toString(values) << 
    " is " << sparseSearch(values, find) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 5 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int SparseSearch::sparseSearch(const vector<string> &values, string find){
  storedVector = values;

   int leftIndex = trollToValid(0, true);
   int rightIndex = trollToValid(values.size() - 1, false);
   int splitIndex = trollToValid(values.size() / 2, true);

   while (leftIndex != rightIndex){
     if (values[splitIndex] == find){
       return splitIndex;
     }

     if (values[splitIndex] > find){
       rightIndex = trollToValid(splitIndex - 1, true);
       splitIndex = trollToValid((leftIndex + rightIndex) / 2, true);
     } else {
       leftIndex = trollToValid(splitIndex + 1, false);
       splitIndex = trollToValid((leftIndex + rightIndex) / 2, true);
     }
   }

   if (values[leftIndex] == find){
     return leftIndex;
   }

   return -1;
}

int SparseSearch::trollToValid(int index, bool goLeft){
  int curIndex = index;

  if (goLeft) {
    while (storedVector[curIndex] == ""){
      curIndex--;

      if (curIndex < 0) {
        return trollToValid(index, false);
      } 
    }
  } else {
    while (storedVector[curIndex] == ""){
      curIndex++;

      if (curIndex >= storedVector.size()){
        return trollToValid(index, true);
      }
    }
  }

  return curIndex;
}