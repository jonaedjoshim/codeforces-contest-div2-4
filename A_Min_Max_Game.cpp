#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ones = 0, zeros = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }

        if (ones >= zeros)
        {
            cout << "Bessie" << endl;
        }
        else
        {
            cout << "Elsie" << endl;
        }
    }

    return 0;
}