/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 17.Sep.2013
**/

#include<iostream>

using namespace std;

struct node
{
	int information;
	node *next, *prev;
};

void destroyTheList(node *nodePointer);
void traverse_frontToEnd(node *nodePointer);
void traverse_endToFront(node *nodePointer);
void searchAndPrint(int searchingElement, node *nodePointer);
node* insertAfterTheElement(int searchingElement, int insertionElement, node *nodePointer);
node* insertBeforeTheElement(int searchingElement, int insertionElement, node *nodePointer);
node* insertAtBeginning(int insertionElement, node *nodePointer);
node* deleteTheElement(int searchingElement, node *nodePointer1, node *nodePointer2);
node* deleteTheNextElement(int searchingElement, node *nodePointer1, node *nodePointer2);
node* deleteThePreviousElement(int searchingElement, node *nodePointer1, node *nodePointer2);

int main(void)
{
    node *head, *tail, *old;//declaring node type pointers

    int count=0;

    int numberOfElements, element;// the variable "numberOfElements" to get the number of the total elements of the list and "element" to insert the element to the list.
    cin >> numberOfElements;

    //creating a two way linked list.
    for(int i=0; i<numberOfElements; i++)
    {
        count++;
        cin >> element;

        node *new_node;
        new_node = new node[1];

        new_node[0].information = element;
        new_node[0].next = NULL;
        new_node[0].prev = NULL;

        if(count==1)head = &new_node[0];
        else
        {
            old->next = &new_node[0];
            new_node[0].prev=old;
        }

        old=&new_node[0];

    }

    tail=old;

    // calling the functions.
    traverse_frontToEnd(head);

    traverse_endToFront(tail);

    int searchingElement;
    cin >> searchingElement;
    searchAndPrint(searchingElement, tail);

    int insertionElement;
    cin >> insertionElement;
    tail=insertAfterTheElement(searchingElement, insertionElement, head);

    head = insertBeforeTheElement(searchingElement, insertionElement, head);

    head = insertAtBeginning(insertionElement, head);

    head = deleteTheElement(searchingElement, head, tail);

    tail = deleteTheNextElement(searchingElement, head, tail);

    head = deleteThePreviousElement(searchingElement, head, tail);

    traverse_frontToEnd(head);

    destroyTheList(head);
}

//destroy function to destroy the whole list to avoid the memory lickage problem
void destroyTheList(node *nodePointer)
{
    node *current;

    while(nodePointer!=NULL)
    {
        current=nodePointer;
        nodePointer=nodePointer->next;
        delete [] current;
    }
}

// traversing the list from front to end, all the elements are being printed
void traverse_frontToEnd(node *nodePointer)
{
    node *current;
    current = nodePointer;

    while(1)
    {
        cout << current->information << endl;
        if(current->next==NULL) break;
        current = current->next;
    }
}

// traversing the list from end to front, all the elements are being printed
void traverse_endToFront(node *nodePointer)
{
    node *current;
    current = nodePointer;

    while(1)
    {
        cout << current->information << endl;
        if(current->prev==NULL) break;
        current = current->prev;
    }
}

// this funtion is to search a specific element and to print the next and the previous elements
void searchAndPrint(int searchingElement, node *nodePointer)
{
    node *current;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->prev==NULL) break;
        current=current->prev;
    }

    if(current->prev==NULL && current->information!=searchingElement)
    {
        cout << "The element " << searchingElement << " not found in the list." << endl;
    }

    else if(current->prev==NULL && current->information==searchingElement)
    {
        cout << "The next element: not found" << endl;
        cout << "The previous element: " << current->prev->information << endl;
    }

    else if(current->next==NULL && current->information==searchingElement)
    {
        cout << "The next element: " << current->next->information << endl;
        cout << "The previous element: not found" << endl;
    }

    else
    {
        cout << "The next element: " << current->next->information << endl;
        cout << "The previous element: " << current->prev->information << endl;
    }

}

//this funtion is to search a specific element and to insert another one after that
node* insertAfterTheElement(int searchingElement, int insertionElement, node *nodePointer)
{
    node *current;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->next==NULL && current->information!=searchingElement) cout << "Element not found in the list." << endl;

    else if(current->next==NULL && current->information==searchingElement)
    {
        node *new_node;
        new_node = new node[1];

        current->next = &new_node[0];

        new_node[0].information = searchingElement;
        new_node[0].next = NULL;
        new_node[0].prev = current;

        nodePointer = &new_node[0];
    }

    else
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = current->next;
        new_node[0].prev = current;

        current->next = &new_node[0];
    }

    return nodePointer;
}

//this funtion is to search a specific element and to insert another one before that
node* insertBeforeTheElement(int searchingElement, int insertionElement, node *nodePointer)
{
    node *current;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->next==NULL && current->information!=searchingElement) cout << "Element not found in the list." << endl;

    else if(current==nodePointer)
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = current;
        new_node[0].prev = NULL;

        current->prev = &new_node[0];

        nodePointer = &new_node[0];
    }

    else
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = current;
        new_node[0].prev = current->prev;

        current->prev->next=&new_node[0];
        current->prev = &new_node[0];

    }

    return nodePointer;
}

//this funtion is to delete a specific element
node* insertAtBeginning(int insertionElement, node *nodePointer)
{
    node *current, *new_node;
    current = nodePointer;
    new_node = new node[1];

    new_node[0].information = insertionElement;
    new_node[0].next = current;
    new_node[0].prev = NULL;

    nodePointer = &new_node[0];

    return nodePointer;
}

//this funtion is to delete a specific element
node* deleteTheElement(int searchingElement, node *nodePointer1, node *nodePointer2)
{
    node *current, *old;
    current=nodePointer1;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        old=current;
        current=current->next;
    }

    if(current->next==NULL && current->information!=searchingElement) cout << "Element not found in the list." << endl;

    else if(current->next==NULL && current->information==searchingElement)
    {
        old->next = NULL;
        delete [] current;
    }

    else if(current==nodePointer1)
    {
        nodePointer1 = current->next;
        current->next = NULL;
        delete [] current;
    }

    else if(nodePointer1==nodePointer2)
    {
        delete [] current;
        cout << "The list is empty now." << endl;
    }

    else
    {
        old->next = current->next;
        current->next->prev = old;
        delete [] current;
    }

    return nodePointer1;
}

//this funtion is  to delete the next element of a specific element
node* deleteTheNextElement(int searchingElement, node *nodePointer1, node *nodePointer2)
{
    node *current, *old;
    current=nodePointer1;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->next==NULL) cout << "Nothing to delete." << endl;

    else if(current->next==nodePointer2)
    {
        old = current;
        current = current->next;
        old->next = current->next;
        delete [] current;
        nodePointer2 = old;
    }

    else
    {
        old = current;
        current = current->next;
        old->next = current->next;
        delete [] current;
    }

    return nodePointer2;
}

//this funtion is  to delete the previous element of a specific element
node* deleteThePreviousElement(int searchingElement, node *nodePointer1, node *nodePointer2)
{

    node *current, *old;
    current=nodePointer1;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->prev==NULL && current->information==searchingElement && current->information!=searchingElement) cout << "Nothing to delete." << endl;

    if(current->prev==nodePointer1)
    {
        old = current;
        current = current->prev;
        delete [] current;
        nodePointer1 = old;
        old->prev = NULL;
    }

    else
    {

        current = current->prev;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete [] current;
    }
    return nodePointer1;
}
