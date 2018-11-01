#if !defined(LIST)
#define LIST

#include <iostream>

template <class T>
class Observer
{
  public:
    virtual void next(T value, int index) = 0;
};

template <class T>
struct Node
{
    T value;
    Node<T> *next;
};

template <class T>
class List
{
  public:
    Node<T> *head;

    List()
    {
        head = NULL;
    };
    List(T data)
    {
        head = new Node<T>;
        head->value = data;
        head->next = NULL;
    };
    ~List()
    {
        free(head);
    };

    void append(T data);
    void prepend(T data);
    T *shift();
    T *pop();
    void forEach(Observer<T> *observer);
    bool find(T *dest, bool callback(T value, int index));
    void display(std::string callback(T value, int index));
    bool includes(T data);
};

template <class T>
void List<T>::prepend(T data)
{
    if (head == NULL)
    {
        head = new Node<T>;
        head->value = data;
        head->next = NULL;
        return;
    }
    else
    {
        Node<T> *temp = new Node<T>;
        temp = head;

        Node<T> *node = new Node<T>;
        node->value = data;
        node->next = temp;

        head = node;
    }
};

template <class T>
T *List<T>::shift()
{
    if (head != NULL)
    {
        Node<T> *temp = new Node<T>;
        Node<T> *node = new Node<T>;
        temp = head;

        if (temp->next != NULL)
        {
            node->value = temp->next->value;
            node->next = temp->next->next;
        }
        else
        {
            node->next = NULL;
        }

        head = node;

        return &temp->value;
    }
    else
    {
        return nullptr;
    }
};

template <class T>
T *List<T>::pop()
{
    if (head != NULL)
    {
        Node<T> *temp = new Node<T>;
        Node<T> *node = new Node<T>;
        temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }

        node = temp->next;
        temp->next = NULL;

        return &node->value;
    }
    else
    {
        return nullptr;
    }
};

template <class T>
void List<T>::append(T data)
{
    if (head == NULL)
    {
        head = new Node<T>;
        head->value = data;
        head->next = NULL;
        return;
    }
    else
    {
        Node<T> *temp = new Node<T>;
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node<T> *node = new Node<T>;
        node->value = data;
        node->next = NULL;

        temp->next = node;
    }
};

template <class T>
bool List<T>::find(T *dest, bool callback(T value, int index))
{
    Node<T> *temp = new Node<T>;
    temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (callback(temp->value, i))
        {
            *dest = temp->value;
            return true;
        }

        temp = temp->next;
        i++;
    }

    return false;
};

template <class T>
void List<T>::forEach(Observer<T> *observer)
{
    Node<T> *temp = new Node<T>;
    temp = head;
    int i = 0;

    while (temp != NULL)
    {
        observer->next(temp->value, i);
        temp = temp->next;
        i++;
    }
};

template <class T>
void List<T>::display(std::string callback(T value, int index))
{
    Node<T> *temp = new Node<T>;
    temp = head;
    int i = 0;

    while (temp != NULL)
    {
        std::cout << callback(temp->value, i) << std::endl;
        temp = temp->next;
        i++;
    }
};

template <class T>
bool List<T>::includes(T data)
{
    bool exists = false;
    Node<T> *temp = new Node<T>;
    temp = head;

    while (temp != NULL)
    {
        if (data == temp->value)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
};

#endif // LIST
