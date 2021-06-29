#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <climits>
#include <set>
#include <functional>
#include <cmath>
#include <stdlib.h>

#define bomt                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define endl '\n'
#define str string
#define ft float
#define ch char
#define vi vector<int>
#define vii vector<pair<int, int>>
#define mp make_pair
#define mi multiset<int>
#define pb push_back
#define pob pop_back
#define MOD 1000000007
#define loop(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define nloop(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

class ID
{
    ch *author, *name, *publisher;
    ft *cost;
    ll *stock;

public:
    ID()
    {
        author = new char[50];
        name = new char[50];
        publisher = new char[50];
        cost = new float;
        stock = new long long;
    }
    void enterdata()
    {
        cin.ignore();
        cout << "\nEnter Author Name: ";
        cin.getline(author, 50);
        cout << "Enter Book Name: ";
        cin.getline(name, 50);
        cout << "Enter Publisher Name: ";
        cin.getline(publisher, 50);
        cout << "Enter Price: ";
        cin >> *cost;
        cout << "Enter Stock Position: ";
        cin >> *stock;
    }
    void editdata()
    {
        cout << "\nEnter Author Name: ";
        cin.getline(author, 50);
        cout << "Enter Book Name: ";
        cin.getline(name, 50);
        cout << "Enter Publisher Name: ";
        cin.getline(publisher, 50);
        cout << "Enter Price: ";
        cin >> *cost;
        cout << "Enter Stock Position: ";
        cin >> *stock;
    }
    void showdata()
    {
        cout << "\nAuthor Name: " << author;
        cout << "\nBook Name: " << name;
        cout << "\nPublisher Name: " << publisher;
        cout << "\nCost: " << *cost;
        cout << "\nStock Position: " << *stock;
    }
    int search(char[], char[]);
    void buybook()
    {
        int count;
        cout << "\nEnter Number Of Books to buy: ";
        cin >> count;
        if (count <= *stock)
        {
            *stock = *stock - count;
            cout << "\nBooks Bought Sucessfully";
            cout << "\nAmount: Rs. " << (*cost) * count;
        }
        else
            cout << "\nRequired Copies not in Stock";
    }
};

int ID ::search(char a[50], char b[50])
{
    if (strcmp(a, name) == 0 && strcmp(b, author) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    ID *B[50];
    int i = 0, r, t, choice;
    char titlebuy[50], authorbuy[50];
    while (1)
    {
        cout << "\n\n\t\tMENU"
             << "\n1. Entry of New Book"
             << "\n2. Buy Book"
             << "\n3. Search For Book"
             << "\n4. Edit Details Of Book"
             << "\n5. Exit"
             << "\n\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            B[i] = new ID;
            B[i]->enterdata();
            i++;
            break;

        case 2:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 50);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 50);
            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    B[t]->buybook();
                    break;
                }
            }
            if (t == 1)
                cout << "\nThis Book is Not in Stock";

            break;
        case 3:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 50);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 50);

            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    cout << "\nBook Found Successfully";
                    B[t]->showdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 4:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 50);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 50);

            for (t = 0; t < i; t++)
            {
                if (B[t]->search(titlebuy, authorbuy))
                {
                    cout << "\nBook Found Successfully";
                    B[t]->editdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 5:
            exit(0);
        default:
            cout << "\nInvalid Choice Entered";
        }
    }

    return 0;
}