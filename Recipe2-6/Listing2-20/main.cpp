#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <typeinfo>

int main()
{
    using MyArray = std::array<uint32_t, 5>;
    MyArray myArray{ 1, 2, 3, 4, 5 };

    auto myClosure = [](auto&& number) {
	    std::cout << number << std::endl;
	};
    std::cout << typeid(myClosure).name() << std::endl;

    std::for_each(myArray.begin(),
        myArray.end(),
	myClosure);

    return 0;
}
