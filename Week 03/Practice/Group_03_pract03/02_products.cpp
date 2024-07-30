#include <iostream>
#include <cstring>
#include <fstream>

namespace MAX_SIZE_CONSTS
{
	constexpr size_t MAX_SIZE_NAME = 100;
	constexpr size_t MAX_SIZE_SUPPLIER = 100;
	constexpr size_t MAX_SIZE_PRODUCTS = 10;
}

enum class Category
{
	ELECTRONICS = 1,
	CLOTHING,
	BOOKS,
	FOOD,
	BEAUTY,
	NOT_EXIST
};

struct Product
{
	char productName[MAX_SIZE_CONSTS::MAX_SIZE_NAME] = {};
	int quantityInStock = 0;
	double pricePerPiece = 0.0;
	Category categoryOfProduct;
	char supplier[MAX_SIZE_CONSTS::MAX_SIZE_NAME] = {};
};

struct AllProducts
{
	Product products[MAX_SIZE_CONSTS::MAX_SIZE_PRODUCTS] = {};
	int allProductsCount = 0;
};

size_t getSizeOfProducts(std::ifstream& fileIn)
{
	fileIn.seekg(0, std::ios::end);
	int len = fileIn.tellg();
	fileIn.seekg(0, std::ios::beg);

	return len / sizeof(Product);
}

void readProductsFromFile(std::ifstream& fileIn, AllProducts& allProducts)
{
	allProducts.allProductsCount = getSizeOfProducts(fileIn);
	fileIn.read((char*)&allProducts.products, allProducts.allProductsCount * sizeof(Product));

	fileIn.close();
}

void writeProductsToFile(std::ofstream& fileOut, const AllProducts& allProducts)
{
	fileOut.write((const char*) &allProducts.products, allProducts.allProductsCount * sizeof(Product));

	fileOut.close();
}

void getCategoryOfProduct(Product& product, int category)
{
	switch (category)
	{
		case 1:
			product.categoryOfProduct = Category::ELECTRONICS;
			break;
		case 2:
			product.categoryOfProduct = Category::CLOTHING;
			break;
		case 3:
			product.categoryOfProduct = Category::BOOKS;
			break;
		case 4:
			product.categoryOfProduct = Category::FOOD;
			break;
		case 5:
			product.categoryOfProduct = Category::BEAUTY;
			break;
		default:
			product.categoryOfProduct = Category::NOT_EXIST;
			break;
	}
}

void initProduct(Product& product)
{
	std::cin.getline(product.productName, MAX_SIZE_CONSTS::MAX_SIZE_NAME);

	std::cin >> product.quantityInStock;
	std::cin >> product.pricePerPiece;

	int category = 0;
	std::cin >> category;
	getCategoryOfProduct(product, category);
	std::cin.ignore();

	std::cin.getline(product.supplier, MAX_SIZE_CONSTS::MAX_SIZE_SUPPLIER);

}

bool isProductValid(const Product& product)
{
	return product.quantityInStock >= 0 && product.pricePerPiece >= 0.00
		&& product.categoryOfProduct != Category::NOT_EXIST;
}

bool doProductExist(const AllProducts& allProducts, const Product& product)
{
	std::cout << allProducts.allProductsCount << " ";
	for (unsigned i = 0; i < allProducts.allProductsCount; i++)
	{
		std::cout << allProducts.products[i].productName << std::endl;
		std::cout << product.productName << std::endl;
		if (strcmp(allProducts.products[i].productName, product.productName) == 0)
		{
			return true;
		}
	}
	return false;
}

void includeProducts(const char* fileName)
{
	std::ifstream fileIn(fileName, std::ios::binary);
	if (!fileIn.is_open())
	{
		std::cout << "[ERROR] File not found";
		return;
	}

	AllProducts allProducts;
	readProductsFromFile(fileIn, allProducts);
	fileIn.close();

	std::ofstream fileOut(fileName, std::ios::binary | std::ios::app);
	if (!fileOut.is_open())
	{
		std::cout << "[ERROR] File not found";
		return;
	}

	int n = 0;
	std::cin >> n;
	std::cin.ignore();

	for (unsigned i = 0; i < n; i++)
	{
		Product product;
		initProduct(product);

		if (isProductValid(product) && !doProductExist(allProducts, product))
		{
			fileOut.write((const char*) &product, sizeof(Product));
		}
	}

	fileOut.close();
}

