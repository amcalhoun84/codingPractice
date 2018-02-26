// #include <bits/stdc++.h> -- does not have the necessary requisites for a huffman encoder
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

#define DEBUG 1

using namespace std;

struct Node
{
	char ch;
	int freq;
	Node *left, *right;	
};

Node* getNode(char ch, int freq, Node *left, Node *right)
{
	Node* node = new Node();
	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;

}

struct comp
{
	bool operator()(Node* l, Node* r)	
	{
		return l->freq > r->freq;
	}
};

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
	if(root == nullptr) return;

	if(!root->left && !root->right) { 
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);

}

// traversal

void decode(Node* root, int &index, string str)
{
	if(root == nullptr) return;

	if(!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if(str[index] == '0') decode(root->left, index, str);
	else decode(root->right, index, str);

}

void buildHuffmanTree(string text)
{
	unordered_map<char, int> freq;
	for(char ch : text) { freq[ch]++; }

	priority_queue<Node*, vector<Node*>, comp> pq;

	for(auto pair : freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}


	while(pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));

	}
	
	Node *root = pq.top();

	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are: \n\n";

	for (auto pair: huffmanCode) { 
		cout << pair.first << " " << pair.second << "\n\n";
	}

	cout << "Original String was: \n" << text << "\n";

	string str = "";
	for (char ch: text) { 
		str += huffmanCode[ch];
	}
	
	int index = -1;
	cout << "\nEncoded String is: " << str << "\n";
	while(index < (int)str.size() - 2)
	{
		decode(root, index, str);
	}

}

int main(int argc, char* argv[])
{
	if(DEBUG) 
	{
		cout << "Argument Count: " << argc << endl;
		cout << "Arguments Presented: " << argv[1] << endl;
	}


	if(argc > 2) 
	{
		cout << "Program for Huffman Codes is used as follows: hCConvert \"<string>\" " << endl << endl;
		exit(-1);
	}
	
	string text = "";
	
    if(argv[1]) text = argv[1];
    else text = "Huffman coding is a data compression algorithm";

	buildHuffmanTree(text);

}


