using namespace std;

class Node{
	private:
		Node *left;
		Node *right;
		char data;
	public:
		int countNodes(Node *root);
		void preOrder(Node *root);
		void postOrder(Node *root);
		void inOrder(Node *root);
		void insertNode(Node *&root, char newData, char leftData, char rightData, bool firstrun);
		void insertNode(Node *&root, char newData);
		void nodeTable(Node *root);
		void nodePrint(Node *root);
		void root();
		Node::Node(char dat){
			data = dat;
			left = NULL;
			right = NULL;
		}
};

void Node::insertNode(Node *&root, char newData, char leftData, char rightData, bool firstrun){
	if(root == NULL && firstrun){
		root = new Node (newData);
		if(leftData != '0'){insertNode(root->left, leftData);}
		if(rightData != '0'){insertNode(root->right, rightData);}
		return;
	}
	else{
		Node *runner;
		runner = root;
		if(runner == NULL){
			return;
		}
		else if(newData == runner->data){
			if(leftData != '0'){insertNode(runner->left, leftData);}
			if(rightData != '0'){insertNode(runner->right, rightData);}
			return;
		}
		insertNode(runner->left, newData, leftData, rightData, false);
		insertNode(runner->right, newData, leftData, rightData, false);
	}
}

void Node::insertNode(Node *&root, char newData){
	root = new Node (newData);
	return;
}

void Node::root(){
	cout<<data;
}

int Node::countNodes(Node *root){
	if(root == NULL){
		return 0;
	}
	else{
		int count = 1;
		count += countNodes(root->left);
		count += countNodes(root->right);
		return count;
	}
}

void Node::preOrder(Node *root){
	if(root != NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void Node::postOrder(Node *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void Node::inOrder(Node *root){
	if(root != NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void Node::nodeTable(Node *root){
	cout<<"|"<<std::left<<setw(10)<<"Node"<<"|"<<setw(10)<<"L-Subtree"<<"|"<<setw(10)<<"R-Subtree"<<"|"<<endl;
	nodePrint(root);
	cout<<endl;
}

void Node::nodePrint(Node *root){
	if(root != NULL){
		char dataLeft = '0', dataRight = '0';
		Node *runner;
		if(root->left != NULL || root->right != NULL){
			if(root->left != NULL){
				runner = root->left;
				dataLeft = runner->data;
			}
			if(root->right != NULL){
				runner = root->right;
				dataRight = runner->data;
			}
			cout<<"|"<<std::left<<setw(10)<<root->data;
			if(dataLeft == '0'){
				cout<<"|"<<setw(10)<<"null";
			}
			else{
				cout<<"|"<<setw(10)<<dataLeft;
			}
			if(dataRight == '0'){
				cout<<"|"<<setw(10)<<"null"<<"|"<<endl;
			}
			else{
				cout<<"|"<<setw(10)<<dataRight<<"|"<<endl;
			}
			nodePrint(root->left);
			nodePrint(root->right);
		}
	}
}
