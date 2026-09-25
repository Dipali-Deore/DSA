class Solution {
public:

    set<string> parse(string &s, int &i) {

        set<string> result;
        set<string> current;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++; // skip {

                set<string> inside = parse(s, i);

                i++; // skip }

                if (current.empty()) {
                    current = inside;
                }
                else {
                    current = multiply(current, inside);
                }
            }

            else if (s[i] == ',') {

                result.insert(current.begin(), current.end());
                current.clear();

                i++;
            }

            else {

                string ch(1, s[i]);

                set<string> letter = {ch};

                if (current.empty()) {
                    current = letter;
                }
                else {
                    current = multiply(current, letter);
                }

                i++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }


    set<string> multiply(set<string> &A, set<string> &B) {

        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};