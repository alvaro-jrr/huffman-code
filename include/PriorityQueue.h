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

		Node *head; // frente
		Node *tail; // final
		int length; // longitud de cola

	public:
		// constructor
		PriorityQueue();

		// destructor
		~PriorityQueue();

		// insertar elemento
		void insert(ElementType, int);

		// obtener minimo
		ElementType min() const;

		// obtener maximo
		ElementType max() const;

		// remover minimo
		void removeMin();

		// remover maximo
		void removeMax();

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
	head = tail = nullptr;
	length = 0;
}

// destructor
template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
	erase();
}

// encolar elemento
template <typename ElementType>
void PriorityQueue<ElementType>::insert(
    ElementType element,
    int priority
) {
	Node *prev = nullptr; // previo a nuevo elemento
	Node *current = head; // elemento actual
	Node *newElement = new Node(element, priority); // nuevo elemento

	// buscar posicion del nuevo elemento
	while(current && newElement->priority > current->priority) {
		prev = current;
		current = current->next;
	}

	// si esta vacio, la cola es nuevo elemento
	if (isEmpty()) tail = newElement;

	// colocar nuevo elemento antes del actual
	newElement->next = current;

	if (prev) {
		// previo apunta a nuevo elemento
		prev->next = newElement;

        // avanzar cola
		if (prev == tail) tail = tail->next;
	} else {
		// frente es igual a nuevo elemento
		head = newElement;
	}

	// aumentar longitud
	length++;
}

// obtener minimo
template <typename ElementType>
ElementType PriorityQueue<ElementType>::min() const {
    if (isEmpty()) {
		// devolver basura
		ElementType *temp = new(ElementType);
		ElementType garbage = *temp;
		delete temp;
		return garbage;
	}

	return head->element;
}

// obtener maximo
template <typename ElementType>
ElementType PriorityQueue<ElementType>::max() const {
    if (isEmpty()) {
		// devolver basura
		ElementType *temp = new(ElementType);
		ElementType garbage = *temp;
		delete temp;
		return garbage;
	}

	return tail->element;
}

// remover minimo
template <typename ElementType>
void PriorityQueue<ElementType>::removeMin() {
    if (isEmpty()) return;

	Node *ptr = head;
	head = head->next;
	delete ptr;

	// disminuir longitud
	length--;

	// si cola esta vacia
	if (isEmpty()) tail = nullptr;
}

// remover maximo
template <typename ElementType>
void PriorityQueue<ElementType>::removeMax() {
    if (isEmpty()) return;

    Node *ptr = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        Node *prev;
        prev = ptr = head;

        while(ptr->next) {
            prev = ptr;
            ptr = ptr->next;
        }

        // actualizar ultimo elemento
        tail = prev;
        prev->next = nullptr;
    }

    // disminuir longitud
    length--;
}

// vaciar
template <typename ElementType>
void PriorityQueue<ElementType>::erase() {
	Node *prev;

	while(!isEmpty()) {
		prev = head;
		head = head->next;
		delete prev;
	}

	length = 0;
}

// determinar si esta vacio
template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
	return head == nullptr;
}

// obtener longitud
template <typename ElementType>
int PriorityQueue<ElementType>::getLength() const {
	return length;
}

#endif // PRIORITYQUEUE_H
