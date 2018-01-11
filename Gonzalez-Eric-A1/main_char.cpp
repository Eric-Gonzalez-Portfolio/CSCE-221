
// main_char.cpp
//Tests functionality of the My_vec class with char type.

#include <iostream>
#include <stdexcept>
#include "My_vec_char.h"

int main(){
try{
    // define an object v of My_vec type
    // insert 'B' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
    // display the vector v size
	My_vec v;
	int num = 0;
	char tmp = 'B';
	
	v.insert_at_rank(num, tmp);
	cout << v;
	cout << endl;
	cout << v.get_size() << endl;

	// insert 'A' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	num = 0;
	tmp = 'A';
	v.insert_at_rank(num, tmp);
	cout << v;
	cout << endl;
	cout << v.get_size() << endl;
	

	// insert 'D' at the rank 10 into the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	num = 10;
	tmp = 'D';
	v.insert_at_rank(num, tmp);
	cout << v;
	cout << endl;
	cout << v.get_size() << endl;

	// remove a character at the rank 2 from the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	num = 2;
	v.remove_at_rank(num);
	cout << v;
	cout << endl;
	cout << v.get_size() << endl;

	// replace a character at the rank 2 by the character 'E' 
	// use the overloaded operator << to display vector elements
	// display the vector v size
	num = 2;
	tmp = 'E';
	v.replace_at_rank(num, tmp);
	cout << v;
	cout << endl;
	cout << v.get_size() << endl;
	
	// create a copy v1 of the vector v using a copy constructor
	// use the overloaded operator << to display the vector v1
    // replace a character at the rank 2 of the vector v1 with the character 'Y'
	// use the overloaded operator << to display vector v1 elements
	My_vec v1;
	v1 = v;
	cout << v1;
	cout << endl;
	cout << "Copied " << v1.get_size() << " element(s)" << endl;
	num = 2;
	tmp = 'Y';
	v1.replace_at_rank(num, tmp);
	cout << v1;
	cout << endl;
	cout << v1.get_size() << endl;

	// define an object v2 of My_vec type
	// insert 'K' at the rank 0 into the vector v2
	// use the overloaded operator << to display vector elements
    // display the vector v2 size
	My_vec v2;
	num = 0;
	tmp = 'K';
	v2.insert_at_rank(num, tmp);
	cout << v2;
	cout << endl;
	cout << "V2 has " << v2.get_size() << " element(s)" << endl;

    // test the assignment operator and copy the vector v1 to v2 
    // use the overloaded operator << to display vector v2
    // display the vector v2 size
	v2 = v1;
	cout << v2;
	cout << endl;
	cout << "V2 has " << v2.get_size() << endl;

    // test the function find_max_index using v2
	// test the function sort_max using v2
	int size = v2.get_size();
	cout << find_max_index(v2, size) << endl;
	sort_max(v2);
	cout << v2;
	cout << endl;

	// replace in the vector v2 a character at the rank 14 with 'S'
	num = 14;
	tmp = 'S';
	v2.insert_at_rank(num, tmp);
	cout << v2;
	cout << endl;

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
