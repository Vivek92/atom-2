/*-----------------------------------------------------------------------------
| Copyright (c) 2013, Nucleic Development Team.
|
| Distributed under the terms of the Modified BSD License.
|
| The full license is in the file COPYING.txt, distributed with this software.
|----------------------------------------------------------------------------*/
#pragma once


// shamelessly derived from qglobal.h
template<typename T>
class GlobalStatic
{
public:
    T* pointer;
    inline GlobalStatic( T* p ) : pointer( p ) {}
    inline ~GlobalStatic() { pointer = 0; }
};


#define GLOBAL_STATIC( TYPE, NAME )                                    \
    static TYPE* NAME()                                                \
    {                                                                  \
        static TYPE this_variable;                                     \
        static GlobalStatic<TYPE> this_global_static( &this_variable); \
        return this_global_static.pointer;                             \
    }
