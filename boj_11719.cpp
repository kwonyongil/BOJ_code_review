#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	while (!getline(cin, str).eof()) {
		cout << str << endl;
	}
	return 0;
}