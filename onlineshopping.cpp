#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Order
{
    int orderID;
    string customerName;
    int items;
    int price;
};

int main()
{
    vector<Order> orders;
    int n;
     cout << "Enter number of orders: ";
     cin >> n;

    for (int i = 0; i < n; i++)
    {
        Order o;
        cout << "\nEnter Order ID: ";
        cin >> o.orderID;
        cout << "Enter Customer Name: ";
        cin >> o.customerName;
        cout << "Enter Number of Items: ";
        cin >> o.items;
        cout << "Enter Price per Item: ";
        cin >> o.price;

        if (o.items > 0 && o.price > 0)
        {
            orders.push_back(o);
        }
        else
        {
            cout << "Invalid values!\n";
            i--;
        }
    }

    ofstream outFile("priority_orders.txt");
    if (!outFile)
    {
        cout << "File not opened!";
        return 0;
    }
          for (int i = 0; i < orders.size(); i++)
    {
        int total = orders[i].items * orders[i].price;
         if (total > 5000)
        {
            outFile << orders[i].orderID << " "<< orders[i].customerName << " "<< total << endl;
        }
    }
    outFile.close();
    ifstream inFile("priority_orders.txt");
    if (!inFile)
    {
        cout << "File not opened!";
        return 0;
    }
    cout << "\nPriority Orders:\n";
    int id, total;
    string name;
       while (inFile >> id >> name >> total)
    {
        cout << "Order ID: " << id
             << " Customer: " << name
             << " Total Bill: " << total << endl;
    }
    inFile.close();
    return 0;
}
