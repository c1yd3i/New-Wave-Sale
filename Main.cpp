#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Item.h"
#include "Cart.h"
#include "Invoice.h"


//product constructor format is: name, price

//if the product has special conditions/sale prices then extend
//the Product class and override the methods from the main Product class
Product products[] = {
	Product("Memory Card", 69.95),
	Product("Disk Drive", 198.50),
};

int main()
{
	//create a new cart object
	Cart cart = Cart();
	std::string customerName;

	std::cout << "Customer name: ";
	getline(std::cin, customerName);

	//add products to cart
	for (Product product : products) {
		std::cout << "Quantity of " + product.getName() + ": ";

		int quantity;
		std::cin >> quantity;

		if (quantity > 0) {
			cart.addToCart(product, quantity);
		}
	}

	//generate our invoice with the cart and print it
	Invoice invoice = Invoice(cart, customerName);
	invoice.print();

	while (1);
}