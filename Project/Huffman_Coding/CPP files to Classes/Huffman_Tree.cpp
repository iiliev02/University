#include "Huffman_Tree.h"

void HuffmanTree::popFront(vector<Node*>& nodes)
{
	if (!nodes.empty())
	{
		nodes.erase(nodes.begin());
	}
}

void HuffmanTree::destructorHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	destructorHelper(node->left);
	destructorHelper(node->right);

	delete node;
}

HuffmanTree::HuffmanTree(vector<Node*> nodes)
{
	while (nodes.size() != 1)
	{
		sort(nodes.begin(), nodes.end(), [](Node* firstNode, Node* secondNode) { return firstNode->data < secondNode->data; });

		int value = nodes[0]->data + nodes[1]->data;
		Node* node = new Node{ value, '\0', nodes[0], nodes[1] };

		popFront(nodes);
		popFront(nodes);

		nodes.push_back(node);
	}

	root = nodes[0];
}

HuffmanTree::~HuffmanTree()
{
	destructorHelper(this->root);
}

const Node* HuffmanTree::getRoot() const {
	return this->root;
}