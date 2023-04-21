#include <iostream>
#include <cstring>
using namespace std;
void show(string arr[],float price[],int num) {
	int i;
	
	for (i = 0; i < num;i++) {
		cout << i+1 << " - " << arr[i]  << " " << price[i] << "$" << endl;
	}
}
void menu(string arr[]) {
	int i;
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "The Menu" << endl << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	for (i = 0; i < 4; i++) {
		cout << i + 1 << " - " << arr[i] << endl;
	}
	cout << endl << "---------------------------------------------------------------------" << endl;
}
void invalid() {
	cout << "Invalid Process!" << endl;
}
void add(string arr, string *order,double price,float *order1,int count,int *perr,int per){
	order[count] = arr;
	order1[count] = price;
	perr[count] = per;
	
}
int main() {
	char ch;
	int chc, th, per, count = 0;
	double result = 0;
	string name, payment, surname;
	int pay,tie;
	string coffees[] = { "Espresso","Double Espresso","Red Eye","Black Eye","Americano","Long Black","Macchiato","Long Macchiato","Cortado","Breve","Cappuccino","Flat White","Cafe Latte","Mocha","Vienna","Affogato","Cafe au Lait","Iced Coffee" };
	string desserts[] = { "Chocolate Cake","Lemon Cake","Cheesecake","Cookies","Biscuits","Apple Pie","Profiteroles","Ice Creams","Chocolate Bars","Fruit Salad" };
	string others[] = { "Bottle Of Water (500ml)","Lemonade","Chocolate Milk","Hot Chocolate","Tea","Green Tea","Mixed Juice" };
	string milkshakes[] = { "Chocolate Milkshake", "Strawberry Milkshake", "Blueberry Milkshake", "Chai Tea Latte Milkshake", "Oreo Milkshake", "Peppermint Bark Milkshake", "Chocolate Peanut Butter Banana Shake", "Shamrock Shake", "PB Cookie Dough Milkshake","Kahlua Mocha Milkshake" };
	string table[] = { "Coffees","Desserts","Milkshakes","Other Drinks" };
	string style[] = { "Small","Medium","Big" };
	float coprice[] = { 5.99,6.99,6.00,6.00,5.99,7.99,8.79,10.99,5.99,6.39,6.77,5.99,6.99,6.99,5.99,6.79,7.99,6.89 };
	float deprice[] = { 14.99,14.99,15.99,5.99,4.99,16.99,9.99,6.99,7.99,10.99 };
	float otprice[] = { 2.99,4.99,5.99,6.99,4.99,5.99,7.99 };
	float mlprice[] = { 8.99,7.89,9.39,10.99,11.99,8.99,9.99,9.75,10.49,11.99 };
	string order[20] = { "" };
	float order1[20] = { 0 };
	float b=0,rate;
	int perr[20] = { 0 };
	cout << "Welcome To MEG Coffe Shop!" << endl << endl;
	do {
		menu(table);
		cout << endl << "Please enter your order : ";
		cin >> chc;
		if (chc == 1) {
			cout << "---------------------------------------------------------------------" << endl << endl;
			cout << "The Coffees' List" << endl << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
			show(coffees, coprice, (sizeof(coffees) / sizeof(string)));
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
		else if (chc == 2) {
			cout << "---------------------------------------------------------------------" << endl << endl;
			cout << "The Desserts' List" << endl << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
			show(desserts, deprice, (sizeof(desserts) / sizeof(string)));
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
		else if (chc == 4) {
			cout << "---------------------------------------------------------------------" << endl << endl;
			cout << "The Other Drinks' List" << endl << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
			show(others, otprice, (sizeof(others) / sizeof(string)));
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
		else if (chc == 3) {
			cout << "---------------------------------------------------------------------" << endl << endl;
			cout << "The Milkshakes' List" << endl << endl;
			cout << "---------------------------------------------------------------------" << endl << endl;
			show(milkshakes, mlprice, (sizeof(milkshakes) / sizeof(string)));
			cout << "---------------------------------------------------------------------" << endl << endl;
		}
		else {
			invalid();
		}
		cout << "Please choose the choice want to order : ";
		cin >> th;
		cout << "Please choose the amount of your order (per) : ";
		cin >> per;

		if (th > 0 && th < 19) {
			if (chc == 1 && th >= 1 && th <= 18) {
				b = coprice[th - 1] * per;
				result += (coprice[th - 1] * per);
				add(coffees[th - 1], order, b, order1, count,perr,per);
			}
			else if (chc == 2 && (th + 18) >= 19 && (th + 18) <= 28) {
				b = deprice[th - 1] * per;
				result += (deprice[th - 1] * per);
				add(desserts[th - 1], order, b, order1, count,perr,per);
			}
			else if (chc == 3 && (th + 28) >= 29 && (th + 28) <= 38) {
				b = mlprice[th - 1] * per;
				result += (mlprice[th - 1] * per);
				add(milkshakes[th - 1], order, b, order1, count,perr,per);
			}
			else if (chc == 4 && (th + 38) >= 39 && (th + 38) <= 45) {
				b = otprice[th - 1] * per;
				result += (otprice[th - 1] * per);
				add(others[th - 1], order, b, order1, count,perr,per);
			}
			else {
				invalid();
			}
		}
		else {
			invalid();
		}
		cout << "Current Total : " << result << endl;
		cout << "Do you want to continue ordering (Y / N) : ";
		cin >> ch;
		count += 1;
	} while (ch == 'Y' || ch == 'y');
	cout << "Please enter your name : ";
	cin >> name;
	cout << "Please enter your surname : ";
	cin >> surname;
	cout << "Please enter your payment type (1 - Cash, 2 - Credit Card) : ";
	cin >> pay;
	if (pay == 1) {
		payment = "Cash";
	}
	else if (pay == 2) {
		payment = "Credit Card";
		cout << "The Type Of Paying With Credit Card" << endl << "1 - Pay Within 0-3 Months" << endl << "2 - Pay Within 3-6 Months" << endl << "3 - Pay Within 6-9 Months" << endl;
		cout << "Please enter your order : ";
		cin >> tie;
		switch (tie) {
		case 1:
			rate = 0.08;
			result = result + result * rate;
			break;
		case 2:
			rate = 0.12;
			result = result + result * rate;
			break;
		case 3:
			rate = 0.16;
			result = result + result * rate;
			break;
		default:
			invalid();
			break;
		}
	}
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "The Bill" << endl << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Name : " << name << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Surname : " << surname << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Payment Type : " << payment << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Product" << "           " << "Per" << "           " << "Price" << endl;
	for (int i = 0; i < count; i++) {
		if (pay == 2) {
			order1[i] = order1[i] + order1[i] * rate;
		}
		cout << "---------------------------------------------------------------------" << endl;
		cout << order[i] << "           " << " X "  << perr[i] << "           " << order1[i] << "$" << endl;
	}
	if (pay == 2) {
		cout << "---------------------------------------------------------------------" << endl;
		rate = rate * 100;
		cout << "Bank Rate : " << "%" << rate << endl;

	}
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Total Price : " << result << "$" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Thanks for choosing us! Have a nice day!" << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
