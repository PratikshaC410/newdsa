
int countGoodNumbers(int index, int n)
{

    if (index == n)
    {

        return 1;
    }

    int result = 0;

    if (index % 2 == 0)
    {

        for (int digit : {0, 2, 4, 6, 8})
        {
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }

    else
    {

        for (int digit : {2, 3, 5, 7})
        {
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }
    return result;
}