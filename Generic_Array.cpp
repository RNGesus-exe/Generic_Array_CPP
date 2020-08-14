#include<iostream>

template<class T>
class Custom_Array {
	T* A;
	int size;
	int length;
	T* undo;                          //first index is start,second index is end/length and rest is the actual array
public:
	Custom_Array(int = 0);		      // Default Parameterized Constructor -O(1)
	~Custom_Array();				  // Destructor -O(1)
	T* getArr();                      // returns address of array on heap  -O(1)
	void display();			          // To display all the elements in an array -O(n)
	void push_back(T);			      // To push an element into an array -O(1)
	void insert(int, T);			  // To insert an element at a specific index -O(n)
	T Delete(int);					  // To delete and return an element from an array at specific index -O(n)
	T pop_start();					  // To delete and return an element from the first index of an array -O(n)
	T pop_end();                      // To delete and return an element from the last index of an array -O(1)
	int search_delete(T);             // To delete an element by searching then returning it's index -O(n^2) 
	int search(T);				      // Linear Search and return index for an element in the array - O(n)
	int bin_search(T, T, T);	      // Binary Search and return index for an element in the SORTED array - O(logn)
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
	void Undo();                      // If there is data in undo then it will revert arr to prior data form -O(n)
	void replace(int, Custom_Array<T>&);				// To replace a part of array with another array -O(n)
	Custom_Array<T>* merge(Custom_Array<T>&);			//To merge two unsorted arrays into a new array -O(m+n)
	Custom_Array<T>* srt_merge(Custom_Array<T>&);		//To merge two sorted arrays into a new sorted array -O(m+n)
	Custom_Array<T>* Union(Custom_Array<T>&);			//To find the union between two non sorted arrays -O(n^2) 
	Custom_Array<T>* srt_union(Custom_Array<T>&);		//To find the union between two sorted arrays -O(m + n)
	Custom_Array<T>* intersection(Custom_Array<T>&);	//To find the intersection between two unsorted arrays -O(n^2)
	Custom_Array<T>* srt_intersection(Custom_Array<T>&);//To find the intersection between two sorted arrays -O(m + n)
	Custom_Array<T>* difference(Custom_Array<T>&);      //To find the difference between two unsorted arrays -O(n^2)
	Custom_Array<T>* srt_difference(Custom_Array<T>&);  //To find the difference between two sorted arrays   -O(n + m)
};

int main() {
	Custom_Array<int> arr1(5), arr2(5);
	arr1.push_back(2);
	arr1.push_back(4);
	arr1.push_back(6);
	arr1.push_back(10);
	arr1.push_back(23);
	arr2.push_back(3);
	arr2.push_back(4);
	arr2.push_back(6);
	arr1.display();
	arr1.replace(2,arr2);
	arr1.display();
	arr1.Undo();
	arr1.display();

	return 0;
}

