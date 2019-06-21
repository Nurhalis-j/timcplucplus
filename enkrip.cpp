#include<iostream>

using namespace std;

int main()

{

  char str_message[500], ch;

  int j, key;

  cout << "Enter a message to encrypt: ";

  cin.getline(str_message, 100);

  cout << "Enter key: ";

  cin >> key;

  for(j = 0; str_message[j] != '\0'; ++j){

    ch = str_message[j];

    if(ch >= 'a' && ch <= 'z'){

      ch = ch + key;

      if(ch > 'z'){

        ch = ch - 'z' + 'a' - 1;

      }

      str_message[j] = ch;

    }

    else if(ch >= 'A' && ch <= 'Z'){

      ch = ch + key;

      if(ch > 'Z'){

        ch = ch - 'Z' + 'A' - 1;

      }

      str_message[j] = ch;

    }

  }

  cout << "Encrypted message: " << str_message;

  return 0;

}