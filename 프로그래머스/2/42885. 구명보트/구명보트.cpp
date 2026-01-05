#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
 int size = people.size();
 sort(people.begin(), people.end());
 int leftIdx=0;
 int rightIdx = size-1;
 while (leftIdx <= rightIdx)
 {
     int left = people[leftIdx];
     int right = people[rightIdx];
     int sum = left + right;
     if (leftIdx == rightIdx)
     {
         answer++;
         break;
     }
     if (sum <= limit)
     {
         leftIdx++;
         rightIdx--;
     }
     else
     {
         rightIdx--;
     }
     answer++;
 }
 
 return answer;
}