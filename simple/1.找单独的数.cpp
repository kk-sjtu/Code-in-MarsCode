#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int solution(std::vector<int> cards) {
  // Edit your code here
  std::unordered_map<int, int> map;
  for (std::vector<int>::iterator it = cards.begin(); it != cards.end(); ++it) {
    if (map[*it] - 1 == 0) {
      //cout << "aa" << *it << endl;
      map.erase(*it);
      continue;
    }
    if (!map[*it]) {
      map[*it] = 1;
      //cout << "bb" << *it << endl;
    }
  }
  //cout << map.begin()->first;
  return map.begin()->first;
}

int main() {
  // Add your test cases here

  std::cout << (solution({1, 1, 2, 2, 3, 3, 4, 5, 5}) == 4) << std::endl;
  std::cout << (solution({0, 1, 0, 1, 2}) == 2) << std::endl;

  return 0;
}