template<class T>
void Custom_Array<T>::append(T element) {
	if (length < size) {
		A[length++] = element;
	}
	else {
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
void Custom_Array<T>::set(int index, T element) {
	if (index >= 0 && index < length) {
		A[index] = element;
	}
	else {
		std::cerr << "Subscript out of range!!!!\n";
	}
}

template<class T>
void Custom_Array<T>::replace(int index, Custom_Array<T>& arr){
	if (arr.length > this->length) {
		std::cerr << "Array subscript out of range!!\n";
	}
	else {
		undo = new T[arr.length + 2];
		int j = 0;
		for (int i = index; i < this->length; i++,j++) {  // -n
			undo[j+2] = this->A[i];
			this->A[i] = arr.A[j];
		}
		undo[0] = index;
		undo[1] = arr.length;
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
	return sum() / length;
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
	for (int i = 0; i < length - 1; i++) {
		A[i] = A[i + 1];
	}
	A[length - 1] = 0;
}

template<class T>
void Custom_Array<T>::rightShift() {
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
	int j = length - 1;
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
void Custom_Array<T>::Undo()
{
	if (undo != nullptr) {
		if(undo[1]>this->size){
			std::cerr << "The array is to small to undo!!!\n";
		}
		else {
			for (int i = undo[0],j=2; i < undo[1] + undo[0]; i++) {
				this->A[i] = undo[j++];
			}
			delete[] undo;
			undo = nullptr;
		}
	}
	else {
		std::cerr << "There is nothin to undo!!!\n";
	}
}



template<class T>
Custom_Array<T>* Custom_Array<T>::merge(Custom_Array<T>& arr)
{
	Custom_Array<T>* temp = new Custom_Array<T>(arr.length + this->length);
	
	for (int i=0; i < arr.length; i++) {
		temp->append(arr.A[i]);
	}
	for (int j = 0; j < this->length; j++){
		temp->append(this->A[j]);
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::srt_merge(Custom_Array<T>& arr)
{
	Custom_Array<T>* temp = new Custom_Array<T>(arr.length + this->length);
	int i = 0, j = 0;
	while (i < arr.length && j < this->length) {  // Takes O(n+m)
		if (arr.A[i] < this->A[j]) {
			temp->append(arr.A[i++]);
		}
		else {
			temp->append(this->A[j++]);
		}
	}
	for (; i < arr.length; i++)   //Takes O(n)
		temp->append(arr.A[i]);
	for (; j < this->length; j++) //Takes O(n)
		temp->append(this->A[j]);
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::Union(Custom_Array<T>& arr)
{
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	for (int i = 0; i < this->length; i++) {  //-n
		temp->append(this->A[i]);
	}
	bool flag;
	for (int i = 0; i < arr.length; i++) {   // -n
		flag = true;
		for (int j = 0; j < this->length; j++) {  //-n^2
			if (arr.A[i] == this->A[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			temp->append(arr.A[i]);
		}
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::srt_union(Custom_Array<T>& arr)
{
	int i = 0, j = 0;
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	while (i < this->length && j < arr.length) {  // n
		if (this->A[i] < arr.A[j]) {
			temp->append(A[i++]);
		}
		else if (this->A[i] > arr.A[j]) {
			temp->append(arr.A[j++]);
		}
		else {
			temp->append(arr.A[i++]);
			j++;
		}
	}
	for (; i < this->length; i++) { //n
		temp->append(this->A[i]);
	}
	for (; j < arr.length; j++) { //m
		temp->append(arr.A[j]);
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::intersection(Custom_Array<T>& arr)
{
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	bool flag;
	for (int i = 0; i < this->length; i++) {   // -n
		flag = false;
		for (int j = 0; j < arr.length; j++) {  //-n^2
			if (this->A[i] == arr.A[j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			temp->append(this->A[i]);
		}
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::srt_intersection(Custom_Array<T>& arr)
{
	int i = 0, j = 0;
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	while (i < this->length && j < arr.length) {  // n + m
		if (this->A[i] < arr.A[j]) {
			i++;
		}
		else if (this->A[i] > arr.A[j]) {
			j++;
		}
		else {
			temp->append(arr.A[i++]);
			j++;
		}
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::difference(Custom_Array<T>& arr){
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	bool flag;
	for (int i = 0; i < this->length; i++) {  //n
		flag = true;
		for (int j = 0; j < arr.length; j++) {  //n^2
			if (this->A[i] == arr.A[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			temp->append(this->A[i]);
		}
	}
	return temp;
}

template<class T>
Custom_Array<T>* Custom_Array<T>::srt_difference(Custom_Array<T>& arr){
	int i = 0, j = 0;
	Custom_Array<T>* temp = new Custom_Array<T>(this->length + arr.length);
	while (i < this->length && j < arr.length) {  // n + m
		if (this->A[i] < arr.A[j]) {
			temp->append(this->A[i++]);
		}
		else if (this->A[i] > arr.A[j]) {
			j++;
		}
		else {
			i++;
			j++;
		}
	}
	return temp;
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
		this->undo = nullptr;
	}
	else {
		this->size = size;
		this->length = 0;
		this->A = new T[size];
		this->undo = nullptr;
	}
}

template<class T>
Custom_Array<T>::~Custom_Array() {
	if (this->A != nullptr) {
		this->size = this->length = 0;
		delete[] this->A;
		A = nullptr;
	}
	if (this->undo != nullptr) {
		delete[] this->undo;
		undo = nullptr;
	}
}

template<class T>
T* Custom_Array<T>::getArr()
{
	return this->A;
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
void Custom_Array<T>::insert(int index, T element) {
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
T Custom_Array<T>::pop_start()
{
	int x = A[0];
	leftShift();
	length--;
	return x;
}

template<class T>
T Custom_Array<T>::pop_end()
{
	int x = A[length - 1];
	length--;
	return x;
}

template<class T>
int Custom_Array<T>::search_delete(T element)
{
	int index = search(element);  // Takes O(n)
	for (int i = index; i < length-1; i++){  //Takes O(n)
		A[i] = A[i + 1];
	}
	length--;
	return index;
}

template<class T>
int Custom_Array<T>::search(T element) {
	for (int i = 0; i < length; i++) {
		if (element == A[i]) {
			return i;
		}
	}
	return -1;
}

template<class T>
int Custom_Array<T>::bin_search(T low, T high, T element) {
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