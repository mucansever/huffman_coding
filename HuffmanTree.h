#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int qt; // quantity
    char val; // value
};

class HuffmanTree {
    public:
        Node* root;
        HuffmanTree(); // constructor
        HuffmanTree(int qt, char val); // constructor
        void merge(HuffmanTree& other); // merge with another tree
        void preorder(); // inorder traversal 
        string decode(string encodedString); // decode
        string encode(string text); // encode
        void store(ofstream& file, Node* node); // stores tree to file
        void build(ifstream& file, Node*& node); // build tree from file
        int getSize(); // return size
};