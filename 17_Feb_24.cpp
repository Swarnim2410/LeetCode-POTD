class Solution
{
public:
    int furthestBuilding(vector<int> &h, int b, int l)
    {
        int n = h.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (l == 0)
            {
                break;
            }
            if (h[i + 1] > h[i])
            {
                pq.push(h[i + 1] - h[i]);
                l--;
            }
        }
        int j = i;
        for (j = i; j < n - 1; j++)
        {
            if (h[j + 1] > h[j])
            {
                pq.push(h[j + 1] - h[j]);
                if (pq.top() <= b)
                {
                    b -= pq.top();
                    pq.pop();
                }
                else
                {
                    break;
                }
            }
        }
        return j;
    }
};