#include<iostream>

template<class T>
class Custom_Array {
	T* A;
	int size;
	int length;
public:
	Custom_Array(int = 0);		      // Default Parameterized Constructor -O(1)
	~Custom_Array();				  // Destructor -O(1)
	void display();			          // To display all the elements in an array -O(n)
	void push_back(T);			      // To push an element into an array -O(1)
	void insert(int, T);			  // To insert an element at a specific index -O(n)
	T Delete(int);					  // To delete and return an element from an array at specific index -O(n)
	int search(T);				      // Linear Search and return index for an element in the array - O(n)
	int bin_search(T,T,T);			  // Binary Search and return index for an element in the SORTED array - O(logn)
	void append(T);				      // Appends a new element to the end of the array - O(1)
	T get(int);			              // To get the element at specific index of an array - O(1)
	void set(int, T);				  // To replace an element in the array with new element -O(1)
	T max();				          // To find the biggest element in the array -O(n)
	T min();		                  // To find the smallest element in the array -O(n)
	T sum();						  // To return the sum of all elements of an array -O(n)
	T avg();                          // To return the average o all elements in an array -O(n)
	void reverse();                   // To reverse elements in array -O(n)
	void leftShift();                 // To shift all elements in an array to left by 1 element and put 0 in last index -O(n)
	void rightShift();		          // To shift all the elements in an array to the right by 1 element and put 0 in first index -O(n)
	void leftRotate();		          // To shift all elements to the left and put first element in last index -O(n)
	void rightRotate();				  // To shift all elements to the right and put last element in first index -O(n)
	bool check_sorted();		      // To check if an array is sorted -O(n)
	void move_neg_left();			  // To move all negative numbers to left side -O(n)
};

int main() {
	Custom_Array<int> arr1(5);
	return 0;
}

template<class T>
void Custom_Array<T>::append(T element) {
	if (length < size) {
		A[length++] = element;
	}
	else{
		std::cerr << "You cannot append an element as array size is small!!!\n";
	}
}

template<class T>
T Custom_Array<T>::get(int index)
{
	if (index >= 0 && index < length) {
		return A[index];
	}
	else {
		std::cerr << "Subscript out of range!!!!\n";
	}
}

template<class T>
void Custom_Array<T>::set(int index, T element){
	if (index >= 0 && index < length) {
		A[index] = element;
	}
	else {
		std::cerr << "Subscript out of range!!!!\n";
	}
}

template<class T>
T Custom_Array<T>::max()
{
	if (length) {
		int max = A[0];
		for (int i = 1; i < length; i++) {
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}
	else
	{
		return -1;
	}
}

template<class T>
T Custom_Array<T>::min()
{
	if (length) {
		int min = A[0];       //First index element to smallest
		for (int i = 1; i < length; i++) {
			if (min > A[i]) {
				min = A[i];
			}
		}
		return min;
	}
	else {
		return -1;
	}
}

template<class T>
T Custom_Array<T>::sum()
{
	if (length) {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += A[i];
		}
	return sum;
	}
	else {
		return -1;
	}
}

template<class T>
T Custom_Array<T>::avg()
{
	return sum()/length;
}

template<class T>
void Custom_Array<T>::reverse()
{
	for (int i = 0; i < length / 2; i++) {
		std::swap(A[i], A[(length - 1) - i]);
	}
}

template<class T>
void Custom_Array<T>::leftShift()
{
	for (int i = 0; i < length-1; i++) {
		A[i] = A[i + 1];
	}
	A[length - 1] = 0;
}

template<class T>
void Custom_Array<T>::rightShift(){
	for (int i = length - 1; i > 0; i--) {
		A[i] = A[i - 1];
	}
	A[0] = 0;
}

template<class T>
void Custom_Array<T>::leftRotate()
{
	int holder = A[0];
	for (int i = 0; i < length - 1; i++) {
		A[i] = A[i + 1];
	}
	A[length - 1] = holder;
}

template<class T>
void Custom_Array<T>::rightRotate()
{
	int holder = A[length - 1];
	for (int i = length - 1; i > 0; i--) {
		A[i] = A[i - 1];
	}
	A[0] = holder;
}

template<class T>
bool Custom_Array<T>::check_sorted()
{
	for (int i = 0; i < length; i++) {
		if (A[i] > A[i - 1]) {
			return false;
		}
	}
	return true;
}

template<class T>
void Custom_Array<T>::move_neg_left()
{
	int i = 0;
	int j=length - 1;
	while (i < j) {
		while (A[i] < 0) {
			i++;
		}
		while (A[j] >= 0) {
			j--;
		}
		if (i < j) {
			std::swap(A[i], A[j]);
		}
	}
}

template<class T>
Custom_Array<T>::Custom_Array(int size) {
	if (size < 0) {
		std::cerr << "You cannot make the size of an array less than 0!!!\n";
	}
	else if (!size) {
		this->size = 0;
		this->length = 0;
		this->A = nullptr;
	}
	else {
		this->size = size;
		this->length = 0;
		this->A = new T[size];
	}
}

template<class T>
Custom_Array<T>::~Custom_Array() {
	if (this->A != nullptr) {
		this->size = this->length = 0;
		delete[] this->A;
	}
}

template<class T>
void Custom_Array<T>::display() {
	for (int i = 0; i < length; i++) {
		std::cout << this->A[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
void Custom_Array<T>::push_back(T element) {
	if (length < size) {
		this->A[length++] = element;
	}
	else
	{
		std::cerr << "You need to increase size of array to push_back more elements!!!\n";
	}
}

template<class T>
void Custom_Array<T>::insert(int index,T element) {
	if (index >= 0 && index < length)
	{
		for (int i = length - 1; i >= index; i--)
		{
			A[i + 1] = A[i];
		}
		A[index] = element;
		length++;
	}
	else
	{
		std::cerr << "You are inserting an element at an invalid position !!!\n";
	}
}

template<class T>
T Custom_Array<T>::Delete(int index)
{
	T x = 0;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (int i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
	}
	return x;
}

template<class T>
int Custom_Array<T>::search(T element){
	for (int i = 0; i < length; i++) {
		if (element == A[i]){
			return i;
		}
	}
	return -1;
}

template<class T>
int Custom_Array<T>::bin_search(T low,T high,T element) {
	while (low <= high) {
		int mid = ceil((low + high) / 2);
		if (element == A[mid]) {
			return mid;
		}
		else if (element > A[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}