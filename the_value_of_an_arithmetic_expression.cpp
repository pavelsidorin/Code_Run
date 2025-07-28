#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
#include <set>

int Value(std::string& s, size_t& i) {
  int value = 0;
  while (i < s.length() && std::isdigit(s[i])) {
    value = value * 10 + (s[i] - '0');
    ++i;
  }
  --i;
  return value;
}

int OperationPriority(std::string& s, int i) {
  if (s[i] == '+' || s[i] == '-') {
    return 1;
  } else if (s[i] == '*') {
    return 2;
  } else {
    return 0;
  }
}

int OperationPriority(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*') {
    return 2;
  } else {
    return 0;
  }
}

bool ApplyOperation(std::stack<int>& values, char op) {
  if (values.size() < 2) {
    return false;
  }
  int a = values.top();
  values.pop();
  int b = values.top();
  values.pop();
  if (op == '-') {
    values.push(b - a);
    return true;
  }
  if (op == '+') {
    values.push(a + b);
    return true;
  }
  if (op == '*') {
    values.push(a * b);
    return true;
  }
  return false;
}

bool ApplyAction(std::stack<int>& values, std::stack<char>& operations) {
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
  std::stack<int> values;
  std::stack<char> operations;
  int priority = 0;
  std::getline(std::cin, s);
  operations.push('(');
  bool b = false;
  for (size_t i = 0; i < s.length(); ++i) {
    if (s[i] == ' ') {
      continue;
    } else if (std::isdigit(s[i]) && !b) {
      values.push(Value(s, i));
      b = true;
    } else if (s[i] == '(') {
      ++priority;
      operations.push('(');
    } else if (s[i] == ')') {
      --priority;
      if (priority < 0) {
        std::cout << "WRONG";
        return 0;
      }
      if (!ApplyAction(values, operations)) {
        std::cout << "WRONG";
        return 0;
      }
    } else if (OperationPriority(s, i)) {
      while (!operations.empty() && operations.top() != '(' && OperationPriority(s, i) <= OperationPriority(operations.top())) {
        if (!ApplyOperation(values, operations.top())) {
          std::cout << "WRONG";
          return 0;
        }
        operations.pop();
      }
      operations.push(s[i]);
      b = false;
    } else {
      std::cout << "WRONG";
      return 0;
    }
  }
  ApplyAction(values, operations);
  if (values.size() != 1 || !operations.empty()) {
    std::cout << "WRONG";
    return 0;
  }
  std::cout << values.top();
}
