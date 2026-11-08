printf("--------------------begain-------------------\n");

vector<int> vector_11{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

cout << "vector_11: " << endl;
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

vector_11.reserve(30); // 使得capacity=30，里面的元素不会改变
cout << "reserve 30: ";
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

vector<int> vector_12;
vector_12.swap(vector_11);

cout << "swap vector_12: ";
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

vector<int> vector_13{9,8,7,6};
vector_11.swap(vector_13);

cout << "swap vector_11: ";
print_vector(vector_11);
cout << "size = " << vector_11.size() << endl;
cout << "capacity = " << vector_11.capacity() << endl << endl;

printf("--------------------end----------------------\n");