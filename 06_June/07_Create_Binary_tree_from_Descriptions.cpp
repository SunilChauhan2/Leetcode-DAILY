// Problem : (LC 2196)Create binary tree from description
// Approach : Hash Table / queue / BFS
// Time Complexity : O(N)

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children, parents;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.insert(parent);
            parents.insert(child);
            children.insert(child);
            parentToChildren[parent].emplace_back(child, isLeft);
        }

        for (auto it = parents.begin(); it != parents.end();) {
            if (children.find(*it) != children.end()) {
                it = parents.erase(it);
            } else {
                ++it;
            }
        }
        TreeNode* root = new TreeNode(*parents.begin());

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* parent = queue.front();
            queue.pop();
            for (auto& childInfo : parentToChildren[parent->val]) {
                int childValue = childInfo.first, isLeft = childInfo.second;
                TreeNode* child = new TreeNode(childValue);
                queue.push(child);
                if (isLeft == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }

        return root;
    }
};