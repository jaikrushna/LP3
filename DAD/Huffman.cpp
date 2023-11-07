#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Compare function for the priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

// Build the Huffman Tree and return the root
HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new HuffmanNode(data[i], freq[i]));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    return minHeap.top();
}

// Print Huffman codes from the root
void printHuffmanCodes(HuffmanNode* root, string str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << "\n";
    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(data) / sizeof(data[0]);

    HuffmanNode* root = buildHuffmanTree(data, freq, size);
    printHuffmanCodes(root, "");

    return 0;
}
