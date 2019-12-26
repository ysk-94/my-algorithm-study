#include<stdio.h>

// 配列の要素を順番に出力
void trace(int array[], int size)
{
  int i;
  for (i=0; i<size; i++)
  {
    // 最初は空白を入れないのでスキップ
    if (i>0) printf(" ");
    printf("%d", array[i]);
  }
  // 改行
  printf("\n");
}

// 挿入ソート
void insertionSort(int array[], int size) {
  int prev, current, tmp;

  for (current = 1; current < size; current++)
  {
    // 未ソート部分の先頭要素を退避
    tmp = array[current];
    // prev(ソート済み部分列からvを挿入する位置を探すための変数)の値を代入
    prev = current - 1;

    /**
     * 探索変数が配列の範囲内である　かつ
     * 探索対象の変数が退避した変数よりも大きい限り回す
     */
    while ( prev >= 0 && array[prev] > tmp)
    {
      // 一つ後ろに退避させる
      array[prev+1] = array[prev];
      // 探索対象を遡る
      prev--;
    }

    // 空いた場所に退避した未ソート部分の先頭を挿入
    array[prev+1] = tmp;

    // ログ
    trace(array, size);
  }
}

int main()
{
  int size, current, prev;
  int array[100];

  scanf("%d", &size);
  for (current=0; current<size; current++)
  {
    scanf("%d", &array[current]);
  }

  trace(array, size);
  insertionSort(array, size);

  return 0;
}
