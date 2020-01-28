#pragma once

#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <stdlib.h>
#include <assert.h>

#include "object.h"

class String : public Object {
  public :
    char* val_;
    size_t size_;

  String() {
    size_ = 0;
    val_ = nullptr;
  }
  
  String (char* val) {
    size_ = strlen(val) + 1; 
    val_ = new char[size_];
    for (size_t i = 0; i < size_; i++) {
      val_[i] = val[i];
    }
    val_[size_ - 1] = '\0';
  }

  String(const char* val) {
    size_ = strlen(val) + 1;
    val_ = new char[size_];
    for (size_t i = 0; i < size_; i++) {
      val_[i] = val[i];
    }
    val_[size_ - 1] = '\0';
  }

  ~String() {
    delete[] val_;
  }

  String* concat(String* other) {
    size_t t_size = size_ + other->size() - 1;
    char* t_val = new char[t_size];
    for (size_t i = 0; i < size_ - 1; i++) {
      t_val[i] = val_[i];
    }
    for (size_t i = 0; i < other->size() - 1; i++) {
      t_val[i + size_ - 1] = other->char_at(i); 
    }
    t_val[t_size - 1] = '\0';
    return new String(t_val);
  }

  char char_at(size_t i) {
    assert(i < size_);
    return val_[i];
  }

  size_t size() {
    return size_;
  }

  virtual size_t hash() {
    size_t v = 0;
    for (int i = 0; i < strlen(this->val_); i++) {
      v = val_[i] + (51 * v); 
    }
    return v;
  }

  virtual bool equals(Object *o) {
    if (o == nullptr) {
      return false;
    }

    String *s = dynamic_cast<String*>(o);

    if (s == nullptr) {
      return false;
    }
    return strcmp(val_, s->val_) == 0;
  }

  virtual int compare(String* other) {
    return strcmp(this->val_, other->val_);
  }
};