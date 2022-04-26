#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* getNewNode(int data) {
    bstNode* newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bstNode* Insert(bstNode* root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    }
    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}
void levelOrder(bstNode* root) {
    if(root == NULL) return;
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty()) {
        bstNode* current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}
void preOrder(bstNode* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(bstNode* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(bstNode* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int Search(bstNode* root, int data) {
    if(root == NULL) return false;
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);    
}
bstNode* findMin(bstNode* root) {
    if(root == NULL) return root;
    bstNode* current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}
bstNode* findMax(bstNode* root) {
    if(root == NULL) return root;
    bstNode* current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    return current;
}
int findHeight(bstNode* root) {
    if(root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}
int isSubLesser(bstNode* root, int val) {
    if(root == NULL) return true;
    else if(root->data <= val && isSubLesser(root->left, val) && isSubLesser(root->right, val)) return true;
    else return false;
}
int isSubGreater(bstNode* root, int val) {
    if(root == NULL) return true;
    else if(root->data > val && isSubGreater(root->left, val) && isSubGreater(root->right, val)) return true;
    else return false;
}
int isBST(bstNode* root) {
    if(root == NULL) return true;
    if(isSubLesser(root->left, root->data) && isSubGreater(root->right, root->data) && isBST(root->left) && isBST(root->right)) {
        return true;
    }
    else return false;
}
bstNode* Delete(bstNode* root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete(root);
            root = NULL;
        }
        else if(root->left == NULL) {
            bstNode* temp = root;
            root = root->right;
            delete(temp);
        }
        else if(root->right == NULL) {
            bstNode* temp = root;
            root = root->left;
            delete(temp);
        }
        else {
            bstNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    bstNode* root = NULL;
    int num[7] = {6,4,8,2,5,7,9};
    for(auto i = 0; i < 7; i++) {
        root = Insert(root, num[i]);
    }
    levelOrder(root);
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);

    // cout << Search(root, 9) << endl;
    // cout << Search(root, 10) << endl;

    // cout << findMin(root) << endl;
    // cout << findMax(root) << endl;

    // cout << findHeight(root);
    
    // cout << isBST(root);

    cout << endl;
    root = Delete(root, 6);
    levelOrder(root);
}