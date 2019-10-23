#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string input_string, int numOfSlots) { // check whether it's a palindrome
    
    int midpoint = numOfSlots / 2;
    
    for(int i = 0; i < midpoint; i++) {
        
        if(input_string[i] != input_string[(i-numOfSlots+1)*-1]) {
            return false;
        }
    }
    return true;
}

string normalize(string original_string) { // delete everything except A-Z/a-z, replace A-Z to a-z
    string temp_string;
    
    for(int i=0; i < original_string.size(); i++) { // check every character one by one
    	if(original_string[i] >= 'A' && original_string[i] <= 'z') { // A-Z,a-z
    		if(original_string[i] >= 'A' && original_string[i] <= 'Z') { // A-Z
    			temp_string += ((char)(original_string[i] + 'a' - 'A')); // convert to a-z
    		} else { // a-z
    			temp_string += ((char)(original_string[i])); // directly include as a-z
    		}
		} // else nothing happens
	}
	return temp_string;
}

int main() {
    string original_string, normalized_string;

    getline(cin, original_string); // get user input
    
    normalized_string = normalize(original_string); // delete everything except A-Z/a-z, replace A-Z to a-z
    
    if(is_palindrome(normalized_string, normalized_string.size())) // check whether it's a palindrome
        cout << "True";
    else
        cout << "False";
}
