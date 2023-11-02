#pragma once
#include"Stack.h"


class Calc
{
	char* expression;


	bool isOperation(char op)
	{
		switch (op)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
		default:
			return false;
		}
	}

	int getPriority(char op)
	{
		switch (op)
		{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^':           return 3;
		}
	}

	int calc(int a, int b, char op)
	{
		switch (op)
		{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '^': return pow(b,a);
		}
	}

public:
	Calc(const char* exp)
	{
		expression = new char[strlen(exp) + 1];
		strcpy_s(expression, strlen(exp) + 1, exp);
	}

	int getResult()
	{
		Stack<int> number;
		Stack<char> oper;

		int i = 0;
		while (expression[i] != '\0')
		{
			if (isdigit(expression[i]))
			{
				number.push(expression[i] - 48);
			}

			if (isOperation(expression[i]))
			{
				if (oper.isEmpty())
				{
					oper.push(expression[i]);
				}
				else
				{
					if (getPriority(expression[i]) > getPriority(oper.peek()))
					{
						oper.push(expression[i]);
					}
					else
					{
						int a = number.peek();
						number.pop();
						int b = number.peek();
						number.pop();
						char op = oper.peek();
						oper.pop();
						number.push(calc(a, b, op));
						oper.push(expression[i]);
					}
				}
			}
			
			i++;
		}

		while (!oper.isEmpty())
		{
			int a = number.peek();
			number.pop();
			int b = number.peek();
			number.pop();
			char op = oper.peek();
			oper.pop();
			number.push(calc(a, b, op));
		}

		return number.peek();
	}
};

