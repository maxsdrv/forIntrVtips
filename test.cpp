#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

class Foo
{
public:
    Foo(int j) { i=new int[j]; }
    virtual ~Foo() { delete [] i; }
private:
    int* i; 
};

class Bar: public Foo 
{
public:
    Bar(int j) : Foo(j) { i=new char[j]; }
    ~Bar() { delete [] i; }
private:
    char* i;
};

/*Reverse string*/
void reverseStringBuffer(char *szBuffer)
{
    char *i = szBuffer;
    while (*i != '\0') {
        ++i;
    }
    while (szBuffer < i) {
        char c = *szBuffer;
        *szBuffer = *i;
        *i = c;
        ++szBuffer;
        --i;
    }
}

/*Reverse string using std::vector<char>;*/
void reverseString(std::vector<char> &s) {
    auto wordStart = s.begin();
    auto wordEnd = s.end();
    
    while (wordStart < wordEnd) {
        char temp = *wordStart;
        if (wordStart == wordEnd) {
            return;
        }
        --wordEnd;
        if (wordStart == wordEnd) {
            return;
        }
        *wordStart = *wordEnd;
        *wordEnd = temp;
        ++wordStart;
    }
}

void mySwap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void testPointer() {
    int x = 10, c = 5, arr[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i;
    }
    int *ptr_first = &x;
    std::cout << "This *ptr_first: " << *ptr_first << '\n';
    std::cout << "This ptr_first: " << ptr_first << '\n'; 
    int *ptr_array = arr;
    std::cout << "This ptr_array: " << ptr_array << '\n';
    std::cout << "This *ptr_array:" << *ptr_array << '\n';
    std::cout << "This *ptr_array + 1: " << *(ptr_array + 1) << '\n';

    std::vector<int> digits {1, 2, 8, 200, -300, -15, 0, 299};
    
    for (auto ptr_iterator = digits.begin(); ptr_iterator != digits.end(); ++ptr_iterator) {
        std::cout << *ptr_iterator << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < digits.size() - 1; ++i) {
        for (int j = i + 1; j < digits.size(); ++j) {
            if (digits[i] > digits[j]) {
                mySwap(&digits[i], &digits[j]);
            }
        }
    }
    std::cout << "After buble sort: " << '\n';
    for (const auto &i : digits) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}


/*Reverse integer*/
int reverseInteger(int x){
    
    /*int sign = 0;
    if (x > 0) {
        sign = 1;
    }
    else {
        sign = -1;
    }
    std::string s = std::to_string(abs((long long)x));
    std::reverse(s.begin(), s.end());
    long long result = std::stoll(s) * sign;
    if (INT32_MIN <= result && result <= INT32_MAX) {
        return (int) result;
    }
    else {
        return 0;
    }*/ 

    int sign = 0;
    if (x > 0) {
        sign = 1;
    }
    else {
        sign = -1;
        x = - x;
    }
    int res = 0;
    while (x > 0) {
        int d = x % 10;
        x /= 10;
        if (res < INT32_MAX / 10 || res == INT32_MAX / 10 &&
                                        d <= INT32_MAX % 10) {
            res = res * 10 + d;
        }
        else {
            return 0;
        }
        
    }
    
    return res * sign; 
}

int removeDuplicates(std::vector<int>& nums) {
    int k = 0;
    if (nums.size() == 0) return 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums[k]) {
            ++k;
            nums[k] = nums[i];
        }
    }
    return k + 1;
}

class A {
public:
    A(const A& a) = delete;
    A(A&& a) = delete;
    A& operator=(const A& a) = delete;
    A& operator=(A&& a) = delete;

    static A& get() {
        static A a;
        return a;
    }
private:
    A() = default;
    int x = 1234;
};

int main()
{


    // Foo* f=new Foo(100);
    // Foo* b=new Bar(200);
    // *f=*b;
    // delete f;
    // delete b;

    // char string[] = "hello";
    // reverseStringBuffer(string);
    // std::cout << "Result = " << std::endl;
    // for (int i = 0; i < 6; ++i) {
    //     std::cout << string[i];
    // }
    // std::cout << '\n';

    /*int x = -123;
    std::cout << reverseInteger(x) << std::endl;
    */

/*
    std::vector<char> string = {'h', 'e', 'l', 'l', 'o'};
    reverseString(string);
    for (const auto &i : string) {
        std::cout << i;
    }
    std::cout << '\n'; */

    // testPointer();

    std::vector<int> array {0, 0, 1, 1 ,2, 2, 3, 3, 4};
    std::cout << removeDuplicates(array) << std::endl;
    for (const auto &i : array) {
        std::cout << i << " ";
    } 
    std::cout << std::endl;

    A& a = A::get();
    char buff[sizeof(A)];
    for (int i = 0; i < sizeof(A); ++i) {
        buff[i] = ((char*)&a)[i];
    }

    A *ptr = (A*)buff;

    return 0;
}

































