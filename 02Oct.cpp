class Solution {
public:
    bool winnerOfGame(string c) 
    {
        int a=0;
        int b=0;
        int ans1 = 0;
        int ans2 = 0;
        int f=0;
        for(int i=0;i<c.length();i++)
        {
            if(c[i]=='A')
            {
                a++;
                f=0;
            }
            else
            {
                b++;
                f=1;
            }
            if(f==0)
            {
                int bcnt = b - 2;
                if(bcnt>0)
                {
                    ans2 += bcnt;
                }
                b=0;
            }
            else
            {
                int acnt = a - 2;
                if(acnt>0)
                {
                    ans1 += acnt;
                }
                a=0;
            }
        } 
        if(a>2)
        {
            ans1 += a-2;
        }   
        if(b>2)
        {
            ans2+= b-2;
        }
        //cout << ans1 << " " << ans2 << endl;
        if(ans1==0)
        {
            return false;
        }
        if(ans1<ans2)
        {
            return false;
        }
        if(ans1==ans2)
        {
            return false;
        }
        return true;
    }
};