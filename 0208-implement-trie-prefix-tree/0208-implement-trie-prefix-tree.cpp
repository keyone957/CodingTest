class Trie {
static constexpr int root=1;
int unused=2;
static constexpr int MX=2000*2000+5;
bool check[MX];
int nxt[MX][26];
public:

    Trie() {
        memset(nxt,-1,sizeof(nxt));
        memset(check,false,sizeof(check));
    }
    int c2i(char c)
    {
        return c-'a';
    }
    void insert(string word) {
        int cur=root;
        for(int i=0;i<word.size();i++)
        {
            if(nxt[cur][c2i(word[i])]==-1)
            {
                nxt[cur][c2i(word[i])]=unused++;
            }
            cur=nxt[cur][c2i(word[i])];
        }
        check[cur]=true;
    }
    
    bool search(string word) {
        int cur=root;
        for(int i=0;i<word.size();i++)
        {
            if(nxt[cur][c2i(word[i])]==-1) return false;
            cur=nxt[cur][c2i(word[i])];
        }
        return check[cur];
    }
    
    bool startsWith(string prefix) {
      int cur =root;
      for(int i=0;i<prefix.size();i++)
      {
        if(nxt[cur][c2i(prefix[i])]==-1) return false;
        cur=nxt[cur][c2i(prefix[i])];
      }
      
      return true;
    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */