#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

// clase Cola de Prioridad
template <typename ElementType>
class PriorityQueue {
	private:
		// estructura Nodo
		struct Node {
			ElementType element;
			int priority;
			Node *next;

			// constructor
			Node() : next(nullptr) { }

			// constructor con parametros
			Node(
                ElementType element,
                int priority,
                Node *next = nullptr
            ) {
				this->element = element;
				this->priority = priority;
				this->next = next;
			}
		};

		Node *myFront; // frente
		Node *myBack; // final
		int myLength; // longitud de cola

	public:
		// constructor
		PriorityQueue();
		
		// destructor
		~PriorityQueue();

		// encolar elemento
		void enqueue(ElementType, int);

		// desencolar elemento
		void dequeue();

		// obtener frente
		ElementType front() const;

		// vaciar
		void erase();

		// determinar si esta vacio
		bool isEmpty() const;

		// obtener longitud
		int getLength() const;
};

// constructor
template <typename ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
	myFront = myBack = nullptr;
	myLength = 0;
}

// destructor
template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
	erase();
}

// encolar elemento
template <typename ElementType>
void PriorityQueue<ElementType>::enqueue(
    ElementType element,
    int priority
) {
	Node *prev = nullptr; // previo a nuevo elemento
	Node *current = myFront; // elemento actual
	Node *newElement = new Node(element, priority); // nuevo elemento

	// buscar posicion del nuevo elemento
	while(current && newElement->priority >= current->priority) {
		prev = current;
		current = current->next;
	}

	// colocar nuevo elemento antes del actual
	newElement->next = current;

	if (prev) {
		// previo apunta a nuevo elemento
		prev->next = newElement;
	} else {
		// frente es igual a nuevo elemento
		myFront = newElement;
	}

    // aumentar longitud
	myLength++;
}

// desencolar elemento
template <typename ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) return;

    Node *ptr = myFront;
    myFront = myFront->next;
    delete ptr;

    // disminuir longitud
    myLength--;

    // si cola esta vacia
    if (isEmpty()) myBack = nullptr;
}

// obtener frente
template <typename ElementType>
ElementType PriorityQueue<ElementType>::front() const {
	if (isEmpty()) {
		// devolver basura
		ElementType *temp = new(ElementType);
		ElementType garbage = *temp;
		delete temp;
		return garbage;
	}

    return myFront->element;
}

// vaciar
template <typename ElementType>
void PriorityQueue<ElementType>::erase() {
    Node *prev;

    while(!isEmpty()) {
        prev = myFront;
        myFront = myFront->next;
        delete prev;
    }

    myLength = 0;
}

// determinar si esta vacio
template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return myFront == nullptr;
}

// obtener longitud
template <typename ElementType>
int PriorityQueue<ElementType>::getLength() const {
    return myLength;
}

#endif // PRIORITYQUEUE_H
