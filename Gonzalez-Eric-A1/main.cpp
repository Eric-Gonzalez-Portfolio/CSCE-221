// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){
try{
    // define an object v of My_vec type
    // insert 'B' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
    // display the vector v size
	My_vec<char> v;
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
	My_vec<char> v1;
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
	My_vec<char> v2;
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
	cout << "V2 has " << v2.get_size() << " element(s)" << endl;

    // test the function find_max_index using v2
	// test the function sort_max using v2
	int size = v2.get_size();
	cout << "Address of largest value: " << find_max_index(v2, size) << endl;
	sort_max(v2);
	cout << v2;
	cout << endl;

	// replace in the vector v2 a character at the rank 14 with 'S'
	num = 14;
	tmp = 'S';
	v2.insert_at_rank(num, tmp);
	cout << v2;
	cout << endl;
	
	
	//////Int implementation
	My_vec<int> v3;
	num = 0;
	int tmp2 = 2;
	
	v3.insert_at_rank(num, tmp2);
	cout << v3;
	cout << endl;
	cout << v3.get_size() << endl;

	num = 0;
	tmp2 = 5;
	v3.insert_at_rank(num, tmp2);
	cout << v3;
	cout << endl;
	cout << v3.get_size() << endl;
	
	num = 10;
	tmp2 = 4;
	v3.insert_at_rank(num, tmp2);
	cout << v3;
	cout << endl;
	cout << v3.get_size() << endl;

	num = 2;
	v3.remove_at_rank(num);
	cout << v3;
	cout << endl;
	cout << v3.get_size() << endl;

	num = 2;
	tmp2 = 1;
	v3.replace_at_rank(num, tmp2);
	cout << v3;
	cout << endl;
	cout << v3.get_size() << endl;
	
	My_vec<int> v4;
	v4 = v3;
	cout << v4;
	cout << endl;
	cout << "Copied " << v4.get_size() << " element(s)" << endl;
	num = 2;
	tmp2 = 7;
	v4.replace_at_rank(num, tmp2);
	cout << v4;
	cout << endl;
	cout << v4.get_size() << endl;

	My_vec<int> v5;
	num = 0;
	tmp2 = 9;
	v5.insert_at_rank(num, tmp2);
	cout << v5;
	cout << endl;
	cout << "V5 has " << v5.get_size() << " element(s)" << endl;

	v5 = v4;
	cout << v5;
	cout << endl;
	cout << "V5 has " << v5.get_size() << " element(s)" << endl;


	int size2 = v5.get_size();
	cout << "Address of largest value: " << find_max_index(v5, size) << endl;
	sort_max(v5);
	cout << v5;
	cout << endl;


	num = 14;
	tmp2 = 3;
	v5.insert_at_rank(num, tmp2);
	cout << v5;
	cout << endl;
	
	/////Float implementation
	My_vec<float> v6;
	num = 0;
	float tmp3 = 2.5;
	
	v6.insert_at_rank(num, tmp3);
	cout << v6;
	cout << endl;
	cout << v6.get_size() << endl;

	num = 0;
	tmp3 = 5.4;
	v6.insert_at_rank(num, tmp3);
	cout << v6;
	cout << endl;
	cout << v6.get_size() << endl;
	
	num = 10;
	tmp3 = 5.7;
	v6.insert_at_rank(num, tmp3);
	cout << v6;
	cout << endl;
	cout << v6.get_size() << endl;

	num = 2;
	v6.remove_at_rank(num);
	cout << v6;
	cout << endl;
	cout << v6.get_size() << endl;

	num = 2;
	tmp3 = 1.1;
	v6.replace_at_rank(num, tmp3);
	cout << v6;
	cout << endl;
	cout << v6.get_size() << endl;
	
	My_vec<float> v7;
	v7 = v6;
	cout << v7;
	cout << endl;
	cout << "Copied " << v7.get_size() << " element(s)" << endl;
	num = 2;
	tmp3 = 7.9;
	v7.replace_at_rank(num, tmp3);
	cout << v7;
	cout << endl;
	cout << v7.get_size() << endl;

	My_vec<float> v8;
	num = 0;
	tmp3 = 9.9;
	v8.insert_at_rank(num, tmp3);
	cout << v8;
	cout << endl;
	cout << "V8 has " << v8.get_size() << " element(s)" << endl;

	v8 = v7;
	cout << v8;
	cout << endl;
	cout << "V8 has " << v8.get_size() << " element(s)" << endl;

	int size3 = v8.get_size();
	cout << "Address of largest value: " << find_max_index(v8, size) << endl;
	sort_max(v8);
	cout << v8;
	cout << endl;

	num = 14;
	tmp3 = 3.8;
	v8.insert_at_rank(num, tmp3);
	cout << v8;
	cout << endl;

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
