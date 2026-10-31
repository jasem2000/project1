#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define max 100

using namespace std;

struct visitor
{
    string name;
    string number;
    string product;
    string address;
    string score;
};

struct visitororder
{
    string number;
    string product;
    string datatime;
    string delivery;
    string price;
    string discount;
    string factor;
    string deliverydate;
    string deliverydate2;
};

//// Functions Definition

string DataTime();
void Delivery(visitor M[], int VisitorIndex);
void RegisterDeliveryDate(visitororder N[], visitor M[], int OrderCount, int VisitorCount);
void RghitInOrderList(visitororder N[], visitor M[], int OrderIndex, int VisitorIndex);
void ContoroPassword(int m);
void LoadVisitors(visitor M[], int &count);
void LoadOrders(visitororder N[], visitor M[], int &count);
void AddVisitor(visitor M[], int &count, int VisitorCount);
void AddProduct(visitororder N[], int &count);
void ManagerPart(char line[100], char filename[100]);
void EditOrder(visitororder N[], visitor M[], int &OrderCount);
void SaveOrders(visitororder N[], visitor M[], int count);
void SaveVisitors(visitor M[], int count);
void ShowOrder(visitororder N[], visitor M[], int OrderCount, int VisitorIndex);
void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
void SerchVisitor(visitororder N[], visitor M[], int OrderCount, int VisitorCount);
void RegisterOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);

//***Load_Visitors***

void LoadVisitors(visitor M[], int &count)
{
    count = 0;
    ifstream f;
    f.open("visitors.txt");
    if (!f)
    {

        return;
    }

    while (count < max && getline(f, M[count].name, '|'))
    {

        getline(f, M[count].number, '|');
        getline(f, M[count].product, '|');
        // getline(f, M[count].address);
        getline(f, M[count].address, '|');
        getline(f, M[count].score);
        count++;
    }
    f.close();
}

//***Load_Orders***

void LoadOrders(visitororder N[], visitor M[], int &count)
{

    count = 0;
    ifstream g;
    g.open("orders.txt");
    if (!g)
    {
        return;
    }

    while (count < max && getline(g, N[count].number, '|'))
    {
        // getline(g, N[count].number, '|');
        getline(g, N[count].product, '|');
        getline(g, N[count].price, '|');
        getline(g, N[count].discount, '|');
        getline(g, N[count].factor, '|');
        getline(g, N[count].delivery, '|');
        getline(g, N[count].datatime, '|');
        getline(g, N[count].deliverydate);
        // getline(g, N[count].deliverydate2);

        count++;
    }
    g.close();
}

//***Register_Order***

void RegisterOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{
    cout << "=====Register Order=====" << endl;
    string Proud;
    cout << " Enter Name's product :";
    getline(cin >> ws, Proud);
    cout << "-----------------------" << endl;
    bool found1 = false;

    for (int i = 0; i < VisitorCount; i++)
    {

        if (M[i].product == Proud)
        {

            cout << "Name :" << M[i].name << endl;
            cout << "Number :" << M[i].number << endl;
            cout << "Product :" << M[i].product << endl;
            cout << "Address :" << M[i].address << endl;
            cout << "-----------------------" << endl;
            found1 = true;
        }
    }
    if (!found1)
    {
        cout << "Product not found...." << endl;
        return;
    }

    string NUMBER;

    cout << "Enter visitor's Number :";
    getline(cin, NUMBER);

    int index = -1;
    for (int i = 0; i < VisitorCount; i++)
    {
        if (M[i].number == NUMBER && M[i].product == Proud)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Incorrect number...." << endl;
        return;
    }

    cout << "Enter Name of product :";
    getline(cin >> ws, N[OrderCount].product);

    cout << "Enter Price of product :";
    getline(cin >> ws, N[OrderCount].price);

    cout << "Enter discount of product :";
    getline(cin >> ws, N[OrderCount].discount);

    cout << "Enter Delivery :";
    getline(cin >> ws, N[OrderCount].delivery);

    RghitInOrderList(N, M, OrderCount, index);
    cout << "-----------------------" << endl;
    OrderCount++;
}

