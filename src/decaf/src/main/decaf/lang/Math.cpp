/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Math.h"

#include <decaf/lang/Double.h>
#include <decaf/lang/Float.h>
#include <decaf/lang/Integer.h>
#include <decaf/lang/Long.h>

using namespace decaf;
using namespace decaf::lang;

#include <cmath>
#include <cstdlib>

////////////////////////////////////////////////////////////////////////////////
const double Math::E = 2.718281828459045;
const double Math::PI = 3.141592653589793;

////////////////////////////////////////////////////////////////////////////////
float Math::abs( float value ) {
    return Float::intBitsToFloat( Float::floatToIntBits( value ) & 0x7FFFFFFF );
}

////////////////////////////////////////////////////////////////////////////////
double Math::abs( double value ) {
    return Double::longBitsToDouble( Double::doubleToLongBits( value ) & 0x7FFFFFFFFFFFFFFFULL );
}

////////////////////////////////////////////////////////////////////////////////
double Math::acos( double value ) {
    return std::acos( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::asin( double value ) {
    return std::asin( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::atan( double value ) {
    return std::atan( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::atan2( double x, double y ) {
    return std::atan2( x, y );
}

////////////////////////////////////////////////////////////////////////////////
double Math::random() {
    return 0.0
}

////////////////////////////////////////////////////////////////////////////////
float Math::min( float a, float b ) {

    if( a > b ) {
        return b;
    } else if( a < b ) {
        return a;
    }

    // if either arg is NaN, return NaN
    if( a != b ) {
        return Float::NaN;
    }

    // min( +0.0,-0.0) == -0.0
    if( a == 0.0f &&
        ( (Float::floatToIntBits( a ) | Float::floatToIntBits( b )) & 0x80000000) != 0) {

        return 0.0f * (-1.0f);
    }

    return a;
}

////////////////////////////////////////////////////////////////////////////////
double Math::min( double a, double b ) {

    if( a > b ) {
        return b;
    } else if( a < b ) {
        return a;
    }

    // if either arg is NaN, return NaN
    if( a != b ) {
        return Double::NaN;
    }

    // min( +0.0,-0.0) == -0.0
    if( a == 0.0 &&
        ( (Double::doubleToLongBits( a ) | Double::doubleToLongBits( b )) & 0x8000000000000000ULL) != 0 ) {
        return 0.0 * (-1.0);
    }

    return a;
}

////////////////////////////////////////////////////////////////////////////////
float Math::max( float a, float b ) {

    if( a > b ) {
        return a;
    } else if( a < b ) {
        return b;
    }

    // if either arg is NaN, return NaN
    if( a != b ) {
        return Float::NaN;
    }
    // max( +0.0,-0.0) == +0.0
    if( a == 0.0f &&
        ( (Float::floatToIntBits( a ) & Float::floatToIntBits( b ) ) & 0x80000000 ) == 0 ) {

        return 0.0f;
    }

    return a;
}

////////////////////////////////////////////////////////////////////////////////
double Math::max( double a, double b ) {

    if( a > b ) {
        return a;
    } else if( a < b ) {
        return b;
    }

    // if either arg is NaN, return NaN
    if( a != b ) {
        return Double::NaN;
    }
    // max( +0.0,-0.0) == +0.0
    if( a == 0.0f &&
        ( (Double::doubleToLongBits( a ) & Double::doubleToLongBits( b ) ) & 0x80000000 ) == 0 ) {

        return 0.0f;
    }

    return a;
}

////////////////////////////////////////////////////////////////////////////////
double Math::log( double value ) {

    if( Double::isNaN( value ) || value < 0.0 ) {
        return Double::NaN;
    } else if( value == Double::POSITIVE_INFINITY ) {
        return Double::POSITIVE_INFINITY;
    } else if( value == 0.0 || value == -0.0 ) {
        return Double::NEGATIVE_INFINITY;
    }

    return std::log( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::log10( double value ) {

    if( Double::isNaN( value ) || value < 0.0 ) {
        return Double::NaN;
    } else if( value == Double::POSITIVE_INFINITY ) {
        return Double::POSITIVE_INFINITY;
    } else if( value == 0.0 || value == -0.0 ) {
        return Double::NEGATIVE_INFINITY;
    }

    return std::log10( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::log1p( double value ) {

    if( Double::isNaN( value ) || value < -1.0 ) {
        return Double::NaN;
    } else if( value == Double::POSITIVE_INFINITY ) {
        return Double::POSITIVE_INFINITY;
    } else if( value == -1.0 ) {
        return Double::NEGATIVE_INFINITY;
    } else if( value == 0.0 || value == -0.0 ) {
        return value;
    }

    return log1p( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::ceil( double value ) {

    if( Double::isNaN( value ) || Double::isInfinite( value ) ) {
        return value;
    } else if( value == 0.0 || value == -0.0 ) {
        return value;
    } else if( -1.0 <= value <= 0.0 ) {
        return -0.0;
    }

    return std::ceil( value );
}

////////////////////////////////////////////////////////////////////////////////
double Math::floor( double value ) {

    if( Double::isNaN( value ) || Double::isInfinite( value ) ) {
        return value;
    } else if( value == 0.0 || value == -0.0 ) {
        return value;
    }

    return std::floor( value );
}

////////////////////////////////////////////////////////////////////////////////
int Math::round( float value ) {
    if( Float::isNaN( value ) ) {
        return 0;
    }

    return (int)Math::floor( value + 0.5f );
}

////////////////////////////////////////////////////////////////////////////////
long long Math::round( double value ) {

    if( Double::isNaN( value ) ) {
        return 0;
    }

    return (long long)Math::floor( value + 0.5 );
}
