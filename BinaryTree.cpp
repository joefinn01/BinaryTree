#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(int data)
{
	root = new TreeNode(data);
}


BinaryTree::~BinaryTree()
{
	root = nullptr;
}

void BinaryTree::Insert(int data)
{
	TreeNode* currentNode;
	currentNode = root;

	while (true)
	{
		if (currentNode->data > data)
		{
			if (currentNode->left != nullptr)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode->left = new TreeNode(data);
				break;
			}
		}
		else
		{
			if (currentNode->right != nullptr)
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode->right = new TreeNode(data);
				break;
			}
		}
	}
}

void BinaryTree::PreOrder(TreeNode* node)
{
	cout << node->data << endl;

	if (node->left != nullptr)
	{
		PreOrder(node->left);
	}

	if (node->right != nullptr)
	{
		PreOrder(node->right);
	}
}

void BinaryTree::InOrder(TreeNode* node)
{
	if (node->left != nullptr)
	{
		PreOrder(node->left);
	}

	cout << node->data << endl;

	if (node->right != nullptr)
	{
		PreOrder(node->right);
	}
}
void BinaryTree::PostOrder(TreeNode* node)
{
	if (node->left != nullptr)
	{
		PreOrder(node->left);
	}

	if (node->right != nullptr)
	{
		PreOrder(node->right);
	}

	cout << node->data << endl;
}

void BinaryTree::Delete(TreeNode* node)
{
	if (node->left != nullptr)
	{
		Delete(node->left);
	}

	if (node->right != nullptr)
	{
		Delete(node->right);
	}

	delete node;
	node = nullptr;
}

void BinaryTree::Delete(int data, TreeNode* node)
{
	if (node->left != nullptr)
	{
		if (node->left->data == data)
		{
			if (node->left->right == nullptr)
			{
				TreeNode* temp = node->left->left;
				
				delete node->left;

				node->left = temp;
			}
			else
			{
				TreeNode* temp = new TreeNode(node->left->right->data);
				temp->left = node->left->right;
				
				delete node->left;

				node->left = temp;

				delete temp;

				temp = nullptr;
			}
		}
		else
		{
			Delete(data, node->left);
		}
	}

	if (node->right != nullptr)
	{
		if (node->right->data == data)
		{
			if (node->right->right == nullptr)
			{
				node->right = node->right->left;
			}
			else
			{
				TreeNode* temp = new TreeNode(node->right->data);
				temp->left = node->right->right;

				delete node->right;

				node->right = temp;

				delete temp;

				temp = nullptr;
			}
		}
		else
		{
			Delete(data, node->right);
		}
	}
}