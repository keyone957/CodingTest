#include <string>
#include <vector>
#include <iostream>
int check[101][101];
using namespace std;
/*
n 명이 있을때 n-1명의 순위만 알수 있다면 순위를 매길 수 있음

*/
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> arr[101];
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                check[i][j]=0;
            }
            else
            {
                check[i][j]=-1;
            }
            
        }
    }
     for (int i = 0; i < results.size(); i++)
    {
        int a = results[i][0];
        int b = results[i][1];

       // arr[a].push_back(b);
         check[a][b]=1;
    }   
   
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(check[i][k]==1&&check[k][j]==1)
                {
                    check[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int checkNum=0;
        for(int j=1;j<=n;j++)
        {
            if(check[i][j]==1||check[j][i]==1)
            {
                checkNum++;
            }
        }
        if(checkNum==n-1)
        {
            answer++;
        }
    }
    return answer;
}