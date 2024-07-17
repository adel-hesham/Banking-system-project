//including libiraries
#include<iostream>
#include<array>
#define initial_value 0                                            //to prevent magic number
#define max_value 100                                              //to prevent magic number

int record_counter=initial_value;                                  //variable to count the new records
class costumers                                                    //a class to store customers info
{
public:
    std::string fisrt_name;
    std::string last_name;
    int passcode;
    int money;
    costumers(std::string &f_n,std::string &l_n,int &p,int &m)     //a constructor to store the data in the variables
    {
        fisrt_name=f_n;
        last_name=l_n;
        passcode=p;
        money=m;
    }    
    costumers()                                                    //empty constructor for the array
    {

    }

};
std::array<costumers,max_value>id;                                    //an array of objects to collect the records and give an id for every account
void add_costumer(std::string &func_first_name,std::string &func_last_name,int &func_passcode,int &func_money)
{
    costumers obj(func_first_name,func_last_name,func_passcode,func_money);
    id[record_counter]=obj;
    record_counter++;
}
void print(std::string msg)
{
    std::cout<<msg;
}
void welcome_msg(void)
{
    print("***BANKING SYSTEM***\n***WELCOME***\n");
    
}
void print_options(void)
{
    print("\nPLEASE CHOOSE AN OPTION\n\n");
    print("1.Create a new account\n");
    print("2.Balance enquiry\n");
    print("3.Deposit\n");
    print("4.Withdrawal\n");
    print("5.Exit\n");
}
int get_option(void)
{
    int op;
    std::cin>>op;
    while((op<0)||(op>5))
    {
        print("Wrong entry try again");
        print_options();
        std::cin>>op;
    }
    return op;
}
std::string get_name(void)
{
    std::string func_name;
    std::cin>>func_name;
    return func_name;
}
int get_passcode(void)
{
    int func_passcode;
    std::cin>>func_passcode;
    while((func_passcode>9999)||(func_passcode<0))
    {
        print("Wrong enrty please try again");
        std::cin>>func_passcode;
    }
    return func_passcode;
}
std::string get_first_name(void)
{
    std::string func_first_name;
    std::cin>>func_first_name;
    return func_first_name;
}
std::string get_last_name(void)
{
    std::string func_last_name;
    std::cin>>func_last_name;
    return func_last_name;
}
int get_init_money(void)
{
    int money;
    std::cin>>money;
    while(money<500)
    {
        print("Try again! *(Minimum amount is 500$)*\n");
        std::cin>>money;
    }
    return money;
}
void new_account_show_details(std::string &f_n,std::string &l_n,int &passcode,int &money)
{
    print("Your name : ");
    std::cout<<f_n<<" "<<l_n<<"\n";
    print("Your passcode : ");
    std::cout<<passcode<<"\n";
    print("Your balance : ");
    std::cout<<money<<"$"<<"\n";
    print("Your id : ");
    std::cout<<record_counter-1<<"\n";
}
int get_id(void)
{
    int func_id;
    std::cin>>func_id;
    while((func_id<initial_value)||(id[func_id].passcode==initial_value)||(func_id>max_value))
    {
        print("Wrong entry! Try again\n ");
        std::cin>>func_id;
    }
    return func_id;
}
void show_details(int &func_id)
{
    print("Your name: ");
    std::cout<<id[func_id].fisrt_name<<" "<<id[func_id].last_name<<"\n";
    print("Account number: ");
    std::cout<<func_id<<"\n";
    print("Your balance: ");
    std::cout<<id[func_id].money<<"\n";
}
int get_money(void)
{
    int func_money;
    std::cin>>func_money;
    while(func_money<0)
    {
        print("Wrong entry ! Please try again\n");
        std::cin>>func_money;
    }
    return func_money;
}
void add_money(int &func_id,int &func_money)
{
    id[func_id].money+=func_money;
}
void withdrawal_money(int &func_id,int &func_money)
{
    if(func_money>id[func_id].money)
    {
        print("Invalid amount!\n");
    }
    else
    {
        id[func_id].money-=func_money;
        print("Done !\n");
    }
}
enum                                                                //numering options for switch case
{
    NEW=1,
    BALANCE,
    DEPOSIT,
    WITHDRAWAL,
    EXIT
};
//Entry point
int main()
{
    welcome_msg();
    bool working=true;                                              //the infinity while loop variable
    while(working==true)
    {
        print_options();
        int op=get_option();
        switch (op)
        {
            case NEW:
                {
                    print("***NEW ACCOUNT***\n\n");
                    print("Please enter your first name\n");
                    std::string first_name=get_first_name();
                    print("Please enter your last name\n");
                    std::string last_name=get_last_name();
                    print("create your passcode *ONLY 4 DIGITS FROM 0-9*\n");
                    int passcode=get_passcode();
                    print("Deposit an amount of money *(Minimum amount is 500$)*\n");
                    int money=get_init_money();
                    add_costumer(first_name,last_name,passcode,money);
                    new_account_show_details(first_name,last_name,passcode,money);
                    break;
                }
            case BALANCE:
                {
                    print("Enter your account number: \n");
                    int main_id=get_id();
                    print("Enter Passcode: \n");
                    int passcode=get_passcode();
                    if(id[main_id].passcode!=passcode)
                    {
                        print("Wrong passcode !\n");
                        break;
                    }
                    else
                    {
                    show_details(main_id);
                    break;
                    }
                }
            case DEPOSIT:
                {
                    print("*DEPOSIT*\n");
                    print("Enter account number: \n");
                    int main_id=get_id();
                    print("Enter Passcode: \n");
                    int passcode=get_passcode();
                    if(id[main_id].passcode!=passcode)
                    {
                        print("Wrong passcode !\n");
                        break;
                    }
                    else
                    {
                    print("Enter amout of money: \n");
                    int amount=get_money();
                    add_money(main_id,amount);
                    print("Done !\n");
                    break;
                    }
                }
            case WITHDRAWAL:
            {
                print("*Withdrawal*\n");
                print("Enter account number: \n");
                int main_id=get_id();
                print("Enter Passcode: \n");
                int passcode=get_passcode();
                if(id[main_id].passcode!=passcode)
                {
                    print("Wrong passcode !\n");
                    break;
                }
                else
                {
                print("Enter amout of money: \n");
                int amount=get_money();
                withdrawal_money(main_id,amount);
                break;
                }
            }
            case EXIT:
            {
                print("*Thank you for using our service*\n");
                working=false;
            }
        }   
    }   
    return 0;
}