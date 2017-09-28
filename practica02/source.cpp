#include <iostream>
#include <vector>

template<typename T, int O=1 >
void fExample1(T ono) {
//	O aux = 1;
//	std::cout << aux << std::endl;
}

template<typename T1, typename T2>
class CExample2{
public:
	std::vector<T1> aV;
	T2 myMember;
};

template<typename P>
struct node {
	P info;
	node *pointer;

	node() {
		info = 0;
		pointer = nullptr;
	}

	node(P data) {
		info = data;
	}
};

template<typename Y>
void swap(Y &one, Y &two) {
	Y aux = one;
	one = two;
	two = aux;
}

template <typename T>
class SuperQueue {
public:

	node *myT;
	node *first;
	node *last;
	int size;



	void push(T data) {
		
		myT=new node(data);

		if (first == nullptr && last == nullptr) {			
			first = last = myT;
		}
		else {
			myT->pointer = last;
			last = myT;
		}
		size++;
	}

	int length() {
		return size;
	}

	void pop() {
		if (size != 0) {
			myT = last;
			for (int i = 0; i < size - 1; ++i) {
				if (i != 0)
					myT = myT->pointer;
				if (i == size - 2) {
					delete myT->pointer;
					myT->pointer = nullptr;
					first = myT;
					size--;
					break;
				}
			}
		}
	}

	SuperQueue() {size=0};
	SuperQueue(SuperQueue <T>newQ) {
		size = 0;
		for (int i = 0; i < newQ.length(); ++i) {
			push(newQ.first->info);
			newQ.pop();
			size++;
		}
	}
};

void main() {
	SuperQueue <int> myQ();
	myQ.push(2);


	int m = 0;
}