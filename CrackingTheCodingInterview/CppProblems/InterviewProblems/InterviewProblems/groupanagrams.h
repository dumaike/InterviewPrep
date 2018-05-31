#ifndef SORTINGANDSEARCHING_GROUPANAGRAMS_H_
#define SORTINGANDSEARCHING_GROUPANAGRAMS_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 2
  class GroupAnagrams: public com::TestableProblem {

    string NO_ANAGRAM = "";

    string GroupAnagrams::getAnagram(string input);

    void groupAnagrams(vector<string> &inputArray);

    void singleTest(vector<string> &inputArray);

    public:

    void runTestCases();
  };
}

#endif
