//Program-3: WAP to convert infix to prefix using stack.
#include <iostream>
#include <string>
#define MAX 15
using namespace std;
template <class T>
class Stack {
T data[MAX];
int top;
public:
Stack() : top(-1) {}
void push(T value) {
if (top == MAX - 1) {
cout << "Stack overflow" << endl;

} else {
data[++top] = value;
}
}
T pop() {
if (top == -1) {
cout << "Stack underflow" << endl;
return 0;
} else {
return data[top--];
}
}
T peek() {
if (top == -1) {
cout << "Stack underflow" << endl;
return 0;
} else {
return data[top];
}
}
};
// Precision check
int precision_check(char x) {
if (x == '^') {
return 3;
} else if (x == '*' || x == '/') {
return 2;
} else if (x == '+' || x == '-') {
return 1;
}
return -1;
}
// Function to convert infix to postfix
string infix_to_postfix(string expression) {
Stack<char> s;
string postfix;
s.push('(');
expression += ')';
for (auto x : expression) {

if (x == '(') {
s.push(x);
} else if (x == ')') {
while (s.peek() != '(') {
postfix += s.pop();
}
s.pop();
} else if (x == '*' || x == '+' || x == '-' || x == '^' || x == '/') {
if(precision_check(x) == precision_check(s.peek())){
s.push(x);
}
else{
while (precision_check(x) < precision_check(s.peek()) && s.peek() != '(') {
postfix += s.pop();
}
s.push(x);
}
} else {
postfix += x; // Append operand to postfix string
}
}
return postfix;
}
// Function to convert infix to prefix
string infix_to_prefix(string expression) {
string reversed_expr, prefix;
// Reverse the input string and swap brackets
for (int i = expression.length() - 1; i >= 0; --i) {
if (expression[i] == ')') {
reversed_expr += '(';
} else if (expression[i] == '(') {
reversed_expr += ')';
} else {
reversed_expr += expression[i];
}
}
// Convert the reversed expression to postfix
string postfix = infix_to_postfix(reversed_expr);
// Reverse the postfix expression to get prefix

for (int i = postfix.length() - 1; i >= 0; --i) {
prefix += postfix[i];
}
return prefix;
}
int main() {
string expression;
cout << "Enter your infix expression [Put '^' as an exponent]: ";
getline(cin, expression);
if (expression.empty()) {
cout << "Empty expression entered!" << endl;
return 1;
}
string prefix_expression = infix_to_prefix(expression);
cout << "Prefix Expression is: " << prefix_expression << endl;
return 0;
}
