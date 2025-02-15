#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void anu()
{
    ull n, k;
    cin >> n >> k;
    ull tmp = k;
    vector<ull> vec;
    if (k == 1)
    {
        for (ull i = n; i >= 1; i--)
        {
            vec.push_back(i);
        }
        for (auto it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ull i, j = 1;
    ull temp = (n / k) + 1;
    while (temp--)
    {
        for (i = n; k > 1; i--)
        {
            if (i == j)
            {
                vec.push_back(i);
                break;
            }
            vec.push_back(i);
            k--;
        }
        n = n - tmp + 1;
        if (i != j)
        {
            vec.push_back(j);
            j++;
        }

        k = tmp;
        // cout << i + j << endl;
    }
    for (auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        anu();
    }

    return 0;
}
