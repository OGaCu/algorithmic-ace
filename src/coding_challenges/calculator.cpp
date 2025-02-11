/**
 * input -> output
 * a-(b+c) -> a-b-c
 * a-(a-b) -> b
 * (a-b)+c -> a-b+c // parenthesis upfront
 * -(a+b) -> -a-b
*/

#include<string>
using std::string;

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// assumed no space in input string
// assumed no nested parenthesis
// handle addition and subtraction

string remove_parenthesis(string input) {
    // check for pattern a-(b+c)
    size_t pos = input.find("-(");
    while(pos != string::npos && pos > 0) {
        size_t closing_bracket = input.find(')', pos);
        if(closing_bracket != string::npos) {
            string before = input.substr(0, pos);
            string inside = input.substr(pos + 2, closing_bracket - (pos + 2));
            string after = input.substr(closing_bracket + 1);
            
            // find '+' to change to '-'
            size_t plus_pos = inside.find('+');
            if(plus_pos != string::npos) {
                // transform -(b+c) to -b-c
                string new_expr = before + "-" + inside.substr(0, plus_pos) + 
                                "-" + inside.substr(plus_pos + 1) + after;
                input = new_expr;
            }
        }
        pos = input.find("-(", pos + 1);
    }
    
    // Check for pattern a-(a-b)
    pos = input.find("-(");
    while(pos != string::npos && pos > 0) {
        size_t closing_bracket = input.find(')', pos);
        if(closing_bracket != string::npos && 
           pos > 0 && 
           closing_bracket - pos == 4 && // Length check for (a-b)
           input[pos-1] == input[pos+2]) { // Check if both 'a' are same
            string before = input.substr(0, pos-1);
            string b = string(1, input[pos+3]); // Get 'b'
            string after = input.substr(closing_bracket + 1);
            input = before + b + after;
        }
        pos = input.find("-(", pos + 1);
    }
    
    return input;
}

