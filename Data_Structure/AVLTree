#ifndef AVL_TREE_H
#define AVL_TREE_H
 
#include<iostream>
using namespace std;
 
 
template <typename Comparable>
class AVLTree
{
 
public:
	typedef enum _order {PREORDER, INORDER, POSTORDER} ORDER; // 通过enum定义常量
 
public:
	AVLTree() :m_root(nullptr){}
	AVLTree(const AVLTree &rhs)
	{
		m_root = clone(rhs.m_root);
	}
	~AVLTree()
	{
		makeEmpty();
	}
 
	/**
	* 返回树的高度。空树的高度定义为-1
	*/
	int getHeight() const
	{
		return m_root.height;
	}
 
	/**
	* 找到树中的最小值，通过调用private的findMin实现递归
	*/
	const Comparable & findMin() const
	{
		return findMin(m_root)->element;
	}
 
	/**
	* 找到树中的最大值，通过调用private的findMax实现递归
	*/
	const Comparable & findMax() const
	{
		return findMax(m_root)->element;
	}
 
	/**
	* 当x找到时返回真，否则返回假
	* 调用了private的那个同名函数，这个是为了递归实现
	*（因为private中包含了一个AVLNode的指针t）
	*/
	bool contains(const Comparable &x) const
	{
		return contains(x, m_root);
	}
 
	/**
	* 判断树是否为空
	*/
	bool isEmpty() const
	{
		return  nullptr == m_root;
	}
 
	/**
	* 把树遍历一遍（顺序可以自己选择，默认为中序）
	*/
	void printTree(ORDER or = INORDER, ostream & out = cout) const
	{
		if (isEmpty())
			out << "Empty tree!" << endl;
		else
		{
			switch (or)
			{ 
				case PREORDER:
					preOrder(m_root, cout);
					break; 
				case INORDER:
					inOrder(m_root, cout);
					break;
				case POSTORDER:
					postOrder(m_root, cout);
					break;
				default:
					cerr << "打印树的顺序只能为PREORDER, INORDER, POSTORDER!" << endl;
					break;
			}
		}		
	}
 
	/**
	* 清空树
	*/
	void makeEmpty()
	{
		makeEmpty(m_root);
	}
 
	/**
	* 把x插入树中，如果重复了就忽略
	*/
	void insert(const Comparable &x)
	{
		insert(x, m_root);
	}
 
	/**
	* 把x从树中删除。如果x不在树中就什么都不做。
	*/
	void remove(const Comparable &x)
	{
		remove(x, m_root);
	}
 
	/**
	* 深拷贝
	*/
	const AVLTree & operator= (const AVLTree &rhs)
	{
		if (this != &rhs)
		{
			AVLNode *tmp = clone(rhs.m_root);
			makeEmpty();
			m_root = tmp;
		}
		return *this;
	}
 
 
private:
	struct AVLNode{
		Comparable element;
		AVLNode *left;
		AVLNode *right;
		int height;
 
		AVLNode(const Comparable &theElement,
			AVLNode *lt,
			AVLNode *rt,
			int h = 0)
			: element(theElement), left(lt), right(rt), height(h) {}
	};
 
	AVLNode *m_root; // 根节点
	static const int ALLOW_IMBALANCE = 1; // 允许实施平衡的高度界限
 
	/**
	* 用于比较两个数的大小（主要用于比较高度）
	*/
	int max (int a, int b)
	{
		return a >= b ? a : b; 
	}
 
	/**
	* 获得节点高度,空树的高度为-1
	*/
	inline int height(AVLNode *t) const
	{
		return nullptr == t ? -1 : t->height;
	}
 
	/**
	* 在树t中插入元素x，如果重复则什么也不做
	*/
	void insert(const Comparable &x, AVLNode * &t);
 
	/**
	* 在树t中删除元素x
	*/
	void remove(const Comparable &x, AVLNode * &t);
	
 
	/**
	* 查找最小的元素, 通过递归的方法
	*/
	AVLNode * findMin(AVLNode *t) const;
	
 
	/**
	* 查找最大的元素, 通过循环的方法
	*/
	AVLNode * findMax(AVLNode *t) const;
 
