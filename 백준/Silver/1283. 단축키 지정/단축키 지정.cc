#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> input;
bool used[26] = { false };

bool IsOption(char check)
{
    return used[tolower(check) - 'a'];
}

void Change(string& str, int idx)
{
    str = str.substr(0, idx) + "[" + str[idx] + "]" + str.substr(idx + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    cin.ignore();

    input.resize(count);
    for (int i = 0; i < count; i++)
    {
        getline(cin, input[i]);
    }

    for (int i = 0; i < count; i++)
    {
        bool assigned = false;

        // 1단계: 단어의 첫 글자 우선 탐색
        for (int j = 0; j < input[i].size(); j++)
        {
            if (j == 0 || input[i][j - 1] == ' ')
            {
                if (!IsOption(input[i][j]))
                {
                    used[tolower(input[i][j]) - 'a'] = true;
                    Change(input[i], j);
                    assigned = true;
                    break;
                }
            }
        }

        // 2단계: 줄 전체 왼쪽부터 탐색
        if (!assigned)
        {
            for (int j = 0; j < input[i].size(); j++)
            {
                if (input[i][j] == ' ') continue;

                if (!IsOption(input[i][j]))
                {
                    used[tolower(input[i][j]) - 'a'] = true;
                    Change(input[i], j);
                    break;
                }
            }
        }
    }

    for (const auto& line : input)
        cout << line << '\n';

    return 0;
}
