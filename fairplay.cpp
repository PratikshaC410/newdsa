#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        int w1 = max(s1, s2);
        int w2 = max(s3, s4);

        vector<int> skills = {s1, s2, s3, s4};
        sort(skills.begin(), skills.end());

        // The two strongest players
        int strongest = skills[3];
        int secondStrongest = skills[2];

        if ((w1 == strongest && w2 == secondStrongest) ||
            (w2 == strongest && w1 == secondStrongest)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
