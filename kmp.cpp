#include "kmp.h"
#include "bits/stdc++.h"
using namespace std;

vector <int> pref_func(string s) {
    int n = (int) s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    return p;
}

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int> result(2, 0);
    string new_string = my_template + '#' + text;
    vector <int> prf = pref_func(new_string);
    for (int i = my_template.size() + 1; i < new_string.size(); i++) {
        if (prf[i] == my_template.size()) {
            result.push_back(i - 2 * my_template.size());
        }
    }
    return result;
}
