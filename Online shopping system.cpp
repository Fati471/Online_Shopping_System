#include<iostream>
#include<string>
#include<vector>
using namespace std;

//...class User...
class User {
	private:
		string username;
		string password;
		string role;
	public:
		void setDetails(string u, string p, string r);
		string getUsername();
		string getPassword();
		string getRole();
		void createAccount();
		bool login();
		void recoverAccount();	
};

void User::setDetails(string u, string p, string r) {
	username=u;
	password=p;
	role=r;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

string User::getRole() {
	return role;
}

// For creating account
void User::createAccount() {
	cout<<"\nEnter your usename: ";
	cin>>username;
	cout<<"Enter your password: ";
	cin>>password;
	cout<<"Enter your role (Admin/Customer): ";
	cin>>role;
}

// For login
bool User::login() {
	string aUsername,aPassword;
	cout<<"\nEnter your username: ";
	cin>>aUsername;
	cout<<"Enter your password: ";
	cin>>aPassword;
	if(username==aUsername && password==aPassword) {
		cout<<"Login Successful! Welcome "<<username<<" ("<<role<<")"<<endl; 
		return true;
    } else {
		cout<<"Login Error! Please check your username or password."<<endl;
		return false;
	}
}

// For reovering account
void User::recoverAccount() {
	int choice;
	cout<<"\nForgotten? We're here for help. Select recovery option: "<<endl;
	cout<<"1. Search your account by Username"<<endl;
	cout<<"2. Search your account by Password"<<endl;
	cout<<"\nEnter your choice: ";
	cin>>choice;
	
	// Find password by username
	if(choice==1) {
		string rUsername;
		cout<<"\nEnter your remembered Username: ";
		cin>>rUsername;
		if(rUsername==username) {
			cout<<"Your Account Found.\nYour Password is "<<password<<"."<<endl;
		} else {
			cout<<"Password not found."<<endl;
		} 
	} 	//Find username by password
		else if(choice==2) {
			string rPassword;
			cout<<"\nEnter your remembered Password: ";
			cin>>rPassword;
		if(rPassword==password) {
			cout<<"Your Account Found.\nYour Username is "<<username<<"."<<endl;
		} else {
			cout<<"Username not found."<<endl;
		} 
		}
	}
	
// ...Product Class...
class Product {
	private:
		int productID;
		string productName;
		string category;
		int price;
		int stockQuantity;
	public:
		Product();
		Product(int id, string name, string cat, int pp, int qty);
		void setStockQuantity(int qty);
		int get_ProductID();
		string get_ProductName();       
		string getCategory();
		int getPrice(); 
		int get_StockQuantity();
		void reduceStock(int quantity);
};

// Default Constructor for the Product class
Product::Product() : productID(0), productName("Unnamed"), category("Uncategorized"), price(0), stockQuantity(0) {}

Product::Product(int id, string name, string cat, int pp, int qty) : productID(id), productName(name), category(cat), price(pp), stockQuantity(qty) {}

void Product::setStockQuantity(int qty) {
    stockQuantity = qty;
}

int Product::get_ProductID() {
	return productID;
}

string Product::get_ProductName() {
	return productName;
}

string Product::getCategory() {
	return category;
}

int Product::getPrice() {
	return price;
}

int Product::get_StockQuantity() {
	return stockQuantity;
}

// For reducing the stock after placing an order
void Product::reduceStock(int quantity) {
	if (quantity<=stockQuantity) {
		stockQuantity -= quantity;
	} else {
		cout << "Error: Not enough stock to fulfill the order!" << endl;
	}
}

// ...Category Class...    
class Category {
	private:
		int categoryID;
		string categoryName;
	public:
		Category(int id, string name);
		int get_CategoryID();
		string get_CategoryName();
};

Category::Category(int id, string name) : categoryID(id), categoryName(name) {}

int Category::get_CategoryID() {
	return categoryID;
}

string Category::get_CategoryName() {
	return categoryName;
}

class Order {
	private:
    	int orderID;
    	int orderPrice;
    	string orderDate;
    	string orderStatus;
	public:
		Order(int id, int p, string d, string s);
		int getOrderID();
		string get_OrderStatus();
		void displayOrderStatus();
		void updateOrderStatus(string status);
};

Order::Order(int i, int p, string d, string s) : orderID(i), orderPrice(p), orderDate(d), orderStatus(s) {}

int Order::getOrderID() { 
	return orderID; 
}

string Order::get_OrderStatus() { 
	return orderStatus; 
}

void Order::displayOrderStatus() {
    cout << "\nOrder ID: " << orderID<< " | Total Price: $" << orderPrice<< " | Date: " << orderDate<< " | Status: " << orderStatus << endl;
}

void Order::updateOrderStatus(string status) {
    orderStatus = status;
    cout << "Order status updated to " << status << "." << endl;
}

// ...Payment Class...
class Payment {
	private:
	    int paymentID;
	    int orderID;
	    int amount;
	    string paymentDate;
	    string paymentMethod;
	    string paymentStatus;

	public:
    	Payment(int pID, int oID, int amt, string date, string method, string status);
		void generateReceipt();
};

Payment::Payment(int pID, int oID, int amt, string date, string method, string status) : paymentID(pID), orderID(oID), amount(amt), paymentDate(date), paymentMethod(method), paymentStatus(status) {}

void Payment::generateReceipt() {
    cout << "Payment Receipt:"<<endl;
    cout << "Payment ID: " << paymentID << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Payment Date: " << paymentDate << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "Payment Status: " << paymentStatus << endl;
}

//...Cart Class...
class Cart {
	private:
	    Product products[100]; 
	    int quantities[100];   
	    int cartSize;          

	public:
	    Cart();
	    void addToCart(Product product, int quantity);
	    void viewCart();
	    void placeOrder(vector<Order> &orders,vector<Product> &allProducts);
	    bool isEmpty();
};

Cart::Cart() : cartSize(0) {}

// For adding product to cart
void Cart::addToCart(Product product, int quantity) {
    if (quantity > product.get_StockQuantity()) {
        cout << "\nError: Quantity exceeds available stock!" << endl;
        return;
    }
    
    for (int i = 0; i < cartSize; ++i) {
        if (products[i].get_ProductID() == product.get_ProductID()) {
            quantities[i] += quantity; 
            cout <<quantity << " more " << product.get_ProductName() << " added to the cart!" << endl;
            return;
        }
    }
    products[cartSize] = product;
    quantities[cartSize] = quantity;
    ++cartSize;
	cout <<"\n"<<quantity << " " << product.get_ProductName() << "(s) added to the cart successfully!" << endl;
}

void Cart::viewCart() {
    if (cartSize == 0) {
        cout << "\nYour cart is empty." << endl;
        return;
    }

    while (true) { 
        cout << "\nCart Items: " << endl;
        cout << "\nProduct Name | Quantity | Price per Item | Total Price" << endl;
        for (int i = 0; i < cartSize; ++i) {
            int totalPrice = products[i].getPrice() * quantities[i];
            cout << products[i].get_ProductName() << " | " << quantities[i] << " | $" << products[i].getPrice() << " | $" << totalPrice << endl;
        }
        cout << "\n1. Update Quantity" << endl;
        cout << "2. Remove from Cart" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        
        // For updating quantity of products
        if (choice == 1) {
            string productName;
            cout << "\nEnter the product name to update quantity: ";
            cin >> productName;
            bool found = false;
            for (int i = 0; i < cartSize; ++i) {
                if (products[i].get_ProductName() == productName) {
                    found = true;
                    int newQuantity;
                    cout << "Enter new quantity: ";
                    cin >> newQuantity;
                    quantities[i] = newQuantity;
                    cout << "Quantity updated successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found in the cart!" << endl;
            }
        }
        
        // For removing a product from cart
        else if (choice == 2) {
            string productName;
            cout << "\nEnter the product name to remove: ";
            cin >> productName;
            bool found = false;
            for (int i = 0; i < cartSize; ++i) {
                if (products[i].get_ProductName() == productName) {
                    found = true;
                    for (int j = i; j < cartSize - 1; ++j) {
                        products[j] = products[j + 1];
                        quantities[j] = quantities[j + 1];
                        }
                    --cartSize; 
                    cout << "Product removed from the cart successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found in the cart!" << endl;
            }
        }
        
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
void Cart::placeOrder(vector<Order> &orders,vector<Product> &allProducts) {
    if (cartSize == 0) {
        cout << "\nYour cart is empty! Please add items before placing an order." << endl;
        return;
    }
    
    cout << "\nItems in your cart:\n";
    cout << "Product Name | Quantity | Price per Item | Total Price\n";
    int totalAmount = 0;
    for (int i = 0; i < cartSize; ++i) {
        int itemTotal = products[i].getPrice() * quantities[i];
        totalAmount += itemTotal;
        cout << products[i].get_ProductName() << " | " << quantities[i] 
             << " | $" << products[i].getPrice() << " | $" << itemTotal << endl;
    }
    cout << "\nTotal Amount: $" << totalAmount << endl;
    
    char confirmOrder;
    cout << "Do you want to confirm the order? (y/n): ";
    cin >> confirmOrder;
    
    if (confirmOrder != 'y' && confirmOrder != 'Y') {
        cout << "Order canceled." << endl;
        return;
    }
	// Ask for payment option
	
    int paymentOption;
    cout << "\nChoose Payment Option: "<<endl;
    cout << "1. PayPal "<<endl;
    cout << "2. Cash on Delivery"<<endl;
    cout << "\nEnter your choice: ";
    cin >> paymentOption;
    
    if (paymentOption == 1) {
        string paypalEmail, paypalPassword;
        cout << "\nEnter your PayPal email: ";
        cin >> paypalEmail;
        cout << "Enter your PayPal password: ";
        cin >> paypalPassword;
        cout << "\nPayment Successful through PayPal!" << endl;
    } 
    
    else if (paymentOption == 2) {
        string name, contact, address;
        cout << "Enter your Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter your Contact Info: ";
        getline(cin, contact);
        cout << "Enter your Delivery Address: ";
        getline(cin, address);
        cout << "\nPayment Successful via Cash on Delivery!" << endl;
    } 
    else {
        cout << "Invalid payment option! Order canceled." << endl;
        return;
    }
    
    // Reduces stock 
    for (int i = 0; i < cartSize; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (products[i].get_ProductID() == allProducts[j].get_ProductID()) {
                allProducts[j].reduceStock(quantities[i]);
            }
        }
    }
    
    int orderID;
    cout << "\nEnter Order ID: ";
    cin >> orderID;
    orders.push_back(Order(orderID, totalAmount, "2024-12-25", "Pending"));
    
    //After placing order initialize cart size = 0
    cartSize = 0; 
    for (int i = 0; i < 100; ++i) {
        products[i] = Product(0, "", "", 0, 0);  
        quantities[i] = 0;  
    }
    
    cout << "\nOrder placed successfully!" << endl;
    cout << "Thank you for shopping with us!" << endl;
}

bool Cart::isEmpty() {
    return cartSize == 0;
}

// ...Admin Class...
class Admin : public User {
	private:
		vector<Product> products;
		vector<Category> categories;
	public:
		void displayStock(vector<Product>& products);
		void addProduct(vector<Product>& products);
		void removeProduct(vector<Product>& products);
		void addCategory();
		void removeCategory();
		void updateProductStock();
		void logout();
};

void Admin::displayStock(vector<Product>& products) {
	cout<<"\nCurrent Stock: "<<endl;
	cout<<"Category | Product ID | Product Name | Stock Quantity | Price\n";
	for(int i=0;i<products.size();i++) {
		cout<<products[i].getCategory()<<" | "<<products[i].get_ProductID()<<" | "<<products[i].get_ProductName()<<" | "<<products[i].get_StockQuantity()<<" | "<<products[i].getPrice()<<endl;
	}
	cout<<"\nTotal products in stock : "<<products.size()<<endl;
}

void Admin::addProduct(vector<Product>& products) {
	string name, category;
	int id, price, stockQuantity;
	cout<<"\nEnter the following details for the new product: "<<endl;
	cout<<"Enter product name: ";
	cin>>name;
	cout<<"Enter category: ";
	cin>>category;
	cout<<"Enter product ID : ";
	cin>>id;
	cout<<"Enter stock quantity : ";
	cin>>stockQuantity;
	cout<<"Enter price : $";
	cin>>price;
	products.push_back(Product(id, name, category, price, stockQuantity));
	cout<<"\nProduct added successfully!"<<endl;
}

void Admin::removeProduct(vector<Product>& products) {
	int id;
	cout<<"\nEnter the product Id to remove : ";
	cin>>id;
	for(int i=0;i<products.size();i++) {
		if(products[i].get_ProductID()==id) {
			cout << "\nProduct found!" << endl;
            cout << "Product ID: " << products[i].get_ProductID() << endl;
            cout << "Product Name: " << products[i].get_ProductName() << endl;
            cout << "Category: " << products[i].getCategory() << endl;
            cout << "Stock Quantity: " << products[i].get_StockQuantity() << endl;
            cout << "Price: " << products[i].getPrice() << endl;
            
            char confirm;
            cout<<"\nAre you sure you want to remove this product? (y/n): ";
            cin>>confirm;
            
            if(confirm=='y' || confirm=='Y') {
            	for(int j=i;j<products.size()-1;j++) {
            		products[j]=products[j+1];
				}
				products.pop_back();
				cout<<"Product removed successfully!"<<endl;
				return;
			} else {
				cout<<"Product removal canceled."<<endl;
				return;
			}
		} else {
			cout<<"Product with ID "<<id<<" not found!"<<endl;
		}
	}
}

void Admin::addCategory() {
	int catID;
	string catName;
	cout<<"\nEnter the ID of new category: ";
	cin>>catID;
	cout<<"Enter the name of new category: ";
	cin>>catName;
	categories.push_back(Category(catID,catName));
	cout<<"Category Added Successfully!"<<endl;
}

void Admin::removeCategory() {
	string cat;
	cout<<"\nEnter the name of the category you want to remove: ";
	cin>>cat;
	bool categoryExist = false;
	for(int i=0;i<products.size();i++) {
		if(products[i].getCategory()==cat) {
			categoryExist = true;
			break;
		} 
	} 
	if(!categoryExist) {
		cout<<"Category "<<cat<<" not found!"<<endl;
		return;
	}
	
	char confirm;
	cout<<"This will remove all products from the category "<<cat<<endl;
	cout<<"\nAre you sure you want to remove this category? (y/n): ";
	cin>>confirm;
	
	if (confirm == 'y' || confirm == 'Y') {
        for (int i = 0; i < products.size();) {
            if (products[i].getCategory() == cat) {
                for (int j = i; j < products.size() - 1;j++) {
                    products[j] = products[j + 1];
                }
                products.pop_back();
            } else {
                ++i; 
            }
        }
        cout << "Category "<< cat << " removed successfully!" << endl;
    } else {
        cout << "Category removal canceled." << endl;
    }
}

void Admin::updateProductStock() {
	int id,qty;
	cout<<"Enter product ID to update stock: ";
	cin>>id;
	
	for(int i=0;i<products.size();i++) {
		if(products[i].get_ProductID()==id) {
			cout << "\nProduct found!" << endl;
            cout << "Product ID: " << products[i].get_ProductID() << endl;
            cout << "Product Name: " << products[i].get_ProductName() << endl;
            cout << "Category: " << products[i].getCategory() << endl;
            cout << "Stock Quantity: " << products[i].get_StockQuantity() << endl;
            cout << "Price: " << products[i].getPrice() << endl;
            cout<<"Enter new stock quantity: ";
            cin>>qty;
            products[i].setStockQuantity(qty);
            cout<<"Stock updated successfully!"<<endl;
            return;
        } else {
        	cout<<"Product with ID "<<id<<" not found!"<<endl;
		}
	}
}

void Admin::logout() {
	cout<<"\nLogging Out...\nYou have successfully logged out."<<endl;
	cout<<"Thank you for visiting the Online Shopping System."<<endl;
}

// ...Customer Class...
class Customer : public User {
	private:
	    Cart cart;  
	    vector<Order> orders; 
	public:
	    void viewProducts(vector<Product> &products);
	    void addToCart(vector<Product> &products);
	    void viewCart();
	    void placeOrder(vector<Product> &allProducts);
	    void cancelOrder();
	    void viewOrderHistory();
	    void logout();
};

void Customer::viewProducts(vector<Product> &products) {
    cout << "\nAvailable Products: "<<endl;
    for (int i = 0; i < products.size(); ++i) {
        cout << "Product ID: " << products[i].get_ProductID()<< " | Name: " << products[i].get_ProductName()<< " | Category: " << products[i].getCategory()<< " | Price: $" << products[i].getPrice()<< " | Stock: " << products[i].get_StockQuantity() << endl;
    }
}

void Customer::addToCart(vector<Product> &products) {
    int productID, quantity;
    cout << "\nEnter the Product ID to add to cart: ";
    cin >> productID;
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].get_ProductID() == productID) {
        	cout << "Available stock: " << products[i].get_StockQuantity() << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
            cart.addToCart(products[i], quantity);
            return; 
        }
    }
    cout << "\nProduct not found!" << endl;
}

void Customer::viewCart() {
    cart.viewCart();
}

void Customer::placeOrder(vector<Product> &allProducts) {
    cart.placeOrder(orders,allProducts);
}

void Customer::cancelOrder() {
    if (orders.size() == 0) {
        cout << "\nNo orders found to cancel!" << endl;
        return;
    }
    cout << "Order History: " << endl;
    for (int i = 0; i < orders.size(); ++i) {
        cout << "Order #" << i + 1 << " | Status: " << orders[i].get_OrderStatus() << endl;
    }
    int orderID;
    cout << "\nEnter the Order ID to cancel: ";
    cin >> orderID;
    bool found = false;
    int orderIndex = -1;
    for (int i = 0; i < orders.size(); ++i) {
        if (orders[i].getOrderID() == orderID) {
            found = true;
            orderIndex = i;
            break; 
        }
    }
    if (found) {
        for (int i = orderIndex; i < orders.size() - 1; ++i) {
            orders[i] = orders[i + 1]; 
        }
        orders.pop_back();
        cout << "Order canceled successfully!" << endl;
    } else {
        cout << "Order not found!" << endl;
    }
}

void Customer::viewOrderHistory() {
    if (orders.size() == 0) {
        cout << "No order history available!" << endl;
        return;
    }
    cout << "Order History: "<<endl;
    for (int i = 0; i < orders.size(); i++) {
        orders[i].displayOrderStatus();
    }
}

void Customer::logout() {
    cout<<"\nLogging Out...\nYou have successfully logged out."<<endl;
	cout<<"Thank you for visiting the Online Shopping System."<<endl;
}

int main()
{
	vector<User> users;
	vector<Product> products;
	Admin adminUser;
	Customer customerUser;
	bool isAdmin=false;
	bool loginSuccessful=false;
	int choice;
	
	while(true) {
		cout<<"\nWELCOME TO THE LOGIN PAGE!"<<endl;
		cout<<"1. Create a New Account"<<endl;
		cout<<"2. Login"<<endl;
		cout<<"3. Forgot Password or Username"<<endl;
		cout<<"4. Go to Shopping Menu"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		if(choice==1) {
			User newUser;
			newUser.createAccount();
			users.push_back(newUser);
			cout<<"Account created successfully!"<<endl;
			
			loginSuccessful = true;
            if (newUser.getRole() == "admin" || newUser.getRole() == "Admin" || newUser.getRole() == "ADMIN") {
                isAdmin = true;
            } else {
                isAdmin = false;
            }
		}
		
		else if(choice==2) {
			if(users.size()==0) {
				cout<<"No accounts found! Please create an account first."<<endl;
			} else {
				for (User& user : users) {
                if (user.login()) {
                    loginSuccessful = true;
                    if (user.getRole() == "admin" || user.getRole() == "Admin" || user.getRole() == "ADMIN") {
                        isAdmin = true;
                    } else {
                        isAdmin = false;
                    }
                    break;
                }
            	}
			}
		} 
		
		else if(choice==3) {
			bool found=false;
			for(User& user : users) {
				user.recoverAccount();
			}
		}
		
		else if(choice==4) {
			if(loginSuccessful) {
				if(isAdmin) {
					while(true) {
						cout << "\nSHOPPING MENU (ADMIN)" << endl;
		                cout << "1. Display Current Stock" << endl;
		                cout << "2. Add New Product" << endl;
		                cout << "3. Remove Product" << endl;
		                cout << "4. Add New Category" << endl;
		                cout << "5. Remove Category" << endl;
		                cout << "6. Logout" << endl;
		                cout << "\nEnter your choice: ";
		                cin >> choice;
                
		                if(choice==1) {
		                	adminUser.displayStock(products);
						} else if(choice==2) {
							adminUser.addProduct(products);
						} else if(choice==3) {
							adminUser.removeProduct(products);
						} else if(choice==4) {
							adminUser.addCategory();
						} else if(choice==5) {
							adminUser.removeCategory();
						} else if(choice==6) {
							adminUser.logout();
							break;
						} else {
							cout << "Invalid choice!" << endl;
						}
					}
				}
				
			 	else {
					while(true) {
						cout << "\nSHOPPING MENU (CUSTOMER)" << endl;
		                cout << "1. View Products" << endl;
		                cout << "2. Add to Cart" << endl;
		                cout << "3. View Cart" << endl;
		                cout << "4. Place Order" << endl;
		                cout << "5. Cancel Order"<<endl;
		                cout << "6. View Order History" << endl;
		                cout << "7. Logout" << endl;
		                cout << "\nEnter your choice: ";
		                cin >> choice;
		                
		                if(choice==1) {
		                	customerUser.viewProducts(products);
						} else if(choice==2) {
							customerUser.addToCart(products);
						} else if(choice==3) {
							customerUser.viewCart();
						} else if(choice==4) {
							customerUser.placeOrder(products);
						} else if(choice==5) {
							customerUser.cancelOrder();
						} else if(choice==6) {
							customerUser.viewOrderHistory();
						}else if(choice==7) {
							customerUser.logout();
							break;
						} else {
							cout << "Invalid choice!" << endl;
						}
					}
				}	
			}
		}
	}
	return 0;
}