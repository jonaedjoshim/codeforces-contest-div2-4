#include <bits/stdc++.h>
using namespace std;

int findRoot(vector<int> &parent, int x)
{
    int root = x;
    while (parent[root] != root)
    {
        root = parent[root];
    }
    while (parent[x] != root)
    {
        int nxt = parent[x];
        parent[x] = root;
        x = nxt;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<long long> diff(n + 2, 0);
        for (int k = 1; k <= n; k++)
        {
            long long m = a[k];
            long long L = m * k;
            if (L < n)
            {
                long long R = min(m * k + k - 1, (long long)(n - 1));
                diff[L] += 1;
                diff[R + 1] -= 1;
            }
        }
        vector<char> excluded(n, 0);
        long long cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += diff[i];
            if (cur > 0)
            {
                excluded[i] = 1;
            }
        }
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (i < n && excluded[i])
            {
                parent[i] = i + 1;
            }
            else
            {
                parent[i] = i;
            }
        }
        vector<char> inB(n, 0);
        for (int k = 1; k <= n; k++)
        {
            long long m = a[k];
            for (long long v = 0; v < m; v++)
            {
                long long L = v * k;
                long long R = min(v * k + k - 1, (long long)(n - 1));
                int pos = findRoot(parent, (int)L);
                if (pos <= R)
                {
                    inB[pos] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (inB[i])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            if (inB[i])
            {
                if (!first)
                {
                    cout << " ";
                }
                cout << i;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}