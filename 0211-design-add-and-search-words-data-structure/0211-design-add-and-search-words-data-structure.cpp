class WordDictionary {
public:
static const int root=1;
static const int max=250005;
int unused=2;
bool chk[max];
int nxt[max][28];
    WordDictionary() {
    memset(chk,false,sizeof(chk));
    memset(nxt,-1,sizeof(nxt));
    }
    
    int func(char c)
    {
        return c-'a';
    }
    void addWord(string word) {
        int cur=root;
        for(int i=0;i<word.size();i++)
        {
            char curWord=word[i];
            if(nxt[cur][func(curWord)]==-1)
            {
                nxt[cur][func(curWord)]=unused++;
            }
            cur=nxt[cur][func(curWord)];
        }
        chk[cur]=true;
    }
    
    bool search(string word) {
        int cur=root;
        
        if(word.find('.')==string::npos)// . 없을때는 걍 일반적인 트라이 탐색 사용.
        {
             for(int i=0;i<word.size();i++)
            {
                char curWord=word[i];
                if(nxt[cur][func(curWord)]==-1) return false;
                cur=nxt[cur][func(curWord)];
            }
        }
        else
        {
           return dfs(root,0,word);
        }
        return chk[cur];
    }
    bool dfs(int node, int idx,string& word)
    {
        if(idx==word.size()) // 문자 끝까지 도달했으면 단어 종료 여부 확인함
        {
            return chk[node];
        }
        if(word[idx]=='.')// 이제 . 을만나면 모든 경우의 수를 확인해봐야함.
        {
            for(int i=0;i<26;i++)
            {
                if(nxt[node][i]!=-1)// 자식있는 곳(문자 있는지)만 탐색
                {
                    if(dfs(nxt[node][i],idx+1,word))//여러 경로중 하나라도 성공하면 true 
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        //일반 적인 경로로 탐색하는 경우  -> . 없을때는 일반적으로 dfs탐색ㄱㄱ
        int c=func(word[idx]);
        if(nxt[node][c]==-1) return false;
        return dfs(nxt[node][c],idx+1,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */