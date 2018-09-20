#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
}TreeNode;

TreeNode *minVal(TreeNode *root) {
	while(root != NULL && root->left != NULL && root->right != NULL) {
		root = root->left;
	}
	return root;
}

TreeNode *maxVal(TreeNode *root) {
	while(root != NULL && root->left != NULL && root->right != NULL) {
		root = root->right;
	}
	return root;
}

int maxValue(TreeNode *root) {
	while(root != NULL && root->left != NULL && root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

int minValue(TreeNode *root) {
	while(root != NULL && root->left != NULL && root->right != NULL) {
		root = root->left;
	}
	return root->data;
}

int treeHeight(TreeNode *root) {
	int leftHeight, rightHeight;
	if(root != NULL) {
		leftHeight = treeHeight(root->left);
		rightHeight = treeHeight(root->right);
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
}

int treeSize(TreeNode *root) {
	if(root != NULL) return 1 + treeSize(root->left) + treeSize(root->right);
}

void inorderTraversal(TreeNode *root) {
	TreeNode *ptr = root;
	if(ptr != NULL) {
		inorderTraversal(ptr->left);
		printf("Data: %d\n", ptr->data);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(TreeNode *root) {
	TreeNode *ptr = root;
	if(ptr != NULL) {
		printf("Data: %d\n", ptr->data);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(TreeNode *root) {
	TreeNode *ptr = root;
	if(ptr != NULL) {
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("Data: %d\n", ptr->data);
	}
}

TreeNode *addTree(TreeNode *root, int data) {
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *ptr = root;
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->parent = NULL;
	if(root == NULL) {
		root = temp;
	} else {
		if(ptr->data > data) {
			if(ptr->left == NULL) {
				ptr->left = temp;
				temp->parent = ptr;
			}
			else {
				addTree(ptr->left, data);
			}
		} else {
			if(ptr->right == NULL) {
				ptr->right = temp;
				temp->parent = ptr;
			}
			else {
				addTree(ptr->right, data);
			}
		}
	}
	return root;
}

TreeNode *deleteTree2(TreeNode *root, int data) {
	TreeNode *ptr = root, *temp = NULL;
	while(ptr != NULL && ptr->data != data) {
		if(data > ptr->data) ptr = ptr->right;
		else if(data < ptr->data) ptr = ptr->left;
	}
	
	if(ptr == NULL) {
		printf("The number to be deleted was not founded: %d\n", data);
		return root;
	}

	if(ptr->left == NULL && ptr->right == NULL) {
		if(ptr->data > ptr->parent->data) ptr->parent->right = NULL;
		else if(ptr->data < ptr->parent->data) ptr->parent->left = NULL;
		free(ptr);

	} else if(ptr->left == NULL) {
		if(ptr->parent->left->data == ptr->data) ptr->parent->left = ptr->right;
		else if(ptr->parent->right->data == ptr->data) ptr->parent->right = ptr->right;
		ptr->right->parent = ptr->parent;
		free(ptr);

	} else if(ptr->right == NULL) {
		if(ptr->parent->left->data == ptr->data) ptr->parent->left = ptr->left;
		else if(ptr->parent->right->data == ptr->data) ptr->parent->right = ptr->left;
		ptr->left->parent = ptr->parent;
		free(ptr);

	} else if(ptr->left != NULL && ptr->right != NULL) {
		temp = minVal(ptr->right);
		ptr->data = temp->data;
		if(temp->data > temp->parent->data) temp->parent->right = NULL;
		else if(temp->data < temp->parent->data) temp->parent->left = NULL;
		free(temp);
	}
	return root;
}

int main(void) {
	TreeNode *root = NULL;
	root = addTree(root, 10);
	root = addTree(root, 5);
	root = addTree(root, 3);
	inorderTraversal(root);
	root = deleteTree2(root, 8);
	return 0;
}