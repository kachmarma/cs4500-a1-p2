#pragma once

#include "object.h"
#include "map.h"
#include "string.h"

class TestMap {
  public:
    bool it_returns_the_value_for_a_key() {
      Map* map = new Map();
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      map->put(foo_key, foo);
      return map->get(foo_key)->equals(foo);
    }

    bool it_contains_the_key() {
      Map* map = new Map();
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      map->put(foo_key, foo);
      return map->contains_key(foo_key) && !map->contains_key(foo);
    }

    bool it_equals_another_empty_map() {
      Map* map1 = new Map();
      Map* map2 = new Map();
      return map1->equals(map2);
    }

    bool it_equals_another_map() {
      Map* map1 = new Map();
      Map* map2 = new Map();
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      map1->put(foo_key, foo);
      map2->put(foo_key, foo);
      return map1->equals(map2);
    }

    bool it_computes_the_same_empty_hashcode() {
      Map* map1 = new Map();
      Map* map2 = new Map();
      return map1->hash() == map2->hash();
    }

    bool it_computes_the_same_hashcode() {
      Map* map1 = new Map();
      Map* map2 = new Map();
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      map1->put(foo_key, foo);
      map2->put(foo_key, foo);
      return map1->hash() == map2->hash();
    }

    bool it_computes_keyset() {
      Map* map = new Map();
      String* foo_key = new String("fooKey");
      String* bar_key = new String("barKey");
      String* foo = new String("foo");
      String* bar = new String("bar");
      map->put(foo_key, foo);
      map->put(bar_key, bar);
      Object** keys = map->key_set();

      bool containsFoo = false;
      bool containsBar = false;
      for (int i = 0; i < map->size(); i++) {
        if (keys[i]->equals(foo_key)) {
          containsFoo = true;
        }
        if (keys[i]->equals(bar_key)) {
          containsBar = true;
        }
      }

      return containsFoo && containsBar && map->size() == 2;
    }

    bool it_removes_elements() {
      Map* map = new Map();
      String* foo_key = new String("fooKey");
      String* bar_key = new String("barKey");
      String* foo = new String("foo");
      String* bar = new String("bar");
      map->put(foo_key, foo);
      map->put(bar_key, bar);

      if (map->size() != 2) return false;

      Object* foo_removed = map->remove(foo_key);
      if (map->size() != 1) return false;
      if (!foo->equals(foo_removed)) return false;

      Object* bar_removed = map->remove(bar_key);
      if (map->size() != 0) return false;
      return bar->equals(bar_removed);
    }

    bool it_computes_size() {
      Map* map = new Map();
      if (map->size() != 0) return false;
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      map->put(foo_key, foo);
      return map->size() == 1;
    }

    bool it_updates_values() {
      Map* map = new Map();
      String* foo_key = new String("fooKey");
      String* foo = new String("foo");
      String* bar = new String("bar");

      map->put(foo_key, foo);
      if (!map->get(foo_key)->equals(foo)) return false;

      map->put(foo_key, bar);
      return map->get(foo_key)->equals(bar);
    }
};