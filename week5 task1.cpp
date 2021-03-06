﻿#include "stdafx.h"
#include <iostream>
using namespace std;

struct BinTreeNode {
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	struct BinTreeNode* toBeDeleted;

};

BinTreeNode* tree_insert(BinTreeNode* tree,  int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;

}

BinTreeNode* bin_tree_find(BinTreeNode* tree,int target) {
	if (tree->value == target || tree == NULL) {
		cout << "node found" << endl;
		return tree;
	}
	else if (target < tree->value)
		return bin_tree_find(tree->left, target);
	else
		return bin_tree_find(tree->right, target);
	return 0;
}


BinTreeNode* FindMin(BinTreeNode* tree)  //find minimum key in sub-node in an itterative way
{
	while (tree->left != NULL) tree = tree->left;
	return tree;
}

struct BinTreeNode* Delete(struct BinTreeNode* tree, int value) {
	int temp_int;

	if (tree == NULL)
		return tree;
	else if (value < tree->value)
		tree->left = Delete(tree->left, value);
	else if (value > tree->value)
		tree->right = Delete(tree->right, value);
	else {
		if (tree->right == NULL && tree->left == NULL) { //case 1 - NO CHILD
			delete tree;
			tree = NULL;
		}
		else if (tree->left == NULL) {  //case 2 - ONE CHILD
			struct BinTreeNode *temp = tree;  //temporary store the address of the current node we're deleting
			tree = tree->right;
			delete temp;
		}
		else if (tree->right == NULL) {
			struct BinTreeNode *temp = tree;
			tree = tree->left;
			delete temp;
		}
		else {  //case 3 - TWO CHILDREN
			struct BinTreeNode* temp = FindMin(tree->right);
			tree->value = temp->value;
			tree->right = Delete(tree->right, temp->value);
		}

	}
	return tree;
}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	cout << tree->value << endl;

}

void pre_order(BinTreeNode* tree) {
	cout << tree->value << endl;
	if (tree->left != NULL)
		pre_order(tree->left);
	if (tree->right != NULL)
		pre_order(tree->right);

}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	cout << tree->value << endl;
	if (tree->right != NULL)
		in_order(tree->right);
}

int main(int argc, char *argv[])
{
	int deleteKey;
	BinTreeNode* t = tree_insert(0, 6);
	tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);
	tree_insert(t, 11);
	tree_insert(t, 8);
	tree_insert(t, 7);
	tree_insert(t, 9);
	tree_insert(t, 13);
	tree_insert(t, 1);

	cout << "pre order traversal" << endl;
	pre_order(t);

	cout << "delete: ";
	cin >> deleteKey;
	cout << " ...deleting" << endl;

	Delete(t, deleteKey);

	pre_order(t);


	system("pause");
	return 0;
}


//refferences#
//https://www.youtube.com/watch?v=gcULXE7ViZw                                              //deletion
//https://www.youtube.com/watch?v=COZK7NATh4k                                             //binary search tree 
//https://www.youtube.com/watch?v=_8-ht2AKyH4&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_    //pointers and memory
