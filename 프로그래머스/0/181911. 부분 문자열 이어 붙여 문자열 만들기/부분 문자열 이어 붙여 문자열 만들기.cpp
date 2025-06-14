#include <string>
#include <vector>

using namespace std;
string solution(vector<string> my_strings, vector<vector<int>> parts) {
    //substr(시작 index, 길이)
    // 시작index에서 길이만큼 문자열 반환
    //
    string answer = "";
    for (int i = 0; i < my_strings.size(); i++)
    {
        int stringSize = my_strings[i].size();
        int startIdx = parts[i][0];
        int endIdx = parts[i][1];
        answer += my_strings[i].substr(startIdx, endIdx - startIdx + 1);
    }
    return answer;
}