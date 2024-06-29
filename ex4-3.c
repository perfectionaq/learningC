#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER: 
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / pop());
			else
				printf("error: zero division\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case '%':
			op2 = pop();
			if (op2 != 0)
				// we need to cast to int because % apparently only works with ints
				// need to check this again
				push((int) pop() %  (int) op2);
			else 
				printf("error: zero division\n");
			break;
		default:
			printf("error: unknown operand %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack is full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;	

	if (!isdigit(c) && c != '.') {
		if (c == '-') {
			if (isdigit(c = getch())) {
				ungetch(c);
				while(isdigit(s[++i] = c = getch()))
					;
			}
		}
		else {
			return c;
		}
	}
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}