//#include <iostream>
//
//struct ComplexNum
//{
//	double realPart;
//	double imPart;
//};
//
//ComplexNum sumComplexNums(const ComplexNum& n, const ComplexNum& m)
//{
//	ComplexNum sum;
//
//	//sum formula
//	sum.realPart = n.realPart + m.realPart;
//	sum.imPart = n.imPart + m.imPart;
//	
//	return sum;
//}
//
//ComplexNum multiplyComplexNums(const ComplexNum& n, const ComplexNum& m)
//{
//	ComplexNum  multiply;
//
//	//multiply formula
//	multiply.realPart = (n.realPart * m.realPart) - (n.imPart * m.imPart);
//	multiply.imPart = (n.realPart * m.imPart) + (n.imPart * m.realPart);
//
//	return multiply;
//}
//
//void printComplexNum(const ComplexNum& n)
//{
//	std::cout << n.realPart << " + " << n.imPart << "i" << std::endl;
//}
//
//int main()
//{
//	printComplexNum(sumComplexNums({ 3, 2 }, { 2, 3 }));
//	printComplexNum(multiplyComplexNums({ 3, 2 }, { 2, 3 }));
//
//
//}