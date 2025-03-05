#include <iostream>

class IValidator {
public:
    virtual bool IsValid(int price) const = 0;
    virtual ~IValidator() = default;
};

class DefaultValidator : public IValidator {
public:
    bool IsValid(int price) const override {
        return price > 0;
    }
};

class CustomerServiceValidator : public IValidator {
public:
    bool IsValid(int price) const override {
        return price > 100000;
    }
};

class Product {
private:
    int price;

public:

    Product(int price) : price(price) {}

    int GetPrice() const {
        return price;
    }

    bool IsValid(const IValidator& validator) const {
        return validator.IsValid(GetPrice());
    }
};

int main() {
    DefaultValidator defaultValidator;
    CustomerServiceValidator customerValidator;

    Product product1(50000);
    Product product2(100001);

    std::cout << "Product1 (default validation): " << product1.IsValid(defaultValidator) << std::endl;
    std::cout << "Product1 (customer service validation): " << product1.IsValid(customerValidator) << std::endl << std::endl;

    std::cout << "Product2 (default validation): " << product2.IsValid(defaultValidator) << std::endl;
    std::cout << "Product2 (customer service validation): " << product2.IsValid(customerValidator) << std::endl;

    return 0;
}
