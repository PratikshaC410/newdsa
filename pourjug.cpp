class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        if (target > x + y)
            return false;

        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            if (a + b == target)
                return true;
            if (visited.count({a, b}))
                continue;
            visited.insert({a, b});

            q.push({x, b});

            q.push({a, y});

            q.push({0, b});

            q.push({a, 0});

            int pour1 = min(a, y - b);
            q.push({a - pour1, b + pour1});

            int pour2 = min(b, x - a);
            q.push({a + pour2, b - pour2});
        }
        return false;
    }
};