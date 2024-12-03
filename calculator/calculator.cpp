//16-4*(6-3+(2+5))/(2-1) = -24

#include <iostream>
#include <stack>
#include <cstring>

double operation (double tema, double temb, char op) {
	switch (op) {
		case '+': return tema + temb;
		case '-': return tema - temb;
		case '*': return tema * temb;
		case '/': return tema / temb;
	}
	return 0;
}

int priority (char op) {
	switch (op) {
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return 0;
}

int main() {
	std::cout << "Enter an expression: ";
	char exp[255];
	std::stack <double> nums;
	std::stack <char> ops;
	std::cin >> exp;
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] >= '0' && exp[i] <= '9') {
			double num = 0;
			bool decim = 0;
			double posit = 1.0;
			while ((exp[i] >= '0' && exp[i] <= '9') && i < strlen(exp) || exp[i] == '.') {
				if (exp[i] == '.') {
					decim = 1;
				}
				else {
					if (decim) {
						num = num + (exp[i] - '0')/(posit *= 10);
					}
					else {
						num = num * 10 + exp[i] - '0';
					}
				}
				i++;
			}
			nums.push(num);
			i--;
		}
		else if (exp[i] == '(') {
			ops.push(exp[i]);
		}
		else if (exp[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				double temb = nums.top(); nums.pop();
				double tema = nums.top(); nums.pop();
				char op = ops.top(); ops.pop();
				nums.push(operation(tema, temb, op));
			}
			ops.pop();
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			while (!ops.empty() && priority(ops.top()) >= priority(exp[i])) {
				double temb = nums.top(); nums.pop();
				double tema = nums.top(); nums.pop();
				char op = ops.top(); ops.pop();
				nums.push(operation(tema, temb, op));
			}
			ops.push(exp[i]);
		}
		else {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	while (!ops.empty()) {
		double temb = nums.top(); nums.pop();
		double tema = nums.top(); nums.pop();
		char op = ops.top(); ops.pop();
		nums.push(operation(tema, temb, op));
	}
	std::cout << nums.top() << std::endl;
}
