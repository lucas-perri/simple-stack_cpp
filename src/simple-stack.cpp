#include <stddef.h>
#include <stdexcept>

using namespace std;

class Node;
class Stack;

class Node
{
private:

    // Value stored in the node
    int _value;

    // Pointer to the next node 
    Node *_next;

public:

    // Returns the value of the node
    const int value(){ return this->_value; }

    // Returns a pointer to the next node
    const Node* next(){ return this->_next; }

    Node(int value, Node *next=nullptr)
    {
        this->_value = value;
        this->_next = next;
    }
    ~Node();
};

class Stack
{
private:

    // Pointer to the node at the top of the stack (or nullptr, if empty)
    Node *_top = nullptr;

    // Integer representing the size of the stack
    size_t _size = 0;

    // Recursively deletes all nodes, starting from to_delete
    void delete_all(Node *to_delete)
    {
        if(to_delete == nullptr) return;
        delete_all((Node *) to_delete->next());
        delete to_delete;
    }

public:

    // Returns the current size of the stack
    const size_t size(){ return this->_size; }

    // Returns whether the stack is empty or not
    const bool empty(){ return this->_size == 0; }

    // Returns the value of the node at the top of the stack
    const int top()
    {
        if(this->empty()) throw underflow_error("Stack is empty!");
        return this->_top->value();
    }

    // Adds a node at the top of the stack
    void push(int value)
    {
        Node *new_node = nullptr;
        try { new_node = new Node(value, this->_top); }
        catch(bad_alloc){ throw; }
        this->_size++;
        if(this->_size == 0) throw overflow_error("Stack is full!");
        this->_top = new_node;
    }
    
    // Removes a node from the top of the stack and returns its value
    int pop()
    {
        if(this->empty()) throw underflow_error("Stack is empty!");
        Node *old_node = this->_top;
        this->_top = (Node *) old_node->next();
        int value = old_node->value();
        delete old_node;
        this->_size--;
        return value;
    }

    Stack();
    ~Stack(){ delete_all(this->_top); }
};

int main(){}