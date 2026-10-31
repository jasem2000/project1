// #include <iostream>
// #include <fstream>
// #include <string>
// #include <stdio.h>
// #include <time.h>
// #define max 100

// using namespace std;

// struct visitor
// {
//     string name;
//     string address;
//     string number;
//     string datatime;
// };

// struct visitororder
// {
//     string number;
//     string product;
//     string quality;
//     string delay;
//     string datatime;
//     string price;
//     string discount;
// };

// //// Functions Definition

// string DataTime();
// void ContoroPassword(int m);
// void LoadVisitors(visitor M[], int &count);
// void LoadOrders(visitororder N[], int &count);
// void AddVisitor(visitor M[], int &count);
// void AddProduct(visitororder N[], int &count);
// void ManagerPart(char line[100], char filename[100]);
// void EditOrder(visitororder N[], int &OrderCount);
// void SaveOrders(visitororder N[], int count);
// void SaveVisitors(visitor M[], int count);
// void ShowOrder(visitororder N[], visitor M[], int OrderCount, int VisitorIndex);
// void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
// void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);
// void SerchVisitor(visitororder N[], visitor M[], int OrderCount, int VisitorCount);
// void RegisterOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount);

// //***Load_Visitors***

// void LoadVisitors(visitor M[], int &count)
// {
//     ifstream f;
//     f.open("visitors.txt");
//     if (!f)
//     {

//         return;
//     }
//     count = 0;
//     while (count < max && getline(f, M[count].name, '|'))
//     {

//         getline(f, M[count].number, '|');
//         getline(f, M[count].address, '|');
//         getline(f, M[count].datatime);
//         count++;
//     }
//     f.close();
// }

// //***Load_Orders***

// void LoadOrders(visitororder N[], int &count)
// {

//     ifstream g;
//     g.open("orders.txt");
//     if (!g)
//     {
//         return;
//     }

//     count = 0;

//     while (count < max && getline(g, N[count].number, '|'))
//     {
//         getline(g, N[count].product, '|');
//         getline(g, N[count].price, '|');
//         getline(g, N[count].discount, '|');
//         getline(g, N[count].quality, '|');
//         getline(g, N[count].delay, '|');
//         getline(g, N[count].datatime);
//         count++;
//     }
//     g.close();
// }

// //***Register_Order***

// void RegisterOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
// {
//     int num;
//     cout << "=====Register Order=====" << endl;
//     cout << "Enter number of your product :";
//     cin >> num;
//     cin.ignore();
//     // string O;
//     string prod[num];
//     for (int i = 0; i < num; i++)
//     {
//         cout << "Product [" << i + 1 << "] :";
//         getline(cin, prod[i]);
//     }
//     cout << "-----------------------" << endl;
//     bool found1 = false;
//     for (int i = 0; i < OrderCount; i++)
//     {

//         for (int j = 0; j < VisitorCount; j++)
//         {

//             if (N[i].product == prod[j])
//             {

//                 for (int k = 0; k < VisitorCount; k++)
//                 {
//                     if (N[i].number == M[k].number)
//                     {
//                         cout << "Name :" << M[k].name << endl;
//                         cout << "Number :" << M[k].number << endl;
//                         cout << "Product :" << N[i].product << endl;
//                         cout << "price :" << N[i].price << endl;
//                         cout << "discount :" << N[i].discount << endl;
//                         cout << "quality :" << N[i].quality << endl;
//                         cout << "delay :" << N[i].delay << endl;
//                         cout << "Address :" << M[k].address << endl;
//                         cout << "-----------------------" << endl;
//                         found1 = true;
//                     }
//                 }
//             }
//         }
//     }
//     if (!found1)
//     {
//         cout << "Order not found...." << endl;
//         // return;
//     }

//     string NUMBER[num];
//     for (int i = 0; i < num; i++)
//     {
//         cout << "Enter visitor's number [" << i + 1 << "] :";
//         getline(cin, NUMBER[i]);
//     }
//     cout << "-----------------------" << endl;
//     long long int calculatprice = 0;

//     bool found = false;
//     for (int i = 0; i < OrderCount; i++)
//     {
//         for (int j = 0; j < num; j++)
//         {
//             if (N[i].number == NUMBER[j])
//             {

