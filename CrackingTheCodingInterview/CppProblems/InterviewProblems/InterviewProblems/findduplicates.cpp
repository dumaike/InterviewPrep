#include "findduplicates.h"

#include "datastructureutils.h"

#include <iostream>
#include <bitset>

using namespace sortingandsearching;

void FindDuplicates::runTestCases(){
  singleTest(vector<int>{0, 1, 1, 2, 3, 4, 4, 4, 5, 6, 7, 7});
}

void FindDuplicates::singleTest(const vector<int> &values){
  cout << "The duplicates in " << com::DataStructureUtils::toString(values) << " are " << endl;
  findDuplicates(values);

  cout << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 8 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
void FindDuplicates::findDuplicates(const vector<int> &values){
  bitset<32000> allCount = bitset<32000>(); //~4k memory
  
  for (int i = 0; i < values.size(); i++){
    bool allCountVal = allCount[values[i]];
    if (allCountVal){
     cout << values[i] << " ";
    }

    allCount[values[i]] = true;
  }
}