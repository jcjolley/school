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
 ***********************************************************************/

#include <cmath>
#include <climits> // for INT_MIN
#include <iostream>
#include <iomanip>
#include <cassert>

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
   void setValue(int value) {mValue = value;}
   Node* getLeft() { return mLeft; }
   void setLeft(Node* inLeft) { mLeft = inLeft; }
   Node* getRight() { return mRight; }
   void setRight(Node* inRight) { mRight = inRight; }
   void setMax();
};

void Node::setMax() {
   assert(mLeft != NULL);
   assert(mRight != NULL);
   
   int left = mLeft->getValue();
   int right = mRight->getValue();   
 
   if (left > right)
      mValue = left;
   else
      mValue = right;
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

   /***************************************************************************
   * Finds the node at the specified level and "which" (position from the left)
   ***************************************************************************/   
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
         findNode(start->getRight(), level - 1, which - halfway);
      }
      
      else
      {
         findNode(start->getLeft(), level - 1, which);
      }
   }

   /***************************************************************************
   * Replaces the specified value with INT_MIN whenever it is found in the tree
   ***************************************************************************/
   void replaceNodeValue(Node * node, int value)
   {
      if (node == NULL) 
      {
            return;
      }
      
      if (node->getValue() == value)
      {
         node->setValue(INT_MIN);
      }

      replaceNodeValue(node->getLeft(), value);
      replaceNodeValue(node->getRight(), value);  
   }

   /************************************
   * Prints a tree of height 4 in a pretty manner
   *******************************/
   void printTree(int height)
   {
      int fill = 62;
      int level = 0;
      while (level <= height)
      {
         cout << setw(fill) << "";
         for (int i = 0; i < pow(2, level); i++)
         {
            cout << setw(2) << findNode(mRoot, level, i + 1)->getValue();
            for (int i = 0; i < fill * 2 + 6; i++)
               cout << " ";
         }
         cout << endl;
         level++;
         fill = (fill / 2) - 2;
      }
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
 *************************************************************************/
void tournamentSort(int array[], int size)
{
   int height = log2(size);
   int const trueHeight = height;
   int const trueSize = size;
   Tree tree = Tree(height);
  
   //Set the values for the leaf nodes
   for(int i = 0; i < size; i++)
   {
      Node * temp = tree.findNode(tree.getRoot(), height, i + 1);
      temp->setValue(array[i]);
   }

   //Run the sort once for each leaf node
   for (int j = 0; j < trueSize; j++)
   {
      height = trueHeight;
      size = trueSize;

      //This is the sort. It bubbles the max of children up the tree
      //one node at a time.  It starts at the parents of leaves.
      while(height >= 0)
      {
         height--;
         size /= 2;

         //For each node on this level set the value to the max of its children
         for (int i = 0; i < size; i++)
         {
            Node * temp = tree.findNode(tree.getRoot(), height, i + 1);
            temp->setMax();
         }
      }

      //Put the winning value in the array
      array[j] = tree.getRoot()->getValue();

      //replace the winning value with INT_MIN
      tree.replaceNodeValue(tree.getRoot(), array[j]);
   }
}

/*************************************************************************
 * What was learned.
 *************************************************************************/
void learned()
{
   cout << "This was a fun exploration!  It took me a while to find the\n"
        << "relationship between which and halfway in the findNode function.\n"
        << "After I figured that out, the rest of the problem wasn't too\n"
        << "difficult.  I payed it forward and wrote a printTree method in\n"
        << "the Tree class which displays the tree we're building in an easy\n"
        << "to follow way.  This exploration also reinforced to me the value\n"
        << "of persistence.  It was tempting to guess and check a bunch of\n"
        << "code while trying to solve this, but by sticking with concepts\n"
        << "and my white board I believe I tackled the problem much more\n"
        << "quickly than I would have otherwise.\n";
}

/*************************************************************************
 * How to use this program.
 *************************************************************************/
void usage(const char* programName)
{
   cout << "USAGE: " << programName << "<treet|tsort|all>\n";
   cout << "    treet: Traverse the tree in each order\n";
   cout << "    tsort: Tournament sort a hard coded tree\n";
   cout << "    all:   Run both treet and tsort\n";
}
