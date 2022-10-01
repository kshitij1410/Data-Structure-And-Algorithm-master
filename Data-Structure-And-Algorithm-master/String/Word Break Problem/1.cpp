#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a valid sentence without any spaces between the words
and a dictionary of valid English words, find all possible ways
to break the sentence into individual dictionary words.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  and, cream, icecream, man, go, mango}

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile

Input: "ilikeicecreamandmango"
Output: i like ice cream and man go
        i like ice cream and mango
        i like icecream and man go
        i like icecream and mango

*/

// O(2^N)

int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "love", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

void wordBreakUtil(string str, int n, string result)
{

    for (int i = 1; i <= n; i++)
    {
        string temp = str.substr(0, i);

        if (dictionaryContains(temp))
        {
            if (i == n)
            {
                result += temp;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i, result + temp + " ");
        }
    }
}
void wordBreak(string str)
{
    // Last argument is prefix
    wordBreakUtil(str, str.size(), "");
}
int main()
{

    // Function call
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}

/*

bool isExist(string s,vector<string>b)
{
    for(int i=0;i<b.size();i++)
    {
        if(b[i]==s) return 1;
    }
    return 0;
}
int flag=0;

   int solve(string a,vector<string>b,int s,int e)
   {

       for(int i=s;i<a.size();i++)
       {
           string str = a.substr(s,i+1-s);

           if(isExist(str,b))
           {

               if(i==e)
               {
                 flag=1;
                 return 1;
               }
                solve(a,b,i+1,e);

           }
       }
       if(flag==1) return 1;
       return 0;
   }

    int wordBreak(string A, vector<string> &B) {

       int n=A.size();
      return solve(A,B,0,n-1);
    }
*/

class Solution
{
public:
    int dp[300];

    bool solve(string s, unordered_set<string> st, int i)
    {
        if (s.size() == i)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        string temp = "";
        for (int k = i; k < s.size(); k++)
        {
            temp += s[k];
            if (st.find(temp) != st.end())
            {
                if (solve(s, st, k + 1) == true)
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof(dp));
        return solve(s, st, 0);
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] and
                    word_set.find(s.substr(j, i - j)) != word_set.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};