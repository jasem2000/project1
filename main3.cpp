#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#define max 100

using namespace std;

struct visitor
{
    string name;
    string address;
    string number;
    string datatime;
};

struct visitororder
{
    string number;
    string product;
    string quality;
    string delay;
    string datatime;
};

//// Functions Definition
void RegisterDelivery();
void ContoroPassword(int m);
void LoadVisitors(visitor M[], int &count);
void LoadOrders(visitororder N[], int &count);
void RegisterVisitor(visitor M[], int &count);
void RegisterOrder(visitororder N[], int &count);
void ManagerPart(char line[100], char filename[100]);
void EditOrder(visitororder N[], int &OrderCount);
void SaveOrders(visitororder N[], int count);
void SaveVisitors(visitor M[], int count);
void ShowOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
void SerchVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
string DatatTime();

void LoadVisitors(visitor M[], int &count)
{
    ifstream f;
    f.open("visitors.txt");
    if (!f)
    {

        return;
    }
    count = 0;
    while (getline(f, M[count].name, '|') && count < max)
    {
        getline(f, M[count].number, '|');
        getline(f, M[count].address, '|');
        getline(f, M[count].datatime);
        count++;
    }
    f.close();
}

void LoadOrders(visitororder N[], int &count)
{

    ifstream g;
    g.open("orders.txt");
    if (!g)
    {
        return;
    }

    count = 0;

    while (getline(g, N[count].number, '|') && count < max)
    {
        getline(g, N[count].product, '|');
        getline(g, N[count].quality, '|');
        getline(g, N[count].delay, '|');
        getline(g, N[count].datatime);
        count++;
    }
    g.close();
}

//***SaveVisitors***
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
        f << M[i].name << "|"
          << M[i].number << "|"
          << M[i].address << "|"
          << M[i].datatime << endl;
    }

    f.close();
}
//***SaveOrders***
void SaveOrders(visitororder N[], int count)
{
    ofstream f("orders.txt");

    if (!f)
    {
        cout << "Cannot open orders.txt!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        f << N[i].number << "|"
          << N[i].product << "|"
          << N[i].quality << "|"
          << N[i].delay << "|"
          << N[i].datatime << endl;
    }

    f.close();
}

