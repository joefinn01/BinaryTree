#pragma once
class BinaryTree
{
public:
	BinaryTree(int data);
	~BinaryTree();
	

	struct TreeNode
	{
		TreeNode(int _data)
		{
			data = _data;
			left = nullptr;
			right = nullptr;
		}

		int data;
		TreeNode* left;
		TreeNode* right;
	};

	void Insert(int data);

	void PreOrder(TreeNode* node);
	void InOrder(TreeNode* node);
	void PostOrder(TreeNode* node);

	void Delete(int data, TreeNode* node);
	void Delete(TreeNode* node);

	TreeNode* GetRoot()
	{
		return root;
	}

private:
	TreeNode * root;
};

