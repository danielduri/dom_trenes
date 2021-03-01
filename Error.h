//
// Created by Daniel Durán on 24/2/21.
//

#ifndef DOM_TRENES_ERROR_H
#define DOM_TRENES_ERROR_H

#include<string>

class Error {
private:
    std::string message;
public:
    explicit Error(std::string m){
        message=m;
    }
    std::string getMessage(){
        return message;
    }
};


#endif //DOM_TRENES_ERROR_H
