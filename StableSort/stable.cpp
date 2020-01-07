#include<iostream>
using namespace std;

struct Card { char suit, value; };

void bubble(struct Card array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = size - 1; j >= i; j--) {
      if (array[j].value < array[j-1].value) {
        Card tmp = array[j]; array[j] = array[j-1]; array[j-1] = tmp;
      }
    }
  }
}

void selection(struct Card array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minj = i;
    for (int j = i; j < size; j++) {
      if (array[j].value < array[minj].value) minj = j;
    }
    Card tmp = array[i]; array[i] = array[minj]; array[minj] = tmp;
  }
}

void print(struct Card array[], int size) {
  for (int i = 0; i < size; i++) {
    if (i > 0) cout << " ";
    cout << array[i].suit << array[i].value;
  }
  cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int size) {
  for (int i = 0; i < size; i++) {
    if (C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

int main() {
  Card C1[100], C2[100];
  int size;
  char ch;

  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < size; i++) {
    C2[i] = C1[i];
  }

  bubble(C1, size);
  selection(C2, size);

  print(C1, size);
  cout << "STABLE" << endl;
  print(C2, size);
  if ( isStable(C1, C2, size) ) {
    cout << "STABLE" << endl;
  } else {
    cout << "Not Stable" << endl;
  }

  return 0;
}

