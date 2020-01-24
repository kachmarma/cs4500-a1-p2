# cs4500-a1-p2

CS4500 Assignment 1 Part 2

## CwC Map API

We designed the CwC Map API based of the the minimal Java specifications for a Map interface. Furthermore, we narrowed down the functionallity to what we deemed was completely necessary of a map to minimize the amount of total interface methods we defined in the class.

The methods we defined were:

```C
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
```

Furthermore, we decided to not keep our implementation too narrow (for example just using strings as keys and some other tightly-coupled data types for values) as well by using Objects as keys and values. We believe this will yeild the best result when it comes time to implement this interface because it allows for any type of data to be used with our Map.
