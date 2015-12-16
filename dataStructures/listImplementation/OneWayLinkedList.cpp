/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 13.Sep.2013
**/

#include<iostream>
#include<list>

using namespace std;

list<int> creatList();              //creates the list
void traversing(list<int> myList);  //prints all the integers in the list
int searching(list<int> myList, int searchingElement);      //searches for selected element
list<int> deleting(list<int> myList, int deletingElement, int a);   //deleting selected element
list<int> inserting(list<int> myList, int destinationElement, int insertingElement, int a); //inserts certain element in definite place
list<int> destroy(list<int> myList);    //destroying the list


int main()
{
    list<int> myList;
    myList = creatList();

    while(true)
    {
        int selection;  //user action
        cout << "\n##What do you want to do? \npress- 1 for traversing\n";  //user prompt
        cout << "       2 for searching\n       3 for deleting\n       4 for inserting\n";
        cout << "       5 for exit\nSelection: ";
        cin >> selection;


        if(selection==1)
            traversing(myList);

        else if(selection==2)
        {
            int searchingElement;   //the element to be searched
            cout << "Enter the element you want to search for: ";
            cin >> searchingElement;

            cout << "\n* " << searchingElement << " is found " << searching(myList, searchingElement) << " times.\n";
        }

        else if(selection==3)
        {
            int deletingElement;    //the element to be deleted
            cout << "Enter the element: ";
            cin >> deletingElement;

            int a=0;    //determines the correct element
            cout << "Press 1 for deleting " << deletingElement;
            cout << "\n      2 for deleting the element after " << deletingElement << "\nSelection- ";
            cin >> a;

            myList = deleting(myList, deletingElement, a);
        }

        else if(selection==4)
        {
            int insertingElement, destinationElement;    //the element to be deleted
            cout << "Enter the element: ";
            cin >> insertingElement;
            cout << "Enter the destination element: ";
            cin >> destinationElement;

            int a=0;    //determines the correct element
            cout << "Press 1 for inserting after " << destinationElement;
            cout << "\n      2 for inserting before " << destinationElement << "\nSelection- ";
            cin >> a;

            myList = inserting(myList, destinationElement, insertingElement, a);
        }

        else if(selection==5) break;

        else cout << "#Invalid input!\n";
    }
    myList = destroy(myList);
}


list<int> creatList()   //creates the list
{
    list<int> myList;   //declaring the list
    int intNumber,  //the number of integers
        input;      //the input that the user gives

    cin >> intNumber;
    for(int i=0; i<intNumber; i++)
	{
		cin >> input;
		myList.push_back(input);
	}
    return myList;
}

void traversing(list<int> myList) //prints the List
{
    list<int>:: iterator it;    //declaring a iterator

    cout << endl;
    for(it=myList.begin(); it!=myList.end(); it++)
		cout << *it << "  ";
	cout << endl << endl ;
}

int searching(list<int> myList, int searchingElement)
{
    int found=0;  //number of the searching element
    list<int>:: iterator it;    //declaring iterator

	for(it=myList.begin(); it!=myList.end(); it++)
		if(searchingElement==*it) found++;

    return found;
}

list<int> deleting(list<int> myList, int deletingElement, int a)
{
    int flag=1;
    if(a==1) myList.remove(deletingElement);
    else {
        list<int>:: iterator it;    //declaring iterator
        flag=0;

        for(it=myList.begin(); it!=myList.end(); it++){
            if(deletingElement==*it){
                it++;
                it=myList.erase(it);
                flag=1;
                if(it==myList.end()) break;
            }
        }
    }

    if(flag) cout << "\n* Deleted!\n";
    return myList;
}

list<int> inserting(list<int> myList, int destinationElement, int insertingElement, int a)
{
    int flag=0;
    list<int>:: iterator it;    //declaring iterator

    for(it=myList.begin(); it!=myList.end(); it++){
        if(destinationElement==*it) {
            flag=1;
            break;
        }
    }
    if(a==1) it++;
    myList.insert(it, insertingElement);

    if(flag) cout << "\n* Inserted!!\n";
    else cout << "Destination not found.\n";

    return myList;
}

list<int> destroy(list<int> myList)
{
    myList.clear();
    return myList;
}


