#include <stdio.h>

void add(double num1, double num2) {
  double result = num1 + num2;
  printf("%lf", result);
}

void subtract(double num1, double num2){
  double result = num1 - num2;
  printf("%lf", result);
}

void multiply(double num1, double num2){
  double result = num1 * num2;
  printf("%lf", result);
}

void divide(double num1, double num2){
  double result = num1 / num2;
  printf("%lf", result);
}

void calc(){
  double num1, num2;
  char op;

  printf("1st number: ");
  scanf("%lf", &num1);

  printf("2nd number: ");
  scanf("%lf", &num2);

  printf("Operation: ");
  scanf(" %c", &op);  // Use %c to read a character, and add a space before %c to consume any whitespace characters.

  if (op == '+'){
    add(num1, num2);
  } else if (op == '-'){
    subtract(num1, num2);
  } else if (op == '*'){
    multiply(num1, num2);
  } else if (op == '/'){
    divide(num1, num2);
  }
}
