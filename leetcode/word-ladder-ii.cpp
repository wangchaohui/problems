class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        start_ = start;
        f_.clear();
        int l = start.size();
        dict.insert(end);
        dict.erase(start);
        unordered_set<string> pre{ start };
        unordered_set<string> now;
        while (!pre.empty() && !dict.empty()) {
            for (const string &s : pre) {
                string t = s;
                for (int i = 0; i < l; i++) {
                    for (char c = 'a'; c <= 'z'; c++) if (s[i] != c) {
                        t[i] = c;
                        if (dict.count(t)) {
                            f_[t].push_back(s);
                            now.insert(t);
                        }
                    }
                    t[i] = s[i];
                }
            }
            for (const string &s : now) dict.erase(s);
            pre = move(now);
        }
        ans_.clear();
        dfs(end);
        return ans_;
    }

private:
    string start_;
    unordered_map<string, vector<string>> f_;
    vector<vector<string>> ans_;

    void dfs(const string &s) {
        if (s == start_) {
            ans_.push_back({ s });
            return;
        }
        int p = ans_.size();
        for (const string &t : f_[s]) dfs(t);
        for (int i = p; i < ans_.size(); i++)
            ans_[i].push_back(s);
    }
};
