#include <iostream>

using namespace std;

class Matrix {
private:
	size_t length;
	size_t width;
	size_t capacity_length;
	size_t capacity_width;
	int ** array;
public:
	Matrix(size_t capacity_length=1, size_t capacity_width=1) {
		this->length = 0;
		this->width = 0;
		this->capacity_length = capacity_length;
		this->capacity_width = capacity_width;

		// 1 x 1 array
		this->array = new int*[capacity_length];

		for (size_t i=0; i < capacity_length; i++) {
			this->array[i] = new int[capacity_width];
		}
	}

	void resize(bool resizeLength = true, bool resizeWidth = true) {
		if (resizeLength) {
			this->capacity_length = this->capacity_length * 2;
		}

		if (resizeWidth) {
			this->capacity_width = this->capacity_width * 2;
		}

		int ** newArray = new int *[capacity_length];
		for (size_t i=0; i<capacity_length; i++) {
			newArray[i] = new int[capacity_width];
		}

		for (size_t i=0; i<length; i++) {
			for (size_t j=0; j<width; j++) {
				newArray[i][j] = this->array[i][j];
			}
		}

		for (size_t i=0; i<length; i++) {
			delete [] this->array[i];
		}

		delete [] this->array;

		this->array = newArray;
	}

	bool insert(size_t i, size_t j, int val) {
		try {
			if (i >= length) {
				this->resize(true, false);
			}

			if (j >= width) {
				this->resize(false, true);
			}

			this->array[i][j] = val;
			if (i > length) {
				length = i+1;
			} else if ( i == length) {
				length++;
			}

			if (j > width) {
				width = j+1;
			} else if ( j == width) {
				width++;
			}
			return true;
		} catch (std::bad_alloc) {
			cout << "Bad allocation" << endl;
			return false;
		}
	}

	void print() {
		for (size_t i=0; i<length; i++) {
			for (size_t j=0; j<width; j++) {
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	~Matrix() {
		if (array) {
			for(size_t i=0; i < capacity_length; i++) {
				delete [] array[i];
			}

			delete [] array;
		}
	}
};

int main() {
	Matrix matrix;
	matrix.insert(0, 0, 1);
	matrix.insert(0, 1, 2);
	matrix.insert(0, 2, 3);

	matrix.insert(1, 0, 4);
	matrix.insert(1, 1, 5);
	matrix.insert(1, 2, 6);

	matrix.insert(2, 0, 7);
	matrix.insert(2, 1, 8);
	matrix.insert(2, 2, 9);
	matrix.print();

	Matrix matrix2(3, 3);
	matrix2.insert(2, 2, 9);
	matrix2.print();

	// cout << "Row: " << row << endl;
	return 0;
}