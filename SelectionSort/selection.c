#include<stdio.h>

int selectionSort(int array[], int size) {
    int unSortedStart, count, tmp, minimumPointer, sw;
    sw = 0;

    // 先頭から配列の最後の要素までたどる
    // 一つずつソート済み部分が増えていく
    for (unSortedStart = 0; unSortedStart < size - 1; unSortedStart++) {
        // 一旦minimumを初期化
        minimumPointer = unSortedStart;
        // 未ソート部分の先頭から最後の要素までをたどる
        // なぜsize-1でない??
        for (count = unSortedStart; count < size; count++ ) {
            // もし現在の最小値よりも小さい要素が配列にいたら
            // その要素の位置を最小値ポインタとする
            if (array[count] < array[minimumPointer]) {
                minimumPointer = count;
            }
        }
        // 未ソート部分の先頭と最小値の要素を入れ替える 
        tmp = array[unSortedStart];
        array[unSortedStart] = array[minimumPointer];
        array[minimumPointer] = tmp;
        if (unSortedStart != minimumPointer) sw++;

    }
    return sw;
}

int main() {
    int A[100], size, i, sw;

    scanf("%d", &size);
    for (i=0; i<size; i++) scanf("%d", &A[i]);

    sw = selectionSort(A, size);

    for (i=0; i < size; i++){
        if (i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d", sw);

    return 0;
}
                
