
/*********************************************************************
** Program name: Inventory.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 10:32 PM
** Description: Class implementation file for Inventory. Inventory is
 *              a container, implemented as a linked-list structured
 *              in a queue container adapter pattern. It is used by
 *              your character to carry items (pointers to items) in
 *              the Space Escape game. An inventory's maximum
 *              capacity is 15.
*********************************************************************/


#include "Inventory.hpp"

using std::cout;
using std::endl;

/********************************************************************
** Function: Constructor/default: Creates an Inventory object, sets
 *              LIMIT, and sets head to nullptr.
** Params:   None
** Returns:  None
*********************************************************************/
Inventory::Inventory() : LIMIT(15), head(nullptr)
{}


/********************************************************************
** Function: Destructor: Deletes all nodes in the Inventory
 *              linked-list, and the item that the node contains.
** Params:   None
** Returns:  None
*********************************************************************/
Inventory::~Inventory()
{
    while (!empty())
    {
        //remove and delete the node and the item pointer
        pop();
    }
}


/********************************************************************
** Function: push: Adds a node to the back of the linked-list queue.
 *              Checks if queue is already at capacity before adding
 *              to queue.
** Params:   Item *value: Pointer to item object to add to queue.
** Returns:  None
*********************************************************************/
void Inventory::push(Item *value)
{
    //add to inventory queue if it is not at capacity
    if (size() < LIMIT)
    {
        if (empty())
        {
            //if list is empty add it to the head
            head = new InventoryNode(value);
        }
        else
        {
            //if list is not empty, add it to the back of the queue
            InventoryNode *cursor = head;
            while (cursor->next)
            {
                cursor = cursor->next;
            }
            cursor->next = new InventoryNode(value);
        }
    }
    else
    {
        cout << "Your inventory is full!" << endl;
    }
}


/********************************************************************
** Function: pop: Deletes item pointer contained in the front node,
 *              then removes and deletes the front node.
** Params:   None
** Returns:  None
*********************************************************************/
void Inventory::pop()
{
    //delete the item pointer
    delete head->val;

    //remove the first node and point head to the next node
    InventoryNode *garbage = head;
    head = head->next;
    delete garbage;
}


/********************************************************************
** Function: find: Searches your inventory and returns a pointer to
 *              the item. If not found, returns nullptr.
** Params:   int index: 1-based index of the items in the linked-list
 *              queue.
** Returns:  Item *: pointer to item at specified index of the queue.
*********************************************************************/
Item *Inventory::find(int index)
{
    if (!empty())
    {
        int counter = 1;
        InventoryNode *cursor = head;

        //traverse the queue and return the item at specified index
        while (cursor)
        {
            if (counter == index)
            {
                return cursor->val;
            }
            counter++;
            cursor = cursor->next;
        }
    }

    //wasn't found or the queue is empty, return nullptr
    return nullptr;
}


/********************************************************************
** Function: Counts the number of items of a specific type in your
 *              inventory.
** Params:   ItemType type: type of item to count.
** Returns:  int: count of specified item.
*********************************************************************/
int Inventory::count(ItemType type) const
{
    //initialize counter
    int counter = 0;

    //check queue if it is not empty
    if (!empty())
    {
        InventoryNode *cursor = head;

        //iterate through the queue to count the item
        while (cursor)
        {
            //if this item is the target item,
            // increment the count of the item by 1
            if (cursor->val->getType() == type)
            {
                counter++;
            }

            //move down the queue
            cursor = cursor->next;
        }
    }

    //return the count
    return counter;
}


/********************************************************************
** Function: size: Iterates through the inventory linked-list and
 *              returns a count of how many nodes are present.
** Params:   None
** Returns:  int: size of inventory queue.
*********************************************************************/
int Inventory::size() const
{
    //initialize counter
    int counter = 0;

    //if queue is not empty, proceed to count the nodes
    if (!empty())
    {
        InventoryNode *cursor = head;

        //iterate through the queue and count the nodes
        while (cursor)
        {
            //valid node, increment counter
            counter++;

            //move down the queue
            cursor = cursor->next;
        }
    }

    //return the counter
    return counter;
}


/********************************************************************
** Function: empty: Checks if the queue is empty.
** Params:   None
** Returns:  bool: True if queue is empty, false otherwise.
*********************************************************************/
bool Inventory::empty() const
{
    return head == nullptr;
}


/********************************************************************
** Function: print: Iterates through the queue, and prints each
 *              item's name and index.
** Params:   None
** Returns:  None
*********************************************************************/
void Inventory::print() const
{
    //if queue is not empty, print the items in the queue
    if (!empty())
    {
        //initialize index of item
        int index = 0;
        InventoryNode *cursor = head;

        //iterate through the queue and print the index and item names
        while (cursor)
        {
            //increment and print the index
            cout << ++index << ": ";

            //print the item's name
            cout << cursor->val->getName() << endl;

            //move down the queue
            cursor = cursor->next;
        }
    }
    else
    {
        cout << "Your inventory is empty!" << endl;
    }
}
