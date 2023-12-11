class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        double c = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                c++;
            }
            else
            {
                double x = c / (double)n;
                if (x > 0.25)
                {
                    return arr[i];
                }
                c = 1;
            }
        }
        return arr[n - 1];
    }
};