	/**
	* 通过遍历的方法查找x是否在树（或子树）t中
	*/
	bool contains(const Comparable &x, AVLNode * t) const;
	
	/**
	* 清空树
	*/
	void makeEmpty(AVLNode * &t);
	
	/**
	* 按前序打印子树
	*/
 
	void preOrder(AVLNode *t, ostream & out) const;
	/**
	* 按中序打印子树
	*/
 
	void inOrder(AVLNode *t, ostream & out) const;
	/**
	* 按后序打印子树
	*/
	void postOrder(AVLNode *t, ostream & out) const;
 
	/**
	* 复制子树
	*/
	AVLNode * clone(AVLNode *t) const;
 
	/**
	* 平衡子树
	*/
	void balance(AVLNode * &t);
 
	/**
	* 左旋（右子树比左子树高2，并且新插入的元素在右子树的右边）
	* 此时以右子树(k1)为轴，它的根(k2)进行左旋
	* 可以理解为它的根在它的左边，所以左旋（在左边旋转）
	*      K2                           K1
	*     /  \                         /  \
	*    X    k1         -----        K2   Z
	*         / \                    /  \   \
	*        Y   Z                  X    Y   Z'
	*             \
	*              Z'
	* Z'可能在Z的左边，也可以在Z的右边。例子中假设在右边。
	**/
	void rotateWithRightChild(AVLNode * & k2);
 
	/**
	* 右旋（左子树比右子树高2，并且新插入的元素在左子树的左边）
	* 此时以左子树（k1）为轴，它的根（k2）进行右旋
	* 可以理解为它的根在它的右边，所以右旋（在右边旋转）
	*       k2                      k1
	*      /  \                    /  \
	*     k1   Z      -------     X    k2
	*    /  \                    /     / \
	*   X    Y                  X'     Y   Z 
	*  /
	* X'
	* X'可能在X的左边，也可以在X的右边。例子中假设在左边。
	*/
	void rotateWithLeftChild(AVLNode * & k2);
 
	/**
	* 左右双旋（左子树K1比右子树D高2，并且新插入的元素在左子树K1的右边K2）
	* 第一步：对左子树k1进行一次左旋(轴为k2)
	* 第二步：对整个树k3进行一次右旋（轴为k2）
	*       k3                k3              k2
	*      /  \              /  \            /  \
	*     k1   D    ----    k2   D  ----    k1   k3
	*    / \               / \             / \   / \
	*   A   k2            k1  C           A   B  C  D
	*       / \          / \
	*      B   C        A   B
	*/
	void doubleWithLeftChild(AVLNode * & k3);
 
	/**
	* 右左双旋（右子树K1比左子树A高2，并且新插入的元素在右子树K1的左边K2）
	* 第一步：对右子树k1进行一次右旋（轴为k2）
	* 第二步：对整个树k3进行一次左旋（轴为k2）
	*      k3              k3                 k2
	*     /  \            /  \               /  \
	*    A    k1   ----  A    k2     ----  k3    k1
	*        / \             /  \         /  \  /  \
	*       K2  D           B    k1      A    B C   D
	*      / \                  /  \
	*     B   C                C    D
	*/
	void doubleWithRightChild(AVLNode * & k3);
 
	/**
	* 更新节点的高度
	*/
	inline void updateHeight(AVLNode * & t)
	{
		t->height = max(height(t->left), height(t->right)) + 1;
	}
 
};
 
 
/**
* 复制子树
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode * 
	AVLTree<Comparable>::clone(
		typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t == nullptr)
		return nullptr;
 
	return new AVLNode(t->element, clone(t->left), clone(t->right));
}
 
/**
* 按前序打印子树
*/
template <typename Comparable>
void AVLTree<Comparable>::preOrder(
	typename AVLTree<Comparable>::AVLNode*t, 
	ostream & out) const
{
	if (nullptr != t)
	{	
		out << t->element << endl;
		preOrder(t->left, out);
		preOrder(t->right, out);
	}
}
 
 
 
