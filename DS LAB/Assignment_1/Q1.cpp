// Q (1) Develop a Menu driven program to demonstrate the following operations of Arrays
// a. CREATE  : user enters elements .
// b. DISPLAY  : prints array contents .
// c. INSERT : insert element at a given position .
// d. DELETE : delete element from a given position .
// e. LINEAR SEARCH : search for an element .
// f. EXIT : quit program .

#include <iostream>
using namespace std;

int arr[10], n = 0;

void create() {
  cout << "Enter number of elements:";
  cin >> n;
  cout << "Enter elements:";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void display() {
  if (n == 0)
    cout << "Array is empty" << endl;
  else {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
}

void insert() {
  int pos, val;
  cout << "Enter position and value: ";
  cin >> pos >> val;
  if (pos < 0 || pos > n) {
    cout << "Invalid position\n";
    return;
  }
  for (int i = n; i > pos; i--)
    arr[i] = arr[i - 1];
  arr[pos] = val;
  n++;
}

void del() {
  int pos;
  cout << "Enter position to delete: ";
  cin >> pos;
  if (pos < 0 || pos >= n) {
    cout << "Invalid position\n";
    return;
  }
  for (int i = pos; i < n - 1; i++)
    arr[i] = arr[i + 1];
  n--;
}

void linearSearch() {
  int key, found = 0;
  cout << "Enter value to search: ";
  cin >> key;
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      cout << "Found at position " << i << endl;
      found = 1;
      break;
    }
  }
  if (!found)
    cout << "Not found\n";
}

int main() {
  int choice;
  do {
    cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        create();
        break;
      case 2:
        display();
        break;
      case 3:
        insert();
        break;
      case 4:
        del();
        break;
      case 5:
        linearSearch();
        break;
      case 6:
        cout << "Exiting...\n";
        break;
      default:
        cout << "Invalid choice\n";
    }
  } while (choice != 6);
  return 0;
}