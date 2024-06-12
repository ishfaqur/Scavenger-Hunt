//Ishfaqur rahman
//CS162


#include "scavenger_hunt.h"
#include <iostream>
using namespace std;

int main() {
	Node* head = nullptr;
	char choice;

	do {
		cout << "Menu:" << endl;
		cout << "1. Add clue/challenge" << endl;
		cout << "2. Display clues" << endl;
		cout << "3. Play scavenger hunt" << endl;
		cout << "4. Quit" << ::endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(); // Ignore newline character from previous input

		switch (choice) {
			case '1':
				buildScavengerHunt(head);
				break;
			case '2':
				displayClues(head);
				break;
			case '3':
				traverseScavengerHunt(head);
				break;
			case '4':
				cout << "Exitting the program!!" << endl;
				break;
			default:
				cout << "Invalid choice. Please enter again." << endl;
		}
	} while (choice != '4');

	destroyScavengerHunt(head);

return 0;
}

