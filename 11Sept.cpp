// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) 
    {
        if(n%2==0)
        {
            return false;
        }
        int val = n;
        int x = 2;
        while(x<=n)
        {
            if(val%x==0)
            {
                return false;
            }
            val=val-val/x;
            x++;
            n--;
        }
        return true;
    }
};