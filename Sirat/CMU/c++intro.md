
# INTRODUCTION TO C++11 AND C++14

C++ programming language is based on C programming. C++ is considered as a general purpose language that supports Object oriented programming as well as multithreading.

### 1. What is C++11?
C++11 refers to the 2011 version of the C++ programming language standard. It introduced several significant features and improvements to the language, making it more powerful, expressive, and easier to use.
C++14 is just a minor extension of C++11 with few bug fixes and small changes.

### 2. Range Based For Loop
* for(int i=0; i<n; ++i) doSomething;
using a for loop in C++ to repeatedly call a function doSomething() n times.

* for(int& i: someDataStructure) { doSomething();}
This loop iterates over elements in the someDataStructure and applies the operation doSomething() to each element. The int& i syntax means that i is a reference to an integer, which allows you to modify the elements of someDataStructure directly

* for(int i: someDataStructure) doSomething();
 enables the access by value but not enble to modify the element in container 

### 3. Strongly Typed enums
Old way of using enums had its flaws, which is fixed with a new way of declaring data that could have few of possible choices.

*enum class CoordinateArea { FirstArea, SecondArea, ThirdArea, FourthArea};

CoordinateArea caOne = CoordinateArea::FirstArea;

CoordinateArea caSome= CoordinateArea::FourhtArea;

### 4. Lamba Expressions of Lambda Functions
 Lambdas are particularly useful in situations where you need to pass a function as an argument to another function or when you want to create short, throwaway functions.
*auto add = [](int a, int b) { return a + b; };
*int result = add(5, 3); // result will be 8

### 5. Static Assertion
Static assertions, introduced in C++11, are a mechanism for the compiler to perform checks at compile time. They allow you to verify properties of your code that can be determined at compile time, rather than at runtime.
*static_assert(expression, "error message");
*static_assert(sizeof(long long int)>=16;”This is unexpected”);

### 6. Random Number Generation
This has been around for a very long time. The old way of generating random numbers was replaced with a new approach.

### 7. Move and &&
*MovableClass(MovableClass&&);
This is the declaration of a move constructor in C++. A move constructor is a special member function that is used to move the resources (such as memory, file handles, etc.) owned by one object to another. It is called when an rvalue is passed to initialize or assign another object.

### 8. Few Notes about Pointers
* they are used to store the address of some object in memory and that way you have a lot of flexibility for your code.
* The dynamic data structures could be constructed, you have very fast way to access the elements of an array, etc.
* unique_ptr is new feature of C++ that will enable you to protect ownership of some resource stored in the memory. cant be shared and transfer to another unique pointer.
*shared_ptr as one could guess from the name is suitable for situations that require ownership of some resource in the memory to be shared.
*weak_ptr is enabling the access to something that might exist in memory, the access is granted if you have object that occupy the memory, and it is possible to delete that object

### 9.  Uniform Initialization and Initializer Lists
 to use constructor it would be preferable to replace old style initialization () with couple of {}.
 *old style of initialization
 CSomeClass SomeObject( argument1, argument2);
 *new
 CSomeClass SomeObject={ argument1, argument2};

### 10. Challenges with Virtual Function
When there is inheritance and you need to apply virtual methods, it is enough to write virtual in the front of the name and every time you have method in lower level class you will dill with a virtual method.large table that is used to keep the track of the methods and it could become bit slow speed vise. If you try to override the function, this could mean that you wish to work with data type that is different form that one applied in parent class, but you are in need to change how method in inherited class behaves, now all you need to do is to add override

### 11. Multi-Threading in C++11
*If you wish to call the thread, which is a class in std namespace, you need to add some header. The appropriate is to add include <thread>, or it might signed some other way
*When you start your thread you could use: join, swap, detach, sleep for etc
*If you try to protect some resource from other threads so that you have expected results now you should have different kinds of mutex that is added with its library: mutex, recursive mutex, timed mutex and recursive timed mutex

### 13.  What is Next for C++11
There are several minor improvements and bug fixes to C++11 standard, which is known as C++14.
