#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct Clue {
	char* text;
	char* answer;
	int difficulty;
	// Add one more member here
};

struct Node {
	Clue data;
	Node* next;
};

void buildScavengerHunt(Node*& head);
void displayClues(Node* head);
void traverseScavengerHunt(Node* head);
void destroyScavengerHunt(Node*& head);
void insertSorted(Node*& head, Clue clue);


