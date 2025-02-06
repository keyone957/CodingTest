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
int main()
{
	/*
	L 커서 왼쪽으로 이동 /맨왼쪽이면 무시
	D 커서 오른쪽으로 이동/ 맨 오른쪽이면 무시
	B 커서왼쪽에 있는 문자 삭제 / 문장맨 앞이면 무시
	P X => X라는문자 커서 왼쪽에 추가
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string firstArr;
	cin >>firstArr;
	int count;
	cin >> count;
	cin.ignore();// 이전 cin작업후의 개행문자 제거하기 위함
	vector<string> editor;
	list<char> listArr;
	for (int i = 0; i < firstArr.size(); i++)
	{
		listArr.push_back(firstArr[i]);
	}

	for (int i = 0; i < count; i++)
	{
		string go;
		getline(cin, go);
		editor.push_back(go);
	}
	/*for (int i = 0; i < editor.size(); i++)
	{
		cout << editor[i]<<endl	;
	}*/
	list<char>::iterator t = listArr.end();
	for (int i = 0; i < count; i++)
	{
		if (editor[i][0] == 'L')
		{
			if (t != listArr.begin())
			{
				t--;
			}
		}
		else if(editor[i][0]=='D')
		{ 
			if (t != listArr.end())
			{
				t++;
			}
		}
		else if (editor[i][0] == 'B')
		{
			if (t != listArr.begin())
			{
				t--;
				t=listArr.erase(t);
			}
		}
		else if (editor[i][0] == 'P')
		{
			listArr.insert(t,editor[i][2]);
		}
	}
	
	for (auto i :listArr) cout << i;
}