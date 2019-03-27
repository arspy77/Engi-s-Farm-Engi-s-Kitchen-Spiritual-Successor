#include <initializer_list>


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

		/** Mengembalikan apakah list empty atau tidak */
		bool isEmpty() const;

		/** Menambah elm sebagai elemen terakhir */
		void add(T elm);

		/** Menghapus keberadaan pertama elm */
		void remove(T elm);

		/**
		 *  Menghapus elemen berindeks idx.
		 *  Jika diluar range, melempar "Index is out of bounds".
		 */
		void removeIdx(int idx);

		/**
		 *  Mengembalikan elemen berindeks idx.
		 * Jika diluar range, melempar "Index is out of bounds".
		 */
		T get(int idx);

		/**
		 *  Mengembalikan reference ke elemen berindeks idx.
		 *  Jika diluar range, melempar "Index is out of bounds".
		 */
		T& operator[](int idx);

	private:
		/** Pointer ke LinkedListNode, kalau empty bernilai nullptr */
		LinkedListNode<T>* list;
};

/** Anggota kelas implementasi LinkedList secara rekursifs */
template<class T>
class LinkedListNode {
public:
	/** Konstruktor LinkedListNode dengan initializer list */ 
	LinkedListNode(T head, LinkedList<T> tail);

	/** Membuat LinkedList dapat mengakses head dan tail */
    friend LinkedList<T>;

private:
	/** Tipe data pertama pada LinkedListNode */
	T head;

	/** Sisa dari LinkedListNode berupa LinkedList */
	LinkedList<T> tail;
};

template<class T>
LinkedList<T>::LinkedList() : list{ nullptr } {}

template<class T>
LinkedList<T>::LinkedList(std::initializer_list<T> args) : LinkedList() {
	for (auto i = args.begin(); i != args.end(); ++i) {
        add(*i);
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& l) {
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
			/** Membuat list temp berisi tail untuk dipindahkan ke list sekarang */
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
			/** Membuat list temp berisi tail untuk dipindahkan ke list sekarang */
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

template<class T>
LinkedListNode<T>::LinkedListNode(T head, LinkedList<T> tail) : head{ head }, tail{ tail } {}

#endif