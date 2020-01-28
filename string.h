#pragma once

#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <stdlib.h>
#include <assert.h>

#include "object.h"

class String : public Object {
  public:
    // Default constructor
    String();
    
    // Construct a String with the given char*
    String (char* val);

    // Construct a String with the given char*
    String(const char* val);

    // Destructor
    ~String();

    // Return a new String representing this String
    // concatenated with the given other String
    String* concat(String* other);

    // Return the character at index i
    char char_at(size_t i);

    // Return the size of this String
    size_t size();

    // Return the hash of this String
    virtual size_t hash();

    // Doed this String equal the given Object?
    virtual bool equals(Object *o);

    // How does this String alphabetically compare to the given other String
    virtual int compare(String* other);
};