#pragma once

#include <stddef.h>

class Object {
  public:
    // Does this object equal the other object
    virtual bool equals(Object* o);

    // Computes the hash value of this object
    virtual size_t hash();
};