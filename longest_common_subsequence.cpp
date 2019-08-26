#include<bits/stdc++.h>
using namespace std;

// recursive approach
int LCS_len(string A, string B)
{
    if(A.size() == 0 ||B.size() == 0)
        return 0;
    
    if(A.back() == B.back())
    {
        return 1 + LCS_len(A.substr(0,A.size()-1),B.substr(0,B.size()-1));
    }
    else
    {
        return max(LCS_len(A.substr(0,A.size()-1),B.substr(0,B.size())),LCS_len(A.substr(0,A.size()),B.substr(0,B.size()-1)));
    }
    
}

// memoized approach or top down approach  using map
// we began with the complete strings and calculated the lcs for them and to prevent recalculation of some substrings we store them in maps. 
int LCS_len_memo(string A , string B, unordered_map<string,int> umap)
{
    if(A.size() == 0 || B.size() == 0)
        return 0;

    string key = to_string(A.size()) + "|" + to_string(B.size());
    if(umap.find(key) == umap.end())
    {

        if(A.back() == B.back())
        {
            umap[key] = LCS_len_memo(A.substr(0,A.size()-1),B.substr(0,B.size()-1),umap) + 1;
        }
        else
        {
            umap[key] =  max(LCS_len_memo(A.substr(0,A.size()-1),B.substr(0,B.size()),umap),LCS_len_memo(A.substr(0,A.size()),B.substr(0,B.size()-1),umap));
        }

    }
    return umap[key];
}
// time complexity : (m*n)
// space complexity complexity : (m*n)
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------------------------
//using tabulation or bottom up approach
/**/
int LCS_len_tab(string A, string B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size()+1,0));
    for(int i = 1 ; i<=A.size();i++)
    {
        for(int j = 1 ; j<=B.size();j++)
        {
            if(A[i-1] == B[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    return dp[A.size()][B.size()];
}
// time complexity : (m*n)
// space complexity : (m*n)


int main()
{
    string s1,s2;   
    cin>>s1>>s2;
    unordered_map<string,int> umap;
    //cout<<LCS_len_memo(s1,s2,umap);
    cout<<LCS_len_tab(s1,s2);
}