#include <iostream>
using namespace std;
void incrementAndPrint()
{
	static int s_value = 1; // static duration variable
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but became inaccessible
void fake()
{
	static int s_value = 1; // static duration variable
    ++s_value;
    std::cout << s_value << '\n';	
}
 
int main()
{
	int A[];
    
    return 0;
}
