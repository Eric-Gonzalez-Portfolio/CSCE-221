/*My_vec_char.h
Eric E. Gonzalez
Header file for a vector data structure.
*/

#include <ostream>
#include <vector>
#include "My_vec_char.h"

using namespace std;

	
//==============================================

//Constructor
My_vec::My_vec(){
	size = 0;
	capacity = 20;
	ptr = new char[capacity];
}

//Copy constructor
My_vec::My_vec(const My_vec& vec){
	capacity=vec.capacity;
	size=vec.size;
	ptr=new char[capacity];
	for(int i=0;i<vec.size;i++)
		ptr[i]=vec.ptr[i];
}

//Assignment operator
My_vec& My_vec::operator=(const My_vec& vec){
	if(this != &vec)
	{
		capacity=vec.capacity;
		size=vec.size;
		delete[] ptr;
		ptr = new char[capacity];
		for(int i=0;i<size;i++)
			ptr[i]=vec.ptr[i];
	}
	return *this;
}

//Destructor
My_vec::~My_vec(){
	delete[] ptr;
}

int My_vec::get_size() const{
	return size;
}

int My_vec::get_capacity() const{
	return capacity;
}

char& My_vec::operator[](int i){
	return ptr[i];
}

char& My_vec::operator[](int i) const{
	return ptr[i];
}

bool My_vec::is_empty() const{
	if (size == 0)
		return true;
	else
		return false;
}

char& My_vec::elem_at_rank(int r) const{
	return ptr[r];
}

//Insert at specified position
void My_vec::insert_at_rank(int r, const char& elem){
	if(size<r)
		size = r;

	if (size+1>capacity){
		capacity=size*2;
		char *tmp = new char[capacity];
		for (int i=0; i < size; i++)
			tmp[i] = ptr[i];
		delete[] ptr;
		ptr = tmp;
	}
	int count = 0;
	char insert = elem;
	char current;
	while(count<=size){
		if(ptr[count]==0 && count<r){
			ptr[count]=' ';
			count++;
		}
		else if(ptr[count]==0 && count>=r){
			current=' ';
			ptr[count]=insert;
			insert=current;
			count++;
		}
		else if(&ptr[count]!=nullptr && count>=r){
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
void My_vec::replace_at_rank(int r, const char& elem){
	if(ptr[r]==0)
		insert_at_rank(r, elem);
	else
		ptr[r] = elem;
}

//Remove from specified position
void My_vec::remove_at_rank(int r){
	int count = capacity;
	char insert = ' ';
	char current = ptr[count];
	while(count!=r){
		current = ptr[count];
		ptr[count]=insert;
		insert=current;
		count--;
	}
	size--;
}

//Overloaded << operator
ostream& operator<<(ostream& out, const My_vec& vec){
	for(int i=0; i<vec.get_capacity(); i++)
		out << vec[i];
}

//Find index of largest value
int find_max_index(const My_vec& v,int size){
	int current = 0;
	int largest = current;
	char largest_char = v[current];
	while(current<size){
		if(v[current]>v[current+1] && v[current]>largest_char){
			largest_char = v[current];
			largest = current;
			current++;
			//next++;
		}
		else{
			current++;
			//next++;
		}
	}
	return largest;
}

//Sort in ascending order
void sort_max(My_vec& vec){

	int i,j;
	int iMin;
 
	/* advance the position through the entire array */
	/*   (could do j < vec.get_size()-1 because single element is also min element) */
	for (j = 0; j < vec.get_size()-1; j++) {
		/* find the min element in the unsorted vector */
 
		/* assume the min is the first element */
		iMin = j;
		/* test against elements after j to find the smallest */
		for ( i = j+1; i < vec.get_size(); i++) {
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