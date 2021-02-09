# huffman_coding
Huffman encoder/decoder
## What's Huffman Encoding?
Huffman algorithm is a powerful algorithm that is used for compressing textual data to make file occupy  less  space  with  respect  to  number  of  bytes.   Intuitively,  the  algorithm  works  based  on  a frequency sorted binary tree to encode the input. \
Normally,  textual  data  is  stored  using  ASCII  encoding  with  8  bits  per  character.   8  bits  fixed encoding is not an efficient way to store large data, thus Huffman encoding uses binary encoding with variable sizes.  The advantage of this idea is that characters with high frequency is given short encoding while ones with low frequency is given high encoding. 
## Implementation
I implemented Huffman encoding, decoding, serialise for transferphases. In order to perform Huffman encoding following steps were used:
1.  Count the number of occurrences of each character.
2.  Build a binary tree where each node represents a character and its count of occurrences in the given file.
3.  Build the encoding map by traversing the produced tree to find the binary encoding of each character.
4.  Encode given file and output the binary version to destined file.
## Requirements
C++11
## Usage
First compile and create the executable file using: 
```
make 
```
Then a .txt file needs to be encoded using: 
```
./main -i <input_file> -encode 
```
After we've encoded, a tree.txt file will be created, following commands will be available for use: 
```
./main -i <input_file> -decode          // Decodes given encoded file 
./main -l                               // Visualizes the huffman tree 
./main -s <char>                        // Gives encoding for a specific character 
```
