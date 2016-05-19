/***********************************************************************
 * This program is designed to demonstrate:
 *      how to loop through a linked list
 ************************************************************************/

#include <iostream>
using namespace std;

// simple linked list node
template <class T>
struct Node
{
   T  data;
   Node * pNext;
};

/**************************************
 * REMOVE FROM HEAD
 * Remove the first item in a linked list
 *************************************/
template <class T>
void removeFromHead(Node<T> * & pHead)
{
   // 1. remember the second item
   Node<T> * pSave = pHead->pNext;

   // 2. delete the head
   delete pHead;

   // 3. make the head point to the second item
   pHead = pSave;
}

/**************************************
 * REMOVE
 * Remove a node from the list
 *************************************/
template <class T>
void remove(Node<T> * pPrevious)
{
   // 1. save the location of the item before the one we are deleting
   Node<T> * pDelete = pPrevious->pNext;

   // 2. update the pointer of pPrevious->pNext
   pPrevious->pNext = pDelete->pNext;

   // 3. delete the pointer at pDelete
   delete pDelete;
}

/**************************************
 * ADD TO HEAD
 * Add a new node to the head of the linked list
 **************************************/
template <class T>
void addToHead(Node<T> * & pHead, const T & data)
{
   // 1. allocate and initialize create a new node
   Node<T> * pNew = new Node<T>;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. put pHead in line after the new node
   pNew->pNext = pHead;                  // set pNext, the old head of the list

   // 3. finally, pNew is the new head
   pHead = pNew;                         // pNew is the new head.  Note that
}                                        //    pHead is a pointer by-reference


/**********************************************
 * FIND NODE
 * Looking for a node based on the index.  Note
 * that the index is 1's based.  If there are
 * six items, then the valid indicies are 1..6.
 * Return pHead if no node exists there
 **********************************************/
template <class T>
Node<T> * findNode(Node<T> * pHead, int index)
{
   // search through the linked list
   for (Node<T> * p = pHead; p; p = p->pNext)
      if (--index == 0)                  // if we are at the desired spot...
         return p;                       // ...return the vlaue

   return pHead;                         // return pHead if no node exists
}

/**************************************
 * ADD
 * Add an item to a linked list
 *************************************/
template <class T>
void add(Node<T> * pNode, const T & data)
{
   // 1. create a new node
   Node<T> * pNew = new Node<T>;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. fix the pNext pointer from pNew to the spot after it in the list
   pNew->pNext = pNode->pNext;

   // 3. finally get pNode->pNext to point to pNew instead of the old node
   pNode->pNext = pNew;
}

/*****************************************
 * DISPLAY
 * Display the content sof a linked list
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const Node<T> * pHead)
{
   for (const Node<T> * p = pHead; p; p = p->pNext)
      out << p->data << ' ';
   return out;
}

/****************************************
 * EMPTY
 * Empty a linked list by deleting each Node
 ****************************************/
template <class T>
void empty(Node<T> * & pHead)
{
   for (Node<T> * p = pHead; p; p = p->pNext)
      delete p;
   pHead = NULL;
}

/************************************
 * FILL
 * Fill a linked list with user data
 ************************************/
template <class T>
void fill(Node<T> * & pHead)
{
   cout << "Enter five numbers to put in the linked list\n";

   // enter the first node
   pHead = new Node<T>;
   cout << "Enter data number 1: ";
   cin  >> pHead->data;
   pHead->pNext = NULL;

   // loop through the list
   for (int i = 2; i <= 5; i++)
   {
      T data;
      cout << "Enter data number " << i << ": ";
      cin  >> data;
      add(findNode(pHead, i - 1), data);
   }
}

/**********************************************************************
 * This will be just a simple driver program to demonstrate the linked list
 ***********************************************************************/
int main()
{
   // first, create a linked list of data;
   Node<string> * pHead = NULL;
   fill(pHead);

   // next, display the contents of the list
   cout << "\tbefore: " << pHead << endl;

   // delete a few items
   cout << "Which item do you want to remove? ";
   int position;
   cin  >> position;
   if (position == 1)
      removeFromHead(pHead);
   else
      remove(findNode(pHead, position - 1));

   // display the linked list again
   cout << "\tafter: " << pHead << endl;

   // finally, delete the nodes
   empty(pHead);
   
   return 0;
}
