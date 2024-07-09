#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function for encrypting text using Caesar cipher
string encryptCaesar(string text, int shift) {
    string result = "";
    for (char character : text) {
        if (isalpha(character)) {
            char base = isupper(character) ? 'A' : 'a';
            char shiftedChar = base + (character - base + shift + 26) % 26;  // Ensure the character stays within A-Z or a-z
            if ((isupper(character) && shiftedChar > 'Z') || (islower(character) && shiftedChar > 'z')) {
                shiftedChar -= 26;  // Wrap around if necessary
            }
            result += shiftedChar;
        }
        else {
            result += character;  // Non-alphabet characters remain unchanged
        }
    }
    return result;
}

// Function for decrypting text using Caesar cipher
string decryptCaesar(string encryptedText, int shift) {
    string result = "";
    for (char character : encryptedText) {
        if (isalpha(character)) {
            char base = isupper(character) ? 'A' : 'a';
            char shiftedChar = base + (character - base - shift + 26) % 26;  // Decrypt by shifting in the opposite direction
            if ((isupper(character) && shiftedChar < 'A') || (islower(character) && shiftedChar < 'a')) {
                shiftedChar += 26;  // Wrap around if necessary
            }
            result += shiftedChar;
        }
        else {
            result += character;  // Non-alphabet characters remain unchanged
        }
    }
    return result;
}

int main() {
    system("chcp 65001");  // Set the code page to UTF-8 for proper character handling

    string input, encryptedText;
    int shift;

    cout << "Enter the text to encrypt: ";
    getline(cin, input);

    cout << "Enter the shift: ";
    cin >> shift;

    encryptedText = encryptCaesar(input, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decryptCaesar(encryptedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
