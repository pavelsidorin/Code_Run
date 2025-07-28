#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <string>

int OperationPriority(std::string& s, int i) {
  if (s[i] == '!') {
    return 3;
  }
  if (s[i] == '&') {
    return 2;
  }
  return 1;
}

int OperationPriority(char op) {
  if (op == '!') {
    return 3;
  }
  if (op == '&') {
    return 2;
  }
  return 1;
}

bool ApplyOperation(std::stack<bool>& values, char op) {
  if (values.size() < 1) {
    return false;
  }
  bool a = values.top();
  values.pop();
  if (op == '!') {
    values.push(!a);
    return true;
  }
  if (values.size() < 1) {
    return false;
  }
  bool b = values.top();
  values.pop();
  if (op == '&') {
    values.push(a && b);
    return true;
  }
  if (op == '|') {
    values.push(a || b);
    return true;
  }
  if (op == '^') {
    values.push(b ^ a);
    return true;
  }
  return false;
}

bool ApplyAction(std::stack<bool>& values, std::stack<char>& operations) {
  while (!operations.empty() && operations.top() != '(') {
    char op = operations.top();
    operations.pop();
    if (!ApplyOperation(values, op)) {
      return false;
    }
  }
  if (!operations.empty() && operations.top() == '(') {
    operations.pop();
  }
  return true;
}

int main() {
  std::string s;
  std::stack<bool> values;
  std::stack<char> operations;
  std::getline(std::cin, s);
  operations.push('(');
  for (size_t i = 0; i < s.length(); ++i) {
    if (s[i] == ' ') {
      continue;
    } else if ((s[i] == '0' || s[i] == '1')) {
      values.push(s[i] - '0');
    } else if (s[i] == '(') {
      operations.push('(');
    } else if (s[i] == ')') {
      ApplyAction(values, operations);
    } else if (s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '^') {
      while (!operations.empty() && operations.top() != '(' && OperationPriority(s, i) <= OperationPriority(operations.top())) {
        ApplyOperation(values, operations.top());
        operations.pop();
      }
      operations.push(s[i]);
    }
  }
  ApplyAction(values, operations);
  std::cout << values.top();
}
