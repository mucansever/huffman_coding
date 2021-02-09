#include "Huffman.h"

// encode given file
void Huffman::encode(string fileName) {
    unordered_map<char,int> m;
    vector< pair<char,int> > chars;
    vector<HuffmanTree> trees;
    vector<string> lines;

    // read input file
    ifstream stringFile (fileName);
    string s;
    while (getline(stringFile, s)) {
        lines.push_back(s);
        // fill the hash map
        for (char c: s)
            if (!m[c])
                m[c] = 1;
            else
                m[c]++;
    }
    // put pairs in hashmap to a vector and sort it
    for (pair<int,char> p: m) {
        chars.push_back(make_pair(p.second,p.first));
    }
    sort(chars.begin(),chars.end(),greater< pair<int,char> >());

    for (pair<int,char> p: chars) {
        // create new tree and add it to front of vector
        HuffmanTree newTree = HuffmanTree(p.first,p.second);
        trees.insert(trees.begin(),newTree);
    }

    // create the huffman tree by merging
    HuffmanTree huffman = trees[0];
    while(trees.size() > 1) {
        // merge first and second tree
        huffman = trees[0];
        huffman.merge(trees[1]);
        // place the merged tree into its respected space in vector ordered by size
        for (int i=2; i<trees.size(); i++) {
            if (trees[i].getSize() >= huffman.getSize()) {
                trees.insert(trees.begin()+i,huffman);
                break;
            }
            if (i==trees.size()-1) {
                trees.push_back(huffman);
                break;
            }
        }
        if (trees.size()==2)
            trees.push_back(huffman);
        // remove first two (merged) elements of vector
        trees.erase(trees.begin());
        trees.erase(trees.begin());
    }
    
    // print encodeed string
    for (string line: lines)
        cout << trees[0].encode(line) << endl;
    // store tree in file in order to decode afterwards
    ofstream outFile ("tree.txt");
    trees[0].store(outFile, trees[0].root);
    outFile.close();
}

// encode given char/string
void Huffman::encodeChar(string s) {
    // build huffman tree from previously saved tree file
    ifstream inFile ("tree.txt");
    HuffmanTree newTree = HuffmanTree();
    newTree.build(inFile, newTree.root);
    inFile.close();

    // encode given string/char
    cout << newTree.encode(s) << endl;
}

// decode given encoded file
void Huffman::decode(string fileName) {
    // build huffman tree from previously saved tree file
    ifstream inFile ("tree.txt");
    HuffmanTree newTree = HuffmanTree();
    newTree.build(inFile, newTree.root);
    inFile.close();

    // read input file
    ifstream stringFile (fileName);
    string s;
    while (getline(stringFile, s))
        // print decoded string
        cout << newTree.decode(s) << endl;
    stringFile.close();
}

// list tree
void Huffman::list() {
    // build huffman tree from previously saved tree file
    ifstream inFile ("tree.txt");
    HuffmanTree newTree = HuffmanTree();
    newTree.build(inFile, newTree.root);
    inFile.close();

    // list tree
    newTree.preorder();
}
