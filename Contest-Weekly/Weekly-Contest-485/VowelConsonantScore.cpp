#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int vowelConsonantScore(string s)
    {

        int consonant = 0;
        int vowel = 0;

        for (char ch : s)
        {

            if(!isalpha(ch)) continue;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'
                 || ch == 'u')
                vowel++;
            else
                consonant++;
        }

        if (consonant == 0)
            return 0;

        return vowel / consonant ;
    }
};

int main()
{
    Solution sol;

    {
        string s = "cooear";
        int result = sol.vowelConsonantScore(s);
        cout << result << endl;
    }

    {
        string s = "axeyizou";
        int result = sol.vowelConsonantScore(s);
        cout << result << endl;
    }

    {
        string s = "au 123";
        int result = sol.vowelConsonantScore(s);
        cout << result << endl;
    }

    return 0;
}