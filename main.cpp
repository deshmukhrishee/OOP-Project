#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  fstream myFile;

  string secret_message;

  cout << "Enter your secret message:\n";
  getline (cin, secret_message);

  char secret_message_array[secret_message.length()];

  for (int i = 0; i < secret_message.length(); i++) {
    secret_message_array[i] = secret_message[i];
  }

  myFile.open("My Diary.txt", ios::out);
  if (myFile.is_open()) {
    for (int i = 0; i < secret_message.length(); i++) {
      myFile << (int)secret_message_array[i];
    }
    myFile.close();
  }

  system("cls");

  cout << "Your deciphered notes:\n";

  myFile.open("My Diary.txt", ios::in);
  if (myFile.is_open())
  {
      string line;
      while(getline(myFile, line)){
          int num = 0;
          for(int i = 0; i < line.length(); i++){
              num = num * 10 + (line[i] - '0');
              if(num>=32 && num<=122){
                  char ch = (char)num;
                  cout << ch;
                  num = 0;
              }
          }
      }
  }
  myFile.close();

  return 0;
}