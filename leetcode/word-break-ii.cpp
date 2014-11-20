class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    s_ = s;
    pre_ = { {} };
    int n = s.size();
    for (int i = 1; i <= n; i++) {
      vector<int> t;
      for (int j = 0; j < i; j++) {
        string w = s.substr(j, i - j);
        if (dict.count(w)) t.push_back(j);
      }
      pre_.push_back(t);
    }
    ans_.clear();
    dfs(n);
    return ans_;
  }

private:
  string s_;
  vector<vector<int>> pre_;
  vector<string> ans_;

  void dfs(int x) {
    if (!x) ans_.push_back("");
    for (int y : pre_[x]) {
      int p = ans_.size();
      dfs(y);
      for (int i = p; i < ans_.size(); i++) {
        if (!ans_[i].empty()) ans_[i] += " ";
        ans_[i] += s_.substr(y, x - y);
      }
    }
  }
};