/**
* 按中序打印子树
*/
template <typename Comparable>
void AVLTree<Comparable>::inOrder(
	typename AVLTree<Comparable>::AVLNode *t, 
	ostream & out) const
{
	if (nullptr != t)
	{
		inOrder(t->left, out);
		out << t->element << endl;
		inOrder(t->right, out);
	}
}
 
/**
* 按后序打印子树
*/
template <typename Comparable>
void AVLTree<Comparable>::postOrder(
	typename AVLTree<Comparable>::AVLNode*t,
	ostream & out) const
{
 
	if (nullptr != t)
	{
		postOrder(t->left, out);
		postOrder(t->right, out);
		out << t->element << endl;
	}
}
 
 
/**
* 清空树
*/
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}
 
/**
* 查找最小的元素, 通过递归的方法
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode * 
	AVLTree<Comparable>::findMin(
	typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}
 
/**
* 查找最大的元素, 通过循环的方法
*/
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode * 
	AVLTree<Comparable>::findMax(
	typename AVLTree<Comparable>::AVLNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}
 
/**
* 在树t中删除元素x,一定要主要保持树的平衡
*/
template <typename Comparable>
void AVLTree<Comparable>::remove(
	const Comparable &x, 
	typename AVLTree<Comparable>::AVLNode * &t) 
{
	if (t == nullptr)
		return; // 没有找要删除的节点x
 
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr &&
		t->right != nullptr)
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		//typename AVLTree<Comparable>::AVLNode * oldNode = t;
		auto oldNode = t; // 这一句等于上面的那长长的语句，可以看出C++11中的auto还是非常有用 的
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
 
	balance(t);
}
 
/**
* 在树t中插入元素x，如果重复则什么也不做
*/
template <typename Comparable>
void AVLTree<Comparable>::insert(
	const Comparable &x, 
	typename AVLTree<Comparable>::AVLNode * &t) 
{
	if (nullptr == t)
		t = new AVLNode(x, nullptr, nullptr);
	else if (x < t->element)
	{
		insert(x, t->left); // 如果带插入的值小于目前的节点，则插入在左子树
		/*
		if (height(t->left) - height(t->right) == 2) // 插入后如果节点的左子树比右子树高2
		{
			if (x < t->left->element)
				rotateWithLeftChild(t); // 右旋
			else
				doubleWithLeftChild(t); // 左-右双旋
		}
		*/
 
	}
	else if (t->element < x)
	{
		insert(x, t->right);// 如果带插入的值大于目前的节点，则插入在右子树
		/*
		if (height(t->right) - height(t->left) == 2)// 插入后如果节点的右子树比左子树高2
		{
			if (t->right->element < x)
				rotateWithRightChild(t); // 左旋
			else
				doubleWithRightChild(t); // 右-左双旋
		}
		*/
 
	}
	else
		; // 表示在树中找到了x，则什么也不做
 
	balance(t); // 每次完成插入都检查子树是否平衡（并且默认更新节点t的高度）
}
 
/**
* 平衡子树
*/
template <typename Comparable>
void AVLTree<Comparable>::balance(
	typename AVLTree<Comparable>::AVLNode * &t)
{
	if (nullptr == t)
		return;
	// 如果左子树的高度与右子树高度差大于实施平衡调整的限度
	if (height(t->left) - height(t->right) > AVLTree<Comparable>::ALLOW_IMBALANCE)
	{
		// 判断是左子树的左边高还是右边高，如果左子树左边高
		if (height(t->left->left) >= height(t->left->right))
		{
			rotateWithLeftChild(t); 
		}
		else
		{ 
			doubleWithLeftChild(t);
		}
 
	}
	// 如果右子树的高度与左子树高度差大于实施平衡调整的限度
	else if (height(t->right) - height(t->left) > AVLTree<Comparable>::ALLOW_IMBALANCE)
	{
		if (height(t->right->right) >= height(t->right->left))
		{
			rotateWithRightChild(t);
		}
		else
		{
			doubleWithRightChild(t);
		}
	}
	else
		;
 
	updateHeight(t);
}
 