//***EditVisitor***
void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{
    if (VisitorCount == 0)
    {
        cout << "No visitors registered!" << endl;
        return;
    }

    int searchChoice;

    cout << "\n===== Find Visitor =====" << endl;
    cout << "1. Search by Name" << endl;
    cout << "2. Search by Phone Number" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> searchChoice;
    cin.ignore();

    if (searchChoice == 3)
        return;

    if (searchChoice != 1 && searchChoice != 2)
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    string key;

    if (searchChoice == 1)
    {
        cout << "Enter visitor name: ";
    }
    else
    {
        cout << "Enter phone number: ";
    }

    getline(cin >> ws, key);

    int index = -1;

    for (int i = 0; i < VisitorCount; i++)
    {
        if ((searchChoice == 1 && M[i].name == key) ||
            (searchChoice == 2 && M[i].number == key))
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
    cout << "Address: " << M[index].address << endl;
    cout << "Registration Date: " << M[index].datatime << endl;

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

            // Prevent duplicate phone numbers
            for (int i = 0; i < VisitorCount; i++)
            {
                if (i != index &&
                    M[i].number == newNumber)
                {
                    cout << "This number already exists!"
                         << endl;
                    return;
                }
            }

            M[index].number = newNumber;

            // Update the visitor's order references
            for (int i = 0; i < OrderCount; i++)
            {
                if (N[i].number == oldNumber)
                {
                    N[i].number = newNumber;
                }
            }

            SaveOrders(N, OrderCount);
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

        cout << "Are you sure you want to delete "
             << M[index].name << "? (y/n): ";

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

//***RegisterVisitor***

void RegisterVisitor(visitor M[], int &count)
{

    cout << "Enter name of visitor :";
    getline(cin >> ws, M[count].name);

    cout << "Enter Phone number of visitor :";
    getline(cin >> ws, M[count].number);

    cout << "Enter addres of visitor :";
    getline(cin >> ws, M[count].address);

    M[count].datatime = DatatTime();

    ofstream f;
    f.open("visitors.txt", ios::app);
    if (!f)
    {
        cout << "Can not open the file...." << endl;
        return;
    }

    f << M[count].name << "|" << M[count].number << "|" << M[count].address << "|" << M[count].datatime << endl;

    f.close();
    count++;
}

//***SerchVisitor***

void SerchVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{
    int choice;
    cout << "====Search Visitor====" << endl;
    cout << "1_Search by Name " << endl;
    cout << "2_Search by Phone number" << endl;
    cout << "3_Exit" << endl;
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
                cout << "Registratio Date :" << M[i].datatime << endl;
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
                cout << "Registratio Date :" << M[i].datatime << endl;
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

//***ShowOrder***

void ShowOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
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
            if (N[i].number == M[VisitorCount].number)
            {

                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "quality :" << N[i].quality << endl;
                cout << "delay :" << N[i].delay << endl;
                cout << "Registratio Date :" << N[i].datatime << endl;
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

//***RegisterOrder***

void RegisterOrder(visitororder N[], int &count)
{

    visitororder p;
    cout << "Enter Phone number of visitor :";
    getline(cin >> ws, N[count].number);

    cout << "Enter the visitor products :";
    getline(cin >> ws, N[count].product);

    cout << "Enter the visitor quality :";
    getline(cin >> ws, N[count].quality);

    cout << "Enter the visitor delay :";
    getline(cin >> ws, N[count].delay);

    N[count].datatime = DatatTime();
    ofstream g;
    g.open("orders.txt", ios::app);
    if (!g)
    {
        cout << "Can not open the file...." << endl;
        return;
    }

    g << N[count].number << "|" << N[count].product << "|" << N[count].quality << "|" << N[count].delay << "|" << N[count].datatime << endl;
    g.close();
    count++;
}

//***SearchOrders***

void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{

    int choice;
    cout << "====Search Order====" << endl;
    cout << "1_Search by Phone number" << endl;
    cout << "2_Search by products " << endl;
    cout << "3_Search by quality" << endl;
    cout << "4_Search by delay" << endl;
    cout << "5_Exit" << endl;
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string NUMBER;
        cout << "Enter number :";
        getline(cin >> ws, NUMBER);

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
                        cout << "Name :" << M[j].name << endl;
                        cout << "Address :" << M[j].address << endl;
                        cout << "Registratio Date :" << M[j].datatime << endl;

                        break;
                    }
                }

                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "quality :" << N[i].quality << endl;
                cout << "delay :" << N[i].delay << endl;
                cout << "Registratio Date :" << N[i].datatime << endl;

                break;
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

        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {
            if (N[i].product == PRODUCT)
            {
                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "quality :" << N[i].quality << endl;
                cout << "delay :" << N[i].delay << endl;
                cout << "Registratio Date :" << N[i].datatime << endl;
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
        string QUALITY;
        cout << "Enter quality :";
        getline(cin >> ws, QUALITY);

        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {
            if (N[i].quality == QUALITY)
            {
                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "quality :" << N[i].quality << endl;
                cout << "delay :" << N[i].delay << endl;
                cout << "Registratio Date :" << N[i].datatime << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }

    else if (choice == 4)
    {
        string DELAY;
        cout << "Enter delay :";
        getline(cin >> ws, DELAY);

        bool found = false;
        for (int i = 0; i < OrderCount; i++)
        {
            if (N[i].delay == DELAY)
            {
                cout << "Number :" << N[i].number << endl;
                cout << "product :" << N[i].product << endl;
                cout << "quality :" << N[i].quality << endl;
                cout << "delay :" << N[i].delay << endl;
                cout << "Registratio Date :" << N[i].datatime << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not found...." << endl;
        }
    }

    else if (choice == 5)
    {
        return;
    }

    else
    {
        cout << "Tray agine..." << endl;
    }
}
//***EditOrder***

void EditOrder(visitororder N[], int &OrderCount)
{
    if (OrderCount == 0)
    {
        cout << "No orders registered!" << endl;
        return;
    }

    string number;
    cout << "Enter visitor phone number: ";
    getline(cin >> ws, number);

    int found = 0;

    for (int i = 0; i < OrderCount; i++)
    {
        if (N[i].number == number)
        {
            cout << "\nOrder index: " << i << endl;
            cout << "Product: " << N[i].product << endl;
            cout << "Quality: " << N[i].quality << endl;
            cout << "Delay: " << N[i].delay << endl;
            cout << "Date: " << N[i].datatime << endl;
            found++;
        }
    }

    if (found == 0)
    {
        cout << "Order not found!" << endl;
        return;
    }

    int index;
    cout << "\nEnter order index: ";
    cin >> index;
    cin.ignore();

    if (index < 0 || index >= OrderCount ||
        N[index].number != number)
    {
        cout << "Invalid order index!" << endl;
        return;
    }

    int choice;

    cout << "\n1. Edit product" << endl;
    cout << "2. Edit quality" << endl;
    cout << "3. Edit delay" << endl;
    cout << "4. Delete order" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";

    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Enter new product: ";
        getline(cin >> ws, N[index].product);
    }
    else if (choice == 2)
    {
        cout << "Enter new quality: ";
        getline(cin >> ws, N[index].quality);
    }
    else if (choice == 3)
    {
        cout << "Enter new delay: ";
        getline(cin >> ws, N[index].delay);
    }
    else if (choice == 4)
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
    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    SaveOrders(N, OrderCount);
}

//***DatatTime***

string DatatTime()
{
    struct tm newtime;
    __time64_t long_time;
    char timebuf[26];

    _time64(&long_time);
    _localtime64_s(&newtime, &long_time);
    asctime_s(timebuf, 26, &newtime);

    return to_string(1900 + newtime.tm_year) + "/" +
           to_string(1 + newtime.tm_mon) + "/" +
           to_string(newtime.tm_mday) + " - " +
           to_string(newtime.tm_hour) + ":" +
           to_string(newtime.tm_min) + ":" +
           to_string(newtime.tm_sec);
}

void ManagerPart(char line[100], char filename[100])
{

    cout << "Enter file name :";
    cin.getline(filename, 100);
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

int main()
{
    int c;
    int VisitorCount = 0;
    int OrderCount = 0;
    int b = 0, d = 0;

    visitor M[max];
    visitororder N[max];

    LoadVisitors(M, VisitorCount);

    LoadOrders(N, OrderCount);

    while (true)
    {

        system("cls");
        cout << "==========Menu==========" << endl;
        cout << "1_Add Visitor" << endl;
        cout << "2_Serch Visitor" << endl;
        cout << "3_Search Order" << endl;
        cout << "4_Add Order" << endl;
        cout << "5_EditVisitor" << endl;
        cout << "6_EditOrder" << endl;
        cout << "7_(For Managers Only)" << endl;
        cout << "8_Exit" << endl;
        cin >> c;
        cin.ignore();

        switch (c)
        {
        case 1:
            RegisterVisitor(M, VisitorCount);
            break;
        case 2:
            SerchVisitor(N, M, OrderCount, VisitorCount);
            break;
        case 3:
            SearchOrder(N, M, OrderCount, VisitorCount);
            break;
        case 4:
            RegisterOrder(N, OrderCount);
            break;
        case 5:
            EditVisitor(N, M, OrderCount, VisitorCount);
            break;
        case 6:
            EditOrder(N, OrderCount);
            break;
        case 7:
            ContoroPassword(b);
            break;
        case 8:
            return 0;

        default:
            cout << "Incorrect option...." << endl;
        }

        system("Pause");
    }
}