//                 for (int k = 0; k < VisitorCount; k++)
//                 {
//                     if (N[i].number == M[k].number)
//                     {

//                         cout << "Name :" << M[k].name << endl;
//                         cout << "Number :" << M[k].number << endl;
//                         cout << "Product :" << N[i].product << endl;
//                         cout << "Price :" << N[i].price << endl;
//                         cout << "Discount :" << N[i].discount << endl;
//                         cout << "Quality :" << N[i].quality << endl;
//                         cout << "Delay :" << N[i].delay << endl;
//                         cout << "Address :" << M[k].address << endl;
//                         cout << "-----------------------" << endl;
//                         found = true;
//                     }
//                 }
//                 long long int price = stod(N[i].price), discount = stod(N[i].discount);
//                 calculatprice += price - ((price * discount) / 100);
//             }
//         }
//     }
//     if (found)
//     {
//         cout << "FACTOR :" << calculatprice << endl;
//         cout << "Order placed successfully." << endl;
//     }
//     else
//     {
//         cout << "Vsitor not found...." << endl;
//         // return;
//     }
// }

// //***Save_Visitors***

// void SaveVisitors(visitor M[], int count)
// {
//     ofstream f("visitors.txt");

//     if (!f)
//     {
//         cout << "Cannot open visitors.txt!" << endl;
//         return;
//     }

//     for (int i = 0; i < count; i++)
//     {
//         f << M[i].name << "|" << M[i].number << "|" << M[i].address << "|" << M[i].datatime << endl;
//     }

//     f.close();
// }

// //***Save_Orders***

// void SaveOrders(visitororder N[], int count)
// {
//     ofstream f("orders.txt");

//     if (!f)
//     {
//         cout << "Cannot open orders.txt!" << endl;
//         return;
//     }

//     for (int i = 0; i < count; i++)
//     {
//         f << N[i].number << "|" << N[i].product << "|" << N[i].price << "|" << N[i].discount << "|" << N[i].quality << "|" << N[i].delay << "|" << N[i].datatime << endl;
//     }

//     f.close();
// }

// //***Edit_Visitor***

// void EditVisitor(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
// {
//     if (VisitorCount == 0)
//     {
//         cout << "No visitors registered!" << endl;
//         return;
//     }

//     int searchChoice;

//     cout << "\n===== Find Visitor =====" << endl;
//     cout << "1. Search by Name" << endl;
//     cout << "2. Search by Phone Number" << endl;
//     cout << "3. Exit" << endl;
//     cout << "Enter choice: ";
//     cin >> searchChoice;
//     cin.ignore();

//     if (searchChoice == 3)
//         return;

//     if (searchChoice != 1 && searchChoice != 2)
//     {
//         cout << "Invalid choice!" << endl;
//         return;
//     }

//     string key;

//     if (searchChoice == 1)
//     {
//         cout << "Enter visitor name: ";
//     }
//     else
//     {
//         cout << "Enter phone number: ";
//     }

//     getline(cin >> ws, key);

//     int index = -1;

//     for (int i = 0; i < VisitorCount; i++)
//     {
//         if ((searchChoice == 1 && M[i].name == key) || (searchChoice == 2 && M[i].number == key))
//         {
//             index = i;
//             break;
//         }
//     }

//     if (index == -1)
//     {
//         cout << "Visitor not found!" << endl;
//         return;
//     }

//     cout << "\n===== Visitor Information =====" << endl;
//     cout << "Name: " << M[index].name << endl;
//     cout << "Number: " << M[index].number << endl;
//     cout << "Address: " << M[index].address << endl;
//     cout << "Registration Date: " << M[index].datatime << endl;

//     int choice;

//     cout << "\n===== Edit Visitor =====" << endl;
//     cout << "1. Edit Name" << endl;
//     cout << "2. Edit Phone Number" << endl;
//     cout << "3. Edit Address" << endl;
//     cout << "4. Delete Visitor" << endl;
//     cout << "5. Exit" << endl;
//     cout << "Enter choice: ";
//     cin >> choice;
//     cin.ignore();

//     if (choice >= 1 && choice <= 3)
//     {

//         string oldNumber = M[index].number;

