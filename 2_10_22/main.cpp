#include "stackType.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void evaluateExpression(ifstream&, ofstream&, stackType<double>&, char&, bool&);
void evaluateOpr(ofstream&, stackType<double>&, char, bool&);
void discardExp(ifstream&, ofstream&, char&);
void printResult(ofstream&, stackType<double>&, bool);

int main()
{
	bool isok;
	char ch;
	stackType<double> stack(100);
	ifstream infile;
	ofstream outfile;
	infile.open("RpnData.txt");
	if(!infile)
	{
		cout << "Cannot open the input file." << endl;
		return 1;
	}
	outfile.open("RpnOutput.txt");
	outfile << fixed << showpoint << setprecision(2);
	
	infile >> ch;
	while(infile)
	{
		stack.initializeStack();
		isok = true;
		outfile << ch;
		evaluateExpression(infile, outfile, stack, ch, isok);
		printResult(outfile, stack, isok);
		infile >> ch;
	}
	infile.close();
	outfile.close();

	return 0;
}


void evaluateExpression(ifstream& in, ofstream& out, stackType<double>& s, char& ch, bool& isok)
{
	double num;
	while(ch != '=')
	{
		switch(ch)
		{
			case '#': 
				in >> num;
				out << num << " ";
				if(!s.isFullStack())
					s.push(num);
				else
				{
					cout << "Stack overflow" << endl;
					exit(0);
				}
				break;
			default:
				evaluateOpr(out, s, ch, isok);
		}
		if(isok)
		{
			in >> ch;
			out << ch;
			if (ch != '#')
				out << " ";
		}
		else 
			discardExp(in, out, ch);
	}
}

void evaluateOpr(ofstream& out, stackType<double>& s, char ch, bool& isok)
{
	double op1, op2;
	if(s.isEmptyStack())
	{
		out << " (Not enough operands)";
		isok = false;
	}
	else
	{
		op2 = s.pop();
		if(s.isEmptyStack())
		{
			out << " (Not enough operands)";
			isok = false;
		}
		else 
		{
			op1 = s.pop();
			switch(ch)
			{
				case '+':
					s.push(op1 + op2);
					break;
				case '-':
					s.push(op1 - op2);
					break;
				case '*':
					s.push(op1 * op2);
					break;
				case '/':
					if(op2 != 0)
						s.push(op1 / op2);
					else
					{
						out << " (Division by 0)";
						isok = false;
					}
					break;
				default:
					out << " (Illegal operator)";
					isok = false;
			}
		}
	}
}

void discardExp(ifstream& in, ofstream& out, char& ch)
{
	while(ch != '=')
	{
		in.get(ch);
		out << ch;
	}
}

void printResult(ofstream& out, stackType<double>& s, bool isok)
{
	double result;
	if(isok)
	{
		if(!s.isEmptyStack())
		{
			result = s.pop();
			if(s.isEmptyStack())
				out << result << endl;
			else 
				out << " (Error: Too many operands)" << endl;
		}
		else 
			out << " (Error in the expression)" << endl;
	}
	else
		out << " (Error in the expression)" << endl;
	out << "_________________________________________" << endl << endl;
}


































































