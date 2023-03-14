#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> keypad = {
    {'A', "2"}, {'B', "2"}, {'C', "2"},
    {'D', "3"}, {'E', "3"}, {'F', "3"},
    {'G', "4"}, {'H', "4"}, {'I', "4"},
    {'J', "5"}, {'K', "5"}, {'L', "5"},
    {'M', "6"}, {'N', "6"}, {'O', "6"},
    {'P', "7"}, {'Q', "7"}, {'R', "7"}, {'S', "7"},
    {'T', "8"}, {'U', "8"}, {'V', "8"},
    {'W', "9"}, {'X', "9"}, {'Y', "9"}, {'Z', "9"}
};

string toKeypadSequence(string sentence) {
    string keypadSequence;
    for (char c : sentence) {
        if (isalpha(c)) {
            keypadSequence += keypad[toupper(c)];
        }
    }
    return keypadSequence;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    string keypadSequence = toKeypadSequence(sentence);
    cout << "The keypad sequence is: " << keypadSequence << endl;
    return 0;
}
