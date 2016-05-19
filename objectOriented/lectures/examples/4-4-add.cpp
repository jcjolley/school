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
   // if the list is empty, use addToHead()
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
 * Display the content sof a linked list
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
      // display the list
      cout << "\t" << pHead << endl;

      // fetch the data
      float data;
      cout << "Data: ";
      cin  >> data;

      // fetch the index
      int index = 0;
      if (i != 1)      // don't prompt for the first item in the list
      {
         cout << "Index after which " << data << " will be inserted: ";
         cin  >> index;
      }
      
      // insert the value
      if (index == 0 || pHead == NULL)
         addToHead(pHead, data);
      else
         add(findNode(pHead, index), data);
   }
}

/**********************************************************************
 * This will be just a simple driver program to demonstrate the loop
 ***********************************************************************/
int main()
{
   // first, create a linked list of data;
   Node * pHead = NULL;
   fill(pHead);

   // next, display the contents of the list
   cout << "\t" << pHead << endl;

   // finally, delete the nodes
   empty(pHead);
   
   return 0;
}
