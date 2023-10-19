class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                if (st.size())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans1;
        while (st.size())
        {
            ans1.push_back(st.top());
            st.pop();
        }
        reverse(ans1.begin(), ans1.end());
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#')
            {
                if (st.size())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(t[i]);
            }
        }
        string ans2;
        while (st.size())
        {
            ans2.push_back(st.top());
            st.pop();
        }
        reverse(ans2.begin(), ans2.end());
        if (ans1 == ans2)
        {
            return true;
        }
        return false;
    }
};