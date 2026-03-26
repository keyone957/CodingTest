#include <bits/stdc++.h>
#define us unsigned
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000007
#define fi first
#define se second
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int X,C,K;
    cin>>X>>C>>K;
    vector<pair<int,pair<int,int>>> log;
    for (int i = 0; i < K; ++i)
    {
        int T,S,N;
        cin>>T>>S>>N;
        log.push_back(make_pair(T,make_pair(S,N)));
    }
    sort(log.begin(),log.end());
    vector<int>student = vector<int>(X+1,-1);
    vector<bool>seat = vector<bool>(C+1,false);
    for (int i = 0; i < K; ++i)
    {
        auto cur = log[i].se;
        if (!seat[cur.fi])
        {
            if (student[cur.se] != -1)
            {
                seat[student[cur.se]] = false;
                seat[cur.fi] = true;
                student[cur.se] = cur.fi;
                continue;
            }
            seat[cur.fi] = true;
            student[cur.se] = cur.fi;
        }
    }
    for (int i = 1; i <= X; ++i)
    {
        if (student[i] == -1)
        {
            continue;
        }
        cout<<i<<" "<<student[i]<<"\n";
    }
    return 0;
}