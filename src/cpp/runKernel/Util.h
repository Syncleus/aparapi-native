/*
 * Util.h
 *
 *  Created on: 24/04/2018
 *      Author: lpnm
 */

#ifndef SRC_CPP_RUNKERNEL_UTIL_H_
#define SRC_CPP_RUNKERNEL_UTIL_H_

#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


#endif /* SRC_CPP_RUNKERNEL_UTIL_H_ */
