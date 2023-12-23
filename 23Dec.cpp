class Solution
{
public:
    bool isPathCrossing(string path)
    {
        map<pair<int, int>, int> mp;
        int x = 0, y = 0;
        mp[{0, 0}] = 1;
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == 'N')
            {
                y++;
            }
            if (path[i] == 'S')
            {
                y--;
            }
            if (path[i] == 'E')
            {
                x++;
            }
            if (path[i] == 'W')
            {
                x--;
            }
            if (mp[{x, y}] == 1)
            {
                return true;
            }
            mp[{x, y}] = 1;
        }
        return false;
    }
};