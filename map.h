#pragma once

#include "object.h"

class Map: public Object {
  public:
    // Does this map contain the given key
    bool contains_key(Object* key);

    // Places the given value at the given key
    void put(Object* key, Object* value);

    // Returns the value at the given key
    Object* get(Object* key);

    // Does this map equal the given Object
    bool equals(Object* other);

    // Computes the hash value of this map
    int hash_code();

    // Returns the set of keys in this map
    Object** key_set();

    // Removes and returns the object at the given key
    Object* remove(Object* key);

    // Returns the number of elements in this map
    int size();
};