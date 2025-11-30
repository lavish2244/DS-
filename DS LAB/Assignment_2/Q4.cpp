
// Q4) String Related Programs
// (a) Write a program to concatenate one string to another string.
// (b) Write a program to reverse a string.
// (c) Write a program to delete all the vowels from the string.
// (d) Write a program to sort the strings in alphabetical order.
// (e) Write a program to convert a character from uppercase to lowercase.

#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

// a.
void concatenate(char s1[], char s2[]) {
  int n1 = strlen(s1), n2 = strlen(s2);
  for (int i = 0; i <= n2; i++)
    s1[n1 + i] = s2[i];
  cout << "Concatenated: " << s1 << endl;
}

// b.
void reverseString(char s[]) {
  int n = strlen(s);
  for (int i = 0; i < n / 2; i++) {
    char temp = s[i];
    s[i] = s[n - 1 - i];
    s[n - 1 - i] = temp;
  }
  cout << "Reversed: " << s << endl;
}

// c.
void deleteVowels(char s[]) {
  char result[100];
  int k = 0;
  for (int i = 0; s[i]; i++) {
    char c = tolower(s[i]);
    if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
      result[k++] = s[i];
  }
  result[k] = '\0';
  cout << "Without vowels: " << result << endl;
}

// d.
void sortStrings(char arr[][50], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(arr[i], arr[j]) > 0) {
        char temp[50];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], temp);
      }
    }
  }
  cout << "Sorted strings: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// e.
void toLowercase(char& c) {
  if (c >= 'A' && c <= 'Z')
    c = c + 32;
}

int main() {
  char s1[100] = "Hello", s2[100] = "World";
  concatenate(s1, s2);

  char s3[100] = "Hello";
  reverseString(s3);

  char s4[100] = "beautiful";
  deleteVowels(s4);

  char arr[3][50] = {"banana", "apple", "cherry"};
  sortStrings(arr, 3);

  char c = 'A';
  toLowercase(c);
  cout << "Lowercase: " << c << endl;

  return 0;
}
