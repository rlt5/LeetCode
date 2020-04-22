#include <string>
#include <iostream>
#include <iomanip>
#include <unordered_map>

class Solution{
public:
    bool isInt(char c){
        if ( '0' <= c && c <= '9'  ){
            return true;
        }
        else {
            return false;
        }
    }

    bool isNumber(std::string s){

        auto c = s.cbegin();
        bool intDetect = false;
        bool nullDetect = true;
        bool numDetect = false;
        bool numAfterEDetect = false;

        while ( c != s.cend() && *c == ' ' ) {
            c++;
        }

        if ( c == s.cend()){
            return false;
        }

        // Check first digit if it is "-"
        if ( *c == '-' || *c == '+'  ){
            c++;
        } 
        
        if ( *c == 'e'){ // Number can not start with an e
            return false;
        }

        while ( c != s.cend() ){

            if ( *c == ' ' ){ // Check if the string ends with spaces
                while ( *c == ' ' ){
                    c++;
                }
                if ( c == s.cend()) {
                    if (intDetect == true ){
                        return true;
                    } else if ( nullDetect == true ){
                        return true;
                    }
                }
                return false;
            }


            if ( *c == '.' ){
                c++;

                while ( c != s.cend() ){
                    if ( *c == ' ' ){ // Check if the string ends with spaces
                        while ( *c == ' ' ){
                            c++;
                        }
                        if ( c == s.cend() ) {
                            if (intDetect == true ){
                                return true;
                            } else if ( nullDetect == true && numDetect == true){
                                return true;
                            }
                        }
                        return false;
                    }
                    
                    if ( *c == 'e' ){
                        c++;

                        // Check first digit if it is "-"
                        if ( *c == '-' || *c == '+' ){
                            c++;
                        } 
                        
                        while ( c != s.cend() ){
                            if ( *c == ' ' ){ // Check if the string ends with spaces
                                while ( *c == ' ' ){
                                    c++;
                                }
                                if ( c == s.cend() && intDetect == true ){
                                    return true;
                                } else {
                                    if ( nullDetect == true){
                                        return true;
                                    }
                                   // std::cout << "false 4";
                                    return false;
                                }
                            }
                            if ( isInt(*c) ){
                                numDetect = true;
                                numAfterEDetect = true;
                                c++;
                            } else {
                                return false;
                            }
                        }
                        if ( intDetect == false ){
                            if ( nullDetect == false ){
                                return false;
                            }
                            return false;
                        }
                        if ( numAfterEDetect == false ){
                            return false;
                        }
 
                        return true;
                    }

                    if ( isInt(*c) ){
                        if ( *c != '0'){
                            intDetect = true;
                            nullDetect = false;
                        } 
                        numDetect = true;
                        c++;
                    } else {
                        return false;
                    }
                    
                }
                
                if ( c == s.cend() && intDetect == true){
                    return true;
                } else if ( nullDetect && numDetect == true ){
                    return true;
                } else {
                    return false;
                }
            }

            if ( *c == 'e' ){
                c++;

                if ( *c == '-' || *c == '+' ){ // Check first digit if it is "-"
                    c++;
                } 
                
                if ( isInt(*c) ) {
                    if ( *c != '0'){
                        intDetect = true;
                    } else {
                        nullDetect = false;
                    }
                    numDetect = true;
                    c++;
                } else {
                    return false;
                }

                while ( c != s.cend() ){
                    if ( *c == ' ' ){ // Check if the string ends with spaces
                        while ( *c == ' ' ){
                            c++;
                        }
                        if ( c == s.cend() )
                            return true;
                        else {
                            return false;
                        }
                    }
                    if ( isInt(*c) ){
                        if ( *c != '0'){
                            intDetect = true;
                        } else {
                            nullDetect = false;
                        }
                        c++;
                    } else {
                        return false;
                    }
                }
                return true;
            }

            if ( isInt(*c)  ){
                if ( *c != '0'){
                    intDetect = true;
                    nullDetect = false;
                } 
                numDetect = true;
                c++;
            } else {
                return false;
            }
        }
        
        if ( intDetect == false && numDetect == false ){
            return false;
        }
        return true;
    }
};

int main(int argc, char* argv[] ){
    // string s = argv[1];
    Solution sol = Solution();
    std::unordered_map<std::string, bool> stringMap;
    stringMap.insert ( std::pair<std::string, bool>("0",true) );
    stringMap.insert ( std::pair<std::string, bool>(" 0.1 ",true) );
    stringMap.insert ( std::pair<std::string, bool>("abc",false) );
    stringMap.insert ( std::pair<std::string, bool>("1 a",false) );
    stringMap.insert ( std::pair<std::string, bool>("2e10",true) );
    stringMap.insert ( std::pair<std::string, bool>(" -90e3   ",true) );
    stringMap.insert ( std::pair<std::string, bool>(" 1e",false) );
    stringMap.insert ( std::pair<std::string, bool>("e3",false) );
    stringMap.insert ( std::pair<std::string, bool>(" 6e-1",true) );
    stringMap.insert ( std::pair<std::string, bool>(" 99e2.5 ",false) );
    stringMap.insert ( std::pair<std::string, bool>("53.5e93",true) );
    stringMap.insert ( std::pair<std::string, bool>(" --6 ",false) );
    stringMap.insert ( std::pair<std::string, bool>("-+3",false) );
    stringMap.insert ( std::pair<std::string, bool>("95a54e53",false) );
    stringMap.insert ( std::pair<std::string, bool>(".1",true) );
    stringMap.insert ( std::pair<std::string, bool>("3.",true) );
    stringMap.insert ( std::pair<std::string, bool>(".",false) );
    stringMap.insert ( std::pair<std::string, bool>("+.8",true) );
    stringMap.insert ( std::pair<std::string, bool>("46.e3",true) );
    stringMap.insert ( std::pair<std::string, bool>(".e1",false) );
    stringMap.insert ( std::pair<std::string, bool>(".0e",false) );
    stringMap.insert ( std::pair<std::string, bool>(".0",true) );
    stringMap.insert ( std::pair<std::string, bool>("0.",true) );
    stringMap.insert ( std::pair<std::string, bool>(". ",false) );
    stringMap.insert ( std::pair<std::string, bool>(".1e",false) );
    stringMap.insert ( std::pair<std::string, bool>("00 ", true) );
    stringMap.insert ( std::pair<std::string, bool>("0 0",false) );
    stringMap.insert ( std::pair<std::string, bool>("0. .e",false) );
    
    std::cout << std::endl;
    std::cout << std::setw(10) << std::right << "Test String" << " " << std::setw(6) << "Actual" << " " << std::right << std::setw(6) << "Result--- PASS/FAIL" <<  std::endl;
    std::cout << "--------------------------------------"<< std::endl;

    
    std::unordered_map<std::string, bool>::iterator it;
    for ( it=stringMap.begin(); it!=stringMap.end(); ++it){
        std::cout << std::setw(10) << std::right << it->first << " " << std::setw(6) << std::boolalpha  << it->second << " " << std::right << std::setw(6) << sol.isNumber(it->first);
        if (sol.isNumber(it->first) == it->second){
            std::cout << " --- PASS" << std::endl;
        } else {
            std::cout << " --- FAIL <-" << std::endl;
        }
    }

}