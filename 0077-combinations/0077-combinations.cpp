class Solution {
    vector<vector<int>> answer;
    vector<int> cur;
    int target;

    void dfs(int start, int n)
    {
        if (cur.size() == target)
        {
            answer.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            cur.push_back(i);
            dfs(i + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        target = k;
        dfs(1, n);
        return answer;
    }
};