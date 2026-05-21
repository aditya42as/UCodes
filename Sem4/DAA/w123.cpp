    /*Q36. Given a string of characters, design an algorithm and implement it using a program to print all
    possible permutations of the string in lexicographic order.*/

    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    void generate(string &s, vector<bool> &used, string curr) {
        if(curr.size() == s.size()) {
            cout << curr << endl;
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            if(used[i]) continue;

            if(i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

            used[i] = true;
            generate(s, used, curr + s[i]);
            used[i] = false;
        }
    }

    int main() {
        string s;

        cout << "Enter string: ";
        cin >> s;

        sort(s.begin(), s.end());

        vector<bool> used(s.size(), false);

        generate(s, used, "");

    }