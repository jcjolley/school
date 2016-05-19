/***********************************************************************
 * This program is designed to demonstrate:
 *      how to loop through a linked list
 ************************************************************************/

#include <iostream>
using namespace std;

// simple linked list node
struct Node
{
   float  data;
   Node * pNext;
};

/*****************************************
 * DISPLAY
 * Display the content sof a linked list
 ****************************************/
void display(const Node * pHead)
{
   for (const Node * p = pHead; p; p = p->pNext)
      cout << p->data << endl;
}

/****************************************
 * EMPTY
 * Empty a linked list by deleting each Node
 ****************************************/
void empty(Node * & pHead)
{
   for (Node * p = pHead; p; p = p->pNext)
      delete p;
   pHead = NULL;
}

/************************************
 * FILL
 * Fill a linked list with user data
 ************************************/
void fill(Node * & pHead)           // because pHead will receive a new value
{                                   //    when we allocate that node, we
   // add the first node            //    need to pass pHead by-reference
   pHead = new Node;
   cout << "> ";
   cin  >> pHead->data;             // use the arrow operator -> to reach
                                    //    the member variable from a pointer
   // add the second node
   pHead->pNext = new Node;
   cout << "> ";
   cin  >> pHead->pNext->data;

   // add the third node
   pHead->pNext->pNext = new Node;
   cout << "> ";
   cin  >> pHead->pNext->pNext->data;

   // mark the end of the list
   pHead->pNext->pNext->pNext = NULL;
}

/**********************************************************************
 * This will be just a simple driver program to demonstrate the loop
 ***********************************************************************/
int main()
{
   // first, create a linked list of data;
   Node * pHead;
   fill(pHead);

   // next, display the contents of the list
   display(pHead);

   // finally, delete the nodes
   empty(pHead);
   
   return 0;
}
