#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl; using std::string;





int main(int argc, char *argv[])
{
    char search_alphabet[] = {'a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string salt = "";
    string correct_hash  = "";
    int cartesian_product_indices[6] = {0};
    while(cartesian_product_indices[0] < 26){
        //build search string
        string password_attempt = "";
        for (int i = 0 ; i < 6; i++) {
            password_attempt += search_alphabet[cartesian_product_indices[i]];
        }
        //TODO: MD5Crypt the password_attempt here, and compare it to correct_hash
        cout<<password_attempt<<endl;
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
    
    //cout << "md5 of 'grape': " << md5("grape") << endl;
    return 0;
}