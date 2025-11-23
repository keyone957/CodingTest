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
int arr[1001];
int temp[1001];
int n;
void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int leftIdx = start;//start~mid 값 보기위해 사용하는 index
    int rightIdx = mid;//mid ~ end 값 보기위해 사용하는 index
    for (int i = start; i < end; i++)
    {
        if (rightIdx == end)
        {
            temp[i] = arr[leftIdx++];
        }
        else if (leftIdx == mid)
        {
            temp[i] = arr[rightIdx++];
        }
        else if (arr[leftIdx] <= arr[rightIdx])
        {
            temp[i] = arr[leftIdx++];
        }
        else
        {
            temp[i] = arr[rightIdx++];
        }

        
    }
    for (int i = start; i < end; i++)
    {
        arr[i] = temp[i];//temp에 임시 저장해둔 값을 a로 다시 옮김.
    }

}
void mergeSort(int start, int end)//배열을 1길이까지 나누는 과정
{
    if (end == start + 1)// 리스트의 길이가 1인 경우에는 이미 정렬된 상태.
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, end);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}