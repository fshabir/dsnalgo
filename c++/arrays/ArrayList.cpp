#include <iostream>

using namespace std;

class ArrayList {
private:
	size_t size;
	size_t capacity;
	int * array;

public:
	ArrayList(size_t _capacity=1) {
		size = 0;
		capacity = _capacity;
		array = new int[_capacity];
	}

	int append(int elm) {
		if (size >= capacity) {
			bool successful = resize();
			if (!successful) {
				return -1; //Error flag indicating unable to resize
			}
		}

		array[size++] = elm;
		return elm;
	}

	size_t getCapacity() {
		return capacity;
	}

	size_t getSize() {
		return size;
	}

	void print() {
		cout << "ArrayList: " << endl;
		for(size_t i=0; i<size; i++) {
			cout << array[i] << "  ";
		}
		cout << endl;
	}

	int operator[](size_t index){
		if (index < size) {
			return array[index];
		} else {
			return -1;
		}
	}

	bool resize() {
		try {
			capacity = capacity * 2;
			int * newArray = new int[capacity];

			for (size_t i=0; i<size; i++) {
				newArray[i] = array[i];
			}

			delete []array;
			array = newArray;
			return true;
		} catch (std::bad_alloc&) {
			return false;
		}
	}

	~ArrayList() {
		delete []array;
	}
};

int main() {
	ArrayList list;
	list.append(34);
	list.append(2);
	list.append(24);
	list.append(4);
	list.append(5);
	list.print();

	cout << "Size: " << list.getSize() << endl;
	cout << "Capacity: " << list.getCapacity() << endl;
	cout << "3rd Element is: " << list[2] << endl;
	return 0;
}