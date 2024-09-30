#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = nullptr;
    }

    void append(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(20);
    dll.append(30);
    dll.display(); // Output: 10 20 30

    return 0;
}