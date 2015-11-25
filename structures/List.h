
template <typename T>
class Node {
    private:
    public:
        T data;
        Node *next;
        Node(T data, Node *next = nullptr) {
            this->data = data;
            this->next = next;
        }
};

template <typename T>
class List {
public:

    List();
    ~List();
    T front();
    T back();
    int size();
    bool empty();
    Node<T> *getHead();
    T getMinElement();

    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();

private:
    Node<T> *head;
    Node<T> *tail;
    int countNodes;
};


template <typename T>
List<T>::List() {
    this->countNodes = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
List<T>::~List() {
    while(!this->empty()) {
        this->pop_front();
    }
}

template <typename T>
T List<T>::front() {
    return head->data;
}

template <typename T>
T List<T>::back() {
    return tail->data;
}

template <typename T>
int List<T>::size() {
    return countNodes;
}

template <typename T>
bool List<T>::empty() {
    return !size();
}

template <typename T>
Node<T> *List<T>::getHead() {
    return head;
}

template <typename T>
T List<T>::getMinElement() {
    T min = this->head->data;
    Node<T> *next = this->head->next;
    while(next != nullptr) {
        if(next->data < min)
            min = next->data;
        next = next->next;
    }
    return min;
}


template <typename T>
void List<T>::push_front(T data) {
    Node<T> *newHead = new Node<T>(data, this->head);
    this->head = newHead;

    if(this->empty())
        tail = head;
    ++countNodes;
}

template <typename T>
void List<T>::push_back(T data) {
    Node<T> *newTail = new Node<T>(data, nullptr);
    if(!this->empty())
        this->tail.next = newTail;
    else
        head = newTail;
    tail = newTail;
    ++countNodes;
}

template <typename T>
void List<T>::pop_front() {
    if(empty()) return;
    
    Node<T> *oldHead = head;
    if(this->size() == 1) {
        this-> head = nullptr;
        this-> tail = nullptr;
    }
    else {
        head = head->next;
    }
    delete oldHead;
    --countNodes;
}
