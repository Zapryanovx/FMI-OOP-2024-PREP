//#include <iostream>
//
//struct Complex
//{
//	int realPart;
//	int imgPart;
//};
//
//Complex sumComplex(const Complex& complexNumFirst, const Complex& complexNumSecond)
//{
//	Complex sumComplex;
//
//	//sum realPart formula
//	sumComplex.realPart = complexNumFirst.realPart + complexNumSecond.realPart;
//	
//	//subtract realPart formula
//	sumComplex.imgPart = complexNumFirst.imgPart + complexNumSecond.imgPart;
//
//	return sumComplex;
//}
//
//Complex subComplex(const Complex& complexNumFirst, const Complex& complexNumSecond)
//{
//	Complex subComplex;
//
//	//subtract realPart formula
//	subComplex.realPart = complexNumFirst.realPart - complexNumSecond.realPart;
//	
//	//subtract imgPart formula
//	subComplex.imgPart = complexNumFirst.imgPart - complexNumSecond.imgPart;
//
//	return subComplex;
//}
//
//Complex multComplex(const Complex& complexNumFirst, const Complex& complexNumSecond)
//{
//	Complex multComplex;
//
//	//multiply realPart formula
//	multComplex.realPart = (complexNumFirst.realPart * complexNumSecond.realPart) 
//						 - (complexNumFirst.imgPart * complexNumSecond.imgPart);
//
//	//multiply imgPart formula
//	multComplex.imgPart = (complexNumFirst.realPart * complexNumSecond.imgPart)
//						 + (complexNumFirst.imgPart * complexNumSecond.realPart);
//
//	return multComplex;
//}
//
//void printComplex(const Complex& complexNum)
//{
//	std::cout << complexNum.realPart << " + " << complexNum.imgPart << "i" << std::endl;
//}
//
//int main()
//{
//
//	Complex complexNum;
//	complexNum.realPart = 3;
//	complexNum.imgPart = 4;
//	printComplex(complexNum);
//
//	printComplex(sumComplex(complexNum, complexNum));
//	printComplex(subComplex(complexNum, complexNum));
//	printComplex(multComplex(complexNum, complexNum));
//
//
//	return 0;
//}