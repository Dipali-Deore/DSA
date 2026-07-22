class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> runStart, runEnd, runVal;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runStart.push_back(i);
            runEnd.push_back(j - 1);
            runVal.push_back(s[i] - '0');
            i = j;
        }
        int k = runStart.size();

        long long totalOnes = 0;
        for (int idx = 0; idx < k; idx++)
            if (runVal[idx] == 1) totalOnes += (runEnd[idx] - runStart[idx] + 1);

        auto runLen = [&](int idx) -> long long {
            return runEnd[idx] - runStart[idx] + 1;
        };

        vector<long long> G(k, -1);
        for (int idx = 1; idx < k - 1; idx++) {
            if (runVal[idx] == 1) G[idx] = runLen(idx - 1) + runLen(idx + 1);
        }

        int LOG = 1;
        while ((1 << LOG) <= k) LOG++;
        vector<vector<long long>> sparse(LOG, vector<long long>(k, -1));
        if (k > 0) sparse[0] = G;
        for (int p = 1; p < LOG; p++) {
            for (int idx = 0; idx + (1 << p) <= k; idx++)
                sparse[p][idx] = max(sparse[p - 1][idx], sparse[p - 1][idx + (1 << (p - 1))]);
        }
        vector<int> logTable(k + 1, 0);
        for (int v = 2; v <= k; v++) logTable[v] = logTable[v / 2] + 1;

        auto queryMax = [&](int l, int r) -> long long {
            if (l > r) return -1;
            int p = logTable[r - l + 1];
            return max(sparse[p][l], sparse[p][r - (1 << p) + 1]);
        };

        auto findRun = [&](int pos) -> int {
            int lo = 0, hi = k - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (runStart[mid] <= pos) lo = mid;
                else hi = mid - 1;
            }
            return lo;
        };

        int qn = queries.size();
        vector<int> ans(qn);
        for (int qi = 0; qi < qn; qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            int iL = findRun(l), iR = findRun(r);
            long long maxGain = -1;
            int low = iL + 1, high = iR - 1;
            if (low <= high) {
                if (low == high) {
                    if (runVal[low] == 1) {
                        long long cand = (runStart[low] - l) + (r - runEnd[low]);
                        maxGain = max(maxGain, cand);
                    }
                } else {
                    if (runVal[low] == 1) {
                        long long cand = (runStart[low] - l) + runLen(low + 1);
                        maxGain = max(maxGain, cand);
                    }
                    if (runVal[high] == 1) {
                        long long cand = runLen(high - 1) + (r - runEnd[high]);
                        maxGain = max(maxGain, cand);
                    }
                    if (low + 1 <= high - 1) {
                        maxGain = max(maxGain, queryMax(low + 1, high - 1));
                    }
                }
            }
            long long result = totalOnes + max(maxGain, (long long)0);
            ans[qi] = (int) result;
        }
        return ans;
    }
};