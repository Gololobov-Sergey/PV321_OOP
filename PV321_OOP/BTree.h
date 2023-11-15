#pragma once
#include<iostream>
#include<cassert>


using namespace std;

template<class TKey, class TVal>
struct BTreeNode
{
	TKey key;
	TVal value;
	BTreeNode* left  = nullptr;
	BTreeNode* right = nullptr;

	BTreeNode(const TKey& key, const TVal& val) : key(key), value(val) { }

	void del()
	{
		if (left  != nullptr) left->del();
		if (right != nullptr) right->del();
		delete this;
	}

	void print()
	{
		if (left  != nullptr) left->print();
		cout << value << " ";
		if (right != nullptr) right->print();
	}

	TVal* getValue(const TKey& key)
	{
		if (key == this->key) return &value;
		if (key < this->key && left  != nullptr) return left->getValue(key);
		if (key > this->key && right != nullptr) return right->getValue(key);
		return nullptr;
	}
};


template<class TKey, class TVal>
class BTree
{
	BTreeNode<TKey, TVal>* root = nullptr;

public:
	~BTree();
	void print();
	void clear();
	bool push(const TKey& key, const TVal& val);
	bool push_r(const TKey& key, const TVal& val);
	bool remove(const TKey& key);

};

template<class TKey, class TVal>
BTree<TKey, TVal>::~BTree()
{
	this->clear();
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::print()
{
	if (root)
		root->print();
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::clear()
{
	if (root)
		root->del();
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push(const TKey& key, const TVal& val)
{
	if (!root)
	{
		root = new BTreeNode<TKey, TVal>(key, val);
		return true;
	}

	BTreeNode<TKey, TVal>* current = root;
	do
	{
		if (key < current->key) 
		{
			if (current->left)
			{
				current = current->left;
			}
			else
			{
				current->left = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else if (key > current->key)
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				current->right = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else
		{
			return false;
		}
	} while (true);
}
