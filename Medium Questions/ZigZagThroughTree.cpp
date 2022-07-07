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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        
        DFS(root, 0, results);
        return results;
    }
    
    void DFS(TreeNode* node, int level, vector<vector<int>> &result) {
        if (level >= result.size()) {
            vector<int> newLevel;
            newLevel.push_back(node->val);
            result.push_back(newLevel);
        }
        else {
            if (level % 2 == 0) {
                result[level].push_back(node->val);
            }
            else {
                result[level].insert(result[level].begin(), node->val);
            }
        }
        
        if (node->left != NULL) DFS(node->left, level+1, result);
        if (node->right != NULL) DFS(node->right, level+1, result);
    }
};