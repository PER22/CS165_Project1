#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl; using std::string;

string MD5Crypt(string password, string salt, string magic){
    MD5 alternate_md5 = MD5();
    alternate_md5.update(password + salt + password);
    string intermediate = md5(password + magic + salt + alternate.substr(0,6) + alternate[0] + char(00) + char(00));  
    for (int i = 0; i < 1000; i++) {
        string accumulator = "";
        if(!(i%2)){accumulator += intermediate;}
        else{accumulator += password;}
        if(i%3){accumulator += salt;}
        if(i%7){accumulator += password;}
        if(!(i%2)){accumulator += password;}
        else{accumulator += intermediate;}
        intermediate = md5(accumulator);
    }
    cout<<intermediate<<endl;
    return intermediate;
}


int main(int argc, char *argv[])
{
    string search_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string our_salt = "4fTgjp6q";
    string our_correct_hash  = "pcnyPpGUQ2MvsGld8UMVa/";
    int cartesian_product_indices[6] = {0};
    while(cartesian_product_indices[0] < 26){
        //build search string
        string password_attempt = "";
        for (int i = 0 ; i < 6; i++) {
            password_attempt += search_alphabet[cartesian_product_indices[i]];
        }
        cout<<password_attempt<<endl;
        //md5Crypt hash our password attempt and compare it to the desired hash:
        string hashed_password = MD5Crypt(password_attempt,our_salt,"$1$");
        if(hashed_password == our_correct_hash){cout<<password_attempt; return 0;}
        //Increment the lsb of the indices list
        cartesian_product_indices[5]++;
        //Update the indices list 
        for (int current_index = 5; current_index > 0;  current_index--) {
            if(cartesian_product_indices[current_index] == 26){
                cartesian_product_indices[current_index] = 0;
                cartesian_product_indices[current_index - 1]++;
                }
        }
    }
    cout << "Failed to find password"<< endl;
    return 0;
}