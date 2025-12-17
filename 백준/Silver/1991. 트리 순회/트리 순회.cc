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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int n;
char lc[27];
char rc[27];
void preorder(char node)
{
    cout << node;
    if (lc[node - 65] != '.') preorder(lc[node - 65]);
    if (rc[node - 65] != '.') preorder(rc[node - 65]);
}
void inorder(char node)
{
    if (lc[node - 65] != '.') inorder(lc[node - 65]);
    cout << node;
    if (rc[node - 65] != '.') inorder(rc[node - 65]);
}
void postorder(char node)
{
    if (lc[node - 65] != '.') postorder(lc[node - 65]);
    if (rc[node - 65] != '.') postorder(rc[node - 65]);
    cout << node;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char node, left, right;
        cin >> node >> left >> right;
        lc[node - 65] = left;
        rc[node - 65] = right;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}