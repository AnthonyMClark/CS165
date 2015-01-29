#include <iostream>
using namespace std;
int getProductID( int ids[], string names[], int numProducts, string target)
{
	string wrong = "You entered an item that does not exist\n";
	for ( int i=0; i < numProducts; i++)
	{
		if(names[i] == target)
		{
			return ids[i];
		}     
	}
	throw wrong;

}
	
int main() // Sample code to test the getProductID function
{
	int productIds[] = {4, 5, 8, 10, 13};
	string products[] = {"computer","flash drive",
	"mouse","printer","camera"};
	try
	{
		cout << getProductID(productIds, products, 5, "mouse") 
		<< endl;
		cout << getProductID(productIds, products, 5, "camera")
		<< endl;
		cout << getProductID(productIds, products, 5, "laptop")
		<< endl;
	}
        catch(string e)
        {
                cout << e << endl;
        }

return 0;
}

/*To test my exception I ran each case where it should work ok, and where it should throw an error. This included altering the item to be correct, making laptop be 
 * on of the products that exists in the stores inventory. When this was ran, no exception was thrown, and the corresponding item number was produced as expected. 
 * I then replaced the original invalid item 'laptop' and ran the program again, which alerted the user that they entered an item that does not exist. 
 * This test worked as expected. I then changed one of the product ids to a new number, to make sure that in some odd case that this would not throw an error, and
 * as expected, it did not, as long as the item that was entered existed within the array of products. Because no user input is being taken by the program,
 * testing for exceptions in this case is much more confined as to what could potentially be entered*/
