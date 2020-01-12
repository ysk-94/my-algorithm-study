#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top, S[1000];

void push(int x) {
  // Topを加算してその位置に挿入
  S[++top] = x;
}

int pop() {
  // Topを減算して
  top--;
  // Topが指していた要素を返す
  return S[top + 1];
}

int main() { 
  int a, b;
  top = 0;
  char s[100];

  while( scanf("%s", s ) != EOF ) {
    if ( s[0] == '+') {
      a = pop();
      b = pop();
      push(a + b);
    } else if ( s[0] == '-' ) {
      b = pop();
      a = pop();
      push(a - b);
    } else if ( s[0] == '*') {
      a = pop();
      b = pop();
      push(a*b);
    } else {
      push(atoi(s));
    }
  }

  printf("\n%d\n", pop());

  return 0;
}

