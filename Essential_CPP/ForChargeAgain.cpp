#include <iostream>
#include <string>
using namespace std;

int main (void)
{
    string user_name ("0");
    string responseForPlayAagin;
    int PutIn(0),user_fraction = 0;
    int  fist_value(5),secend_value(8),next_value(0);
    bool play_again = true;
    cout << "please enter your name : \r\n ";
    cin >> user_name;
    cout << "\r\n Game begain,the list is 1,1,2,3,5,8 please enter the next value of the list \r\n"<<endl;
    while (play_again)
    {
        cin >> PutIn;
        next_value = fist_value+secend_value;
        fist_value = secend_value;
        secend_value = next_value;
        if (PutIn == next_value)
        {
            cout<<"Wow,Good Jop! \r\n"<<endl;
            user_fraction +=1;
        }else {
            cout<< "Sad ,your are wrong!\r\n"
                   <<"the number is "<<next_value<<endl;
                user_fraction -=1;
                   }
        cout << "  \r\n Do you want to play again?Please enter yes or no. \r\n";
        cin >> responseForPlayAagin;
        if (responseForPlayAagin == "yes") {play_again = true; cout << "please enter the next number:"<<endl;}
        else {play_again = false; }
    }
    cout<<"thanks for playing the game"
        << "and the fraction of you is : "
        << user_fraction <<endl;
    return 0;
}