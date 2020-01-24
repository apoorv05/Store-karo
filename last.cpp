#include<iostream>
#include<cstring>
#include<vector>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int i,j;
int main_exit;
void menu();

class date{
   public:
    int month,day,year;

    };

class farmer {

   public:
    double annual_income;
    string name;
    int acc_no,age;
    string address;
    string citizenship;
    long long int phone;
    string crop1,crop3,crop2;

    double quant;
    date dob;
    date deposit;
    date withdraw;
    farmer(string c1,string c2,string c3,double ai, string n,int acc,string add,string citi,long long int pho,double qua,int d1_month, int d1_day, int d1_year, int d2_month, int d2_day, int d2_year ,int d3_month, int d3_day, int d3_year)
    {   crop1=c1;
        crop2=c2;
        crop3=c3;
        annual_income=ai;
        name=n;
        acc_no=acc;
        address=add;
        citizenship=citi;
        phone=pho;
        quant=qua;
        dob.month=d1_month;
        dob.day=d1_day;
        dob.year=d1_year;
        deposit.month=d2_month;
        deposit.day=d2_day;
        deposit.year=d2_year;
        withdraw.month=d3_month;
        withdraw.day=d3_day;
        withdraw.year=d3_year;

    }
    farmer()
    {

    }

    }add,upd,check,rem,transaction;

vector<farmer> v;


void new_acc()

