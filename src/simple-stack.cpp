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
    // Returns the value stored in the node
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

int main(){}