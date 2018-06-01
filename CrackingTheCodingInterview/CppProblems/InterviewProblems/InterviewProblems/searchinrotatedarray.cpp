#include "searchinrotatedarray.h"

#include "datastructureutils.h"

#include <iostream>

using namespace sortingandsearching;

void SearchInRotatedArray::runTestCases(){
  singleTest(vector<int>{}, 0);
  singleTest(vector<int>{15, 16, 19, 20, 25, 1, 3, 4, 5 ,7, 10, 14}, 5);
  singleTest(vector<int>{2, 2, 2, 2, 2, 2}, 2);
}

void SearchInRotatedArray::singleTest(const vector<int> &values, int find){
  cout << "Value " << find << " is at index " << searchInRotatedArray(values, find) << " in array " << 
    com::DataStructureUtils::toString(values) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 3 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int SearchInRotatedArray::searchInRotatedArray(const vector<int> &values, int find){
  if (values.size() == 0){
    return VALUE_NOT_FOUND;
  } else if (values.size() == 1 ){
    if (values[0] == find)
      return 0;
    else
      return VALUE_NOT_FOUND;
  }

  wrapOffset = getRotationIndex(values);
  arraySize = values.size();

  int binarySplit = values.size() / 2;
  int leftBound = 0;
  int rightBound = values.size() - 1;

  int wrappedSplitIndex = getWrappedIndex(binarySplit);
  while (values[wrappedSplitIndex] != find) {
    if (leftBound == rightBound)
      return VALUE_NOT_FOUND;

    if (values[wrappedSplitIndex] < find){
      leftBound = binarySplit + 1;
      binarySplit = (leftBound + rightBound) / 2;
    }
    else if (values[wrappedSplitIndex] > find) {
      rightBound = binarySplit -1 ;
      binarySplit = (leftBound + rightBound) / 2;
    }

    wrappedSplitIndex = getWrappedIndex(binarySplit);
  }

  return wrappedSplitIndex;
}

//Returns the "first" element in the sorted rotated array
int SearchInRotatedArray::getRotationIndex(const vector<int> &values){
  for (int i = 0; i < values.size() - 1; ++i){
    if (values[i] > values[i+1])
      return i + 1;
  }

  return 0;


  //First find the rotated start index
  int startIndex = 0;
  int nextIndex = values.size() / 2;

  while (values[startIndex]  < values[nextIndex]) {

  }

  return nextIndex;
}

int SearchInRotatedArray::getWrappedIndex(int baseIndex){
  return (baseIndex + wrapOffset) % arraySize;
}