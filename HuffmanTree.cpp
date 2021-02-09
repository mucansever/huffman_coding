#include "HuffmanTree.h"

// constructor
HuffmanTree::HuffmanTree() {
    root = NULL;
}

// constructor
HuffmanTree::HuffmanTree(int qt, char val) {
    root = new Node;
    root->left = NULL;
    root->right = NULL;
    root->qt = qt;
    root->val = val;
}

// merges tree with given tree
void HuffmanTree::merge(HuffmanTree& other) {
    // create new root
    Node* newTree = new Node;
    // assign current root to new root's left node
    newTree->left = root;
    // assign other tree's root to new root's right node
    newTree->right = other.root;
    newTree->val = '\0';
    // sum their quantities
    newTree->qt = root->qt+other.root->qt;
    root = newTree;
}

// recursive function for preorder traversal
void preorderHelper(Node* node, int depth) {
    if (node==NULL) 
        return;

    // print according to tree view
    for (int i=0; i<depth; i++) {
        if (i==0)
            cout << "   ";
        else
            cout << "|  ";
    }
    cout << "+- ";
    if (node->left==NULL && node->right==NULL)
        cout << node->val;
    else 
        cout << to_string(node->qt);
    cout << "\n";
    
    preorderHelper(node->left,depth+1);
    preorderHelper(node->right,depth+1);
}

// preorder traversal 
void HuffmanTree::preorder() {
    preorderHelper(root,0);
}

// Recursive function to tree
//   0 <char>      leaf nodes 
//   1 <quantity>  middle nodes
//   -             empty nodes
void HuffmanTree::store(ofstream& file, Node* node) {
    if (node==NULL) {
        file << "-\n";
        return;
    }
    // write to file
    if (node->left==NULL && node->right==NULL)
        file << "0 " << node->val << "\n";
    else
        file << "1 " << node->qt << "\n";
    
    store(file, node->left);
    store(file, node->right);
}

// build tree from file
void HuffmanTree::build(ifstream& file, Node*& node) {
    // if file has ended
    if (file.eof())
        return;

    string line;
    getline(file, line);
    // empty (NULL) node
    if (line[0]=='-') {
        node = NULL;
        return;
    }
    Node* newNode = new Node();
    if (line[0]=='0') // character node (leaf)
        newNode->val = line[2];
    else if (line[0]=='1') // quantity node
        newNode->qt = stoi(line.substr(2,line.size()-1));
    
    node = newNode;    
    build(file, node->left);
    build(file, node->right);
}

// build table with each character's huffman encoding
void buildTable(unordered_map<char, string> &table, string s, Node* node) {
    if (node==NULL)
        return;
    if (node->left==NULL && node->right==NULL) {
        table[node->val] = s;
        return;
    }
    buildTable(table,s+'0',node->left);
    buildTable(table,s+'1',node->right);
}

// decode given encoded string
string HuffmanTree::decode(string encodedString) {
    string ans = "";
    Node* temp = root;
    // from current node, go left for 0, right for 1
    for (char c: encodedString) {
        if (c=='0')
            temp=temp->left;
        else if (c=='1')
            temp = temp->right;
        // if reached a leaf, go back to root
        if (temp->left==NULL && temp->right==NULL) {
            ans += temp->val;
            temp = root;
        }
    }
    return ans;
}

// encode given string
string HuffmanTree::encode(string text) {
    // create a code table that stores binary sequence for all characters used
    unordered_map<char, string> table;
    buildTable(table,"",root);
    // encode entered text using code table
    string encodedText = "";
    for (char c: text) {
        encodedText += table[c];
    }
    return encodedText;
}

// return size
int HuffmanTree::getSize() {
    return root->qt;
}
