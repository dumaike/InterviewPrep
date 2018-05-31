#include "groupanagrams.h"

#include "datastructureutils.h"

#include <iostream>
#include <unordered_map>
#include <string>

using namespace sortingandsearching;
using namespace std;

void GroupAnagrams::runTestCases(){
  singleTest(vector<string>{});
  singleTest(vector<string>{"ab", "bc", "ba", "aoeu", "thtsn", "allan", "amwb", "nalla"});
}

void GroupAnagrams::singleTest(vector<string> &inputArray){
  cout << "Unsorted: " << com::DataStructureUtils::toString(inputArray) << endl;
  groupPalindromes(inputArray);
  cout << "Sorted: " << com::DataStructureUtils::toString(inputArray)<< endl;
  cout << "-------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 2 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
void GroupAnagrams::groupPalindromes(vector<string> &inputArray){
  unordered_map<string, string> anagramMap = unordered_map<string, string>();

  //Assuming no duplicates
  for (int i = 0; i < inputArray.size(); ++i){
    string origString = inputArray[i];
    string anagram = getAnagram(origString);

    //If they orig and anagram aren't in the map, insert the orig
    bool origFound = anagramMap.find(origString) != anagramMap.end();
    bool anagramFound = anagramMap.find(anagram) != anagramMap.end();
    if (!origFound && !anagramFound){
      anagramMap.insert(pair<string, string>(origString, NO_ANAGRAM));
    } else if (anagramFound) {
      anagramMap[anagram] = origString;
    }
  }

  int anagramIndex = 0;
  int nonAnagarmIndex = inputArray.size() - 1;

  for (auto it = anagramMap.begin(); it != anagramMap.end(); ++it){
    if (it->second == NO_ANAGRAM){
      inputArray[nonAnagarmIndex] = it->first;
      nonAnagarmIndex--;
    } else {
      inputArray[anagramIndex] = it->first;
      anagramIndex++;
      inputArray[anagramIndex] = it->second;
      anagramIndex++;
    }
  }
}

string GroupAnagrams::getAnagram(string input){
  string returnAnagram = input;
  for (int i = 0; i < input.size(); ++i){
     returnAnagram[i] = input[input.size() - i - 1];
  }
  return returnAnagram;
}