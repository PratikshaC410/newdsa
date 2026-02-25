class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        long long count = 0;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum == target)
            {

                //  Both elements are same
                if (arr[left] == arr[right])
                {
                    long long n = right - left + 1;
                    count += (n * (n - 1)) / 2;
                    break;
                }

                //  duplicates on left
                int leftCount = 1;
                while (left + 1 < right && arr[left] == arr[left + 1])
                {
                    leftCount++;
                    left++;
                }

                //  duplicates on right
                int rightCount = 1;
                while (right - 1 > left && arr[right] == arr[right - 1])
                {
                    rightCount++;
                    right--;
                }

                count += (long long)leftCount * rightCount;

                left++;
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return count;
    }
};