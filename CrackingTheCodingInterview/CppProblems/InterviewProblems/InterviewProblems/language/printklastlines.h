#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_

#include <iostream>

#include "com/graphnode.h"

using namespace std;

namespace language {

  void printTLastKLines(){

    com::GraphNode node = com::GraphNode(5);

    cout << "test of lines";
  }

}

#endif