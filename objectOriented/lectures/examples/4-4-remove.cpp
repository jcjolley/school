/***********************************************************************
 * This program is designed to demonstrate:
 *      how to remove items from a linked list
 ************************************************************************/

#include <iostream>
using namespace std;

// simple linked list node
struct Node
{
   float  data;
   Node * pNext;
};

/**************************************
 * REMOVE FROM HEAD
 * Remove the first item in a linked list
 *************************************/
void removeFromHead(Node * & pHead)
{
   // 0. do nothing if there is nothing to do
   if (pHead == NULL)
      return;
   
   // 1. remember the second item
   Node * pSave = pHead->pNext;

   // 2. delete the head
   delete pHead;

   // 3. make the head point to the second item
   pHead = pSave;
}

/**************************************
 * REMOVE
 * Remove a node from the list
 *************************************/
void remove(Node * pPrevious)
{
   // 0. if the list is empty or there is just one item, use removeFromHead
   if (pPrevious == NULL || pPrevious->pNext == NULL)
      return;
   
   // 1. save the location of the item before the one we are deleting
   Node * pDelete = pPrevious->pNext;

   // 2. update the pointer of pPrevious->pNext
   pPrevious->pNext = pDelete->pNext;

   // 3. delete the pointer at pDelete
   delete pDelete;
}

/**************************************
 * ADD TO HEAD
 * Add a new node to the head of the linked list
 **************************************/
void addToHead(Node * & pHead, float data)
{
   // 1. allocate and initialize create a new node
   Node * pNew = new Node;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. put pHead in line after the new node
   pNew->pNext = pHead;                  // set pNext, the old head of the list

   // 3. finally, pNew is the new head
   pHead = pNew;                         // pNew is the new head.  Note that
}                                        //    pHead is a pointer by-reference

/**************************************
 * ADD
 * Add an item to a linked list
 *************************************/
void add(Node * pNode, float data)
{
   // 0. if the list is empty, use addToHead()
   if (pNode == NULL)
      return;
   
   // 1. create a new node
   Node * pNew = new Node;               // allocate the node
   pNew->data = data;                    // set the data member variable

   // 2. fix the pNext pointer from pNew to the spot after it in the list
   pNew->pNext = pNode->pNext;

   // 3. finally get pNode->pNext to point to pNew instead of the old node
   pNode->pNext = pNew;
}

/**********************************************
 * FIND NODE
 * Looking for a node based on the index.  Note
 * that the index is 1's based.  If there are
 * six items, then the valid indicies are 1..6.
 * Return pHead if no node exists there
 **********************************************/
Node * findNode(Node * pHead, int index)
{
   // search through the linked list
   for (Node * p = pHead; p; p = p->pNext)
      if (--index == 0)                  // if we are at the desired spot...
         return p;                       // ...return the value

   return pHead;                         // return pHead if no node exists
}

/*****************************************
 * DISPLAY
 * Display the contents of a linked list
 ****************************************/
ostream & operator << (ostream & out, const Node * pHead)
{
   for (const Node * p = pHead; p; p = p->pNext)
      out << p->data << ' ';
   return out;
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
void fill(Node * & pHead)
{
   cout << "Enter five numbers to put in the linked list\n";

   // loop through the list
   for (int i = 1; i <= 5; i++)
   {
      // fetch the data
      float data;
      cout << "#" << i << ": ";
      cin  >> data;

      // insert onto the list
      if (i == 1 || pHead == NULL)
         addToHead(pHead, data);
      else
         add(findNode(pHead, i - 1), data);
   }
}

/**********************************************************************
 * This will be just a simple driver program to demonstrate the linked list
 ***********************************************************************/
int main()
{
   // first, create a linked list of data;
   Node * pHead = NULL;
   fill(pHead);

   // next, display the contents of the list
   cout << "\tbefore: " << pHead << endl;

   // delete an item
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
