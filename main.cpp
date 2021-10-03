#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl; using std::string;





int main(int argc, char *argv[])
{
    char search_alphabet[] = {'a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string salt = "";
    string correct_hash  = "";
    int cartesian_product_indices[6] = {0};
    while(cartesian_product_indices[5] != 25 || cartesian_product_indices[0]!= 25){
        string password_attempt = "";
        for (int i = 0 ; i < 6; i++) {
            password_attempt += search_alphabet[cartesian_product_indices[i]];
        }
        for (int current_index = 5; current_index > 0;  current_index--) {

        }

    }
    
    //cout << "md5 of 'grape': " << md5("grape") << endl;
    return 0;
}