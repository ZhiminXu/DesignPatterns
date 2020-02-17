#pragma once
#include <iostream>

class Product
{
public:
	virtual Product* Clone() = 0;
	virtual void Show() {}
	virtual ~Product(void) {};
};

class NamedProduct : public Product
{
public:
	NamedProduct(const char* name)
	{
		if(name == nullptr) {
			mName = new char[1];
			mName[0] = '\0';
		}
		else {
			mName = new char[strlen(name)+1];
			strcpy_s(mName, strlen(name) + 1, name);
		}
	}

	NamedProduct(const NamedProduct &np)
	{
		if(np.mName == nullptr) {
			mName = new char[1];   
			mName[0] = '\0';   
		}
		else {
			mName = new char[strlen(np.mName)+1];
			strcpy_s(mName, strlen(np.mName) + 1, np.mName);
		}
	}

	~NamedProduct()
	{
		delete mName;
		mName = nullptr;
	}

	virtual Product* Clone()
	{
		return new NamedProduct(*this);
	}

	virtual void Show()
	{
		std::cout << "Named Product: "<< mName <<std::endl;
	}

private:
	char* mName;
};