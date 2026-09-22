class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, K;
    vector<Node> seg;

    Node merge(Node &A, Node &B) {
        Node C;

        // Product of entire segment
        C.prod = (A.prod * B.prod) % K;

        // Prefixes completely inside A
        for (int r = 0; r < K; r++) {
            C.cnt[r] += A.cnt[r];
        }

        // Prefixes that contain all of A
        // and some prefix of B
        for (int r = 0; r < K; r++) {
            int newR = (A.prod * r) % K;
            C.cnt[newR] += B.cnt[r];
        }

        return C;
    }

    void build(int node, int l, int r, vector<int>& nums) {

        if (l == r) {
            int rem = nums[l] % K;

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = merge(seg[node * 2],
                           seg[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int idx, int value) {

        if (l == r) {

            int rem = value % K;

            seg[node] = Node();

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        seg[node] = merge(seg[node * 2],
                           seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Complete overlap
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        // Entirely in right
        if (ql > mid) {
            return query(node * 2 + 1,
                         mid + 1, r,
                         ql, qr);
        }

        // Entirely in left
        if (qr <= mid) {
            return query(node * 2,
                         l, mid,
                         ql, qr);
        }

        // Split
        Node left = query(node * 2,
                          l, mid,
                          ql, qr);

        Node right = query(node * 2 + 1,
                           mid + 1, r,
                           ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        n = nums.size();
        K = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1,
                   index, value);

            // Query nums[start ... n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};