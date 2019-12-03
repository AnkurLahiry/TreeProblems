#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    
    public: 
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createBST(Node * node, int value) {
    if (node == NULL) {
        return new Node(value);
    }
    if(value >= node->value) {
        node->right = createBST(node->right, value);
    } else {
        node->left = createBST(node->left, value);
    }

    return node;
}

void inorder(Node * node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->value << "\t";
        inorder(node->right);
    }
}

void preOrder(Node * node) {
    if(node != NULL) {
        cout<< node->value << "\t";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node * node) {
    if(node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout<< node->value << "\t";
    }
}

void inorderIterative(Node * node) {
    stack<Node *> st;
    Node * current = node;
    while(current || !st.empty()) {
        while(current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->value << "\t";
        current = current->right;
    }
}

void preOrderIterative(Node * node) {
    stack<Node *> st;
    Node * current = node;
    while(current || !st.empty()) {
        
        while(current != NULL) {
            cout << current->value << "\t";
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        current = current->right;
    }
}

void postOrderIterative(Node * node) {
    stack<Node *> st;
    Node * current = node;
    while(current || !st.empty()) {
        if(current != NULL) {
            st.push(current);
            current = current->left;
        } else {
            Node * temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                cout<<temp->value<<"\t";
                st.pop();
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    cout<<temp->value<<"\t";
                }
            } else {
                current = temp;
            }
        }
    }
}


int main(int argc, char **argv) {

    Node * tree; 
    tree = createBST(tree, 25);
    createBST(tree, 15);
    createBST(tree, 10);
    createBST(tree, 4);
    createBST(tree, 12);
    createBST(tree, 22);
    createBST(tree, 18);
    createBST(tree, 24);
    createBST(tree, 50);
    createBST(tree, 35);
    createBST(tree, 31);
    createBST(tree, 44);
    createBST(tree, 70);
    createBST(tree, 66);
    createBST(tree, 90);

    // inorder(tree);
    // cout<< "\n";

    // inorderIterative(tree);
    // cout<< "\n";

    // preOrder(tree);
    // cout<< "\n";

    // preOrderIterative(tree);
    // cout<<"\n";

    postOrder(tree);
    cout << "\n";

    postOrderIterative(tree);
    cout << "\n";

    // postOrder(tree);
    // cout<< "\n";
    
    
    return 0;
}