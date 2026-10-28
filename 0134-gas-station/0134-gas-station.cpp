class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int aSize=gas.size();
        int answer;
        int curGas=0;
        int totalNeed=0;
        int curIdx=0;
        for(int i=0;i<aSize;i++)
        {
            curGas+=gas[i]-cost[i];
            totalNeed+=gas[i]-cost[i];
            //일단 이 값이 만약에 음수면 가스가 부족해. 따라서 
            //현재 이 인덱스의 주유소부터는 시작을 못함
            if(curGas<0)
            //충전되는 가스보다 사용할 가스가 더 많다면 이제
            //출발 지점 재 설정 + 누적 가스 초기화
            {
                curGas=0;
                curIdx=i%aSize+1;
            }
        }
        // cout<<totalNeed;
        if(totalNeed<0)
        {
            return -1;
        }
        return curIdx;
    }
};
