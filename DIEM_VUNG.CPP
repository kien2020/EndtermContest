/*
Author: chikien2009
*/
#include <bits/stdc++.h>

using namespace std;

inline void setup()
{
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, l[200003], r[200003], u[200003], d[200003];
int pre_l[200003], pre_r[200003], pre_u[200003], pre_d[200003]; 
int suf_l[200003], suf_r[200003], suf_u[200003], suf_d[200003];
long long res_dist = 8e18, cur_dist, c_left, c_up, c_down, c_right, res_left, res_down;

int main()
{
    setup();

    cin >> n;
    n++;
    pre_r[0] = pre_u[0] = suf_r[n + 1] = suf_u[n + 1] = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> u[i] >> r[i] >> d[i];
        pre_l[i] = max(pre_l[i - 1], l[i]);
        pre_r[i] = min(pre_r[i - 1], r[i]);
        pre_d[i] = max(pre_d[i - 1], d[i]);
        pre_u[i] = min(pre_u[i - 1], u[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        suf_l[i] = max(suf_l[i + 1], l[i]);
        suf_r[i] = min(suf_r[i + 1], r[i]);
        suf_d[i] = max(suf_d[i + 1], d[i]);
        suf_u[i] = min(suf_u[i + 1], u[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        c_left = max(pre_l[i - 1], suf_l[i + 1]);
        c_right = min(pre_r[i - 1], suf_r[i + 1]);
        c_down = max(pre_d[i - 1], suf_d[i + 1]);
        c_up = min(pre_u[i - 1], suf_u[i + 1]);
        if (c_left <= c_right && c_down <= c_up)
        {
            cur_dist = c_left * c_left + c_down * c_down;
            if (cur_dist < res_dist || (cur_dist == res_dist && c_left < res_left))
            {
                res_left = c_left;
                res_down = c_down;
                res_dist = res_left * res_left + res_down * res_down;
            }
        }
    }
    if (res_dist == 8e18)
    {
        cout << "NU\n";
        return 0;
    }
    cout << res_left << " " << res_down;
    return 0;
}
