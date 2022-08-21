class Solution {
public:
    // in this use the concept of perorder root right left
   vector<int> rightSideView(TreeNode*root)
{
	vector<int> ans;
	// perorder(root,0,ans);
    levelordered(root,ans);
	return ans;


}
    void levelordered(TreeNode*root,vector<int>&ans){
        if(root==NULL)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                auto node = q.front();
                q.pop();
                if(i==n-1){
                    ans.push_back(node->val);
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
        }
        
    }

// 
void perorder(TreeNode*root,int l,vector<int>&ans)
{
	if(root==NULL)
		return;

	if(ans.size()==l)ans.push_back(root->val); // when the level  equal to root size it push the value in the answer
	perorder(root->right,l+1,ans); // right side call
	perorder(root->left,l+1,ans); // left side call
}