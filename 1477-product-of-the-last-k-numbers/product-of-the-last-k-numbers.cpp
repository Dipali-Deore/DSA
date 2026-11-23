
class ProductOfNumbers {
public:
    vector<long long> prefix;
    int lastZeroIndex;

    ProductOfNumbers() {
        prefix.push_back(1);
        lastZeroIndex = 0;
    }

    void add(int num) {
        if (num == 0) {
            prefix.push_back(1);
            lastZeroIndex = prefix.size() - 1;
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        // If the last k numbers contain zero
        if (n - 1 - k < lastZeroIndex) {
            return 0;
        }

        return prefix[n - 1] / prefix[n - 1 - k];
    }
};
