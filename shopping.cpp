#include<iostream>
#include<fstream>
#include<string>
#include<windows.h> // To access windows library

using namespace std;
class shopping{
   int pricecode;
   float price,discount ;
   string productname;

   public:
       void loading();
       void menu();
       void administrator();
       void buyer();
       void add();
       void edit();
       void rem();
       void lst();
       void receipt();





};

  /* shopping::menu() This is the function name.
                    It appears to be a member function of a class named shopping.
                    The :: operator is used to specify that menu()
                    is a member of the shopping class.*/
  void shopping :: menu()
{
     m:
    int choice;
     string email,password;

         cout<<"\n\n\n\n\n";
  cout<<"\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
  cout<<"\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
  cout<<"\n\t\t      =                  WELCOME                  =";
  cout<<"\n\t\t      =                    TO                     =";
  cout<<"\n\t\t      =                  SHOPPING                 =";
  cout<<"\n\t\t      =                 MANAGEMENT                =";
  cout<<"\n\t\t      =                   SYSTEM                  =";
  cout<<"\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
  cout<<"\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
  cout<<endl<<endl;

       cout<<"\t\t\t\t|      1)Administrator   |"<<endl;
       cout<<"\t\t\t\t|                        |"<<endl;
       cout<<"\t\t\t\t|      2) Buyer          |"<<endl;
       cout<<"\t\t\t\t|                        |"<<endl;
       cout<<"\t\t\t\t|      3)Exit            |"<<endl<<endl<<endl;
       cout<<"\t\t\t\t Please select:";
       cin>>choice;
        cout<<endl;
       switch(choice){
              case(1):
                  {
                      cout<<"\t\t\t\t______Please Login_______________"<<endl<<endl;
                      cout<<"\t\t\t\t      User ID :";
                      cin>>email;
                      cout<<endl;
                      cout<<"\t\t\t\t      Enter password:";
                      cin>>password;
                      cout<<endl;
                      if(email=="admin"  && password=="123"){

                        administrator();

                      }else{

                         cout<<"\t\t\t\t  Invalid Email ID or Password.  "<<endl;
                      }
                      break;
                   }
              case(2):
                {
                  buyer();

                }
              case(3):
                {

                    exit(0); /*In C++, exit(0) is a function call that is used to terminate a program.
                              Specifically, it is used to indicate a successful or normal termination of the program.*/

                }
              default:
                {
                    cout<<"Please select from the given options. ";
                }
            }
            goto m;
        }

 void shopping:: administrator(){
     Administrator_menu:
      int choice;
       cout<<"\n\n\t\t\t\t       Administrator menu  \n\n";
       cout<<"\t\t\t\t|______1)Add the product_______|"<<endl;
       cout<<"\t\t\t\t|                              |"<<endl;
       cout<<"\t\t\t\t|______2)Modify the product____|"<<endl;
       cout<<"\t\t\t\t|                              |"<<endl;
       cout<<"\t\t\t\t|______3)Delete the product____|"<<endl;
       cout<<"\t\t\t\t|                              |"<<endl;
       cout<<"\t\t\t\t|______4)Back to main menu_____|"<<endl;
       cout<<endl<<endl;
       cout<<"\t\t\t\t  Please enter your choice:";
       cin>>choice;

         switch(choice){
              case 1:
                {
                      add();
                      break;

                  }
              case 2:
                {
                    edit();
                    break;

                }
              case 3:
                {
                    rem();
                    break;
                }
              case 4:
                {
                    menu();
                    break;
                }
              default:
                {
                    cout<<"Invalid choice!!";
                }




                  }

         goto Administrator_menu;

         }

    void shopping:: buyer(){
        buyer_menu:
         int choice;

       cout<<"\n\n\t\t\t\t Buyer \n\n";
       cout<<"\t\t\t\t|______1)Buy product_______|"<<endl;
       cout<<"\t\t\t\t|                          |"<<endl;
       cout<<"\t\t\t\t|______2)Go back___________|"<<endl<<endl;
       cout<<"\t\t\t\t  Please enter your choice:";

       cin>>choice;

       switch(choice){
            case 1:
            {
              receipt();
              break;
                }
            case 2:
            {
              menu();
                }
            defalt:
            {
              cout<<"Invalid choice";

                }
            }

             goto buyer_menu;
    }

    void shopping :: add()
    {
        add:
        fstream data;
        int c;
        int token=0;
        float p,d;
        string n;

        cout<<"\n\n\t\t\t Add new product";
        cout<<"\n\n\t Product code of the product:";
        cin>>pricecode;
        cout<<"\n\n\t Name of the product:";
        cin>>productname;
        cout<<"\n\n\t Price of the product:";
        cin>>price;
        cout<<"\n\n\t Discount on product";
        cin>>discount;

        data.open("database.txt",ios::in);

            if(!data){
                data.open("database.txt",ios::app|ios::out);
                data<<" "<<pricecode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";
                data.close();
            }else{

               data>>c>>n>>p>>d;

               while(!data.eof())
                {
                    if(c ==pricecode){

                        token++;

                    }
                    data>>c>>n>>p>>d;
               }
               data.close();


               if(token==1){
                goto add;
               }else{

                data.open("database.txt",ios::app|ios::out);
                data<<" "<<pricecode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";
                data.close();

               }
            }

               cout<<"\n\n\t\t Record inserted";

    }



    void shopping:: edit()
    {
        fstream data,data1;
        int pkey,token=0,c;
        float p,d;
        string n;

        cout<<"\n\t\t\t Modify the record";
        cout<<"\n\t\t\t product code:";
        cin>>pkey;

        data.open("database.txt",ios::in);
        if(!data)
        {
            cout<<"\n\n File doesn't exist!";

        }else
        {
            data1.open("database1.txt",ios::app|ios::out);

            data>>pricecode>>productname>>price>>discount;
            while(!data.eof())
            {
                if(pkey==pricecode)
                {
                    cout<<"\n\t\t Product new code: ";
                    cin>>c;
                    cout<<"\n\t\t Name of the product:";
                    cin>>n;
                    cout<<"\n\t\t Price:";
                    cin>>p;
                    cout<<"\n\t\t Discount: ";
                    cin>>d;
                    data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\n\t\t Record edited";
                    token++;
                }else
                {
                    data1<<" "<<pricecode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";

                }
                data>>pricecode>>productname>>price>>discount;
                }
                data.close();
                data1.close();

                remove("database.txt");
                rename("database1.txt","database.txt");

                if(token==0)
                {
                    cout<<"\n\n Record not found sorry!";
                }

            }
        }

        void shopping::rem()
        {
            fstream data ,data1;
            int pkey,token=0;
            cout<<"\n\n\t Delete product";
            cout<<"\n\n\t Product code: ";
            cin>>pkey;
            data.open("database.txt",ios::in);
            if(!data)
            {
                cout<<"File doesn't exist";
            }
            else{
                data1.open("database1.txt",ios::app|ios::out);
                data>>pricecode>>productname>>price>>discount;
                while(!data.eof())
                {
                    if(pricecode==pkey)
                    {
                        cout<<"\n\n\t Product deleted successfully";
                        token++;
                    }
                    else
                    {
                        data1<<" "<<pricecode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";

                    }
                    data>>pricecode>>productname>>price>>discount;
                }
                data.close();
                data1.close();
                remove("database.txt");
                rename("database1.txt","database.txt");

                if(token==0)
                {
                    cout<<"\n\n Record not found";
                }
            }
       }



       void shopping:: lst()
       {
           fstream data;
           data.open("database.txt",ios::in);
           cout<<"\n\n|____________________________________\n";
           cout<<"ProNo\t\tName\t\tPrice\n";
           cout<<"\n\n|____________________________________\n";
           data>>pricecode>>productname>>price>>discount;

           while(!data.eof())
           {
               cout<<pricecode<<"\t\t"<<productname<<"\t\t"<<price<<"\n";
               data>>pricecode>>productname>>price>>discount;

           }
           data.close();

       }


      void shopping :: receipt()
      {
          fstream data;
          int arrc[100],arrq[100];
          string choice;
          int c=0;
          float amount=0,dis=0,total=0;

          cout<<"\n\n\t\t\t\t RECEIPT ";
          data.open("database.txt",ios::in);
          if(!data){
            cout<<"\n\n Empty database";
          }else{
              data.close();

              lst();
              cout<<"\n_____________________________________\n"<<endl;
              cout<<"\n                                     \n"<<endl;
              cout<<"\n         Please place the order      \n"<<endl;
              cout<<"\n                                     \n"<<endl;
              cout<<"\n_____________________________________\n"<<endl;
              do
              {
                  m:
                  cout<<"\n\nEnter product code:";
                  cin>>arrc[c];
                  cout<<"\n\nEnter the product quantity:";
                  cin>>arrq[c];
                  for(int i=0;i<c;i++)
                  {
                      if(arrc[c]==arrc[i])
                      {
                          cout<<"\n\n Duplicate product code.Please try again!";
                          goto m;
                      }

                  }
                  c++;
                  cout<<"\n\n Do you want to buy another product? If yes press y else no.";
                  cin>>choice;
                }
                while (choice =="y");

                cout<<"\n\n\t\t\t_________________________RECEIPT___________________________\n";
                cout<<"\nProduct No\t Product Name\t Product quantity\tprice\t Total Amount\t Amount with discount\n ";


                for(int i=0;i<c;i++)
                {
                    data.open("database.txt",ios::in);
                    data>>pricecode>>productname>>price>>discount;
                    while(!data.eof())
                    {
                        if(pricecode==arrc[i])
                        {
                            amount=price*arrq[i];
                            discount=amount-(amount*discount/100);
                            total=total+discount;
                            cout<<"\n"<<pricecode<<"\t\t  "<<productname<<"\t\t       "<<arrq[i]<<"\t\t  "<<price<<"\t\t"<<amount<<"\t\t  "<<discount;

                        }
                        data>>pricecode>>productname>>price>>discount;
                    }
                }
                data.close();

          }

          cout<<"\n\n__________________________________________________________________________________________________";
          cout<<"\n Total Amount: "<<total;


                      cout<<"\n\n\n\n\n";

           cout<<"\n\t\t  #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n";
           cout<<"\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
           cout<<"\n\t\t      |                                           |";
           cout<<"\n\t\t      |                  THANK                    |";
           cout<<"\n\t\t      |                   YOU                     |";
           cout<<"\n\t\t      |                   FOR                     |";
           cout<<"\n\t\t      |                 SHOPPING                  |";
           cout<<"\n\t\t      |                                           |";
           cout<<"\n\t\t      ---------------------------------------------";
           cout<<"\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
           cout<<"\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";

           cout<<"\n\n\n\n";

}


void loading()  /////////////////////////////////////For loading animation
{
    system("cls");
    int r,q;


    printf("\t \t \t LOADING...");

    for(r=1; r<=20; r++)
    {
        for(q=0; q<=10000000; q++);
        printf("%c",177);
    }
    system("cls");


}

   int main()
   {

       loading();
       system("cls"); //command in C++ is used to clear the console or terminal screen.
       HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(h,3);////////////////////////// to add colour in text//////////////////////////
       shopping s;
       s.menu();

       return 0;
   }



















