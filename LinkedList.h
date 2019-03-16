template<class T>
class LinkedList;

template<class T>
class LinkedListNode {
private:
	T head;
	LinkedList<T> tail;

public:
	LinkedListNode(T head, LinkedList<T> tail);

    friend class LinkedList<T>;
};

template<class T>
class LinkedList {
private:
	LinkedListNode<T>* list;

public:
	// first = nullptr
	LinkedList();

	LinkedList(const LinkedList<T>& l);

	~LinkedList();

	LinkedList<T>& operator=(const LinkedList<T>& l);

	// -1 if not found
	int find(T elm);

	bool isEmpty() const;

	// add elm as last element
	void add(T elm);

    // remove the first occurence of element
	void remove(T elm);

	void removeIdx(int idx);

	T get(int idx);

	T& operator[](int idx);

	friend class LinkedListNode<T>;
};

template<class T>
LinkedListNode<T>::LinkedListNode(T head, LinkedList<T> tail) : head{ head }, tail{ tail } {}


template<class T>
LinkedList<T>::LinkedList() : list{ nullptr } {}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) : LinkedList() {
	if (!l.isEmpty()) {
		list = new LinkedListNode<T>{ l.list->head, l.list->tail };
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	if (!isEmpty()) {
		delete list;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& l) {
	if (this != &l) {
		if (!isEmpty()) {
			delete list;
		}
		if (!l.isEmpty()) {
			list = new LinkedListNode<T>{ l.list->head, l.list->tail };
		}
	}
	return *this;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
	return list == nullptr;
}

template<class T>
void LinkedList<T>::add(T elm) {
	if (isEmpty()) {
		list = new LinkedListNode<T>{ elm, LinkedList<T>{} };
	} else {
		list->tail.add(elm);
	}
}

template<class T>
void LinkedList<T>::remove(T elm) {
	if (!isEmpty()) {
		if (elm == list->head) {
			LinkedList<T> temp{ list->tail };
			operator=(temp);
		} else {
			list->tail.remove(elm);
		}
	}
}

template<class T>
void LinkedList<T>::removeIdx(int idx) {
	if (idx < 0) {
		throw "Index is out of bounds";
	}
	if (!isEmpty()) {
		if (idx == 0) {
			LinkedList<T> temp{ list->tail };
			operator=(temp);
		} else {
			list->tail.remove(idx - 1);
		}
	}
	else {
		throw "Index is out of bounds";
	}
}

template <class T>
T LinkedList<T>::get(int idx) {
	if (idx < 0) {
		throw "Index is out of bounds";
	}
	if (!isEmpty()) {
		if (idx == 0) {
			return list->head;
		} else {
			return list->tail.get(idx - 1);
		}
	} else {
		throw "Index is out of bounds";
	}
}

template <class T>
T& LinkedList<T>::operator[](int idx) {
	if (idx < 0) {
		throw "Index is out of bounds";
	}
	if (!isEmpty()) {
		if (idx == 0) {
			return list->head;
		}
		else {
			return list->tail[idx-1];
		}
	}
	else {
		throw "Index is out of bounds";
	}
}
