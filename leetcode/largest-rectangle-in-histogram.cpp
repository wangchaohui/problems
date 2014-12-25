template<class T> inline void CheckMax(T &a, T b) { if (b > a) a = b; }

class MQueue {
public:
  void Add(int key, int value) {
    s_.push({ key, value });
  }

  void Pop(int value, function<void(int key, int value)> f) {
    pii top;
    while (value < (top = s_.top()).second) {
      f(top.first, top.second);
      s_.pop();
    }
  }

  int TopValue() {
    return s_.top().second;
  }

private:
  typedef pair<int, int> pii;

  stack<pii> s_;
};

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    q_.Add(-1, 0);
    int n = height.size();
    for (int i = 0; i < n; i++)
      add(height[i], i);
    add(0, n);
    return ans_;
  }

private:


  void add(int height, int i) {
    int l = i;
    q_.Pop(height, [&](int k, int v) {
      CheckMax(ans_, (i - k) * v);
      l = k;
    });
    if (height > q_.TopValue())
      q_.Add(l, height);
  }

  int ans_ = 0;
  MQueue q_;
};
