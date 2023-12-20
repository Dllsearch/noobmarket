#include "goods_page.h"

class goods_page
{
private:



	enum DiscountType
	{
		discountTypeNone,
		discountTypePrice,
		discountTypePC
	};

	struct coupon
	{
		std::string couponID;
		DiscountType discountType;
		float discountPrice, discountPC; // discountVal

	};

	DiscountType currentDiscountType;
	float basePrice, discountPrice, discountPC, priceCalculated; // discountVal

	void recalculatePrice();

	std::vector<coupon> coupons;

public:

	goods_page(float basePriceSet)
	{
		basePrice = basePriceSet;
		recalculatePrice();
	}

	float getPrice()
	{
		return priceCalculated;
	}

	void setBasePrice(float price)
	{
		basePrice = price;
		recalculatePrice();
	}

	void setDiscointPrice(float discountPriceSet)
	{
		discountPrice = discountPriceSet;
		recalculatePrice();
	}

	void setDiscointPC(float discountPCSet)
	{
		discountPC = discountPCSet;
		recalculatePrice();
	}

	std::string generateCouponPC(float discountPC);

	std::string generateCouponDiscount(float discount);

};


