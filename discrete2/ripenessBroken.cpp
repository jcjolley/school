/***********************************************************************
 * Program:
 *    Exploration 4, Ripeness
 *    Brother Neff, CS238
 *
 * Author:
 *    Joshua Jolley
 *
 * Summary:
 *    Tree Structure time-for-space traversal tradeoff and
 *    Tournament Sort
 *
 * Note:
 *    This code is mostly uncommented --- this is deliberate.
 *
 ***********************************************************************/

#include <cmath>
#include <climits> // for INT_MIN
#include <iostream>
using namespace std;


class Node
{
private:
   int mValue;
   Node* mLeft;
   Node* mRight;
public:
   Node(int inValue) { mValue = inValue; mLeft = NULL; mRight = NULL; }
   int getValue() { return mValue; }
   void setValue(int value) { mValue = value; }
   Node* getLeft() { return mLeft; }
   void setLeft(Node* inLeft) { mLeft = inLeft; }
   Node* getRight() { return mRight; }
   void setRight(Node* inRight) { mRight = inRight; }
   void setMax();
};

void Node::setMax() {
   int left = INT_MIN;
   int right = INT_MIN;
   
   if (mLeft)
   {
      left = mLeft->getValue();
   }
   
   if (mRight)
   {
      right = mRight->getValue();
   }

   mValue = left > right ? left : right;
}

ostream& operator<<(ostream& os, Node* node)
{
   if (node != NULL)
   {
      os << node->getValue() << " ";
      os << node->getLeft();
      os << node->getRight();
   }
   return os;
}

class Tree
{
private:
   static int cNextNodeNumber;
   int mHeight;
   Node* mRoot;
   Node* buildTree(int height)
   {
      Node* root = new Node(cNextNodeNumber++);
      if (height > 0)
      {
         root->setLeft(buildTree(height - 1));
         root->setRight(buildTree(height - 1));
      }
      return root;
   }

public:
   Tree(int height)
   {
      mHeight = height;
      mRoot = buildTree(height);
   }

   void setRoot(Node* node) { mRoot = node;}
   Node* getRoot() { return mRoot; }

   void traversePreorder()
   {
      traverse(mRoot, -1);
   }
   void traverseInorder()
   {
      traverse(mRoot, 0);
   }
   void traversePostorder()
   {
      traverse(mRoot, 1);
   }

   void traverse(Node* node, int tType)
   {
      if (node == NULL) return;
      if (tType == -1)
      {
         visit(node);
      }
      traverse(node->getLeft(), tType);
      if (tType == 0)
      {
         visit(node);
      }
      traverse(node->getRight(), tType);
      if (tType == 1)
      {
         visit(node);
      }
   }

   void visit(Node* node)
   {
      cout << node->getValue() << " ";
   }

   void traverseLevel1()
   {
      const int MAX = 128;
      Node* queue[MAX];
      Node* temp;
      int front = 0;
      int back = 0;

      queue[back++] = mRoot;

      while (front != back)
      {
         temp = queue[front];
         front = (front + 1) % MAX;
         if (temp != NULL)
         {
            cout << temp->getValue() << " ";
            queue[back] = temp->getLeft();
            back = (back + 1) % MAX;
            queue[back] = temp->getRight();
            back = (back + 1) % MAX;
         }
      }
   }

   void traverseLevel2()
   {
      for (int level = 0; level <= mHeight; level++)
      {
         int maxWhich = (int) pow((double) 2, (double) level);
         for (int which = 1; which <= maxWhich; which++)
         {
            visit(findNode(mRoot, level, which));
         }
      }
   }

   Node* findNode(Node* start, int level, int which)
   {
      int maxWhich = (int) pow((double) 2, (double) level);
      int halfway = maxWhich / 2;
      if (level == 0)
      {
         return start;
      }
      if (which > halfway)
      {
         findNode(start->getRight(), level - 1, which);
      }
      else
      {
         findNode(start->getLeft(), level - 1, which - halfway);
      }
   }

   void replaceNode(Node* node ,int value)
   {
      if (node == NULL) return;
      
      if (node->getValue() == value)
      {
         node->setValue(INT_MIN);
      }

      traverse(node->getLeft(), value);
      traverse(node->getRight(), value);
   }
};

ostream& operator<<(ostream& os, Tree& tree)
{
   os << tree.getRoot();
   return os;
}

int Tree::cNextNodeNumber = 0;

/*************************************************************************
 * treeTraversal
 *
 * Makes a tree of specified height, then outputs a printed representation
 * of the tree followed by output from calling the traversal functions:
 * PRE-order, IN-order, POST-order, LEVEL-order and (versions 1 and 2).
 *************************************************************************/
void treeTraversal(int height)
{
   Tree tree(height);
   cout << tree << endl;
   tree.traversePreorder();
   cout << endl;
   tree.traverseInorder();
   cout << endl;
   tree.traversePostorder();
   cout << endl;
   tree.traverseLevel1();
   cout << endl;
   tree.traverseLevel2();
   cout << endl;
}

/*************************************************************************
 * Tournament Sort implemented here.
 *
 * TODO: if you think it will help, add to (but don't subtract from) the
 * above-defined classes, and/or make other helper functions.
 *************************************************************************/
void tournamentSort(int array[], int size)
{

   cout << "Sorting Tree" << endl;
   int height = log2(size);
   Tree * tree = new Tree(height);
   Node * temp;
   Node * temp2;
   cout << "Base nodes: " << endl;
   //set the bottom row of nodes
   for (int i = 0; i < pow(2, height); i++)
   {
      temp = tree->findNode(tree->getRoot(), height, i + 1);
      temp->setValue(array[i]);
      cout << "Base node at height " << height << " position " << i + 1 << " is: " << temp->getValue() << endl;
   }

   for (int i = 0; i < pow(2, height); i++)
   {
      temp2 = tree->findNode(tree->getRoot(), height, i + 1);
      cout << "Node at height " << height << " position " << i + 1 << " should be: " << array[i] << " but is actually: " << temp2->getValue() << endl;  
   }
}



/*************************************************************************
 * What was learned.
 *************************************************************************/
void learned()
{
}

/*************************************************************************
 * How to use this program.
 *************************************************************************/
void usage(const char* programName)
{
}
