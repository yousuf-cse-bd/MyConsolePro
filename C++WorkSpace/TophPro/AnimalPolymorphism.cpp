
#include <iostream>
#pragma pack(1)
using namespace std;

class Interface{
private:
	friend ostream &operator<< (ostream &output, const Interface &object){
		object.print(output);
		return output;
	}
protected:
	virtual void print(ostream &output) const = 0;
};

class BaseClass1 : public Interface{
private:
protected:
	string nameBase{};
	virtual void print(ostream &output) const override{
		output<<"BaseClass: "<<nameBase;
	}
public:
	BaseClass1(){
		nameBase = "BaseClass1";
	}
	BaseClass1(const string_view &nameBase):nameBase{nameBase}{
		
	}
	~BaseClass1() = default;
};

class BaseClass2: public Interface{
private:
protected:
	string nameBase{};
	virtual void print(ostream &output) const override{
		output<<"BaseClass2: "<<nameBase;
	}
public:
	BaseClass2(){
		nameBase = "BaseClass2";
	}
	BaseClass2(const string_view &nameBase):nameBase{nameBase}{
		
	}
	~BaseClass2() = default;
};

class DerivedClass:  BaseClass1,  BaseClass2{
private:
	string nameDerived{};
protected:
//	virtual void print(ostream &output) const override{
//		output<<"\tIn Derived: "<<name<<endl;
//		output<<"In Base1: "<<x<<endl;
//		output<<"In Base2: "<<y;
//	}
public:
	DerivedClass(){
		nameDerived = "Derived-Class";
	}
	DerivedClass(const string_view &nameDerived):nameDerived{nameDerived}{
		
	}
	void display(void) const{
		cout<<"ClassName: "<<nameDerived<<endl;
		cout<<"Base1: "<<BaseClass1::nameBase<<endl;
		cout<<"Base2: "<<BaseClass2::nameBase<<endl;
	}
	~DerivedClass() = default;
};



int main(int argc, const char *const argv[]){
	BaseClass1 base1{"Base-Class1"};
//	cout<<base1<<endl;
//	
	BaseClass2 base2{"Base-Class2"};
//	cout<<base2<<endl;
	
	DerivedClass derived{"Derived Class"};
	cout<<"---------------------------------"<<endl;
	derived.display();
	
	
	return 0;
}
