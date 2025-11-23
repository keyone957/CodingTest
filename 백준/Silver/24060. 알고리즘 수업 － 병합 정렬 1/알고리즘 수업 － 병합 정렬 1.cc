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
int arr[500001];
int temp[500001];
int n, k;
/*
* 5 7
4 5 1 3 2

*/
int answer = 0;
void merge(int start, int end)
{
    int mid = (start + end+1) / 2;
    int leftIdx= start;
    int rightIdx = mid;
    for (int i = start; i < end; i++)
    {
        if (leftIdx == mid)
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
            answer++;
        }
        else if (rightIdx == end)
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
            answer++;

        }
        else if (arr[leftIdx]<arr[rightIdx])
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
            answer++;
        }
        else
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
            answer++;
        }
        if (answer == k)
        {
            cout << temp[i];
        }
    }
    for (int i = start; i < end; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int start,int end)
{
    if (end == start + 1) return;
    int mid = (start + end+1) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    mergeSort(0, n);
    if (answer < k)
    {
        cout << -1;
    }
    
}