class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // 그래프 생성
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();

            for (string &ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        queue<string> q;

        // 처음 가지고 있는 재료들
        for (string &s : supplies) {
            q.push(s);
        }

        vector<string> answer;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            // 현재 재료로 만들 수 있는 레시피들
            for (string &next : graph[cur]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    answer.push_back(next);
                    q.push(next);   // 완성된 레시피도 새로운 재료가 된다.
                }
            }
        }

        return answer;
    }
};