/**
Name: Minhas Kamal
Description: This program reads a infix notation from a file & converts it to postfix
Date: Oct-2013
**/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;


double stringToDouble(string str);
int operatorPrecedence(string str);
struct element{
    string str;     //string property
    double value;    //value of the string
    bool opert;      //operator-true, operand-false
};

int main(){
    ifstream input; //the input file

    input.open("InfixToPrefix_Input.txt");
    if(!input.is_open()){   //when file is not found exit
        cout << "File name is wrong!\n";
        return 0;
    }

    string s;   //stores the input file's element as string
    vector<element> inputElement;   //holds the behaviour of the input elements

    element e;  //pushing '(' at the start of the input representing the start
	e.str = "(";
	e.opert = true;
	e.value = -0.0;
	inputElement.push_back(e);

    while(input >> s){  //the loop determines the behaviour of the input elements
        element elem;
        elem.str = s;

        if(s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/' || s[0]=='^' || s[0]=='(' || s[0]==')'){ //when an operator is found
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

    /*/cout << "string \toperat \tvalue \n";   //output of the inputElement
    for(int i=0; i<inputElement.size(); i++){
        cout << inputElement[i].str << "\t" << inputElement[i].opert << "\t" << inputElement[i].value << endl;
	}/**/

    vector<string> prefix;     //postfix form of the input
	stack<string> tempOpertStore; //temporarily stores operators

	tempOpertStore.push(")");

	for(int i=inputElement.size()-1; !tempOpertStore.empty(); i--){ //conversion
        if(!inputElement[i].opert){
            prefix.push_back(inputElement[i].str);
        }
        else{
            if(inputElement[i].str[0]==')'){
                tempOpertStore.push(inputElement[i].str);
            }
            else if(inputElement[i].str[0]=='('){
                while(tempOpertStore.top()[0]!=')'){
                    prefix.push_back(tempOpertStore.top());
                    tempOpertStore.pop();
                }
                tempOpertStore.pop();   //pops the ')'
            }
            else{
                int opertPrecedence = operatorPrecedence(inputElement[i].str);

                while(tempOpertStore.top()[0]!=')'){
                    int stackPrecedence = operatorPrecedence(tempOpertStore.top());

                    if(stackPrecedence < opertPrecedence) break;
                    else{
                        prefix.push_back(tempOpertStore.top());
						tempOpertStore.pop();
                    }
                }
                tempOpertStore.push(inputElement[i].str);
            }
        }

        /*cout << "after " << inputElement[i].str << ": ";  //analysing every step
		for(int j=0; j<postfix.size(); j++)
		{
			cout << postfix[j] << " " ;
		}
		cout << endl;*/
	}

    cout << "The prefix form is:  ";
	for(int i=prefix.size()-1; i>=0; i--) //the output
		cout << prefix[i] << " " ;
	cout << "\n\n";



    return 0;
}


double stringToDouble(string str){  //converts a string to a double
    double value=0, //holds the value of the string
           afterPoint=0;    //holds the value after a point

    bool flag = false;  //represents if any point is found in the string
    int numberOfElementAfterPoint=0;

    for(int i=0; str[i]!=NULL; i++){
        if(str[i]=='.') flag = true;
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


int operatorPrecedence(string str){ //takes an operator string and sends the precedence
    int i=0;

    if(!str.compare("+")) i=1;  //compare method returns 0 if the strings are matched
    else if(!str.compare("-")) i=2;
    else if(!str.compare("*")) i=3;
    else if(!str.compare("/")) i=4;
    else if(!str.compare("^")) i=5;
    else i=7;

    return i;
}



