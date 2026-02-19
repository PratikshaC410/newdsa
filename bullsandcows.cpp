string getHint(string secret, string guess)
{
    int bulls = 0, cows = 0;
    unordered_map<char, int> count;

    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else
        {
            if (count[secret[i]] < 0)
                cows++;
            if (count[guess[i]] > 0)
                cows++;

            count[secret[i]]++;
            count[guess[i]]--;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}
