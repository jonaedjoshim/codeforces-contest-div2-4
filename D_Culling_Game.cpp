#include <bits/stdc++.h>

using namespace std;

struct Fenwick
{
    int n;
    vector<long long> tree;

    void init(int sz)
    {
        n = sz;
        tree.assign(n + 1, 0);
    }

    void update(int pos, long long val)
    {
        for (; pos <= n; pos += pos & (-pos))
        {
            tree[pos] += val;
        }
    }

    long long prefix(int pos)
    {
        long long res = 0;

        for (; pos > 0; pos -= pos & (-pos))
        {
            res += tree[pos];
        }

        return res;
    }

    long long rangeSum(int l, int r)
    {
        if (l > r)
        {
            return 0;
        }

        return prefix(r) - prefix(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }

        Fenwick bit;
        bit.init(n);

        set<int> active;
        set<int> blockStart;

        vector<int> ans(n + 1, 0);

        for (int m = 1; m <= n; m++)
        {
            int q = p[n + 1 - m];
            long long x = a[q];

            active.insert(q);
            bit.update(q, x);

            auto it = active.find(q);

            int cur;

            if (it == active.begin())
            {
                blockStart.insert(q);
                cur = q;
            }
            else
            {
                auto predIt = it;
                --predIt;

                int pred = *predIt;

                auto bIt = blockStart.upper_bound(pred);
                --bIt;

                int B = *bIt;

                long long sPre = bit.rangeSum(B, pred);

                if (sPre >= x)
                {
                    cur = B;
                }
                else
                {
                    blockStart.insert(q);
                    cur = q;
                }
            }

            while (true)
            {
                auto nxtIt = blockStart.upper_bound(cur);

                if (nxtIt == blockStart.end())
                {
                    break;
                }

                int nxt = *nxtIt;

                long long curSum = bit.rangeSum(cur, nxt - 1);

                if (curSum >= a[nxt])
                {
                    blockStart.erase(nxt);
                }
                else
                {
                    break;
                }
            }

            ans[m] = (int)blockStart.size() - 1;
        }

        for (int i = 0; i < n; i++)
        {
            int m = n - i;

            cout << ans[m];

            if (i != n - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}