//         if (choice == 1)
//         {
//             cout << "Enter new name: ";
//             getline(cin >> ws, M[index].name);
//         }
//         else if (choice == 2)
//         {
//             string newNumber;

//             cout << "Enter new phone number: ";
//             getline(cin >> ws, newNumber);

//             // Prevent duplicate phone numbers
//             for (int i = 0; i < VisitorCount; i++)
//             {
//                 if (i != index && M[i].number == newNumber)
//                 {
//                     cout << "This number already exists!" << endl;
//                     return;
//                 }
//             }

//             M[index].number = newNumber;

//             // Update the visitor's order references
//             for (int i = 0; i < OrderCount; i++)
//             {
//                 if (N[i].number == oldNumber)
//                 {
//                     N[i].number = newNumber;
//                 }
//             }

//             SaveOrders(N, OrderCount);
//         }
//         else if (choice == 3)
//         {
//             cout << "Enter new address: ";
//             getline(cin >> ws, M[index].address);
//         }

//         SaveVisitors(M, VisitorCount);

//         cout << "Visitor updated successfully!" << endl;
//     }

//     else if (choice == 4)
//     {
//         char confirm;

//         cout << "Are you sure you want to delete " << M[index].name << "? (y/n): ";

//         cin >> confirm;
//         cin.ignore();

//         if (confirm == 'y' || confirm == 'Y')
//         {

//             for (int i = index; i < VisitorCount - 1; i++)
//             {
//                 M[i] = M[i + 1];
//             }

//             VisitorCount--;

//             SaveVisitors(M, VisitorCount);

//             cout << "Visitor deleted successfully!" << endl;
//         }
//         else
//         {
//             cout << "Deletion cancelled." << endl;
//         }
//     }

//     else if (choice == 5)
//     {
//         return;
//     }

//     else
//     {
//         cout << "Invalid choice!" << endl;
//     }
// }

// //***Add_Visitor***

// void AddVisitor(visitor M[], int &count)
// {

//     cout << "Enter name of visitor :";
//     getline(cin >> ws, M[count].name);

//     cout << "Enter Phone number of visitor :";
//     getline(cin >> ws, M[count].number);

//     cout << "Enter addres of visitor :";
//     getline(cin >> ws, M[count].address);

//     M[count].datatime = DataTime();

//     ofstream f;
//     f.open("visitors.txt", ios::app);
//     if (!f)
//     {
//         cout << "Can not open the file...." << endl;
//         return;
//     }

//     f << M[count].name << "|" << M[count].number << "|" << M[count].address << "|" << M[count].datatime << endl;

//     f.close();
//     count++;
// }

// //***Serch_Visitor***

// void SerchVisitor(visitororder N[], visitor M[], int OrderCount, int VisitorCount)
// {
//     int choice;
//     cout << "====Search Visitor====" << endl;
//     cout << "1_Search by Name " << endl;
//     cout << "2_Search by Phone number" << endl;
//     cout << "3_Exit" << endl;
//     cin >> choice;
//     cin.ignore();

//     if (choice == 1)
//     {
//         string NAME;
//         cout << "Enter Name :";
//         getline(cin >> ws, NAME);

//         bool found = false;
//         for (int i = 0; i < VisitorCount; i++)
//         {
//             if (M[i].name == NAME)
//             {
//                 cout << "Name :" << M[i].name << endl;
//                 cout << "Number :" << M[i].number << endl;
//                 cout << "Address :" << M[i].address << endl;
//                 cout << "Registratio Date :" << M[i].datatime << endl;
//                 cout << "===================" << endl;
//                 ShowOrder(N, M, OrderCount, i);
//                 found = true;
//                 break;
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }
//     else if (choice == 2)
//     {
//         string NUMBER;
//         cout << "Enter Number :";
//         getline(cin >> ws, NUMBER);

//         bool found = false;
//         for (int i = 0; i < VisitorCount; i++)
//         {
//             if (M[i].number == NUMBER)
//             {
//                 cout << "Name :" << M[i].name << endl;
//                 cout << "Number :" << M[i].number << endl;
//                 cout << "Address :" << M[i].address << endl;
//                 cout << "Registratio Date :" << M[i].datatime << endl;
//                 cout << "===================" << endl;
//                 ShowOrder(N, M, OrderCount, i);
//                 found = true;
//                 break;
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }
//     else if (choice == 3)
//     {
//         return;
//     }
//     else
//     {
//         cout << "Tray agine..." << endl;
//     }
// }

