#ifndef COM_TESTABLEPROBLEM_H
#define COM_TESTABLEPROBLEM_H

//-----------------------------------------------------------------------------

#include <vector>

using namespace std;

namespace com
{
  class TestableProblem {

  public:
    virtual void runTestCases() = 0;
  };
}

#endif