/**
* 通过遍历的方法查找x是否在树（或子树）t中
*/
template <typename Comparable>
bool AVLTree<Comparable>::contains(
	const Comparable &x, 
	typename AVLTree<Comparable>::AVLNode * t) const
{
	if (t == nullptr) // 遍历中未找到元素的中止条件
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else // 如果 x 不大于 也 不小于t所指的节点中的元素，则x==t->element
		return true;
}
 
/**
* 右旋（左子树比右子树高2，并且新插入的元素在左子树的左边）
* 此时以左子树（k1）为轴，它的根（k2）进行右旋
* 可以理解为它的根在它的右边，所以右旋（在右边旋转）
*       k2                      k1
*      /  \                    /  \
*     k1   Z      -------     X    k2
*    /  \                    /     / \
*   X    Y                  X'     Y   Z
*  /
* X'
* X'可能在X的左边，也可以在X的右边。例子中假设在左边。
*/
template <typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(
	typename AVLTree<Comparable>::AVLNode * & k2)
{
	//typename AVLTree<Comparable>::AVLNode * k1 = k2->left; // 获得k2的左节点
	auto k1 = k2->left; // 使用auto定义
	// 开始旋转
	k2->left = k1->right; 
	k1->right = k2;
	//更新高度, 先更新k2可以，更新k1时减少一次height函数的调用
	k2->height = max(height(k2->left), height(k2->right)) + 1;//等价于updateHeight(k2)
	k1->height = max(height(k1->left), k2->height) + 1;
 
	k2 = k1;
	
}
 
/**
* 左旋（右子树比左子树高2，并且新插入的元素在右子树的右边）
* 此时以右子树(k1)为轴，它的根(k2)进行左旋
* 可以理解为它的根在它的左边，所以左旋（在左边旋转）
*      K2                           K1
*     /  \                         /  \
*    X    k1         -----        K2   Z
*         / \                    /  \   \
*        Y   Z                  X    Y   Z'
*             \
*              Z'
* Z'可能在Z的左边，也可以在Z的右边。例子中假设在右边。
**/
template <typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(
	typename AVLTree<Comparable>::AVLNode * & k2)
{
	//typename AVLTree<Comparable>::AVLNode * k1 = k2->right;
	auto k1 = k2->right; // 使用auto定义
	// 开始旋转
	k2->right = k1->left;
	k1->left = k2;
	//更新高度, 先更新k2可以减少一次height函数的调用
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(k2->height, height(k1->right)) + 1; 
 
	k2 = k1;
}
 
/**
* 左右双旋（左子树K1比右子树D高2，并且新插入的元素在左子树K1的右边K2）
* 第一步：对左子树k1进行一次左旋(轴为k2)
* 第二步：对整个树k3进行一次右旋（轴为k2）
*       k3                k3              k2
*      /  \              /  \            /  \
*     k1   D    ----    k2   D  ----    k1   k3
*    / \               / \             / \   / \
*   A   k2            k1  C           A   B  C  D
*       / \          / \
*      B   C        A   B
* 注：一般来说，只会有B或C一个存在，就会进行树的平衡调整
*/
template <typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(
	typename AVLTree<Comparable>::AVLNode * & k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}
 
 
/**
* 右左双旋（右子树K1比左子树A高2，并且新插入的元素在右子树K1的左边K2）
* 第一步：对右子树k1进行一次右旋（轴为k2）
* 第二步：对整个树k3进行一次左旋（轴为k2）
*      k3              k3                 k2
*     /  \            /  \               /  \
*    A    k1   ----  A    k2     ----  k3    k1
*        / \             /  \         /  \  /  \
*       K2  D           B    k1      A    B C   D
*      / \                  /  \
*     B   C                C    D
*注：一般来说，只会有B或C一个存在，就会进行树的平衡调整
*/
template <typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(
	typename AVLTree<Comparable>::AVLNode * & k3)
{
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}
#endif  //AVL_TREE_H
