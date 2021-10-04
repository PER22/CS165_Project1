#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl; using std::string;

string MD5Crypt(string password, string salt, string magic){
    string Alternate = md5(password + salt + password);
    string Intermediate = md5(password + magic + salt  );//Incomplete logic here
}


int main(int argc, char *argv[])
{
    char search_alphabet[] = {'a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string our_salt = "4fTgjp6q";
    string our_correct_hash  = "pcnyPpGUQ2MvsGld8UMVa/";
    int cartesian_product_indices[6] = {0};
    while(cartesian_product_indices[0] < 26){
        //build search string
        string password_attempt = "";
        for (int i = 0 ; i < 6; i++) {
            password_attempt += search_alphabet[cartesian_product_indices[i]];
        }
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