{
    int choice;

    /*label*/account_no:

    cout<<"******************* ADD RECORD **************";

    cout<<"\n\n\nEnter today's date(mm dd yyyy):";
    cin>>add.deposit.month>>add.deposit.day>>add.deposit.year;
    cout<<"\nEnter the account number:";
    cin>>check.acc_no;
   for(int i=0;i<v.size();i++){
        if (check.acc_no==v[i].acc_no)
            {cout<<"Account no. already in use!";

                goto account_no;

            }
    }
    system("cls");
    add.acc_no=check.acc_no;
        cout<<"\nEnter the name:";
    cin>>add.name;
    cout<<("\nEnter the date of birth(mm/dd/yyyy):");
    cin>>add.dob.month>>add.dob.day>>add.dob.year;
    cout<<"\nEnter the age:";
    cin>>add.age;
    cout<<"\nEnter the annual income:";
    cin>>add.annual_income;
    cout<<"\nEnter the address:";
    cin>>add.address;
    cout<<"\nEnter the country:";
    cin>>add.citizenship;
    cout<<"\nEnter the phone number: ";
    cin>>add.phone;
    cout<<"\nEnter the quantity to deposit:";
    cin>>add.quant;
    cout<<"\nEnter first crop:";
    cin>>add.crop1;
    cout<<"\nEnter second crop:";
    cin>>add.crop2;
    cout<<"\nEnter third crop:";
    cin>>add.crop3;

    v.push_back(add);
    cout<<"\nAccount created successfully!";

   /*label*/ add_invalid:
    cout<<"\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            cout<<"closed";
    else
        {
            cout<<"\nInvalid!\a";
            goto add_invalid;
        }
}
void view_list()
{
    int test=0;


           cout<<"\nACC.NO.\t   NAME\t       ADDRESS\t       PHONE\n";

    for(int i=0;i<v.size();i++){

           cout<<v[i].acc_no<<setw(15)<<v[i].name<<setw(15)<<v[i].address<<setw(15)<<v[i].phone<<endl;
           test++;
       }


    if (test==0)
        {
           cout<< "\nNO RECORDS!!\n";}

        view_list_invalid:
        cout<<"\n\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;

        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            cout<<"closed";
        else
        {
            cout<<"\nInvalid!\a";
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;

    cout<<"\nEnter the account no. of the customer whose info you want to change:";
    cin>>upd.acc_no;
    for(int i=0;i<v.size();i++)
        {
        if (upd.acc_no==v[i].acc_no)
        {   test=1;
			again:
            cout<<"\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):";
            cin>>choice;
            system("cls");
            if(choice==1)
                {cout<<"Enter the new address:";
                cin>>upd.address;
               v[i].address=upd.address;
               system("cls");
                cout<<"Changes saved!";
                }
            else if(choice==2)
                {
                    cout<<"Enter the new phone number:";
                cin>>upd.phone;
               v[i].phone=upd.phone;
                cout<<"Changes saved!";
                }

        }
        else
         {

          cout<<"wrong choice";
           goto again;
         }
    }
        cout<<("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        cin>>main_exit;
        system("cls");
        if (main_exit==1)
            menu();
        else
             cout<<"closed";


if(test!=1)
        {   system("cls");
            cout<<"\nRecord not found!!\a\a\a";
            edit_invalid:
              cout<<"\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
              cin>>main_exit;
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    cout<<"closed";
                else if(main_exit==0)
                    edit();
                else
                    {cout<<("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {cout<<("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        cin>>main_exit;
        system("cls");
        if (main_exit==1)
            menu();
        else
             cout<<"closed";
        }
}

void transact(void)
{   int choice,test=0;

        cout<<("Enter the account no. of the customer:");
    cin>>transaction.acc_no;
    for(int i=0;i<v.size();i++) {

            if(v[i].acc_no==transaction.acc_no)
            {   test=1;

                cout<<("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                cin>>choice;
                if (choice==1)
                {
                    cout<<("Enter the quantity you want to deposit: ");
                    cin>>transaction.quant;
                    v[i].quant+=transaction.quant;
                    cout<<("\n\nDeposited successfully!");
                }
                else if(choice==2)
                {
                    cout<<("Enter the quantity you want to withdraw: ");
                    cin>>transaction.quant;
                    v[i].quant-=transaction.quant;
                    cout<<("\n\nWithdrawn successfully!");
                }

            }
            cout<<"updated quantity:";
            cout<<v[i].quant<<endl;

   }
 if(test!=1)
   {
       cout<<("\n\nRecord not found!!");
       transact_invalid:
      cout<<("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      cin>>main_exit;
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
     cout<<"closed";
    else
    {
        cout<<("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       cout<<("\nEnter 1 to go to the main menu and 0 to exit:");
        cin>>main_exit;
         system("cls");
        if (main_exit==1)
            menu();
        else
           cout<<"closed";
   }

}
void erase(void)
{
    int test=0;
    cout<<("Enter the account no. of the customer you want to delete:");
    cin>>rem.acc_no;
     for(int i=0;i<v.size();i++) {
        if(v[i].acc_no==rem.acc_no)
            {test++;
            v.erase(v.begin()+i);
            cout<<"\nRecord deleted successfully!\n";
            }

   }
   if(test==0)
        {
            cout<<("\nRecord not found!!\a\a\a");
            erase_invalid:
              cout<<("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              cin>>main_exit;

                system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    cout<<"closed";
                else if(main_exit==0)
                    erase();
                else
                    {cout<<("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {cout<<("\nEnter 1 to go to the main menu and 0 to exit:");
        cin>>main_exit;
        system("cls");
        if (main_exit==1)
            menu();
        else
         cout<<"closed";
        }

}

void see(void)
{
    int test=0,rate;
    int choice;
    double time;

         cout<<"Enter the account number:";
        cin>>check.acc_no;

       for(int i=0;i<v.size();i++) {
            if(v[i].acc_no==check.acc_no)
            {
                  system("cls");
                test=1;

                cout<<"\nAccount NO.:\t"<<v[i].acc_no<<"\nName:"<<setw(10)<<v[i].name<<"\nannual income:"<<setw(10)<<v[i].annual_income<<"\nDOB:"<<setw(10)<<v[i].dob.month<<"/"<<v[i].dob.day<<"/"<<v[i].dob.year<<"\nAge:"<<setw(10)<<v[i].age<<"\nAddress:"<<setw(10)<<v[i].address<<"\nCitizenship No:"<<setw(10)<<v[i].citizenship<<"\nPhone number:"<<setw(15)<<v[i].phone<<"\nquantity deposited:"<<setw(10)<<v[i].quant<<"\nDate Of Deposit:"<<setw(10)<<v[i].deposit.month<<"/"<<v[i].deposit.day<<"/"<<v[i].deposit.year<<endl;

            }
        }

     if(test!=1)
        {
            cout<<"\nRecord not found!!\a\a\a";
            see_invalid:
              cout<<"\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
              cin>>main_exit;
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                     cout<<"closed";
                else if(main_exit==0)
                    see();
                else
                    {

                        cout<<"\nInvalid!\a";
                        goto see_invalid;}
        }
    else
        {cout<<"\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;}
        system("cls");
        if (main_exit==1)
        {

            menu();
        }

        else
           {


           cout<< "closed";
            }


}

class crop_count
{
public:
    string crop;
    int count=1;

};


int ar_crop(string area)
{   vector<crop_count> cc;

 for(int i=0;i<v.size();i++)
        {
            int c1=0, c2=0, c3=0;
             if(v[i].address==area)
            {
                for(int j=0; j<cc.size(); j++)
                {
                    if(v[i].crop1==cc[j].crop)
                    {
                        cc[j].count++;
                        c1++;
                    }
                     if(v[i].crop2==cc[j].crop)
                    {
                        cc[j].count++;
                        c2++;
                    }
                     if(v[i].crop3==cc[j].crop)
                    {
                        cc[j].count++;
                        c3++;
                    }
                    }
                    crop_count n;
                    n.crop=v[i].crop1;
                    if(c1==0)
                      cc.push_back(n);

                    if(c2==0){
                            n.crop=v[i].crop2;
                        cc.push_back(n);
                    }

                    if(c3==0)
                     {
                       n.crop=v[i].crop3;
                        cc.push_back(n);
                     }

}

        }
        int max=1; int index=0;
        for(int k=0; k<cc.size(); k++)
        {
            if(max<cc[k].count)
                {max=cc[k].count;
                index=k;
                }

        }
        cout<<area<<"          "<<cc[index].crop<<"          "<<cc[index].count;
return 1;
}


double av_salary(string area)
{
    int test=0;
    double sum=0.0;
         for(int i=0;i<v.size();i++)
        {
             if(v[i].address==area)
            {
                sum=sum+v[i].annual_income;
                test++;
            }

        }return (double)sum/test;
}
void area_income()
{
    vector<string> area;

   for(int outer=0;outer<v.size();outer++){
        bool done=0;
       for(int j=0;j<area.size();j++)
       {
           if(v[outer].address==area[j])
           {
               done=1;
           }
       }
       if(done!=1){
            area.push_back(v[outer].address);
       cout<<v[outer].address <<":   " <<av_salary(v[outer].address)<<endl;
   }
}
 /*label*/ invalid:
    cout<<"\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            cout<<"closed";
    else
        {
            cout<<"\nInvalid!\a";
            goto invalid;
        }
}



void area_crop()
{
   vector<string> area;
cout<<"area    ||    major_crop      ||    no. of farmers\n";
   for(int outer=0;outer<v.size();outer++){
        bool done=0;
       for(int j=0;j<area.size();j++)
       {
           if(v[outer].address==area[j])
           {
               done=1;
           }
       }
       if(done!=1){
            area.push_back(v[outer].address);
      ar_crop(v[outer].address);
      cout<<endl;
   }
}
 /*label*/ invalid:
    cout<<"\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            cout<<"closed";
    else
        {
            cout<<"\nInvalid!\a";
            goto invalid;
        }
}
void bpl()
{  int j=1;
cout<<"NAME OF FARMER\t\t\t PHONE NO.\n";
    for(int i=0;i<v.size();i++)
    {
        if(v[i].annual_income<av_salary(v[i].address))
        {
            cout<<j<<". "<<v[i].name<<"\t\t\t "<<v[i].phone<<endl;
            j++;
        }
    }
     /*label*/ invalid:
    cout<<"\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            cout<<"closed";
    else
        {
            cout<<"\nInvalid!\a";
            goto invalid;
        }
}
void menu(void)
{  int choice;


   cout<<("\n\n\t\t\tSTORE KARO");
   cout<<("\n\n\n\t\t\t**********WELCOME TO THE MAIN MENU **********");
    cout<<("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.Modify account\n\t\t4.Check the details of existing account\n\t\t5.Delete existing account\n\t\t6.View farmer's list\n\t\t7.Average income of a particular area\n\t\t8.farmers having annual income less than average area income\n\t\t9.major crop produced area wise\n\t\t10.Exit\n\n\n\n\n\t\t Enter your choice:");
    cin>>choice;
    system("cls");

    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
         case 7: area_income();
        break;
        case 8: bpl();
        break;
         case 9: area_crop();
        break;
        case 10: cout<<"closed";
        break;

    }
}

int main()
{


                farmer f1("wheat","rice","cane",500000, "Kishan" , 123, "ghaziabad", "Indian", 521337771 , 1000, 5, 10 ,1989, 11, 30, 2017, 8, 7 ,2018);
                v.push_back(f1);
                farmer f2("pulse","rice","cane",6000,"rahul" , 251, "noida", "Indian", 521337772 , 2000, 10, 6 ,1989, 12, 10, 17, 7, 7 ,2018);
                v.push_back(f2);
                farmer f3("wheat","potato","mustard",168000,"jagmohan" , 109, "ghaziabad", "Indian", 521336771 , 9000, 9, 19 ,1979, 11, 16, 2017, 7, 7 ,2018);
                v.push_back(f3);
                farmer f4("wheat","rice","potato",256830,"ramesh" , 163, "ghaziabad", "Indian", 591337771 , 10000, 8, 10 ,1989, 12, 10, 17, 7, 7 ,2018);
                v.push_back(f4);
                farmer f5("tomato","rice","cane",6000,"rahul" , 251, "noida", "Indian", 521337772 , 2000, 10, 6 ,1989, 12, 10, 17, 7, 7 ,2018);
                v.push_back(f5);
                menu();
}
