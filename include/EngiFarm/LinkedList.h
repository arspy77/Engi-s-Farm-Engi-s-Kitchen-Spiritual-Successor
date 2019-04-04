#include <initializer_list>
#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/** Forward declaration dari kelas LinkedListNode */
template<class T>
class LinkedListNode;

/** Tipe data LinkedList, diimplementasi secara rekursif dengan LinkedListNode */
template<class T>
class LinkedList {
	public:
		/** Konstruktor default LinkedList, membuat empty list */
		LinkedList();

		/** Konstruktor dengan initializer list */
		LinkedList(std::initializer_list<T> args);

		/** Copy constructor LinkedList */
		LinkedList(const LinkedList<T>& l);

		/** Destructor LinkedList */
		~LinkedList();

		/** Operator= LinkedList */
		LinkedList<T>& operator=(const LinkedList<T>& l);

		/** 
		 *  Mencari indeks pertama dari elm dari LinkedList.
		 *  Jika tidak ada, bernilai -1.
		 */
		int find(T elm);
		int findPointer(T elm);

		/** Mengembalikan apakah list empty atau tidak */
		bool isEmpty() const;

		/** Menambah elm sebagai elemen terakhir */
		void add(T elm);

		/** Menghapus keberadaan pertama elm */
		void remove(T elm);

		/**
		 *  Menghapus elemen berindeks idx.
		 *  Jika diluar range, melempar "Index out of range".
		 */
		void removeIdx(int idx);

		/**
		 * Mengembalikan elemen berindeks idx.
		 * Jika diluar range, melempar "Index out of range".
		 */
		T& get(int idx);

		/**
		 *  Mengembalikan reference ke elemen berindeks idx.
		 *  Jika diluar range, melempar "Index out of range".
		 */
		T& operator[](int idx);

		/** Menampilkan isi dar list ke layar */
		void print();

		/** Mengembalikan panjang dari list */
		int len();
	private:
		/** Pointer ke LinkedListNode, kalau empty bernilai nullptr */
		LinkedListNode<T>* first;
};

/** Anggota kelas implementasi LinkedList secara rekursifs */
template<class T>
class LinkedListNode {
	public:
		/** Konstruktor LinkedListNode dengan argume, deafult tail = nullptr */ 
		LinkedListNode(T _head, LinkedListNode<T>* _next = nullptr);

		/** dtor */
		~LinkedListNode();

		/** Membuat LinkedList dapat mengakses head dan tail */
		friend LinkedList<T>;

	private:
		/** Tipe data pertama pada LinkedListNode */
		T head;

		/** Pointer yang menghubungkan ke Node lainnya */
		LinkedListNode<T>* next;
};

template<class T>
LinkedListNode<T>::LinkedListNode(T _head, LinkedListNode<T>* _next) {
	head = _head;
	next = _next;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
	delete next; //Will recursively call LinkedListNode<T>::~LinkedListNode(), BE CAREFULL
}

template<class T>
LinkedList<T>::LinkedList() {
	first = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(std::initializer_list<T> args) : LinkedList() {
	for (auto i = args.begin(); i != args.end(); ++i) {
        add(*i);
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L2) : LinkedList() {
	LinkedListNode<T>* currNode;
	if (!L2.isEmpty()) {
		currNode = L2.first;
		while(currNode != nullptr) {
			add(currNode->head);
			currNode = currNode->next;
		}
	} else {
		first = nullptr;
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	if (!isEmpty()) {
		delete first; //Will recursively call LinkedListNode<T>::~LinkedListNode() BE CAREFULL
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L2) {
	LinkedListNode<T>* currNode;
	first = nullptr;
	if (!L2.isEmpty()) {
		currNode = L2.first;
		while(currNode != nullptr) {
			add(currNode->head);
			currNode = currNode->next;
		}
	} else {
		first = nullptr;
	}
	return *this;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
	return first == nullptr;
}

template<class T>
void LinkedList<T>::print() {
	LinkedListNode<T>* currNode;
	currNode = first;
	while (currNode != nullptr) {
		std::cout << currNode->head << " ";
		currNode = currNode->next;
	}
}

template<class T>
void LinkedList<T>::add(T elm) {
	if (isEmpty()) {
		first = new LinkedListNode<T>(elm);
	} else {
		LinkedListNode<T>* currNode;
		currNode = first;
		while (currNode->next != nullptr) {
			currNode = currNode->next;
		} // Last node found
		currNode->next = new LinkedListNode<T>(elm);
	}
}

template<class T>
void LinkedList<T>::remove(T elm) {
	LinkedListNode<T>* deletedNode;
	int idx = 0;
	deletedNode = first;
	while (deletedNode != nullptr && deletedNode->head != elm) {
		deletedNode = deletedNode->next;
		idx++;
	}
	if (deletedNode == nullptr) {
		throw "element not found";
	} else {
		removeIdx(idx);
	}
}

template<class T>
int LinkedList<T>::find(T elm) {
	LinkedListNode<T>* currNode;
	currNode = first;
	int idx = 0;
	while (currNode != nullptr && currNode->head != elm) {
		currNode = currNode->next;
		idx++;
	}
	if (currNode == nullptr) {
		return -1;
	} else {
		return idx;
	}
}

template<class T>
int LinkedList<T>::findPointer(T elm) {
	LinkedListNode<T>* currNode;
	currNode = first;
	int idx = 0;
	while (currNode != nullptr && *(currNode->head) != *elm) {
		currNode = currNode->next;
		idx++;
	}
	if (currNode == nullptr) {
		return -1;
	} else {
		return idx;
	}
}

template<class T>
void LinkedList<T>::removeIdx(int idx) {
	LinkedListNode<T>* deletedNode; 
	LinkedListNode<T>* prevNode;
	if (idx < 0 || idx >= len()) {
		throw "Index out of range";
	} else if (len() == 1) {
		deletedNode = first;
		delete deletedNode;
		first = nullptr;
	} else if (idx == 0) {
		deletedNode = first;
		first = deletedNode->next;
		deletedNode->next = nullptr;
		delete deletedNode;
	} else {
		deletedNode = first;
		while (idx > 0) {
			deletedNode = deletedNode->next;
			idx--;
		} //deletedNode found
		prevNode = first;
		while (prevNode->next != deletedNode) {
			prevNode = prevNode->next;
		} //prevNode found
		prevNode->next = deletedNode->next;
		deletedNode->next = nullptr;
		delete deletedNode;
	}
}

template <class T>
int LinkedList<T>::len() {
	LinkedListNode<T>* currNode;

	int i = 0;
	currNode = first;
	while (currNode != nullptr) {
		currNode = currNode->next;
		i++;
	}
	return i;
}

template <class T>
T& LinkedList<T>::get(int idx) {
	LinkedListNode<T>* currNode;
	currNode = first;
	if (idx < 0 || idx >= len()) {
		throw "Index out of range";
	} else {
		while (idx > 0) {
			currNode = currNode->next;
			idx--;
		} 
		return currNode->head;
	}	
}

template <class T>
T& LinkedList<T>::operator[](int idx) {
	return get(idx);
}
#endif