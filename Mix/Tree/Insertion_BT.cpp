// In Binary tree(Not BST) insertion of new node is done always from left nost child ans then right
// Note : Anywhere (random) is not possible for now

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node {
    int data;
    Node* left;
    Node* right;
    public:
    Node* getNewNode(int val);
    Node* insertNode(Node* root, int insertVal);
    void levelOrder(Node* root);
    void inorder(Node* root);

	void postorderIterative(Node* root)
{
    stack<Node*> s;
    s.push(root);
    stack<int> out;
    while (!s.empty())
    {
        Node* curr = s.top();
        s.pop();
 
        
		
		out.push(curr->data);
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
};
int main() {
    Node* head = NULL;
    Node* oo = new Node();
    oo->levelOrder(head);
    cout<<"\n";
    head = oo->insertNode(head, 20);
    oo->levelOrder(head);
    cout<<"\n";
    head = oo->insertNode(head, 5);
    head = oo->insertNode(head, 70);
    head = oo->insertNode(head, 10);
    head = oo->insertNode(head, 25);
    head = oo->insertNode(head, 9);
    
    
    oo->levelOrder(head);
    cout<<"\n\n";
    oo->inorder(head);
    cout<<"fioor \n";
    oo->postorderIterative(head);
    
    
	return 0;
}

Node* Node::getNewNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* Node::insertNode(Node* root, int insertVal) {
    if(root == NULL) {
        root = getNewNode(insertVal);
    }
    else {
        std::queue<Node*> storage;
        storage.push(root);
        while(storage.size()) {
            Node* temp = storage.front();
            storage.pop();
            if(temp->left != NULL) {
                storage.push(temp->left);
            }
            else {
                temp->left = getNewNode(insertVal);
                return root;
            }
            if(temp->right != NULL) {
                storage.push(temp->right);
            }
            else {
                temp->right = getNewNode(insertVal);
            	return root;
			}
        }
    }
}
void Node::levelOrder(Node* root) {
    if(root == NULL) {
        cout<<"Empty ";
        return ;
    }
    else {
        std::queue<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* temp = st.front();
            cout<<temp->data<<" ";
            if(temp->left != NULL) {
                st.push(temp->left);
            }
            if(temp->right != NULL) {
                st.push(temp->right);
            }
            st.pop();
        }
    }
}
void Node::inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    else {
        inorder(root->left);
        
        inorder(root->right);
        cout<<root->data<<" ";
    }
}
