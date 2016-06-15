/**
Name: Minhas Kamal (minhaskamal024@gmail.com)
Description: This program reads an infix notation from a file & finds the result.
Date: Oct-2013
**/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


double stringToDouble(string str);  //converts a string to a double
int operatorPrecedence(char operat); //returns bigger integer depending on the precedence
double operation(double a, double b, char operat);  //returns a result depending on the operator


struct element{
    string str;     //string property
    double value;    //value of the string
    bool opert;      //operator-true, operand-false
};

int main(){
    ifstream input; //the input file

    input.open("InfixEvaluation_Input.txt");
    if(!input.is_open()){   //when file is not found exit
        cout << "File name is wrong!\n";
        return 0;
    }

    string s;   //stores the input file's element as string
    vector<element> inputElement;   //holds the behaviour of the input elements
    while(input >> s){  //the loop determines the behaviour of the input elements
        element elem;
        elem.str = s;

        if(s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/' || s[0]=='^'
            || s[0]=='(' || s[0]==')'){ //when an operator is found
            elem.value = -0.0;
            elem.opert = true;
        }
        else{
            elem.value = stringToDouble(s); //this method converts string to double
            elem.opert = false;
        }

        inputElement.push_back(elem);
    }

    input.close();  //closing the stream

    /*cout << "string \toperat \tvalue \n";   //output of the inputElement
    for(int i=0; i<inputElement.size(); i++){
        cout << inputElement[i].str << "\t" << inputElement[i].opert << "\t" << inputElement[i].value << endl;
	}*/


    element e;  //pushing ')' at the end of the input representing the end
	e.str = ")";
	e.opert = true;
	e.value = -0.0;
	inputElement.push_back(e);


    stack<double> operand;     //postfix form of the input
	stack<char> operat; //temporarily stores operators

	operat.push('(');   //pushing '(' at the beginning of stack

    bool everyThingOkFlag=true;

    for(int i=0; !operat.empty(); i++){ //evaluation
        if(!inputElement[i].opert){
            operand.push(inputElement[i].value);
        }
        else{
            if(inputElement[i].str[0]=='('){
                operat.push('(');
            }
            else if(inputElement[i].str[0]==')'){
                while(operat.top()!='('){
                    double b = operand.top();   //taking first two elements of the stack
                    operand.pop();
                    double a = operand.top();
                    operand.pop();

                    char oprt = operat.top();   //taking the top the operator of stack
                    operat.pop();

                    double result = 0;  //result after the operation of a & b
                    result = operation(a, b, oprt);

                    operand.push(result);   //pushing the result in the operand stack
                }
                operat.pop();   //pops the '('
            }
            else{
                int opertPrecedence = operatorPrecedence(inputElement[i].str[0]);

                while(operat.top()!='('){
                    int stackPrecedence = operatorPrecedence(operat.top());

                    if(stackPrecedence < opertPrecedence) break;
                    else{
                        double b = operand.top();   //taking first two elements of the stack
                        operand.pop();
                        double a = operand.top();
                        operand.pop();

                        char oprt = operat.top();   //taking the top the operator of stack
                        operat.pop();

                        double result = 0;  //result after the operation of a & b
                        result = operation(a, b, oprt);

                        operand.push(result);   //pushing the result in the operand stack
                    }
                }
                operat.push(inputElement[i].str[0]);
            }
        }

        if(i>inputElement.size()) {
            cout << "Math error! \n";
            everyThingOkFlag=false;
            break;
        }
    }

    if(everyThingOkFlag) cout << "The result is: " << operand.top() << endl;

	return 0;
}


double stringToDouble(string str){  //converts a string to a double
    double value=0, //holds the value of the string
           afterPoint=0;    //holds the value after a point

    bool flag = false;  //represents if any point is found in the string
    int numberOfElementAfterPoint=0;

    for(int i=0; str[i]!=NULL; i++){
        if(str[i]=='.') flag = true; //waiting for a '.'
        else{
            if(flag){
                afterPoint = afterPoint*10 + (str[i]-48);
                numberOfElementAfterPoint++;
            }
            else
                value = value*10 + (str[i]-48);
        }
    }

    int divisor=1;  //divides the afterPoint element by precise number of 10s
    for(int i=0; i<numberOfElementAfterPoint; i++) divisor = divisor*10;

    value = value + afterPoint/divisor;

    return value;
}


int operatorPrecedence(char operat){ //takes an operator string and sends the precedence
    int i=0;

    if(operat=='+') i=1;
    else if(operat=='-') i=2;
    else if(operat=='*') i=3;
    else if(operat=='/') i=4;
    else if(operat=='^') i=5;
    else i=7;

    return i;
}


double operation(double a, double b, char operat){
    double result = 0;  //result after the operation of a & b

    if(operat=='+') result = a+b;
    else if(operat=='-') result = a-b;
    else if(operat=='*') result = a*b;
    else if(operat=='/') result = a/b;
    else if(operat=='^'){
        result = 1;
        for(int i=0; i<b; i++)
            result = result*a;
    }

    return result;
}


