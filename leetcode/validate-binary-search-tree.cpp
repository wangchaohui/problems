class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
  }

 private:
  bool isValidBST(TreeNode *root, int low, int high) {
    return !root || low <= root->val && root->val <= high
        && (!root->left || low < root->val && isValidBST(root->left, low, root->val - 1))
        && (!root->right || high > root->val && isValidBST(root->right, root->val + 1, high));
  }
};
