#include<iostream>
#include<iomanip>
#include<conio.h>
#include"Node.cpp"
using namespace std;

int main(void){
	char node, left, right;
	int width = 10;
	Node *root;
	cout<<"Enter nodes by character (Node, Left, Right)"<<endl;
	cout<<"Press 0 if you want to stop input or the branches should be null."<<endl<<endl;
	while(true){
		cout<<"(";
		node = getch();
		if(node == '0'){cout<<"null,null,null)"<<endl<<endl; break;}
		else{cout<<node;}
		cout<<",";
		left = getch();
		if(left == '0'){cout<<"null";}
		else{cout<<left;}
		cout<<",";
		right = getch();
		if(right == '0'){cout<<"null";}
		else{cout<<right;}
		cout<<")"<<endl;
		if(node != '0'){root->insertNode(root, node, left, right, true);}
		
	}
	root->nodeTable(root);
	cout<<"Root of the Tree: ";
	root->root();
	cout<<endl<<endl<<"Preorder Traversal: ";
	root->preOrder(root);
	cout<<endl<<"Inorder Traversal: ";
	root->inOrder(root);
	cout<<endl<<"Postorder Traversal: ";
	root->postOrder(root);
	return 0;
}
