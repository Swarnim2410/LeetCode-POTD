class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int>arr(n,0);
        int val = 1;
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    temp[j] = arr[j] + val; 
                    val = 0;
                }
                else
                {
                    temp[j] = arr[j] + temp[j-1];
                }
            }
            arr = temp;
        }  
        return arr[n-1];  

    }
};