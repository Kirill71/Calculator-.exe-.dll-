#include"Calculator.h"


using std::cout;
using std::endl;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	
	string input_string("3+�");
	input_string.shrink_to_fit();
	Calculator obj1(input_string);
	cout<<obj1.calculate()<<endl;
	system("pause");
	return 0;
}