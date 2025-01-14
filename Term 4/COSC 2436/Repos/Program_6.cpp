/*
Name: Patrick Ignaut W211197397

Date: 10/29/24

Explanation: The program creates a struct to hold the values of a list node ListNode, outlines the design of a singlely linked list LinkedList, and demonstrates its
member functions in the main function. The class can copy construct lists, add nodes, check for a certain node value, remove nodes, and reverse the order of the list.
*/

#include <iostream>


struct ListNode
{
    double value {0.0};
    ListNode* next {nullptr};
};

class LinkedList
{
private:
    ListNode* head{nullptr};

public:
    // Default constructor
    LinkedList() { }
    // Copy constructor
    LinkedList(const LinkedList& v)
    {
        // Return early if it's an empty list
        if (v.head == nullptr)
        {
            head = nullptr;
            return;
        }

        head = new ListNode;
        head->value = v.head->value;

        ListNode* current {v.head->next};
        ListNode* copy {head};

        while (current != nullptr)
        {
            // Create a node and copy into is
            ListNode* temp {new ListNode};
            temp->value = current->value;
            copy->next = temp;

            // Move to the next nodes
            copy = temp;
            current = current->next;
        }
    }
    // Destructor
    ~LinkedList()
    {
        ListNode* temp {head};
        while (temp != nullptr)
        {
            ListNode* nextNode {temp->next};
            delete temp;
            temp = nextNode;
        }
    }
    // Adds a new node containing v to the front (head) of the list
    void add(double v)
    {
        ListNode* addedListNode {new ListNode};
        addedListNode->value = v;

        addedListNode->next = head;
        head = addedListNode;
    }
    // Searches if the list has a node with the given value
    bool isMember(double v)
    {
        ListNode* temp;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->value == v)
            {
                std::cout << "Value found!" << std::endl;
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        std::cout << "Value not found." << std::endl;
        return false;
    }
    // Same as above but done recursively
    bool isMemberRecursive(double v, ListNode* node = nullptr)
    {
        if (node == nullptr) 
        {
            node = head;
        }
        if (node == nullptr) 
        {
            std::cout << "Value not found." << std::endl;
            return false;  // Reached end of list
        }
        if (node->value == v)
        {
            std::cout << "Value found!" << std::endl;
            return true;
        }

        return isMemberRecursive(v, node->next);
    }
    // Prints all the values in this list
    void print()
    {
        ListNode* temp {head};
        std::cout << std::endl;
        while (temp != nullptr)
        {
            std::cout << "Node value: " << temp->value << '\n';
            temp = temp->next;
        }
    }
    // Finds and removes a node from the list that holds the same value
    void remove(double v)
    {
        // Check for the end of the list
        ListNode* temp {head};
        ListNode* prev {nullptr};

        while (temp != nullptr)
        {
            if (temp->value == v)
            {
                if (prev == nullptr)
                {
                    // Removing head
                    head = temp->next;
                }
                else
                {
                    // Removing non-head
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        std::cout << "Value not found." << std::endl;
    }
    // Reverses the order of the list
    void reverse()
    {
        // Create variables to keep track of pointers
        ListNode* prev {nullptr};
        ListNode* current {head};
        ListNode* next {nullptr};

        // Swap the next and prev in the current to reverse the pointing order
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};


int main()
{
    LinkedList list;

    list.add(2.2);
    list.add(5.6);
    list.add(9.3);

    list.print();

    list.isMember(2.2);
    list.isMember(2.8);

    list.remove(9.3);

    list.print();

    list.reverse();

    list.print();

    return 0;
}