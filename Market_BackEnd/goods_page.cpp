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
	std::string name, description;


	void recalculatePrice()
	{
		switch (currentDiscountType)
		{
		case 1:
			priceCalculated = discountPrice;
			break;

		case 2:
			priceCalculated = basePrice * (1 - discountPC / 100);
			break;

		default:
			priceCalculated = basePrice;
			break;
		}
	}

	std::vector<coupon> coupons;

public:

	goods_page(std::string nameSet, float basePriceSet)
	{
		name = nameSet;
		basePrice = basePriceSet;
		recalculatePrice();
	}

	float getPrice()
	{
		return priceCalculated;
	}

	void setName(std::string nameSet)
	{
		name = nameSet;
	}

	void setDesc(std::string descriptionSet)
	{
		description = descriptionSet;
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

	//std::string generateCouponPC(float discountPC);

	//std::string generateCouponDiscount(float discount);

};