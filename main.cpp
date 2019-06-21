#include <iostream>
using namespace std;

int main()
{
    char str_message[500], selection, ch, q;
    int j, key;
menu:
    cout << "  Menu Enkripsi dan Deskripsi\n";
    cout << "  ====================================\n";
    cout << "  1.  Enkripsi\n";
    cout << "  2.  Deskripsi\n";
    cout << "\n";
    cout << "  3.  Exit\n";
    cout << "  ====================================\n";
    cout << "  Masukkan Pilihan: ";
    cin >> selection;

    switch (selection)
    {
    case '1':
        cout << "====================================\n";
        cout << "Enter a message to encrypt: ";
        cin >> str_message;
        cout << "Enter key: ";
        cin >> key;
        for (j = 0; str_message[j] != '\0'; ++j)
        {
            ch = str_message[j];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch + key;
                if (ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                str_message[j] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + key;
                if (ch > 'Z')
                {
                    ch = ch - 'Z' + 'A' - 1;
                }
                str_message[j] = ch;
            }
        }
        cout << "Encrypted message: " << str_message << "\n";

        std::cout << "Apakah anda ingin mencoba lagi? [Y/N] : ";
        std::cin >> q;
        if (q == 'Y' || q == 'y')
        {
            goto menu;
        }
        else if (q == 'N' || q == 'n')
        {
            goto finish;
        }
        else
        {
            goto finish;
        }
        cin.get();
        break;

    case '2':
        cout << "====================================\n";
        cout << "Enter a message to decrypt: ";
        cin >> str_message;
        cout << "Enter key: ";
        cin >> key;
        for (j = 0; str_message[j] != '\0'; ++j)
        {
            ch = str_message[j];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - key;
                if (ch < 'a')
                {
                    ch = ch + 'z' - 'a' + 1;
                }
                str_message[j] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - key;
                if (ch > 'a')
                {
                    ch = ch + 'Z' - 'A' + 1;
                }
                str_message[j] = ch;
            }
        }
        cout << "Decrypted message: " << str_message << "\n";

        std::cout << "Apakah anda ingin mencoba lagi? [Y/N] : ";
        std::cin >> q;
        if (q == 'Y' || q == 'y')
        {
            goto menu;
        }
        else if (q == 'N' || q == 'n')
        {
            goto finish;
        }
        else
        {
            goto finish;
        }
        cin.get();
        break;

    case '3':
        cout << "====================================\n";
        cout << "Goodbye\n";
        cout << "====================================\n";
        break;

    default:
        cout << endl;
        cout << "\nMasukkan pilihan yang benar\n"
             << endl;
        goto menu;
    }
finish:
    cout << "\nProgram selesai....\n";
    return 0;
}