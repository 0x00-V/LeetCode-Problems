/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
       int closest = root->val;
       TreeNode* next = target < closest ? root->left : root->right;
       if(!next) return closest;

       int closest_subtr = closestValue(next, target);

       if(abs(closest - target) == abs(closest_subtr - target)) return min(closest, closest_subtr);

       return abs(closest - target) < abs(closest_subtr - target) ? closest :closest_subtr;
    }
};