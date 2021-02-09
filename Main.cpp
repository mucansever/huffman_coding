#include "Huffman.h"

int main(int argc, char** argv) {
    Huffman h;
    // determine which operation to take place
    if (strcmp(argv[1],"-i")==0) {
        if (strcmp(argv[3],"-encode")==0)
            h.encode(argv[2]);
        else if (strcmp(argv[3],"-decode")==0)
            h.decode(argv[2]);
    } else if (strcmp(argv[1],"-l")==0)
        h.list();
    else if (strcmp(argv[1],"-s")==0)
        h.encodeChar(argv[2]);
}
