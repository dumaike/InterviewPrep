#include "peaksandvalleys.h"

#include "datastructureutils.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace sortingandsearching;

void PeaksAndValleys::runTestCases(){
  /* initialize random seed: */
  srand (time(NULL));

  singleTest();
}

void PeaksAndValleys::singleTest(){
  vector<int> values = vector<int>();
  for (int i = 0; i < 15; ++i){
    values.push_back(rand() % 100);
  }

  cout << "Resort: " << com::DataStructureUtils::toString(values) << " into ";
  peaksAndValleys(values);
  cout << com::DataStructureUtils::toString(values) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 11 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
void PeaksAndValleys::peaksAndValleys(vector<int> &values){
  if (values.size() < 3){
    throw invalid_argument("Array to small");
    return;
  }
  cachedValues = &values;

  //Make the first set Valley-Peak-Valley

  //Find the max in the first three
  int maxIndex = 0;
   if (values[1] > values[0])
    maxIndex = 1;
  if (values[2] > values[maxIndex])
    maxIndex = 2;

  //Swap elements to keep peaks and valleys
  swapElements(maxIndex, 1);

  for (int i = 2; i < values.size() - 1; ++i){
    //Odd index start, looking for a Valley-Peak
    //Even index start, looking for a Peak-Valley
    if ((i % 2 == 0 && values[i] > values[i+1]) || 
        (i % 2 == 1 && values[i + 1] > values[i])) {      
      swapElements(i, i+1);
    }
  }
}

void PeaksAndValleys::swapElements(int firstIndex, int secondIndex){  
    int temp = (*cachedValues)[firstIndex];
    (*cachedValues)[firstIndex] = (*cachedValues)[secondIndex];
    (*cachedValues)[secondIndex] = temp;
}