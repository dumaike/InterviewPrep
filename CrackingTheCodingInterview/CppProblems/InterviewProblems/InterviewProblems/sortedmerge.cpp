#include "sortedmerge.h"

#include "datastructureutils.h"

#include <iostream>

using namespace sortingandsearching;

void SortedMerge::runTestCases(){
  singleTest();
}

void SortedMerge::singleTest(){
  const int combinedSize = 10;
  int aArray[combinedSize] = {0, 2, 4, 6, 8, 9};
  int bArray[] = {1, 3, 5, 7}; 

  sortedMerge(aArray, 6, bArray, 4);

  cout << "Combined Array: " << com::DataStructureUtils::toString(aArray, combinedSize) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 1 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
void SortedMerge::sortedMerge(int a[], int aSize, const int b[], int bSize){
  int insertIndex = aSize + bSize - 1;
  int aIndex = aSize - 1;
  int bIndex = bSize - 1;

  while (insertIndex > -1){
    if (aIndex == -1){
      a[insertIndex] = b[bIndex];
      bIndex--;
    } else if (bIndex == -1){
      a[insertIndex] = a[aIndex];
      aIndex--;
    } else {
      int aValue = a[aIndex];
      int bValue = b[bIndex];

      if (aValue > bValue) {
        a[insertIndex] = aValue;
        aIndex--;
      } else {
        a[insertIndex] = bValue;
        bIndex--;
      }
    }

    insertIndex--;
  }
}