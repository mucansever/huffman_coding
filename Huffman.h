#include <vector>
#include <fstream>
#include <algorithm> 
#include "HuffmanTree.h"
using namespace std;

class Huffman {
    public:
        void encode(string fileName);
        void encodeChar(string s);
        void decode(string fileName);
        void list();
};