// //***Show_Order***

// void ShowOrder(visitororder N[], visitor M[], int OrderCount, int VisitorIndex)
// {
//     int choice;
//     cout << "1_Show Orders visitor :" << endl;
//     cout << "2_Exit :" << endl;
//     cin >> choice;
//     cin.ignore();

//     if (choice == 1)
//     {
//         bool found = false;
//         for (int i = 0; i < OrderCount; i++)
//         {
//             if (N[i].number == M[VisitorIndex].number)
//             {

//                 cout << "Number :" << N[i].number << endl;
//                 cout << "product :" << N[i].product << endl;
//                 cout << "price :" << N[i].price << endl;
//                 cout << "discount :" << N[i].discount << endl;
//                 cout << "quality :" << N[i].quality << endl;
//                 cout << "delay :" << N[i].delay << endl;
//                 cout << "Registratio Date :" << N[i].datatime << endl;
//                 cout << "===================" << endl;
//                 found = true;
//             }
//         }
//         if (!found)
//         {
//             cout << "No orders for this visitor..." << endl;
//         }
//     }
//     else if (choice == 2)
//     {
//         return;
//     }
//     else
//     {
//         cout << "Try again..." << endl;
//     }
// }

// //***Add_Product***

// void AddProduct(visitororder N[], int &count)
// {

//     visitororder p;
//     cout << "Enter Phone number of visitor :";
//     getline(cin >> ws, N[count].number);

//     cout << "Enter the visitor products :";
//     getline(cin >> ws, N[count].product);

//     cout << "Enter the visitor price :";
//     getline(cin >> ws, N[count].price);

//     cout << "Enter the visitor discount :";
//     getline(cin >> ws, N[count].discount);

//     cout << "Enter the visitor quality :";
//     getline(cin >> ws, N[count].quality);

//     cout << "Enter the visitor delay :";
//     getline(cin >> ws, N[count].delay);

//     N[count].datatime = DataTime();
//     ofstream g;
//     g.open("products.txt", ios::app);
//     if (!g)
//     {
//         cout << "Can not open the file...." << endl;
//         return;
//     }

//     g << N[count].number << "|" << N[count].product << "|" << N[count].price << "|" << N[count].discount << "|" << N[count].quality << "|" << N[count].delay << "|" << N[count].datatime << endl;
//     g.close();
//     count++;
// }

// //***Search_Orders***

// void SearchOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
// {

//     int choice;
//     cout << "====Search Order====" << endl;
//     cout << "1_Search by Phone number" << endl;
//     cout << "2_Search by products " << endl;
//     cout << "3_Search by quality" << endl;
//     cout << "4_Search by delay" << endl;
//     cout << "5_Exit" << endl;
//     cin >> choice;
//     cin.ignore();
//     if (choice == 1)
//     {
//         string NUMBER;
//         cout << "Enter number :";
//         getline(cin >> ws, NUMBER);
//         cout << "-----------------------" << endl;

//         bool found = false;
//         for (int i = 0; i < OrderCount; i++)
//         {
//             if (N[i].number == NUMBER)
//             {
//                 found = true;
//                 for (int j = 0; j < VisitorCount; j++)
//                 {

//                     if (N[i].number == M[j].number)
//                     {
//                         cout << "Name :" << M[j].name << endl;
//                         cout << "Address :" << M[j].address << endl;
//                         cout << "Registratio Date :" << M[j].datatime << endl;
//                         cout << "-----------------------" << endl;

//                         break;
//                     }
//                 }

//                 cout << "Number :" << N[i].number << endl;
//                 cout << "product :" << N[i].product << endl;
//                 cout << "price :" << N[i].price << endl;
//                 cout << "discount :" << N[i].discount << endl;
//                 cout << "quality :" << N[i].quality << endl;
//                 cout << "delay :" << N[i].delay << endl;
//                 cout << "Registratio Date :" << N[i].datatime << endl;

