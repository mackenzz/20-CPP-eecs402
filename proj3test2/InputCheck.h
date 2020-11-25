//
//  InputCheck.hpp
//  project3r
//
//  Created by Zijin Zhang on 11/25/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"


#ifndef _INPUTCHECK_H_
#define _INPUTCHECK_H_

#include <stdio.h>
class InputCheck {
private:
    bool isValid;
public:
    InputCheck();
    
    int colorCheck();
    
    int rowColCheck(string inputWords);
    
};



#endif /* INPUTCHECK_H */
