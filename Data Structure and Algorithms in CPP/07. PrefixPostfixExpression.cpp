#include <iostream>
#include <stack>
using namespace std;


bool is_operator(char symbol)
{
	const char operators[] = "+-*/^(){}[]";
	for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
	{
		if (symbol == operators[i])
			return true;
	}

	return false;
}

bool is_leftToRight(char symbol)
{
	switch (symbol)
	{
	case '^':
		return false;
	}

	return true;
}

int get_precedence(char operation)
{
	switch (operation)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}

	return 0;
}

int evaluate_operation(int operandA, int operandB, char operation)
{
	switch (operation)
	{
	case '+':
		return (operandA + operandB);
	case '-':
		return (operandA - operandB);
	case '*':
		return (operandA * operandB);
	case '/':
		return (operandA / operandB);
	case '^':
		return pow(operandA, operandB);
	}

	return 0;
}

/*
*
* Infix  : 2+3*4-8/2^3  = 13
* Postfix: 234*+823^/-  = 13
* Prefix : -+2*34/8^23  = 13
*
*/
int evaluate_expression(char* expstring, bool is_postfix)
{
	int result = 0;
	int postidx = 0;
	stack<int> number_stack;

	while (expstring[postidx] != 0)
	{
		char symbol = expstring[postidx++];
		if (!is_operator(symbol))
		{
			number_stack.push(symbol - '0');
			continue;
		}

		int operandB = number_stack.top();
		number_stack.pop();

		int operandA = number_stack.top();
		number_stack.pop();

		if (is_postfix)
			result = evaluate_operation(operandA, operandB, symbol);
		else
			result = evaluate_operation(operandB, operandA, symbol);

		number_stack.push(result);
	}

	return number_stack.top();
}

/*
* Sample Expressions
*
* Infix   : A-B/C*D+E
* Postfix : ABC/D*-E+
* Prefix  : +-A* /BCDE
*
* Infix   : K+L-M*N+(O^P)*W/U/V*T+Q
* Postfix : KL+MN*-OP^W*U/V/T*+Q+
* Prefix  : ++-+KL*MN*//*^OPWUVTQ
*
* Infix   : (M+((A*((((C+((D+B)*E))*I)*K)*L))+J))(2-3^4+8*6-5)/((3-2)*(2+2))^3
* Postfix : MACDB+E*+I*K*L**J++234^-86*+5-32-22+*3^/
* Prefix  : /+M+*A***+C*+DBEIKLJ-+-2^34*865^*-32+223 (which one correct???)
*
* https://raj457036.github.io/Simple-Tools/prefixAndPostfixConvertor.html
*
*/
void infix_to_postfix(char* infix, char* postfix, bool to_postfix)
{
	int inidx = 0;
	int postidx = 0;
	stack<char> opstack;

	char BRAKET_START = to_postfix ? '(' : ')';
	char BRAKET_END = to_postfix ? ')' : '(';

	while (infix[inidx] != 0)
	{
		char symbol = infix[inidx++];
		if (!is_operator(symbol))
		{
			postfix[postidx++] = symbol;
			continue;
		}

		if (symbol == BRAKET_START || opstack.empty() || opstack.top() == BRAKET_START)
		{
			opstack.push(symbol);
		}
		else if (symbol == BRAKET_END)
		{
			while (!opstack.empty())
			{
				if (opstack.top() == BRAKET_START)
				{
					opstack.pop();
					break;
				}
				postfix[postidx++] = opstack.top();
				opstack.pop();
			}
		}
		else
		{
			while (!opstack.empty())
			{
				int presedence = get_precedence(symbol) - get_precedence(opstack.top());
				if (presedence > 0)
				{
					opstack.push(symbol);
					break;
				}
				else if (presedence < 0)
				{
					postfix[postidx++] = opstack.top();
					opstack.pop();
					if (opstack.empty())
					{
						opstack.push(symbol);
						break;
					}
				}
				else //equal presedence
				{
					if (to_postfix && is_leftToRight(symbol))
					{
						postfix[postidx++] = opstack.top();
						opstack.pop();
					}
					opstack.push(symbol);
					break;
				}
			}
		}
	}

	while (!opstack.empty())
	{
		postfix[postidx++] = opstack.top();
		opstack.pop();
	}

	postfix[postidx] = 0;
}

void infix_to_prefix(char* infix, char* prefix)
{
	strrev(infix);
	infix_to_postfix(infix, prefix, false);
	strrev(prefix);
}

void PrefixPostfixUsageExample()
{
	printf("\n\n07. PrefixPostfixUsageExample: ");

	char inputExp[128] = { 0 };
	char postfixExp[128] = { 0 };
	char prefixExp[128] = { 0 };

	strcpy(inputExp, "2+3*4-8/2^3");
	//printf("\nInput Infix Expression: ");
	//int inputLength = scanf("%s", inputExp);
	printf("\nInfix  : %s", inputExp);

	infix_to_postfix(inputExp, postfixExp, true);
	printf("\nPostfix: %s", postfixExp);

	infix_to_prefix(inputExp, prefixExp);
	printf("\nPrefix : %s", prefixExp);


	char postfix_exp[] = "234*+823^/-"; //13
	printf("\n\nPostfix Exp: %s", postfix_exp);
	int result1 = evaluate_expression(postfix_exp, true);
	printf("\nPostfix Result: %d", result1);

	char prefix_exp[] = "-+2*34/8^23"; //13
	printf("\n\nPrefix  Exp: %s", prefix_exp);
	strrev(prefix_exp);
	int result2 = evaluate_expression(prefix_exp, false);
	printf("\nPrefix  Result: %d", result2);
}
