//copy this whole code inside your function for RMQ
int log[2 * MAXN + 5];
    log[1] = 0;
    for (int i = 2; i <= 2 * MAXN; i++)
        log[i] = log[i / 2] + 1;  
    int N, Q;
    cin >> N >> Q;
    vector<ll> v(N + 5);
    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }
    int K = log[N];
    int dp[N + 5][K + 10];
    for (ll i = 0; i < N; i++) {
        debug(i)
        //     cout << i << endl;
        dp[i][0] = v[i];
    }
    for (ll j = 1; j <= K; j++) {
        for (ll i = 0; i + (1 << j) <= N; i++) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        L--;
        R--;
        int j = log[R - L + 1];
        int minimum = min(dp[L][j], dp[R - (1 << j) + 1][j]);
        cout << minimum << "\n";
    }
