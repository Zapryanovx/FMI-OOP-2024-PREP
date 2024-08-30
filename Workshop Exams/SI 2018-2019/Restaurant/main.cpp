#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Restaurant.h"

int main()
{
	Restaurant r;

	Food f;
	f.setName("Pizza");
	f.setWeight(0.4);
	f.setQuantity(30);
	f.setPrice(5.50);

	Drink d;
	d.setName("Water");
	d.setAlcoholPerc(0);
	d.setQuantity(100);
	d.setPrice(2.80);

	r.addProduct(f);
	r.addProduct(d);
	r.printAll();

	r.changePrice(1, 1.30);

	r.removeProduct(0);
	r.printAll();
	return 0;
}