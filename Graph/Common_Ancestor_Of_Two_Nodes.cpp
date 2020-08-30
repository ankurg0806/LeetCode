/* Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique integer identifier.

 

For example, in this diagram, 6 and 8 have common ancestors of 4 and 14.

 

         14  13
         |   |
1   2    4   12
 \ /   / | \ /
  3   5  8  9
   \ / \     \
    6   7     11

 

parent_child_pairs_1 = [
    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
    (4, 8), (4, 9), (9, 11), (14, 4), (13, 12), (12, 9)
] */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

vector<pair<int, int>> parent_child_pairs_1 = {
  make_pair(1, 3),
  make_pair(2, 3),
  make_pair(3, 6),
  make_pair(5, 6),
  make_pair(5, 7),
  make_pair(4, 5),
  make_pair(4, 8),
  make_pair(4, 9),
  make_pair(9, 11),
  make_pair(14, 4),
  make_pair(13, 12),
  make_pair(12, 9)
};

vector<pair<int, int>> parent_child_pairs_2 = {
  make_pair(11, 10),
  make_pair(11, 12),
  make_pair(2, 3),
  make_pair(10, 2),
  make_pair(10, 5),
  make_pair(1, 3),
  make_pair(3, 4),
  make_pair(5, 6),
  make_pair(5, 7),
  make_pair(7, 8)
};

unordered_map<int, vector<int>> computeParents(vector<pair<int,int>> parent_child_pairs)
{
  unordered_map<int, vector<int>> child_parents;
  for (auto& pairAB: parent_child_pairs)
  {
    int A = pairAB.first;
    int B = pairAB.second;
    child_parents[B].push_back(A);
    if (child_parents.find(A) == child_parents.end())
      child_parents[A] = {};
  }
  return child_parents;
}

void findpath(unordered_map<int, vector<int>>& child_parents, set<int>& path, int child)
{
  if (child_parents.find(child) == child_parents.end() or
     child_parents[child].empty())
  {
    return;
  }
  else
  {
    for (auto& parent: child_parents[child])
    {
      path.insert(parent);
      findpath(child_parents, path, parent);
    }
  }
}

bool computeAncestors(vector<pair<int,int>> parent_child_pairs, int A, int B)
{
  auto child_parents = computeParents(parent_child_pairs);
  set<int> pathA;
  set<int> pathB;
  findpath(child_parents, pathA, A);
  findpath(child_parents, pathB, B);
  for (auto num : pathA)
  {
    cout<<num<<" ";
  }
  cout<<endl;
  for (auto num : pathB)
  {
    cout<<num<<" ";
  }
  vector<int> intersection(pathA.size()+pathB.size());
  auto it = std::set_intersection(pathA.begin(), pathA.end(),
                        pathB.begin(),pathB.end(),                                       intersection.begin());
   intersection.resize(it-intersection.begin());
  return not intersection.empty();
}

int main() {

  cout<<computeAncestors(parent_child_pairs_1, 1, 3);
  return 0;
}