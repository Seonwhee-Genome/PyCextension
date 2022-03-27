#include <bits/stdc++.h>
#include "levenshtein.h"

using namespace std;

int minimum(int x, int y, int z){
    return min(min(x,y),z);
}


int levenshtein(wstring s1, wstring s2)
{
    const int m = s1.length();
    const int n = s2.length();

    if (m < n)
        return levenshtein(s2, s1);

    
    int **row = new int *[n+1];
    
    
    for (int i = 0; i <= n; i++)
        row[i] = new int[m+1];
    
    int cost;
    int ed;    
    
    if (n == 0)
        return m;
    
    for (int i = 0; i <= m; i++)
        row[0][i] = i;
    
    for (int j = 0; j <= n; j++)
        row[j][0] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <=n; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                cost = 0;
            }
            else {
                cost = 1;
            }
            row[j][i] = minimum( (row[j-1][i] + 1),
                                (row[j][i-1] + 1),
                                (row[j-1][i-1] + cost));
        }
    }
    ed = row[n][m];
    
    for (int i = 0; i <= n; i++)
        delete[] row[i];
    delete[] row;

    return ed;
}

int main()
{
    
    wstring str1 = L"메론";
    wstring str2 = L"수암숲속목장";
    cout << levenshtein(str1, str2);
    return 0;
}

