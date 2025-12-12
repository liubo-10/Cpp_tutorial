cout << " -------------------- begain -------------------- " << endl;

// 查找方式1: find 函数

// 1.查找字符串 sting
//查找str第一次出现的位置，从第pos位置开始查找
// int find(const string &str,int pos=0) const;
string str11("world,hello,world!");
string str1_1("world");
int find11 = str11.find(str1_1);
cout << "find11:" << find11 << endl;

int find12 = str11.find(str1_1, 1);
cout << "find12:" << find12 << endl;

//没有找到返回 -1
string str1_2("World");
int find13 = str11.find(str1_2);
cout << "find13:" << find13 << endl;

// 2.查找字符串 const char *s
//查找字符s第一次出现的位置，从pos位置开始查找
// int find(const char *s,int pos=0) const;

string str21("world,hello,world!");
const char *str2_1 = "hello";
int find21 = str21.find(str2_1);
cout << "find21:" << find21 << endl;

//从pos查找s的前n个字符在当前对象出现的位置
//int find(const char *s,int pos,int n) const;

string str22("world,hello,world!");
const char *str2_2 = "ldllo";
int find22 = str22.find(str2_2, 4, 2);
cout << "find22:" << find22 << endl;

// 3.查找字符 const char c
//从pos查找字符c在当前对象出现的位置
//int find(const char c,int pos=0) const;

string str31("world,hello,world!");
const char c3_1 = 'o';
int find31 = str31.find(c3_1, 2);
cout << "find31:" << find31 << endl;

// 查找方式2: rfind 函数

// 4.查找字符串 sting
//查找str最后一次出现的位置，从第pos位置开始向前查找
//int rfind(const string &str,int pos=npos) const;

string str41("world,hello,world!");
string str4_1("world");
int find41 = str41.rfind(str4_1);
cout << "find41:" << find41 << endl;

int find42 = str41.rfind(str4_1, 11);
cout << "find42:" << find42 << endl;

int find43 = str41.rfind(str4_1, 12);
cout << "find43:" << find43 << endl;

// 5.查找字符串 const char *s
//查找字符s最后一次出现的位置，从pos位置开始向前查找
// int rfind(const char *s,int pos=npos) const;
string str51("world,hello,world!");
const char *str5_1 = "world";
int find51 = str51.rfind(str5_1);
cout << "find51:" << find51 << endl;

int find52 = str51.rfind(str5_1, 11);
cout << "find52:" << find52 << endl;

//从pos向后查找s的前n个字符在当前对象出现的位置
//int rfind(const char *s,int pos,int n) const;

string str53("world,hello,world!");
const char *str5_3 = "ldllo";
int find53 = str53.rfind(str5_3, string::npos, 2);
cout << "find53:" << find53 << endl;

int find54 = str53.rfind(str5_3, 14, 2);
cout << "find54:" << find54 << endl;

cout << " -------------------- end -------------------- " << endl;