//***Rghit_In_Order_List***

void RghitInOrderList(visitororder N[], visitor M[], int OrderIndex, int VisitorIndex)
{
    ofstream g;
    g.open("orders.txt", ios::app);
    if (!g)
    {
        cout << "Can not open the file...." << endl;
        return;
    }
    // M[VisitorIndex].datatime = DataTime();
    N[OrderIndex].datatime = DataTime();
    long long int calculatprice = 0;
    long long int price = stof(N[OrderIndex].price), discount = stof(N[OrderIndex].discount);
    calculatprice += price - ((price * discount) / 100);
    N[OrderIndex].factor = to_string(calculatprice);
    g << M[VisitorIndex].number << "|" << N[OrderIndex].product << "|" << N[OrderIndex].price << "|" << N[OrderIndex].discount << "|" << N[OrderIndex].factor << "|" << N[OrderIndex].delivery << "|" << N[OrderIndex].datatime << '|' << N[OrderIndex].deliverydate << endl;
    g.close();
}

///***Register_Delivery_Date***

void RegisterDeliveryDate(visitororder N[], visitor M[], int OrderCount, int VisitorCount)
{
    string NUMBER;
    cout << "===== Register Delivery Date =====" << endl;
    cout << "Enter Number of visitor :";
    cin >> NUMBER;
    cin.ignore();
    bool found = false;
    int Visitorindex = -1;

    for (int i = 0; i < OrderCount; i++)
    {

        if (NUMBER == N[i].number)
        {

            for (int j = 0; j < VisitorCount; j++)
            {
                if (NUMBER == M[j].number)
                {
                    Visitorindex = j;

                    cout << "Index :" << i << endl;
                    cout << "Name :" << M[j].name << endl;
                    cout << "Product :" << N[i].product << endl;
                    cout << "Address :" << M[j].address << endl;
                    cout << "==============" << endl;
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found)
    {
        cout << "Order not found!" << endl;
        return;
    }

    int index;

    cout << "\nEnter order index: ";

    cin >> index;
    cin.ignore();

    char confirm;
    if (index >= 0 || index <= OrderCount)
    {
        cout << "==============" << endl;
        cout << "Are you sure the order[" << N[index].product << "] arived ? (y/n): ";

        cin >> confirm;
        cin.ignore();

        N[index].deliverydate = DataTime();

        string oldtime = N[index].deliverydate;

        if (confirm == 'y' || confirm == 'Y')
        {
            N[index].deliverydate2 = DataTime();
            string newtime = N[index].deliverydate2;
            if (oldtime == newtime)
            {

                // cout << "Delivery date :" << N[index].deliverydate << endl;

                // cout << "this order alred exist...." << endl;
                // Delivery(M, Visitorindex);
                // cout << "Successfully order" << endl;
            }
            else
            {
                cout << "Delivery date :" << N[index].deliverydate << endl;
                // cout << "this order alred exist...." << endl;
                Delivery(M, Visitorindex);
                cout << "Successfully order" << endl;
            }
        }
        else
        {
            cout << "Unsuccessfully order...." << endl;
            return;
        }
    }
    else
    {
        cout << "try againe...." << endl;
        return;
    }

    // SaveOrders(N, M, OrderCount);
    string lines[max];
    string line;
    int count = 0;

    ifstream f;
    f.open("orders.txt");

    while (count < max && getline(f, line))
    {
        lines[count] = line;
        count++;
    }

    f.close();

    for (int i = 0; i < count; i++)
    {
        if (i == index)
        {
            lines[i] += "|" + N[index].deliverydate;
        }
    }

    ofstream g;
    g.open("orders.txt");

    for (int i = 0; i < count; i++)
    {
        g << lines[i] << endl;
    }

    g.close();
}

//***Delivery***

void Delivery(visitor M[], int VisitorIndex)
{
    int Delay;
    string status;
    cout << "Enter[-1] if the order arrived early." << endl;
    cout << "Enter [0] if the order arrived without delay." << endl;
    cout << "Enter 1 if the order is delayed." << endl;
    cout << "Enter number :";
    cin >> Delay;
    cin.ignore();

    string lines[max];
    string line;
    int count = 0;

    ifstream f;
    f.open("visitors.txt");

    while (count < max && getline(f, line))
    {
        lines[count] = line;
        count++;
    }

    f.close();

    for (int i = 0; i < count; i++)
    {
        stringstream ss(lines[i]);
        string name, number;

        getline(ss, name, '|');
        getline(ss, number, '|');

        if (M[VisitorIndex].number == number)
        {
            if (Delay <= 0)
            {
                lines[i] += "|KHosh Ghol!|";
                cout << "KHosh Ghol!" << endl;
            }
            else
            {
                lines[i] += "|Bad Ghol!|";
                cout << "Bad Ghol!" << endl;
            }

            break;
        }
    }
    ofstream g;
    g.open("visitors.txt");

    for (int i = 0; i < count; i++)
    {
        g << lines[i] << endl;
    }

    g.close();
}

//***Data_Time***

string DataTime()
{
    struct tm newtime;
    __time64_t long_time;
    char timebuf[26];

    _time64(&long_time);
    _localtime64_s(&newtime, &long_time);
    asctime_s(timebuf, 26, &newtime);

    return to_string(1900 + newtime.tm_year) + "/" +
           to_string(1 + newtime.tm_mon) + "/" +
           to_string(newtime.tm_mday);
}

//***Save_Visitors***

void SaveVisitors(visitor M[], int count)
{
    ofstream f("visitors.txt");

    if (!f)
    {
        cout << "Cannot open visitors.txt!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        f << M[i].name << "|" << M[i].number << "|" << M[i].product << "|" << M[i].address << "|" << M[i].score << endl;
    }

    f.close();
}

//***Save_Orders ***

void SaveOrders(visitororder N[], visitor M[], int count)
{
    ofstream f("orders.txt");

    if (!f)
    {
        cout << "Cannot open orders.txt!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        f << N[i].number << "|" << N[i].product << "|" << N[i].price << "|" << N[i].discount << "|" << N[i].factor << "|" << N[i].delivery << "|" << N[i].datatime << "|" << N[i].deliverydate << endl;
    }

    f.close();
}

//***Edit_Visitor***

void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{
    if (VisitorCount == 0)
    {
        cout << "No visitors registered!" << endl;
        return;
    }

    int Choice;

    cout << "\n===== Find Visitor =====" << endl;
    cout << "1. Search by Name" << endl;
    cout << "2. Search by Phone Number" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> Choice;
    cin.ignore();

    if (Choice == 3)
        return;

    if (Choice != 1 && Choice != 2)
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    string NAME, NUMBER;

    if (Choice == 1)
    {
        cout << "Enter visitor name: ";
        getline(cin >> ws, NAME);
    }

    else if (Choice == 2)
    {
        cout << "Enter visitor number : ";
        getline(cin >> ws, NUMBER);
    }
    else
    {
        cout << "Visitor Not found.... ";
    }

    int index = -1;

    for (int i = 0; i < VisitorCount; i++)
    {
        if ((Choice == 1 && M[i].name == NAME) || (Choice == 2 && M[i].number == NUMBER))
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Visitor not found!" << endl;
        return;
    }

    cout << "\n===== Visitor Information =====" << endl;
    cout << "Name: " << M[index].name << endl;
    cout << "Number: " << M[index].number << endl;
    cout << "Product :" << M[index].product << endl;
    cout << "Address: " << M[index].address << endl;
    cout << "Score: " << M[index].score << endl;

    int choice;

    cout << "\n===== Edit Visitor =====" << endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Edit Phone Number" << endl;
    cout << "3. Edit Address" << endl;
    cout << "4. Delete Visitor" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= 3)
    {

        string oldNumber = M[index].number;

        if (choice == 1)
        {
            cout << "Enter new name: ";
            getline(cin >> ws, M[index].name);
        }
        else if (choice == 2)
        {
            string newNumber;

            cout << "Enter new phone number: ";
            getline(cin >> ws, newNumber);

            for (int i = 0; i < VisitorCount; i++)
            {
                if (i != index && M[i].number == newNumber)
                {
                    cout << "This number already exists!" << endl;
                    return;
                }
            }

            M[index].number = newNumber;

            for (int i = 0; i < OrderCount; i++)
            {
                if (N[i].number == oldNumber)
                {
                    N[i].number = newNumber;
                }
            }

            SaveOrders(N, M, OrderCount);
        }
        else if (choice == 3)
        {
            cout << "Enter new address: ";
            getline(cin >> ws, M[index].address);
        }

        SaveVisitors(M, VisitorCount);

        cout << "Visitor updated successfully!" << endl;
    }

    else if (choice == 4)
    {
        char confirm;

        cout << "Are you sure you want to delete " << M[index].name << "? (y/n): ";

        cin >> confirm;
        cin.ignore();

        if (confirm == 'y' || confirm == 'Y')
        {

            for (int i = index; i < VisitorCount - 1; i++)
            {
                M[i] = M[i + 1];
            }

            VisitorCount--;

            SaveVisitors(M, VisitorCount);

            cout << "Visitor deleted successfully!" << endl;
        }
        else
        {
            cout << "Deletion cancelled." << endl;
        }
    }

    else if (choice == 5)
    {
        return;
    }

    else
    {
        cout << "Invalid choice!" << endl;
    }
}

//***Add_Visitor***

void AddVisitor(visitor M[], int &count, int VisitorCount)
{

    cout << "Enter name of visitor :";
    getline(cin >> ws, M[count].name);

    cout << "Enter Phone number of visitor :";
    getline(cin >> ws, M[count].number);

    string oldNumber = M[VisitorCount].number;

    string newNumber = M[count].number;

    for (int i = 0; i < VisitorCount; i++)
    {
        if (i != count && M[i].number == newNumber)
        {
            cout << "This number already exists!" << endl;
            return;
        }
    }
    //  cout << "Enter Phone number of visitor :";
    // getline(cin >> ws, M[count].number);

    cout << "Enter product of visitor:";
    getline(cin >> ws, M[count].product);

    cout << "Enter addres of visitor :";
    getline(cin >> ws, M[count].address);

    ofstream f;
    f.open("visitors.txt", ios::app);
    if (!f)
    {
        cout << "Can not open the file...." << endl;
        return;
    }

    M[count].score = "0";
    f << M[count].name << "|" << M[count].number << "|" << M[count].product << "|" << M[count].address << '|' << M[count].score << endl;

    f.close();
    count++;
}

//***Serch_Visitor***

void SerchVisitor(visitororder N[], visitor M[], int OrderCount, int VisitorCount)
{
    int choice;
    cout << "====Search Visitor====" << endl;
    cout << "1_Search by Name " << endl;
    cout << "2_Search by Phone number" << endl;
    cout << "3_Exit" << endl;
    cout << "Enter Number :";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        string NAME;
        cout << "Enter Name :";
        getline(cin >> ws, NAME);

        bool found = false;
        for (int i = 0; i < VisitorCount; i++)
        {
            if (M[i].name == NAME)
            {
                cout << "Name :" << M[i].name << endl;
                cout << "Number :" << M[i].number << endl;
                cout << "Address :" << M[i].address << endl;
                cout << "===================" << endl;
                ShowOrder(N, M, OrderCount, i);
                found = true;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }
    else if (choice == 2)
    {
        string NUMBER;
        cout << "Enter Number :";
        getline(cin >> ws, NUMBER);

        bool found = false;
        for (int i = 0; i < VisitorCount; i++)
        {
            if (M[i].number == NUMBER)
            {
                cout << "Name :" << M[i].name << endl;
                cout << "Number :" << M[i].number << endl;
                cout << "Address :" << M[i].address << endl;
                cout << "===================" << endl;
                ShowOrder(N, M, OrderCount, i);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "Tray agine..." << endl;
    }
}

//***Show_Order***

void ShowOrder(visitororder N[], visitor M[], int OrderCount, int VisitorIndex)
{
    int choice;
    cout << "1_Show Orders visitor :" << endl;
    cout << "2_Exit :" << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {
            if (N[i].number == M[VisitorIndex].number)
            {

                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "price :" << N[i].price << endl;
                cout << "discount :" << N[i].discount << endl;
                cout << "factor :" << N[i].factor << endl;
                cout << "Delivery :" << N[i].delivery << endl;
                cout << "===================" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No orders for this visitor..." << endl;
        }
    }
    else if (choice == 2)
    {
        return;
    }
    else
    {
        cout << "Try again..." << endl;
    }
}

///***Search_Orders ***

void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{

    int choice;
    cout << "====Search Order====" << endl;
    // cout << "1_Search by Phone number" << endl;
    cout << "2_Search by products " << endl;
    cout << "3_Exit" << endl;
    cout << "Enter number :";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string NUMBER;
        cout << "Enter number of visitor :";
        getline(cin >> ws, NUMBER);
        cout << "-----------------------" << endl;

        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {
            if (N[i].number == NUMBER)
            {
                found = true;
                for (int j = 0; j < VisitorCount; j++)
                {

                    if (N[i].number == M[j].number)
                    {
                        cout << "Order Date :" << N[i].datatime << endl;
                        cout << "Delivery Date :" << N[i].deliverydate << endl;
                        cout << "Name :" << M[j].name << '\t' << "Address :" << M[j].address << endl;

                        break;
                    }
                }

                cout << "Number :" << N[i].number << '\t' << "Product :" << N[i].product << endl;
                cout << "Price :" << N[i].price << '\t' << "Discount :" << N[i].discount << endl;
                cout << "Delivery :" << N[i].delivery << endl;
                cout << "==================" << endl;
                cout << "Factor :" << N[i].factor << endl;
                cout << "==================" << endl;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }
    else if (choice == 2)
    {
        string PRODUCT;
        cout << "Enter product :";
        getline(cin >> ws, PRODUCT);
        cout << "-----------------------" << endl;
        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {

            if (N[i].product == PRODUCT)
            {
                found = true;
                for (int j = 0; j < VisitorCount; j++)
                {

                    if (N[i].number == M[j].number)
                    {
                        cout << "Order Date :" << N[i].datatime << endl;
                        cout << "Delivery Date :" << N[i].deliverydate << endl;
                        cout << "Name :" << M[j].name << '\t' << "Address :" << M[j].address << endl;

                        break;
                    }
                }

                cout << "Number :" << N[i].number << '\t' << "Product :" << N[i].product << endl;
                cout << "Price :" << N[i].price << '\t' << "Discount :" << N[i].discount << endl;
                cout << "Delivery :" << N[i].delivery << endl;
                cout << "==================" << endl;
                cout << "Factor :" << N[i].factor << endl;
                cout << "==================" << endl;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }

    else if (choice == 3)
    {
        return;
    }

    else
    {
        cout << "Tray agine..." << endl;
    }
}

//***Edit_Order ***

void EditOrder(visitororder N[], visitor M[], int &OrderCount)
{
    if (OrderCount == 0)
    {
        cout << "No orders registered!" << endl;
        return;
    }

    string number;
    cout << "Enter visitor phone number: ";
    getline(cin >> ws, number);

    bool found = false;

    for (int i = 0; i < OrderCount; i++)
    {
        if (N[i].number == number)
        {
            cout << "Index :" << i << endl;
            cout << "Product: " << N[i].product << endl;
            cout << "Price: " << N[i].price << endl;
            cout << "Discount: " << N[i].discount << endl;
            cout << "Delivery : " << N[i].delivery << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Order not found!" << endl;
        return;
    }

    int index;
    cout << "\nEnter order index: ";
    cin >> index;
    cin.ignore();

    if (index < 0 || index >= OrderCount || N[index].number != number)
    {
        cout << "Invalid order index!" << endl;
        return;
    }
    // if (index == -1)
    // {
    //     cout << "order not found...." << endl;
    //     return;
    // }

    int choice;

    cout << "\n1. Edit product" << endl;
    cout << "2. Edit price" << endl;
    cout << "3. Edit discount" << endl;
    cout << "4. Edit Delivery" << endl;
    cout << "5. Delete order" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter number : ";

    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Enter new product :";
        getline(cin >> ws, N[index].product);
    }
    else if (choice == 2)
    {
        cout << "Enter new price :";
        getline(cin >> ws, N[index].price);
    }
    else if (choice == 3)
    {
        cout << "Enter new discount :";
        getline(cin >> ws, N[index].discount);
    }
    else if (choice == 4)
    {
        cout << "Enter new Delivery :";
        getline(cin >> ws, N[index].delivery);
    }
    else if (choice == 5)
    {
        char confirm;

        cout << "Delete this order? (y/n): ";
        cin >> confirm;
        cin.ignore();

        if (confirm != 'y' && confirm != 'Y')
        {
            cout << "Deletion cancelled." << endl;
            return;
        }

        for (int i = index; i < OrderCount - 1; i++)
        {
            N[i] = N[i + 1];
        }

        OrderCount--;
        cout << "Order deleted successfully!" << endl;
    }
    else if (choice == 6)
    {
        return;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    SaveOrders(N, M, OrderCount);
}

//***Manager_Part***

void ManagerPart(char line[100], char filename[100])
{

    cout << "Enter file name :";
    cin.getline(filename, 100);
    cout << "-----------------------" << endl;
    ifstream f;
    f.open(filename);
    if (!f)
    {
        cout << "Cannat open file!" << endl;
        return;
    }
    do
    {
        f >> line;
        if (f.eof())
            break;
        cout << line << endl;

    } while (!f.eof());
    f.close();
}

//***Contoro_Password***

void ContoroPassword(int m)
{
    int p;
    char g[100], k[100];
    cout << "Enter Password :";
    cin >> p;
    cin.ignore();
    if (p == 12345678)
    {
        ManagerPart(g, k);
    }

    else
    {
        cout << "Try agine...";
    }
}

//***Main***

int main()
{
    int c;
    int count = 0;
    int VisitorCount = 0;
    int OrderCount = 0;
    int b = 0, d;
    visitor M[max];
    visitororder N[max];

    LoadVisitors(M, VisitorCount);

    LoadOrders(N, M, OrderCount);

    while (true)
    {

        system("cls");
        cout << "==========Menu==========" << endl;
        cout << "1_Add Visitor" << endl;
        cout << "2_Search Visitor" << endl;
        cout << "3_Search Order" << endl;
        cout << "4_Register Order" << endl;
        cout << "5_EditV isitor" << endl;
        cout << "6_Edit Order" << endl;
        cout << "7_(For Managers Only)" << endl;
        cout << "8_Register Delivery Date" << endl;
        cout << "9_Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter number :";
        cin >> c;
        cin.ignore();

        switch (c)
        {
        case 1:
            AddVisitor(M, count, VisitorCount);
            break;
        case 2:
            SerchVisitor(N, M, OrderCount, VisitorCount);
            break;
        case 3:
            SearchOrder(N, M, OrderCount, VisitorCount);
            break;
        case 4:
            RegisterOrder(N, M, OrderCount, VisitorCount);
            break;
        case 5:
            EditVisitor(N, M, OrderCount, VisitorCount);
            break;
        case 6:
            EditOrder(N, M, OrderCount);
            break;
        case 7:
            ContoroPassword(b);
            break;

        case 8:
            RegisterDeliveryDate(N, M, OrderCount, VisitorCount);
            break;
        case 9:
            return 0;
            break;

        default:
        {
            cout << "Incorrect option...." << endl;
        }
        }

        system("Pause");
    }
}