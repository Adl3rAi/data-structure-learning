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
int findMin(bstNode* root) {
    if(root == NULL) return -1;
    bstNode* current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return current->data;
}
int findMax(bstNode* root) {
    if(root == NULL) return -1;
    bstNode* current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    return current->data;
}
int findHeight(bstNode* root) {
    if(root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}
int main()
{
    bstNode* root = NULL;
    int num[7] = {6,4,8,2,5,7,9};
    for(auto i = 0; i < 7; i++) {
        root = Insert(root, num[i]);
    }
    // levelOrder(root);
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);

    // cout << Search(root, 9) << endl;
    // cout << Search(root, 10) << endl;

    // cout << findMin(root) << endl;
    // cout << findMax(root) << endl;

    // cout << findHeight(root);
}