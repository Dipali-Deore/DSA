class Solution {
    struct Node {
        char lc, rc;
        int pref, suff, best, len;

        Node() {}

        Node(char c) {
            lc = rc = c;
            pref = suff = best = len = 1;
        }
    };

    vector<Node> st;
    string s;

    Node merge(Node &a, Node &b) {
        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.rc == b.lc) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = Node(s[l]);
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, char c) {
        if (l == r) {
            st[p] = Node(c);
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, c);
        else
            update(p * 2 + 1, m + 1, r, idx, c);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        st.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(st[1].best);
        }

        return ans;
    }
};