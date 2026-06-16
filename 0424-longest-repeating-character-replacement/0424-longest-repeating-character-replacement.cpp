class Solution {
int word[26]={0};
int func(char s)
{
    return s-'A';
}
public:
    int characterReplacement(string s, int k) {
        int sSize=s.length();
        int answer=0;
        int left =0;
        int right=0;
        word[func(s[right])]++;
        while(left<sSize&&right<sSize)
        {
            int windowSize=(right-left)+1;
            int maxWordCnt=*max_element(word,word+26);
            if(windowSize-maxWordCnt>k)//k번내에 똑같은 문자로 못바꿀때
            {
                word[func(s[left])]--;
                left++;
            }
            else
            { 
                right++;
                   if(right<sSize) word[func(s[right])]++;
                answer=max(answer,windowSize);
            }
           
        }
        return answer;
    }
};