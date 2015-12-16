/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 17.Sep.2013
**/

#include<iostream>

using namespace std;

struct node
{
    int information;
    node *next;
};

void traverse(node *nodePointer);
void destroyTheList(node *nodePointer);
void searchAndPrintTheNextElement(int searchingElement, node *nodePointer);
void insertAfterTheElement(int searchingElement, int insertionElement, node *nodePointer);
node* insertBeforeTheElement(int searchingElement, int insertionElement, node *nodePointer);
node* insertAtBeginning(int insertionElement, node *nodePointer);
node* deleteTheElement(int searchingElement, node *nodePointer);
void deleteTheNextElement(int searchingElement, node *nodePointer);

int main (void)
{
    node *head, *old; //declaring node type pointers

    int count=0;

    int numberOfElements, element; // the variable "numberOfElements" to get the number of the total elements of the list and "element" to insert the element to the list.
    cin >> numberOfElements;


    //creating a one way linked list.
    for(int i=0; i<numberOfElements; i++)
    {
        count++;
        cin >> element;

        node *new_node;
        new_node = new node[1];

        new_node[0].information = element;
        new_node[0].next = NULL;

        if(count==1)head = &new_node[0];
        else old->next = &new_node[0];

        old = &new_node[0];
    }

    // calling the functions.
    traverse(head);

    int searchingElement;
    cin >> searchingElement;
    searchAndPrintTheNextElement(searchingElement, head);

    int insertionElement;
    cin >> insertionElement;
    insertAfterTheElement(searchingElement, insertionElement, head);

    head = insertBeforeTheElement(searchingElement, insertionElement, head);

    head = insertAtBeginning(insertionElement, head);

    head = deleteTheElement(searchingElement, head);

    deleteTheNextElement(searchingElement, head);

    traverse(head);

    destroyTheList(head);

    return 0;
}


// traversing the list, all the elements are being printed
void traverse(node *nodePointer)
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


// this funtion is to search a specific element and to print the next one
void searchAndPrintTheNextElement(int searchingElement, node *nodePointer)
{
    node *current;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->next==NULL) cout << "The element " << searchingElement << " not found in the list." << endl;
    else cout << "The next element of " << searchingElement << " is " <<current->next->information << "." << endl;
}

//this funtion is to search a specific element and to insert another one after that
void insertAfterTheElement(int searchingElement, int insertionElement, node *nodePointer)
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
        new_node[0].information = insertionElement;
        new_node[0].next = NULL;
    }

    else
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = current->next;
        current->next = &new_node[0];
    }
}

//this funtion is to search a specific element and to insert another one before that
node* insertBeforeTheElement(int searchingElement, int insertionElement, node *nodePointer)
{
    node *current, *old;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        old=current;
        current=current->next;
    }

    if(current->next==NULL && current->information!=searchingElement) cout << "Element not found in the list." << endl;

    else if(current==nodePointer)
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = current;
        nodePointer = &new_node[0];
    }

    else
    {
        node *new_node;
        new_node = new node[1];

        new_node[0].information = insertionElement;
        new_node[0].next = old->next;
        old->next = &new_node[0];
    }

    return nodePointer;
}

//this funtion is to insert an element at the begginig of the list
node* insertAtBeginning(int insertionElement, node *nodePointer)
{
    node *current, *new_node;
    current = nodePointer;
    new_node = new node[1];

    new_node[0].information = insertionElement;
    new_node[0].next = current;
    nodePointer = &new_node[0];

    return nodePointer;
}

//this funtion is to delete a specific element
node* deleteTheElement(int searchingElement, node *nodePointer)
{
    node *current, *old;
    current=nodePointer;

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

    else if(current==nodePointer)
    {
        nodePointer = current->next;
        delete [] current;
    }

    else
    {
        old->next = current->next;
        delete [] current;
    }

    return nodePointer;
}

//this funtion is  to delete the next element of a specific element
void deleteTheNextElement(int searchingElement, node *nodePointer)
{
    node *current, *old;
    current=nodePointer;

    while(1)
    {
        if(current->information==searchingElement) break;
        if(current->next==NULL) break;
        current=current->next;
    }

    if(current->next==NULL) cout << "Nothing to delete." << endl;

    else
    {
        old = current;
        current = current->next;
        old->next = current->next;
        delete [] current;
    }
}
