#include "buildorder.h"

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_set>
#include <iostream>

#include "graphnode.h"
#include "datastructureutils.h"

using namespace com::graph;
using namespace std;

using namespace graphsandtrees;

void BuildOrder::runTestCases()
{
  vector<char> projects = vector<char>({ 'a', 'b', 'c', 'd', 'e', 'f' });
  vector<pair<char, char>> dependencies = vector<pair<char, char>>({
    pair<char,char>('a','d'),
    pair<char,char>('f','b'),
    pair<char,char>('b','d'),
    pair<char,char>('f','a'),
    pair<char,char>('d','c')
  });
  cout << com::DataStructureUtils::toString(buildOrder(projects, dependencies)) << endl;
}

void BuildOrder::singleTest()
{
  cout << "Running one test!";
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 7 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
vector<char> BuildOrder::buildOrder(const vector<char> &projList, const vector<pair<char, char>> &depList) {
  map<char, Node*> depGraph = map<char, Node*>();

  for (int i = 0; i < projList.size(); ++i) {
    Node* cur = new Node(projList[i]);
    depGraph.insert(pair<char,Node*>(projList[i], cur));
  }
  for (int i = 0; i < depList.size(); ++i) {
    Node* dependency = depGraph[depList[i].first];
    Node* dependent = depGraph[depList[i].second];
    dependent->addChild(dependency);
  }

  stack<char> toBuild = stack<char>();
  unordered_set<char> hasBuild = unordered_set<char>();
  unordered_set<char> inStack = unordered_set<char>();
  vector<char> buildOrder = vector<char>();

  int nodeIndex = 0;

  while (toBuild.size() > 0 || nodeIndex < projList.size()) {

    if (toBuild.size() == 0) {
      int cur = projList[nodeIndex];
      if (inStack.find(cur) == inStack.end())
      {
        inStack.insert(cur);
        toBuild.push(cur);
      }
      nodeIndex++;

    } else {

      int cur = toBuild.top();
      Node* curNode = depGraph[cur];
      int numUnmetDependencies = 0;
      int notBuildChildren = 0;
      for (int i = 0; i < curNode->numChildren(); ++i) {

        int childNodeValue = curNode->getChildren()[i]->getValue();

        //The nodes dependency has been build
        if (hasBuild.find(childNodeValue) != hasBuild.end()) {
          continue;
        }

        //The node's dependency has been visited, but has it's own dependency
        if (inStack.find(childNodeValue) == inStack.end()) {
          numUnmetDependencies++;
          toBuild.push(childNodeValue);
          inStack.insert(childNodeValue);
        }
        
      }

      if (numUnmetDependencies == 0) {
        toBuild.pop();
        buildOrder.push_back(curNode->getValue());
      }
    }
  }

  //Check to see if all nodes are in set
  if (buildOrder.size() == projList.size()) {
    return buildOrder;
  }

  throw invalid_argument("dependencies cannot be met");
}