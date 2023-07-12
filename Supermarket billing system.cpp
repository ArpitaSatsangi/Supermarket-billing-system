#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void removed();
    void listed();
    void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t__________________________________\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t      Supermarket main menu       \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t__________________________________\n\n";

    cout<<"\t\t\t|           1)Administrator         |\n\n";
    cout<<"\t\t\t|           2)Buyer                 |\n\n";
    cout<<"\t\t\t|           3)Exit                  |\n\n";
    cout<<"\n\t\t\t\t Please select: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t\t Please login \n";
        cout<<"\t\t\t\t enter email : ";
        cin>>email;
        cout<<"\t\t\t\t password : ";
        cin>>password;

        if(email=="arpita@gmail.com" && password=="arpita@15")
        {
            administrator();
        }
        else
        {
            cout<<"invalid email/password"<<endl;
        }
        break;


    case 2:
        {
            buyer();
        }

    case 3:
        {
            exit(0);
        }

    default:
        {
            cout<<"Please select from the given options"<<endl;
        }

    }
    goto m;

}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n";
    cout<<"\t\t\t__________________________________\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t        Administrator menu        \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t__________________________________\n\n";


    while(1)
    {


    cout<<"\t\t\t|          1)Add the product         |\n\n";
    cout<<"\t\t\t|          2)Modify the product      |\n\n";
    cout<<"\t\t\t|          3)Delete the product      |\n\n";
    cout<<"\t\t\t|          4)Back to main menu       |\n\n";
    cout<<"\n\t\t\t\t Please enter your choice: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        removed();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice"<<endl;
    }
    goto m;

    }
}


void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\n\n";
    cout<<"\t\t\t__________________________________\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t             Buyer menu           \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t__________________________________\n\n";

    cout<<"\t\t\t|          1)Buy product          |\n";
    cout<<"\t\t\t|          2)Go back              |\n";
    cout<<"\n\t\t\t Please enter your choice: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout<<"Invalid choice"<<endl;
    }
    goto m;
}


void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Add new product \n";
    cout<<"\n\n\t\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t\t Discount on the product ";
    cin>>discount;

    data.open("database.txt", ios::in); //input(read)

    if(!data)
    {
        data.open("database.txt", ios::app | ios::out); //append & output(write)
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())//eof-end of file
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)//for duplication
            goto m;

        else
        {
            data.open("database.txt", ios::app | ios::out); //append & output(write)
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted"<<endl;
}


void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t product code: ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\nFile does not exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\n\t\t Name of the product: ";
                cin>>n;
                cout<<"\n\t\t Price of the product: ";
                cin>>p;
                cout<<"\n\t\t Discount on the product: ";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\n\n\t\t Record edited";
                token++;
            }

            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        //after editing removing the old one and renaming the new one
        remove("database.txt");
        rename("database1.txt" , "database.txt");


        if(token==0)
        {
            cout<<"\n\n Record not found,sorry!";
        }
    }

}


void shopping :: removed()
{
    fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\n\t Delete product ";
    cout<<"\n\n\t Product code: ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File does not exist"<<endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                //all products will display here
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
            }

            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found!";
        }
    }
}


void shopping :: listed()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n_______________________________________\n\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n_______________________________________\n\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;

    }
    data.close();
}


void shopping :: receipt()
{
    fstream data;
    int arrc[10]={};//codes
    int arrq[10]={};//quantities
    char choice;
    int c=0,j=0;
    float amount=0.0;
    float discount=0.0;
    float total=0.0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        listed();
        cout<<"\n_______________________________________\n";
        cout<<"\n                                       \n";
        cout<<"\n         Please place the order        \n";
        cout<<"\n                                       \n";
        cout<<"\n_______________________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter product code: ";
            cin>>arrc[c];
            cout<<"\n\nEnter the quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\nDuplicate product code. Please try again.";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to buy another product? if yes then press y else n: ";
            cin>>choice;
        }
        while(choice=='y');


        cout<<"\n\n\t\t____________RECEIPT___________\n";
        cout<<"\nProduct_No  Product_Name  Product_Quantity  Price  Amount  Amount_with_discount Total\n";


        data.open("database.txt", ios::in);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof())
        {
            for(int j=0;j<c;j++)
            {
                if(pcode==arrc[j])
                {
                    amount=price*arrq[j];
                    discount=amount-(amount*discount/100.0);
                    total=total+discount;
                    cout<<endl<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[j]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount<<"\t\t"<<total<<endl;
                }

            }
            data>>pcode>>pname>>price>>discount;

        }
    }
    data.close();

    cout<<"\n\n__________________________________\n";
    cout<<"\n Total amount: "<<total;
}


int main()
{
    shopping s;
    s.menu();

    return 0;
}
