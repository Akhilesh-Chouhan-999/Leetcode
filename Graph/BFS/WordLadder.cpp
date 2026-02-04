#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        int length = beginWord.length();

        queue<pair<string, int>> que;
        unordered_set<string> check(wordList.begin(), wordList.end());
        unordered_set<string> visited;

        if (check.find(endWord) == check.end())
            return 0;

        que.push({beginWord, 1});
        visited.insert(beginWord);

        while (!que.empty())
        {

            auto p = que.front();
            que.pop();

            string curr = p.first;
            int level = p.second;

            if (curr == endWord)
                return level;

            for (int i = 0; i < length; i++)
            {

                for (int j = 0; j < 26; j++)
                {

                    string temp = curr;

                    temp[i] = char('a' + j);

                    if (visited.find(temp) != visited.end())
                    {
                        continue;
                    }

                    if (check.find(temp) != check.end())
                    {
                        que.push({temp, level + 1});
                        visited.insert(temp);
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

        cout << "Test Case 1 Output: "
             << sol.ladderLength(beginWord, endWord, wordList) << endl;
    }

    // Test Case 2
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};

        cout << "Test Case 2 Output: "
             << sol.ladderLength(beginWord, endWord, wordList) << endl;
    }

    // Test Case 3
    {
        string beginWord = "a";
        string endWord = "c";
        vector<string> wordList = {"a", "b", "c"};

        cout << "Test Case 3 Output: "
             << sol.ladderLength(beginWord, endWord, wordList) << endl;
    }

    return 0;
}


// N : Length of wordlist 
// L : Length of wordlist[i]
// Time Complexity : O( N * L * 26)
// Space Complexity : O(N) 