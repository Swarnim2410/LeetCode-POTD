class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.length();
        vector<int>freq(26,0);
        vector<int>vis(26,0);
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }    
        string ans = "";
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']--;
            if(vis[s[i]-'a'])
            {
                continue;
            }
            while (ans.size() && ans.back()>s[i] && freq[ans.back()-'a'])
            {
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            vis[s[i]-'a']=1;
            ans.push_back(s[i]);
        }
        return ans;
    }
};