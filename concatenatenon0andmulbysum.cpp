class Solution {
public:
    long long sumAndMultiply(int n) {
     std::string s = std::to_string(n);

   
    std::string x_str = "";
    for (char c : s) {
        if (c != '0')
            x_str += c;
    }

    long long x = x_str.empty() ? 0 : stoll(x_str);

  
    long long sum = 0;
    for (char c : x_str) {
        sum += (c - '0');
    }

    return x * sum;
}
};