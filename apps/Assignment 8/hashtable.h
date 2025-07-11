// hashtable.h
// Hash table class — Assignment 08 (Making a Hash of It)

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <functional>
#include <cstddef>

/* ───── compile-time constants (from slides) ───── */
const std::size_t CAPACITY = 11;        // small so collisions happen
const int  NEVER_USED      = -1;
const int  PREVIOUSLY_USED = -2;

/* ───── record structure (slide style) ───── */
struct RecordType {
    int         key   = NEVER_USED;     // key ≥ 0 only when OCCUPIED
    std::string value = "";
};

/* ───── hash-table class ───── */
class HashTable {
public:
    HashTable();                                      // constructor

    /* core operations */
    void insert(const RecordType& entry);
    void remove(int key);
    void find(int key, bool& found, RecordType& result,
              std::function<void(int,bool&,std::size_t&)> hashingFunction =
                  std::bind(&HashTable::findIndex, this,
                            std::placeholders::_1,
                            std::placeholders::_2,
                            std::placeholders::_3));

    /* optional: print entire table for debugging */
    void printTable() const;

private:
    RecordType   data[CAPACITY];
    std::size_t  used;                                // how many ACTIVE slots

    /* helper predicates (slides) */
    bool   neverUsed (std::size_t index) const { return data[index].key == NEVER_USED; }
    bool   isVacant  (std::size_t index) const { return data[index].key < 0; }

    /* linear probe helpers (slides) */
    std::size_t hash(int key)               const { return key % CAPACITY; }
    std::size_t nextIndex(std::size_t idx)  const { return (idx + 1) % CAPACITY; }

    /* probing functions — same signature so they can be passed to find() */
    void findIndex     (int key, bool& found, std::size_t& index); // linear (default)
    void quadraticProbe(int key, bool& found, std::size_t& index); // i² offsets
    void secondHash    (int key, bool& found, std::size_t& index); // h2(x)=7-(x mod 7)
};

#endif // HASHTABLE_H

