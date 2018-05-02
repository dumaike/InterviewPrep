#ifndef COM_TESTABLEPROBLEM_H
#define COM_TESTABLEPROBLEM_H

#include <vector>

//*-----------------------------------------------------------------------------------------*/
// A very basic interface for implementing test cases of code transcribed from my whiteboard
// problem solving sessions. Just so I don't have to edit main too much for each problem.
//*-----------------------------------------------------------------------------------------*/
using namespace std;

namespace com
{
  class TestableProblem {

  public:
    virtual void runTestCases() = 0;
  };
}

#endif