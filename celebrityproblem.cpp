#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This function determines if person 'a' knows person 'b'.
// It is assumed to be an existing API or a function defined elsewhere.
// For demonstration, we use a hardcoded adjacency matrix.
bool knows(int a, int b, const vector<vector<int>>& relations) {
    if (a < 0 || a >= relations.size() || b < 0 || b >= relations.size()) {
        return false;
    }
    return relations[a][b] == 1;
}

int findCelebrity(int n, const vector<vector<int>>& relations) {
    if (n <= 0) {
        return -1;
    }

    // Phase 1: Elimination
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b, relations)) {
            // A knows B, so A cannot be the celebrity.
            s.push(b);
        } else {
            // A does not know B, so B cannot be the celebrity.
            s.push(a);
        }
    }

    if (s.empty()) {
        return -1; // No candidate found
    }

    int candidate = s.top();
    
    // Phase 2: Verification
    // Check if the candidate is a true celebrity
    for (int i = 0; i < n; ++i) {
        if (i != candidate) {
            // The candidate must know nobody, and everyone else must know the candidate.
            if (knows(candidate, i, relations) || !knows(i, candidate, relations)) {
                return -1; // The candidate fails the celebrity criteria.
            }
        }
    }

    return candidate;
}