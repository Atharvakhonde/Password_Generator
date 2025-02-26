#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int passLen() {
	int n = 0;
	cout << "Enter the length of the password (between 8-64): ";
	cin >> n;

	return n;
}

string passwordGenerator(int len, bool *gen) {
	
	string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$%&*?!";
	string password{};

	srand(static_cast<unsigned int> (time(0)));
	for (int i = 0; i < len; i++) {
		int randomNum = rand() % characters.size();
		password += characters[randomNum];
	}

	*gen = false;
	return password;
}

int main() {
	
	int n = passLen();
	string password;

	bool generate = true;
	bool *gen = &generate;

	do {
		if (n < 8 || n > 64) {
			cout << "Invalid input - can't generate password of the desired length. Please, try again." << endl << "\n";
			int n = passLen();
			password = passwordGenerator(n , &generate);
			cout << "\n" << password << endl;
		}
		else {
			password = passwordGenerator(n, &generate);
			cout << "\n" << password << endl;
		}
	} while (generate);

}