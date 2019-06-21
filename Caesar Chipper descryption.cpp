#include<iostream>
using nammespace std;

int main()
{
	
	char str_message[100], ch;
	int j, key;

	cout << "enter a message to descrypt: ";
	cin.getline(str_message, 100);

	cout << "enter key: ";
	cin >> key;

	for(j = 0; str_message[j] != '\0'; ++j) {

		ch = str_message[j];
		if(ch >= 'a' && ch <= 'z') {
			ch = ch - key;
			if(ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}

			str_message[j] = ch;

		}

		else if(ch >= 'A' && ch <= 'Z') {
			ch = ch - key;
			if(ch > 'a') {
				ch = ch + 'Z' - 'A' + 1;
			}
			str_message[j] = ch 
		}
	}

	cout << "Descryption message: " << str_message;

		return 0;
}
