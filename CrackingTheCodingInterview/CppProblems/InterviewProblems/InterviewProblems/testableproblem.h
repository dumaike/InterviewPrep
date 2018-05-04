#ifndef COM_TESTABLEPROBLEM_H
#define COM_TESTABLEPROBLEM_H

#include <vector>

using namespace std;

namespace com
{

//*-----------------------------------------------------------------------------------------*/
// A very basic interface for implementing test cases of code transcribed from my whiteboard
// problem solving sessions. Just so I don't have to edit main too much for each problem.
//*-----------------------------------------------------------------------------------------*/
  class TestableProblem {

  public:
    virtual void runTestCases() = 0;
  };
}

#endif