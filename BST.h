#include<iostream>
#include"Node.h"
#include<queue>
using namespace std;


//Binary Search Tree STL

template <typename T>
struct BSTNode
{
	T data;
	BSTNode<T>* left_child;
	BSTNode<T>* right_child;

	BSTNode()
	{
		data = T();
		left_child = NULL;
		right_child = NULL;
	}

	BSTNode(T d)
	{
		data = d;
		left_child = NULL;
		right_child = NULL;
	}
};

template <typename T>
class Tree
{
	BSTNode<T>* root;
	queue<T> q;
public:
	Tree()
	{
		root = NULL;
	}

	Tree(const Tree<T>& Obj)
	{
		root = NULL;
		queue<BSTNode<T>*> Q;
		Q.push(Obj.root);
		BSTNode<T>* currnode;
		while (!Q.empty())
		{
			currnode = Q.front();
			Q.pop();
			insert(currnode->data);
			if (currnode->left_child != NULL)
			{
				Q.push(currnode->left_child);
			}

			if (currnode->right_child != NULL)
			{
				Q.push(currnode->right_child);
			}

		}
	}
	Tree<T>& operator=(const Tree<T>& Obj)
	{

		queue<BSTNode<T>*> Q;
		Q.push(Obj.root);
		BSTNode<T>* currnode;
		while (!Q.empty())
		{
			currnode = Q.front();
			Q.pop();
			insert(currnode->data);
			if (currnode->left_child != NULL)
			{
				Q.push(currnode->left_child);
			}

			if (currnode->right_child != NULL)
			{
				Q.push(currnode->right_child);
			}

		}
		return *this;
	}

	void erase(T val)
	{
		BSTNode<T>* curr = root;
		BSTNode<T>* parent = NULL;

		while (curr != NULL && curr->data != val) {
			parent = curr;
			if (val < curr->data)
				curr = curr->left_child;
			else
				curr = curr->right_child;
		}

		if (curr == NULL)
		{
			return;
		}
		if (curr->left_child == NULL && curr->right_child == NULL)
		{
			if (parent == NULL)
			{
				root = NULL;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = NULL;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = NULL;
			}
			delete curr;

		}
		else if (curr->right_child == NULL)
		{
			if (parent == NULL)
			{
				root = curr->left_child;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = curr->left_child;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = curr->left_child;
			}
			delete curr;
		}
		else if (curr->left_child == NULL)
		{
			if (parent == NULL)
			{
				root = curr->right_child;
			}
			else if (parent->left_child == curr)
			{
				parent->left_child = curr->right_child;
			}
			else if (parent->right_child == curr)
			{
				parent->right_child = curr->right_child;
			}
			delete curr;
		}
		else
		{
			BSTNode<T>* tempparent = NULL;
			BSTNode<T>* temp;

			temp = curr->right_child;
			while (temp->left_child != NULL) {
				tempparent = temp;
				temp = temp->left_child;
			}

			if (tempparent != NULL)
			{

				tempparent->left_child = temp->right_child;
			}

			else
				curr->right_child = temp->right_child;

			curr->data = temp->data;
			delete temp;
		}

	}



	void insert(T input)
	{
		BSTNode<T>* newnode = new BSTNode<T>(input);

		if (root == NULL)
		{
			root = newnode;
		}
		else
		{
			BSTNode<T>* currnode = root;

			while (currnode != NULL)
			{
				if (input < currnode->data) // Left subtree
				{
					if (currnode->left_child)
					{
						currnode = currnode->left_child;
					}
					else
					{
						currnode->left_child = newnode;
						break;
					}
				}
				else if (input > currnode->data) // Right subtree
				{
					if (currnode->right_child)
					{
						currnode = currnode->right_child;
					}
					else
					{
						currnode->right_child = newnode;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	bool find(T num)
	{
		BSTNode<T>* currnode = root;

		while (currnode != NULL)
		{
			if (currnode->data == num)
				return true;  // value is found
			else if (num < currnode->data)
				currnode = currnode->left_child;
			else
				currnode = currnode->right_child;
		}
		return false; // value not found
	}

	bool update(T olddata, T newdata)
	{
		BSTNode<T>* currnode = root;

		while (currnode != NULL)
		{
			if (currnode->data == olddata)
			{
				currnode->data = newdata;
				return true;  // value is found
			}
			else if (olddata < currnode->data)
			{
				currnode = currnode->left_child;
			}
			else
			{
				currnode = currnode->right_child;
			}
		}
		return false; // value not found
	}

	void levelOrder()

	{
		queue<BSTNode<T>*> tempq;
		if (!q.empty())
		{
			while (!q.empty())
			{
				q.pop();
			}
		}
		if (root != NULL)
		{
			tempq.push(root);
		}
		BSTNode<T>* temp = NULL;
		while (!tempq.empty())
		{
			temp = tempq.front();
			tempq.pop();
			q.push(temp->data);
			if (temp->left_child != NULL)
			{
				tempq.push(temp->left_child);
			}
			if (temp->right_child != NULL)
			{
				tempq.push(temp->right_child);
			}
		}
	}


	void clear() //will be used in destructor to prevent memory leak
	{
		if (root != NULL)
		{
			queue<BSTNode<T>*> Q;
			BSTNode<T>* currNode = NULL;
			Q.push(root);

			while (!Q.empty())
			{
				currNode = Q.front();
				Q.pop();

				if (currNode->left_child != NULL)
					Q.push(currNode->left_child);
				if (currNode->right_child != NULL)
					Q.push(currNode->right_child);

				delete currNode;
			}

			root = NULL;
		}
	}

	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void reset()
	{
		levelOrder();
	}

	bool islast()
	{
		return q.empty();
	}
	T getnext()
	{
		T temp = q.front();
		q.pop();
		return temp;
	}

	~Tree()
	{
		clear();
	}

};
