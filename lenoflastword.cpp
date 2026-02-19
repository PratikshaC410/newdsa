class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int cnt = 0;
        int prevCnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                cnt++;
            }
            else
            {
                if (cnt > 0)
                { // Only update if a word just ended
                    prevCnt = cnt;
                    cnt = 0;
                }
            }
        }

        // If string does not end with space
        if (cnt > 0)
            return cnt;

        return prevCnt;
    }
};