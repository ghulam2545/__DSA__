#include <iostream>
#include <stack>
#include <queue>
struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node *getNewNode(int val);
    Node *insertNode(Node *root, int insertVal);
    void traversal(Node *root);
    void toVerify(Node* root);
    void _traversal(Node *root);
};
int main() {
    Node* oo = new Node();
    Node* head = nullptr;
    
	// Insreting some random value
	head = oo->insertNode(head, 21);
    head = oo->insertNode(head, 45);
    head = oo->insertNode(head, 12);
    head = oo->insertNode(head, 67);
    head = oo->insertNode(head, 44);
    head = oo->insertNode(head, 20);

    oo->traversal(head);
    std::cout<<"\n\n";
    oo->toVerify(head);
    std::cout<<"\n\n";
    oo->_traversal(head);

    return 0;
}
Node *Node::getNewNode(int val) {
    Node *node = new Node();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node *Node::insertNode(Node *root, int insertVal) {
    if (root == nullptr) {
        root = getNewNode(insertVal);
    }
    else {
        std::queue<Node *> storage;
        storage.push(root);
        while (storage.size()) {
            Node *temp = storage.front();
            storage.pop();
            if (temp->left != nullptr) {
                storage.push(temp->left);
            } else {
                temp->left = getNewNode(insertVal);
                return root;
            }
            if (temp->right != nullptr) {
                storage.push(temp->right);
            } else {
                temp->right = getNewNode(insertVal);
                return root;
            }
        }
    }
}
void Node::traversal(Node *root) {
	if(root == nullptr) {
		std::cout<<"Empty :";
		return;
	}
    std::stack<Node*> s;
    s.push(root);
    std::stack<int> output;
    while (!s.empty()) {
        Node *curr = s.top();
        s.pop();
        output.push(curr->data);
        if (curr->left) {
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
    while (!output.empty()) {
        std::cout << output.top() << " ";
        output.pop();
    }
}
void Node::toVerify(Node* root) {
	if(root == nullptr) {
        return;
    }
    else {
        toVerify(root->left);
        toVerify(root->right);
        std::cout<<root->data<<" ";
    }
}
void Node::_traversal(Node *root) {
	if(root == nullptr) {
		std::cout<<"Empty :";
		return ;
	}
	Node* temp = nullptr;
	std::stack<Node*> ss;
	while(root!=nullptr || !ss.empty()) {
		if(root != nullptr) {
			ss.push(root);
			root = root->left;
		}
		else {
			root = ss.top();
			if(root->right==nullptr || root->right == temp) {
				std::cout<<root->data<<" ";
				ss.pop();
				temp = root;
				root = nullptr;
			}
			else {
				root = root->right;
			}
		}
	}
}
