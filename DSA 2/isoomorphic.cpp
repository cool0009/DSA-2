#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    unordered_map<char, char> mapping;
    unordered_set<char> used;
    for (int i = 0; i < s.size(); i++) {
        if (mapping.find(s[i]) == mapping.end()) {
            if (used.find(t[i]) != used.end()) {
                return false;
            }
            mapping[s[i]] = t[i];
            used.insert(t[i]);
        } else {
            if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s, t;
    cout << "Enter the first string: ";
    getline(cin, s);
    cout << "Enter the second string: ";
    getline(cin, t);
    if (areIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }
    return 0;
}
