#include "scavenger_hunt.h"
using namespace std;

// Inserts a new clue at the beginning of the linked list.
void insertAtBeginning(Node*& head, Clue clue) {
	Node* newNode = new Node;
	newNode->data = clue;
	newNode->next = head;
	head = newNode;
}

// Appends a new clue at the end of the linked list.
void append(Node*& head, Clue clue) {
	Node* newNode = new Node;
	newNode->data = clue;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	} else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

// Builds the scavenger hunt game by reading input from the first player.
void buildScavengerHunt(Node*& head) {
	// Assuming input is read from standard input (keyboard)
	char text[100]; // Assuming max size of text is 100 characters
	char answer[100]; // Assuming max size of answer is 100 characters
	int difficulty;

	cout << "Enter clue text: ";
	cin.getline(text, 100);

	cout << "Enter answer: ";
	cin.getline(answer, 100);

	cout << "Enter difficulty: ";
	cin >> difficulty;

	Clue newClue;
	newClue.text = new char[strlen(text) + 1];
	strcpy(newClue.text, text);
	newClue.answer = new char[strlen(answer) + 1];
	strcpy(newClue.answer, answer);
	newClue.difficulty = difficulty;

	// For simplicity, inserting at the beginning
	insertSorted(head, newClue);
}

// Displays all the clues in the scavenger hunt game.
void displayClues(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << "Clue: " << temp->data.text << endl;
		cout << "Answer: " << temp->data.answer << endl;
		cout << "Difficulty: " << temp->data.difficulty << endl;
		temp = temp->next;
	}
}

// Allows the second player to traverse through the scavenger hunt game
void traverseScavengerHunt(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << "Current clue: " << current->data.text << endl;
		// Add code for player to answer the clue or complete the challenge
		current = current->next;
	}
}

// Destroys the scavenger hunt game, releasing all dynamically allocated memory.
void destroyScavengerHunt(Node*& head) {
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete[] temp->data.text;
		delete[] temp->data.answer;
		delete temp;
	}
	head = nullptr;
}

// Inserts a new clue into the linked list in sorted order based on difficulty.
void insertSorted(Node*& head, Clue clue) {
	Node* newNode = new Node;
	newNode->data = clue;
	newNode->next = nullptr;

	if (head == nullptr || head->data.difficulty >= clue.difficulty) {
		newNode->next = head;
		head = newNode;
	} else {
		Node* current = head;
		while (current->next != nullptr && current->next->data.difficulty < clue.difficulty) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

