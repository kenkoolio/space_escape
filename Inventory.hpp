
/********************************************************************* 
** Program name: Inventory.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 10:32 PM
** Description: Class specification file for Inventory. Inventory is
 *              a container, implemented as a linked-list structured
 *              in a queue container adapter pattern. It is used by
 *              your character to carry items (pointers to items) in
 *              the Space Escape game. An inventory's maximum
 *              capacity is 15.
*********************************************************************/


#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "Item.hpp"

class Inventory
{
private:
    //node for linked-list
    struct InventoryNode
    {
        Item *val;
        InventoryNode *next;

        //node constructor
        InventoryNode(Item *val = nullptr, InventoryNode *next = nullptr)
                    : val(val), next(next)
        {}
    };

    const int LIMIT;
    InventoryNode *head;

public:

    /********************************************************************
    ** Function: Constructor/default: Creates an Inventory object, sets
     *              LIMIT, and sets head to nullptr.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    Inventory();


    /********************************************************************
    ** Function: Destructor: Deletes all nodes in the Inventory
     *              linked-list, and the item that the node contains.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    ~Inventory();


    /********************************************************************
    ** Function: push: Adds a node to the back of the linked-list queue.
     *              Checks if queue is already at capacity before adding
     *              to queue.
    ** Params:   Item *value: Pointer to item object to add to queue.
    ** Returns:  None
    *********************************************************************/
    void push(Item *value);


    /********************************************************************
    ** Function: pop: Deletes item pointer contained in the front node,
     *              then removes and deletes the front node.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void pop();


    /********************************************************************
    ** Function: find: Searches your inventory and returns a pointer to
     *              the item. If not found, returns nullptr.
    ** Params:   int index: 1-based index of the items in the linked-list
     *              queue. 
    ** Returns:  Item *: pointer to item at specified index of the queue.
    *********************************************************************/
    Item *find(int index);
    
    
    /********************************************************************
    ** Function: Counts the number of items of a specific type in your
     *              inventory.
    ** Params:   ItemType type: type of item to count.
    ** Returns:  int: count of specified item.
    *********************************************************************/
    int count(ItemType type) const;


    /********************************************************************
    ** Function: size: Iterates through the inventory linked-list and
     *              returns a count of how many nodes are present.
    ** Params:   None
    ** Returns:  int: size of inventory queue.
    *********************************************************************/
    int size() const;
    
    
    /********************************************************************
    ** Function: empty: Checks if the queue is empty.
    ** Params:   None
    ** Returns:  bool: True if queue is empty, false otherwise.
    *********************************************************************/
    bool empty() const;


    /********************************************************************
    ** Function: print: Iterates through the queue, and prints each
     *              item's name and index.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void print() const;

};

#endif
