#pragma once

class Object {
  public:
    // Does this object equal the other object
    virtual bool equals(Object* o);

    // Computes the hash value of this object
    virtual int hash_code();

    // Returns the string representation of this object
    virtual char* to_string();
};