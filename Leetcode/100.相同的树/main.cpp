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

//方法一：深度优先搜索
//如果两个二叉树都为空，则两个二叉树相同。如果两个二叉树中有且只有一个为空，则两个二叉树一定不相同。
//如果两个二叉树都不为空，那么首先判断他们的根节点的值是否相同，若不相同则两个二叉树一定不同；若相同，再分别判断两个二叉树的左子树是否相同以及右子树是否相同。
//这是一个递归的过程，因此可以使用深度优先搜索，递归地判断两个二叉树是否相同。

//时间复杂度分析：O(min(m,n))，其中m和n分别是两个二叉树的节点数。对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点都不为空时才会访问到该节点，因此被访问到的节点数不会超过较小的二叉树的节点数。


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            return false;
        }else if(p->val != q->val){
            return false;
        }else{
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

//方法二：广度优先搜索
//也可以通过广度优先搜索判断两个二叉树是否相同。同样首先判断两个二叉树是否为空，如果两个二叉树都不为空，则从两个二叉树的根节点开始广度优先搜索。
//使用两个队列分别存储两个二叉树的节点。初始时将两个二叉树的根节点分别加入两个队列。每次从两个队列各取出一个节点，进行如下比较操作。
//1.比较两个节点的值，如果两个节点的值不相同则两个二叉树一定不同；
//2.如果两个节点的值相同，则判断两个节点的子节点是否为空，如果只有一个节点的左子节点为空，或者只有一个节点的右子节点为空，则两个二叉树的结构不同，因此两个二叉树一定不同；
//3.如果两个节点的子节点的结构相同，则将两个节点的非空子节点分别加入两个队列，子节点加入队列时需要注意顺序，如果左右子节点都不为空，则先加入左子节点，后加入右子节点。
//如果搜索结束时两个队列同时为空，则两个二叉树相同。如果只有一个队列为空，则两个二叉树的结构不同，因此两个二叉树不同。

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      queue<TreeNode*> que;
      if(p==NULL&&q==NULL)
        return true;
      que.push(p);
      que.push(q);
      while(!que.empty())
      {
       TreeNode* lefttree = que.front();que.pop();
       TreeNode* righttree = que.front();que.pop();
       if(!lefttree&&!righttree) 
         continue;
       if(!lefttree||!righttree||(lefttree->val!=righttree->val))
         return false;
       que.push(lefttree->left);
       que.push(righttree->left);
       que.push(lefttree->right);
       que.push(righttree->right);
      }
      return true;
    }
};