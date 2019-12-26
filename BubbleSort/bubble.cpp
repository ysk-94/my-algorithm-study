#include<iostream>
using namespace std;

// バブルソート
int bubbleSort(int array[], int size) {
  // 並び替え回数カウント用
  int times = 0;
  bool flag = 1;
  // 順番が逆になっている要素がなくなるまで繰り返す
  // array[i]までがソート済み配列になる
  for ( int i = 0; flag; i++ ) {
    flag = 0;
    // 最後の要素から、未ソート部分すべての要素
    // を探索する
    for ( int j = size - 1; j >= i; j-- ) {
      // 順番が逆になっていたら入れ替える
      if ( array[j] < array[j-1]) {
        swap(array[j], array[j-1]);
        flag = 1;
        times++;
      }
    }
  }
  return times;
}

int main() {
  int array[100], size, times;

  cin >> size;

  for (int i=0; i<size; i++) cin >> array[i];

  times = bubbleSort(array, size);

  for (int i=0; i<size; i++){
    if (i) cout << " ";
    cout << array[i];
  }

  cout << endl;
  cout << times << endl;

  return 0;
}

