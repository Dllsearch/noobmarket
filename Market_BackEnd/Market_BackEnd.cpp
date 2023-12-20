
#include "goods_page.cpp"
#include <iostream>

int main()
{
	std::vector<goods_page> goods;
	goods_page * theonegood = new goods_page("test", 300);
	goods.push_back(*theonegood);
	theonegood->setBasePrice(69);
	*theonegood = goods[0];
	std::cout << theonegood->getPrice();


}