// lab 2, variant 18: 
// (a + 6) / b   , если a > b
// 6             , a = b
// (12 + a) / b  , если a < b
#include <iostream>

//signed 16bit integers
int16_t a, b;
int16_t result;

extern "C" {void calculate_asm(void);}

void f_c(void)
{
	std::cout << "in function f_c:\n";
	if(a > b)
		result = (a + 6) / b;
	else if(a == b)
		result = 6;
	else if(a < b)
		result = (12 + a) / b;
	std::cout << "result = " << result << "\n";
}

void f_asm(void)
{
	std::cout << "in function f_asm:\n";
	calculate_asm();
	std::cout << "result = " << result << "\n";
}

int main(void)
{
	std::cout << "Enter a b: ";
	if(!(std::cin >> a >> b)) {
		std::cout << "Invalid input.\n";
		return 1;
	}
	f_c();
	result = 0;
	f_asm();
	return 0;
}