//                 break;
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }
//     else if (choice == 2)
//     {
//         string PRODUCT;
//         cout << "Enter product :";
//         getline(cin >> ws, PRODUCT);
//         cout << "-----------------------" << endl;
//         bool found = false;
//         for (int i = 0; i < OrderCount; i++)
//         {
//             if (N[i].product == PRODUCT)
//             {
//                 for (int j = 0; j < VisitorCount; j++)
//                 {
//                     cout << "Number :" << N[i].number << endl;
//                     cout << "product :" << N[i].product << endl;
//                     cout << "price :" << N[i].price << endl;
//                     cout << "discount :" << N[i].discount << endl;
//                     cout << "quality :" << N[i].quality << endl;
//                     cout << "delay :" << N[i].delay << endl;
//                     cout << "Registratio Date :" << N[i].datatime << endl;
//                     cout << "-----------------------" << endl;
//                     found = true;
//                     break;
//                 }
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }

//     else if (choice == 3)
//     {
//         string QUALITY;
//         cout << "Enter quality :";
//         getline(cin >> ws, QUALITY);
//         cout << "-----------------------" << endl;
//         bool found = false;
//         for (int i = 0; i < OrderCount; i++)
//         {
//             if (N[i].quality == QUALITY)
//             {
//                 for (int j = 0; j < VisitorCount; j++)
//                 {
//                     cout << "Number :" << N[i].number << endl;
//                     cout << "product :" << N[i].product << endl;
//                     cout << "price :" << N[i].price << endl;
//                     cout << "discount :" << N[i].discount << endl;
//                     cout << "quality :" << N[i].quality << endl;
//                     cout << "delay :" << N[i].delay << endl;
//                     cout << "Registratio Date :" << N[i].datatime << endl;
//                     cout << "-----------------------" << endl;
//                     found = true;
//                     break;
//                 }
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }

//     else if (choice == 4)
//     {
//         string DELAY;
//         cout << "Enter delay :";
//         getline(cin >> ws, DELAY);
//         cout << "-----------------------" << endl;
//         bool found = false;
//         for (int i = 0; i < OrderCount; i++)
//         {
//             if (N[i].delay == DELAY)
//             {
//                 for (int j = 0; j < VisitorCount; j++)
//                 {
//                     cout << "Number :" << N[i].number << endl;
//                     cout << "product :" << N[i].product << endl;
//                     cout << "price :" << N[i].price << endl;
//                     cout << "discount :" << N[i].discount << endl;
//                     cout << "quality :" << N[i].quality << endl;
//                     cout << "delay :" << N[i].delay << endl;
//                     cout << "Registratio Date :" << N[i].datatime << endl;
//                     cout << "-----------------------" << endl;
//                     found = true;
//                     break;
//                 }
//             }
//         }
//         if (!found)
//         {
//             cout << "Not found...." << endl;
//         }
//     }

//     else if (choice == 5)
//     {
//         return;
//     }

//     else
//     {
//         cout << "Tray agine..." << endl;
//     }
// }

// //***Edit_Order***

// void EditOrder(visitororder N[], int &OrderCount)
// {
//     if (OrderCount == 0)
//     {
//         cout << "No orders registered!" << endl;
//         return;
//     }

//     string number;
//     cout << "Enter visitor phone number: ";
//     getline(cin >> ws, number);

//     int found = 0;

//     for (int i = 0; i < OrderCount; i++)
//     {
//         if (N[i].number == number)
//         {
//             cout << "\nOrder index: " << i << endl;
//             cout << "Product: " << N[i].product << endl;
//             cout << "Price: " << N[i].price << endl;
//             cout << "Discount: " << N[i].discount << endl;
//             cout << "Quality: " << N[i].quality << endl;
//             cout << "Delay: " << N[i].delay << endl;
//             cout << "Date: " << N[i].datatime << endl;
//             found++;
//         }
//     }

//     if (found == 0)
//     {
//         cout << "Order not found!" << endl;
//         return;
//     }

//     int index;
//     cout << "\nEnter order index: ";
//     cin >> index;
//     cin.ignore();

//     if (index < 0 || index >= OrderCount || N[index].number != number)
//     {
//         cout << "Invalid order index!" << endl;
//         return;
//     }

