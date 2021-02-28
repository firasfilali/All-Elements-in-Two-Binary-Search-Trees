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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2, list3;
        inorder(root1,list1);
        inorder(root2,list2);
        return merge(list1,list2,list3);
        
    }
   	void inorder(TreeNode* root,vector<int>& list){
      if(!root) return;// same as if (root == NULL)
      inorder(root->left,list);
      list.push_back(root->val); // push_back()
      inorder(root->right,list);
    }
    	vector<int> merge(vector<int>& list1,vector<int>& list2,vector<int>& list3){
      int i = 0, j = 0;
      while (i < list1.size() && j < list2.size()) {
      	if (list1[i] < list2[j]) {
          list3.push_back(list1[i]);
          i++;
        } else {
        	list3.push_back(list2[j]);
          j++;
        }
      }
      //  1 2 4
      // 2 3 
      while (i < list1.size()) {
        list3.push_back(list1[i]);
        i++;
      }
      while (j < list2.size()) {
        list3.push_back(list2[j]);
        j++;
      }
      return list3;
    }
};
