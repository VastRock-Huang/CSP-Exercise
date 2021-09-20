/*
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

struct Node {
	int v;
	Node(int val) :v(val) {}
};

int main() {
	unordered_map<int, Node*> hash;
	hash.emplace(1,new Node(1));
	hash.emplace(2, new Node(2));
	printf("%d\n", hash.find(2)->second->v);
	Node* dest = hash.find(2)->second;
	delete dest;
	dest = new Node(3);
	printf("%d\n", hash.find(2)->second->v);
	return 0;
}
/**/