//     int choice;

//     cout << "\n1. Edit product" << endl;
//     cout << "2. Edit quality" << endl;
//     cout << "3. Edit price" << endl;
//     cout << "4. Edit discount" << endl;
//     cout << "5. Edit delay" << endl;
//     cout << "6. Delete order" << endl;
//     cout << "7. Exit" << endl;
//     cout << "Enter choice: ";

//     cin >> choice;
//     cin.ignore();

//     if (choice == 1)
//     {
//         cout << "Enter new product: ";
//         getline(cin >> ws, N[index].product);
//     }
//     else if (choice == 2)
//     {
//         cout << "Enter new quality: ";
//         getline(cin >> ws, N[index].quality);
//     }
//     else if (choice == 3)
//     {
//         cout << "Enter new price: ";
//         getline(cin >> ws, N[index].price);
//     }
//     else if (choice == 4)
//     {
//         cout << "Enter new discount : ";
//         getline(cin >> ws, N[index].discount);
//     }
//     else if (choice == 5)
//     {
//         cout << "Enter new delay: ";
//         getline(cin >> ws, N[index].delay);
//     }
//     else if (choice == 6)
//     {
//         char confirm;

//         cout << "Delete this order? (y/n): ";
//         cin >> confirm;
//         cin.ignore();

//         if (confirm != 'y' && confirm != 'Y')
//         {
//             cout << "Deletion cancelled." << endl;
//             return;
//         }

//         for (int i = index; i < OrderCount - 1; i++)
//         {
//             N[i] = N[i + 1];
//         }

//         OrderCount--;
//         cout << "Order deleted successfully!" << endl;
//     }
//     else
//     {
//         cout << "Invalid choice!" << endl;
//         return;
//     }

//     SaveOrders(N, OrderCount);
// }

// //***Data_Time***

// string DataTime()
// {
//     struct tm newtime;
//     __time64_t long_time;
//     char timebuf[26];

//     _time64(&long_time);
//     _localtime64_s(&newtime, &long_time);
//     asctime_s(timebuf, 26, &newtime);

//     return to_string(1900 + newtime.tm_year) + "/" +
//            to_string(1 + newtime.tm_mon) + "/" +
//            to_string(newtime.tm_mday) + " - " +
//            to_string(newtime.tm_hour) + ":" +
//            to_string(newtime.tm_min) + ":" +
//            to_string(newtime.tm_sec);
// }

// //***Manager_Part***

// void ManagerPart(char line[100], char filename[100])
// {

//     cout << "Enter file name :";
//     cin.getline(filename, 100);
//     cout << "-----------------------" << endl;
//     ifstream f;
//     f.open(filename);
//     if (!f)
//     {
//         cout << "Cannat open file!" << endl;
//         return;
//     }
//     do
//     {
//         f >> line;
//         if (f.eof())
//             break;
//         cout << line << endl;

//     } while (!f.eof());
//     f.close();
// }

// //***Contoro_Password***

// void ContoroPassword(int m)
// {
//     int p;
//     char g[100], k[100];
//     cout << "Enter Password :";
//     cin >> p;
//     cin.ignore();
//     if (p == 12345678)
//     {
//         ManagerPart(g, k);
//     }

//     else
//     {
//         cout << "Try agine...";
//     }
// }

// //***Main***

// int main()
// {
//     int c;
//     int VisitorCount = 0;
//     int OrderCount = 0;
//     int b = 0, d;

//     visitor M[max];
//     visitororder N[max];

//     LoadVisitors(M, VisitorCount);

//     LoadOrders(N, OrderCount);

//     while (true)
//     {

//         system("cls");
//         cout << "==========Menu==========" << endl;
//         cout << "1_Add Visitor" << endl;
//         cout << "2_Search Visitor" << endl;
//         cout << "3_Search Order" << endl;
//         cout << "4_Add Product" << endl;
//         cout << "5_Edit Visitor" << endl;
//         cout << "6_Edit Order" << endl;
//         cout << "7_(For Managers Only)" << endl;
//         cout << "8_Register Order" << endl;
//         cout << "9_Exit" << endl;
//         cout << "-----------------------" << endl;
//         cout << "Enter number :";
//         cin >> c;
//         cin.ignore();

