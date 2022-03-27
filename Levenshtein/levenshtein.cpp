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


    vector<int> previous_row(n+1);
    vector<int> current_row;
    
    int cost;
    int ed;    
    
    if (n == 0)
        return m;

    for (int j = 0; j <= n; j++)
        previous_row[j] = j;

    for (int i = 0; i < m; i++)
    {        
        current_row.clear();
        current_row.push_back(i+1);
        for (int j = 0; j < n; j++)
        {            
            // get_cost
            if (s1[i] == s2[j]){
                cost = 0;
            }
            else {
                cost = 1;
            }
            
            int *insertions = new int;
            int *deletions = new int;
            int *substitutions = new int;
            int *min_ed = new int;

            *insertions = previous_row[j+1] + 1;
            *deletions = current_row[j] + 1;
            *substitutions = previous_row[j] + cost;            
            *min_ed = minimum(*insertions, *deletions, *substitutions);
            current_row.push_back(*min_ed);

            delete min_ed;
            delete insertions;
            delete deletions;
            delete substitutions;            
        }        
        previous_row = current_row;
        
    }

    ed = previous_row.back();    

    return ed;
}


int main()
{
    
    wstring str1 = L"메론";
    wstring str2 = L"수암숲속목장";
    cout << levenshtein(str1, str2);
    return 0;
}

