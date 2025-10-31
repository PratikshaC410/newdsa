#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

void insert_sorted(vector<int>& arr, int val) {
   long unsigned int i=0;
    while(i<arr.size() && arr[i]<val)
        i++;
    arr.insert(arr.begin() +i,val);
}
vector<double> runningMedian(vector<int> a)
{
    vector<int> sorted_arr;
    vector<double> median;
    for(int num:a)
    {
        insert_sorted(sorted_arr,num);
        int curr_size=sorted_arr.size();
        double curr_median;
        if(curr_size%2==1)
        {
            curr_median=(double)sorted_arr[curr_size/2];
        }
        else
        {
            int mid_right=curr_size/2;
            int mid_left=mid_right-1;
            curr_median=((double)sorted_arr[mid_left]+(double)sorted_arr[mid_right])/2.0;
        }
        median.push_back(curr_median);
    }
    return median;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}