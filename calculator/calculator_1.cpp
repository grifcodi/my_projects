//16-4*(6-3^2+(2!+5))/(2-1) = 0
//16 4 6 3 2 ^ - 2 ! 5 + + * 2 1 - / -
//16 4 6 3 2 2 5 2 1
//- * ( - ^ + ( ! + ) ) / ( - )

#include <iostream>

enum kind {
	number,
	binary_op,
	factorial,
	parenthesis
};

struct token {
	kind k;
	char op;
	double num;
	void print() {
		if (k == number) {
			std::cout << " Kind: " << k << " Value: " << num << '\n';
		}
		else {
			std::cout << " Kind: " << k << " Value: " << op << '\n';
		}
	}
	void print_2() {
		if (k == number) {
			std::cout << " " << num;
		}
		else {
			std::cout << " " << op;
		}
	}
};

double pow (double base, int exp) {
	double result = 1;
	for (int i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

double factr (int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
	return result;
}

bool is_digit (char ch) {
	return ch >= '0' && ch <= '9';
}

bool is_operator (char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

double stod (const char* exp, int& size) {
        double result = 0;
        bool decim = 0;
        double decim_fact = 1;
	while (exp[size] != '\0' && is_digit(exp[size]) || exp[size] == '.') {
		if (exp[size] == '.') {
			decim = 1;
		}
		else {
			if (decim) {
				result += (exp[size] - '0')/(decim_fact *= 10);
			}
			else {
				result = result * 10 + (exp[size] - '0');
			}
		}
		size++;
	}
	size--;
	return result;
}

void tokenize (const char* exp, token* stack, int& token_size) {
	int size = 0;
	while (exp[size] != '\0') {
		if (is_digit(exp[size])) {
			stack[token_size].k = number;
			stack[token_size].num = stod(exp, size);
		}
		else if ((exp[size] == '-') && (size == 0 || is_operator(exp[size-1]) || exp[size-1] == '(')) {
			size++;
			stack[token_size].k = number;
			stack[token_size].num = -1*stod(exp,size);
		}
		else if (is_operator(exp[size])) {
			stack[token_size].k = binary_op;
			stack[token_size].op = exp[size];
		}
		else if (exp[size] == '!') {
			stack[token_size].k = factorial;
			stack[token_size].op = exp[size];
		}
		else if (exp[size] == '(' || exp[size] == ')') {
			stack[token_size].k = parenthesis;
			stack[token_size].op = exp[size];
		}
		else {
			throw std::runtime_error("Invalid input.");
			break;
		}
		token_size++;
		size++;
	}
}

int priority (char op) {
	switch (op) {
		case '+': return 2;
		case '-': return 2;
		case '*': return 3;
		case '/': return 3;
		case '^': return 4;
		case '!': return 5;
		case '(': return 0;
		case ')': return 1;
	}
	return 0;
}

void convert_to_rpn(token* stack, int& token_size) {
	token rpn_stack[512];
	int rpn_top = 0;
	token ops_stack[512];
	int ops_top = 0;
	for (int i = 0; i < token_size; i++) {
		if (stack[i].k == number) {
			rpn_stack[rpn_top++] = stack[i];
		}
		else if (stack[i].k == parenthesis) {
			if (stack[i].op == '(') {
				ops_stack[ops_top++] = stack[i];
			}
			else if (stack[i].op == ')') {
				while (ops_top > 0 && ops_stack[ops_top-1].op != '(') {
					rpn_stack[rpn_top++] = ops_stack[--ops_top];
				}
				ops_top--;
			}
		}
		else if (stack[i].k == binary_op || stack[i].k == factorial) {
			while (ops_top > 0 && priority(ops_stack[ops_top-1].op) >= priority(stack[i].op)) {
				rpn_stack[rpn_top++] = ops_stack[--ops_top];
			}
			ops_stack[ops_top++] = stack[i];
		}
	}
	while (ops_top > 0) {
		rpn_stack[rpn_top++] = ops_stack[--ops_top];
	}
	for (int i = 0; i < rpn_top; i++) {
		stack[i] = rpn_stack[i];
	}
	token_size = rpn_top;
}

double evaluate_rpn (token* stack, int& token_size) {
	double eval_stack[512];
	int eval_top = 0;

	for (int i = 0; i < token_size; i++) {
		if (stack[i].k == number) {
			eval_stack[eval_top++] = stack[i].num;
		}
		else if (stack[i].k == binary_op) {
			double b = eval_stack[--eval_top];
			double a = eval_stack[--eval_top];
			double result = 0;
			switch (stack[i].op) {
				case '+': result = a + b; break;
				case '-': result = a - b; break;
				case '*': result = a * b; break;
				case '/': result = a / b; break;
				case '^': result = pow(a, b); break;
			}
			eval_stack[eval_top++] = result;
		}
		else if (stack[i].k == factorial) {
			int a = eval_stack[--eval_top];
			eval_stack[eval_top++] = factr(a);
		}
	}
	return eval_stack[0];
}
			
			

double evaluate (const char* exp) {
	token stack[512];
	int token_size = 0;
	
	tokenize(exp, stack, token_size);
	
	convert_to_rpn(stack, token_size);

	double result = evaluate_rpn(stack, token_size);

	return result;
}

int main() {
	while(1) {
		try {
			char exp[512];
			std::cout << "Enter an expression: ";
			std::cin >> exp;
			double result = evaluate(exp);
			std::cout << "Result: " << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
