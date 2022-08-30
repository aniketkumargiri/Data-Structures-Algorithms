// Letter cominations of a phone number
#include <bits/stdc++.h>
using namespace std;

void help(int i, string s, string temp, vector<string> &ans,
          unordered_map<char, string> mp) {
    if (i == s.size()) {
        ans.push_back(temp);
        return;
    }

    string str = mp[s[i]];
    for (int j = 0; j < str.size(); j++) {
        temp.push_back(str[j]);
        help(i + 1, s, temp, ans, mp);
        temp.pop_back();
    }
}

vector<string> f(string s) {
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    vector<string> ans;
    string temp;
    help(0, s, temp, ans, mp);
    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<string> ans;
    ans = f(s);

    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}