 #include<iostream>
 #include<fstream>
 #include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t____________________________________________________\n\n\n";
    cout<<"\t\t\t              welcome to the login page             \n\n\n";
    cout<<"\t\t\t______________________Menu__________________________\n\n";
    cout<<"                                                           \n\n";
    cout<<"\t| press 1 to LOGIN                         |"<<endl;
    cout<<"\t| press 2 to REGESTER                      |"<<endl;
    cout<<"\t| press 3 if you forgot your PASSWARD      |"<<endl;
    cout<<"\t| press 4 to EXIT                          |"<<endl;
    cout<<"\n\t\t\t please enter your choice : ";
    cin>>c;
    cout<<endl;
    switch (c)
    {
        case 1:
             login();
             break;
        
        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t thank you \n\n";
        break;
        default:
        system("cls");
        cout<<"\t\t\t please select from the options given above \n"<<endl;
        main();

    }


}

void login(){
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;
    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id==userId && pass== password){
            count =1;
            system("cls");

        }
    }
    input.close();
    if(count==1){
        cout<<userId<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n please check your username or password\n";
        main();
    }

}

void registration(){
    string ruserId ,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username :";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password :";
    cin>>rpassword;
    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful !\n";
    main();

}
void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t you forgot thr password ? No worries \n";
    cout<<"press 1 to search your id by username"<<endl;
    cout<<"press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice :";
    cin>>option;
    switch (option)
    {
    case 1:
    {
    int count =0;
    string suserId,sId,spass;
    cout<<"\t\t\t Enter the username which you remembered :";
    cin>>suserId;
    ifstream f2("records.txt");
    while(f2>>sId>>spass){
        if(sId==suserId)
        {
            count=1;
        }
        
    }
    f2.close();
    if(count==1){
        cout<<"\n\n your account is found \n";
        cout<<"\n\n your password is : "<<spass;
        main();
    }
    else{
        cout<<"\n\t sorry! your account is not found!";
        main();
    }
        break;
    
    }

     case 2:
     {
         main();
     }
     default:
     cout<<"\t\t\t wrong choice ! please try again"<<endl;
     forgot();
    }
    

}
     

 
 