void changeQuantityOfProduct(const char* fileName, const char* productName, int newQuanity)
{
	std::ifstream fileIn(fileName, std::ios::binary);
	if (!fileIn.is_open() || newQuanity < 0)
	{
		std::cout << "[ERROR] File not found or invalid value for new quantity.";
		return;
	}

	AllProducts allProducts;
	readProductsFromFile(fileIn, allProducts);
	fileIn.close();

	for (unsigned i = 0; i < allProducts.allProductsCount; i++)
	{
		if (strcmp(allProducts.products[i].productName, productName) == 0)
		{
			allProducts.products[i].quantityInStock = newQuanity;
		}
	}

	std::ofstream fileOut(fileName, std::ios::binary);
	writeProductsToFile(fileOut, allProducts);
	fileOut.close();
}

const char* convertCategoryToStr(int category)
{
	switch (category)
	{
		case 1:
			return "ELECTRONICS";
			break;
		case 2:
			return "CLOTHING";
			break;
		case 3:
			return "BOOKS";
			break;
		case 4:
			return "FOOD";
			break;
		case 5:
			return "BEAUTY";
			break;
		default:
			return "NOT EXIST";
			break;
	}
}

void printProduct(const Product& product)
{
	std::cout << product.productName << " " << product.quantityInStock << " " << product.pricePerPiece << " "
		<< convertCategoryToStr((int) product.categoryOfProduct) << " " << product.supplier << std::endl;
}

void printAllProducts(std::ifstream& fileIn)
{
	AllProducts allProducts;
	readProductsFromFile(fileIn, allProducts);

	for (unsigned i = 0; i < allProducts.allProductsCount; i++)
	{
		printProduct(allProducts.products[i]);
	}

	fileIn.close();
}

void printProductsByName(std::ifstream& fileIn, const char* productName)
{
	AllProducts allProducts;
	readProductsFromFile(fileIn, allProducts);

	for (unsigned i = 0; i < allProducts.allProductsCount; i++)
	{
		if (strcmp(allProducts.products[i].productName, productName) == 0)
		{
			printProduct(allProducts.products[i]);
		}
	}

	fileIn.close();
}
//По подадено име на друг файл и категория да се запишат всички продукти от дадената категория в съответния файл;
void saveProductsByCategory(const char* fileNameTo, const char* fileNameFrom, Category& category)
{
	std::ifstream fileIn(fileNameFrom, std::ios::binary);
	AllProducts allProducts;

	readProductsFromFile(fileIn, allProducts);
	fileIn.close();

	std::ofstream fileOut(fileNameTo, std::ios::binary);
	for (unsigned i = 0; i < allProducts.allProductsCount; i++)
	{
		if (allProducts.products[i].categoryOfProduct == category)
		{
			fileOut.write((const char*) &allProducts.products[i], sizeof(Product));
		}
	}
}

int main()
{
	//std::ofstream fileOut1("02_products.txt", std::ios::binary | std::ios::app);
	//AllProducts allProducts1;
	//allProducts1.products[0] = { "ime", 2, 2, Category::BEAUTY, "ekont" };
	//allProducts1.products[1] = { "ime2", 2, 2, Category::BEAUTY, "ekont" };
	//allProducts1.allProductsCount = 2;

	//writeProductsToFile(fileOut1, allProducts1);

	//std::ifstream fileIn("02_products.txt", std::ios::binary);
	//AllProducts allProducts;
	//readProductsFromFile(fileIn, allProducts);

	//includeProducts("02_products.txt");
	//const char* productName = "testvam";
	//changeQuantityOfProduct("02_products.txt", productName, 12);

	//std::ifstream fileTwo("02_products.txt", std::ios::binary);
	//printAllProducts(fileTwo);

	//std::ifstream fileThree("02_products.txt", std::ios::binary);
	//onst char* productName = "testvam";
	//printProductsByName(fileThree, productName);

	const char* fileFrom = "02_products.txt";
	const char* fileTo = "02_products_filtered.txt";
	Category category = Category::CLOTHING;
	saveProductsByCategory(fileTo, fileFrom, category);

	return 0;
}