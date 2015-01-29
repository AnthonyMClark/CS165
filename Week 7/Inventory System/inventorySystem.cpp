#include<iostream>
#include<vector>
using namespace std;
class Item
{
	public:
		Item(string theName, string theColor, int theAge, int theAskingPrice, int thePricePaid);	
		string getName(){return name;}
		string getColor(){return color;}
		int getAge(){return age;}
		int getAskingPrice(){return askingPrice;}
		int getPricePaid(){return pricePaid;}
		
	private:
		string name, color;
		int age, askingPrice, pricePaid;
		
};
Item::Item(string theName, string theColor, int theAge, int theAskingPrice, int thePricePaid)
		:name(theName), color(theColor), age(theAge), askingPrice(theAskingPrice), pricePaid(thePricePaid)
{
}
int main ()
{
	string productName, productColor;
	int productAge, productAskingPrice, productPricePaid;
	cout << "What is the name of the product?\n";
        cin >> productName;
        cout << "What color is the product?\n";
        cin >> productColor;
        cout << "What's the age of the product?\n";
        cin >> productAge;
        cout << "What is the price?\n";
        cin >> productAskingPrice;
        cout << "What was paid for it?\n";
        cin >> productPricePaid;      	
	Item newProduct(productName, productColor, productAge, productAskingPrice, productPricePaid);

	cout << "The new item you have entered has the following properties:\n";
	cout << "The name of it is " << newProduct.getName() <<endl;
	cout << "The color of it is " << newProduct.getColor() <<endl;
	cout << "The age of it is " << newProduct.getAge() << endl;
	cout << "The price of it is " << newProduct.getAskingPrice() <<endl;
	cout << "The price paid for it is " << newProduct.getPricePaid() <<endl; 
	return 0;
}