//         switch (c)
//         {
//         case 1:
//             AddVisitor(M, VisitorCount);
//             break;
//         case 2:
//             SerchVisitor(N, M, OrderCount, VisitorCount);
//             break;
//         case 3:
//             SearchOrder(N, M, OrderCount, VisitorCount);
//             break;
//         case 4:
//             AddProduct(N, OrderCount);
//             break;
//         case 5:
//             EditVisitor(N, M, OrderCount, VisitorCount);
//             break;
//         case 6:
//             EditOrder(N, OrderCount);
//             break;
//         case 7:
//             ContoroPassword(b);
//             break;
//         case 8:
//             RegisterOrder(N, M, OrderCount, VisitorCount);

//         case 9:
//             return 0;
//             break;

//         default:
//             cout << "Incorrect option...." << endl;
//         }

//         system("Pause");
//     }
// }

void RegisterOrder(visitororder N[], visitor M[], int &OrderCount, int &VisitorCount)
{
    cout << "===== Register Order =====" << endl;

    if (OrderCount >= max)
    {
        cout << "Order list is full!" << endl;
        return;
    }

    string Proud;
    cout << "Enter Name of product: ";
    getline(cin >> ws, Proud);

    bool found1 = false;

    for (int i = 0; i < VisitorCount; i++)
    {
        if (M[i].product == Proud)
        {
            cout << "Name: " << M[i].name << endl;
            cout << "Number: " << M[i].number << endl;
            cout << "Product: " << M[i].product << endl;
            cout << "Address: " << M[i].address << endl;
            cout << "-----------------------" << endl;

            found1 = true;
        }
    }

    if (!found1)
    {
        cout << "Product not found!" << endl;
        return;
    }

    string NUMBER;
    cout << "Enter visitor's Number: ";
    getline(cin >> ws, NUMBER);

    int Index = -1;

    for (int i = 0; i < VisitorCount; i++)
    {
        if (M[i].number == NUMBER && M[i].product == Proud)
        {
            Index = i;
            break;
        }
    }

    if (Index == -1)
    {
        cout << "Incorrect number!" << endl;
        return;
    }

    N[OrderCount].number = M[Index].number;
    N[OrderCount].product = M[Index].product;

    cout << "Enter Price of product: ";
    getline(cin >> ws, N[OrderCount].price);

    cout << "Enter discount of product: ";
    getline(cin >> ws, N[OrderCount].discount);

    cout << "Enter quality: ";
    getline(cin >> ws, N[OrderCount].quality);

    cout << "Enter delivery: ";
    getline(cin >> ws, N[OrderCount].delivery);

    RghitInOrderList(N, OrderCount);

    OrderCount++;
    SaveOrders(N, OrderCount);

    cout << "Order registered successfully!" << endl;
}

void RegisterDeliveryDate(visitororder N[], visitor M[],
                          int OrderCount, int VisitorCount)
{
    string NUMBER;
    bool found = false;

    cout << "===== Register Delivery Date =====" << endl;
    cout << "Enter Number of visitor :";
    cin >> NUMBER;

    for (int i = 0; i < OrderCount; i++)
    {
        if (NUMBER == N[i].number)
        {
            found = true;

            cout << "Product :" << N[i].product << endl;

            N[i].deliverydate = DataTime();

            cout << "Delivery date :"
                 << N[i].deliverydate << endl;
        }
    }

    if (found == false)
    {
        cout << "Order not found!" << endl;
    }
}

#include <iostream>
void computeDate(int, int &, int &);
using namespace std;
int main()
{
    int day_num, month, day;
    do
    {
        cout << "Input the number of days spent of the year:";
        cin >> day_num;
    } while (day_num <= 0 || day_num > 365);
    computeDate(day_num, month, day);
    cout << "Date =" << month << " / " << day << endl;
}

void computeDate(int dn, int &m, int &d)
{
    if (dn <= 186)
    {
        d = (dn - 1) % 31 + 1;
        m = (dn - 1) / 31 + 1;
    }
    else
    {
        dn -= 186;
        d = (dn - 1) % 30 + 1;
        m = (dn - 1) / 30 + 7;
    }
}