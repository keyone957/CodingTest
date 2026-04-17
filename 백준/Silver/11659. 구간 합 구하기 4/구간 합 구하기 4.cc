#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int N, M;
	int sumList[100000] = {};
	vector<int> answer;

	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		sumList[i] = sumList[i - 1] + temp;
	}
	
	
	for (int i = 1; i <= M; i++)
	{
		int startIdx, endIdx;
		cin >> startIdx;
		cin >> endIdx;
		int result = 0;
		result = sumList[endIdx] - sumList[startIdx - 1];
		answer.push_back(result);
	}
	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << "\n";
	}
	

}