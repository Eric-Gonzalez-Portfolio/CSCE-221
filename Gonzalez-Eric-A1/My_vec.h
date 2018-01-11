/*My_vec.h
Eric E. Gonzalez
Header file for a vector data structure.
*/

#include <ostream>
#include <vector>

using namespace std;

template <class T>
class My_vec {
	
	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	My_vec();
	~My_vec();
	My_vec(const My_vec& vec);
	My_vec& operator=(const My_vec& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	
};
	template <typename T>
	ostream& operator<<(ostream& out, const My_vec<T>& vec);
	
	template <typename T>
	int find_max_index(const My_vec<T>& v,int size);
	
	template <typename T>
	void sort_max(My_vec<T>& vec);
	
//==============================================

// All of the information from My_vec.cpp

//Constructor
template <typename T>
My_vec<T>::My_vec(){
	size = 0;
	capacity = 20;
	ptr = new T[capacity];
}

//Copy constructor
template <typename T>
My_vec<T>::My_vec(const My_vec<T>& vec){
	capacity=vec.capacity;
	size=vec.size;
	ptr=new T[capacity];
	for(int i=0;i<vec.size;i++)
		ptr[i]=vec.ptr[i];
}

//Assignment operator
template <typename T>
My_vec<T>& My_vec<T>::operator=(const My_vec<T>& vec){
	if(this != &vec)
	{
		capacity=vec.capacity;
		size=vec.size;
		delete[] ptr;
		ptr = new T[capacity];
		for(int i=0;i<capacity;i++)
			ptr[i]=vec.ptr[i];
	}
	return *this;
}

//Destructor
template <typename T>
My_vec<T>::~My_vec(){
	delete[] ptr;
}

template <typename T>
int My_vec<T>::get_size() const{
	return size;
}

template <typename T>
int My_vec<T>::get_capacity() const{
	return capacity;
}

template <typename T>
T& My_vec<T>::operator[](int i){
	return ptr[i];
}

template <typename T>
T& My_vec<T>::operator[](int i) const{
	
	return ptr[i];
}

template <typename T>
bool My_vec<T>::is_empty() const{
	if (size == 0)
		return true;
	else
		return false;
}

template <typename T>
T& My_vec<T>::elem_at_rank(int r) const{
	return ptr[r];
}

//Insert at specified position
template <typename T>
void My_vec<T>::insert_at_rank(int r, const T& elem){
	if(size<r)
		size = r;

	if (size+1>capacity){
		capacity=size*2;
		T *tmp = new T[capacity];
		for (int i=0; i < size; i++)
			tmp[i] = ptr[i];
		delete[] ptr;
		ptr = tmp;
	}
	
	int count = 0;
	T insert = elem;
	T current;
	while(count<=size){
		if(ptr[count]==T() && count<r){
			ptr[count]=T();
			count++;
		}
		else if(ptr[count]==T() && count>=r){
			current=T();
			ptr[count]=insert;
			insert=current;
			count++;
		}
		else if(&ptr[count]!=NULL && count>=r){
			current=ptr[count];
			ptr[count]=insert;
			insert=current;
			count++;
		}
		else{
			count++;
		}
	}
	size++;
}

//Replace at specified position
template <typename T>
void My_vec<T>::replace_at_rank(int r, const T& elem){
	if(ptr[r]==T()){
		insert_at_rank(r, elem);
		size--;
	}
	else
		ptr[r] = elem;
}

//Remove from specified position
template <typename T>
void My_vec<T>::remove_at_rank(int r){
	int count = capacity;
	T insert = T();
	T current = ptr[count];
	while(count!=r){
		current = ptr[count];
		ptr[count]=insert;
		insert=current;
		count--;
	}
	size--;
}

//Overloaded << operator
template <typename T>
ostream& operator<<(ostream& out, const My_vec<T>& vec){
	for(int i=0; i<vec.get_capacity(); i++)
		if(vec[i]!=T())
			out << vec[i] << ", ";
		else
			out << " ";
}

//Find index of largest value
template <typename T>
int find_max_index(const My_vec<T>& v,int size){
	int current = 0;
	int largest = current;
	T largest_char = v[current];
	while(current<size){
		if(v[current]>v[current+1] && v[current]>largest_char){
			largest_char = v[current];
			largest = current;
			current++;
		}
		else{
			current++;
		}
	}
	return largest;
}

//Sort in ascending order
template <typename T>
void sort_max(My_vec<T>& vec){

	int i,j;
	int iMin;
 
	/* advance the position through the entire array */
	/*   (could do j < vec.get_size() because single element is also min element) */
	for (j = 0; j < vec.get_size(); j++) {
		/* find the min element in the unsorted vector */
 
		/* assume the min is the first element */
		iMin = j;
		/* test against elements after j to find the smallest */
		for ( i = j+1; i < vec.get_size()+1; i++) {
			/* if this element is less, then it is the new minimum */  
			if (vec[i] < vec[iMin]) {
				/* found new minimum; remember its index */
				iMin = i;
			}
		}
 
		if(iMin != j) {
			swap(vec[j], vec[iMin]);
		}
 
	}
}