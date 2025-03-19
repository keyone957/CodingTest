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
using namespace std;
int input;
string line;
bool isend;
void func2(int b)
{

}
void Func(int a)
{
	
	if (a != 0)
	{
		line += "____";
	}
	if (input == a)
	{
		cout << line << "\"재귀함수가 뭔가요?\"" << "\n";
		cout << line << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
		cout << line << "라고 답변하였지." << "\n";
		for (int i = 0; i < input; i++)
		{
			line.erase(0, 4);
			cout << line << "라고 답변하였지." << "\n";
		}
	}
	else
	{
		cout << line << "\"재귀함수가 뭔가요?\"" << "\n";
		cout << line << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << "\n";
		cout << line << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << "\n";
		cout << line << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << "\n";
		Func(a + 1);
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<"\n";
	isend = true;
	Func(0);
	

}
