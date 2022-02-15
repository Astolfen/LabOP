#include "unordered_array_set.h"
#include <malloc.h>

unordered_array_set unordered_array_set_create(size_t capacity) {
    assert(capacity > 0);
    int *a = (int *) malloc(capacity * sizeof(int));
    return (unordered_array_set) {a, 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (int i = 0; i < size; ++i)
        if (linearSearch_(set.data, set.size, a[i]) == set.size) {
            set.data[set.size] = a[i];
            set.size++;
        }
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    if (unordered_array_set_isEqual(set, subset))
        return 0;
    qsort(subset.data, subset.size, sizeof(int), compare_ints);
    qsort(set.data, set.size, sizeof(int), compare_ints);
    size_t i = 0;
    size_t j = 0;
    while (i < set.size && j < subset.size) {
        if (set.data[i] == subset.data[j])
            j++;
        i++;
    }
    return j == subset.size;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size != set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t posFinNumber = unordered_array_set_in(set, value);
    if (posFinNumber != set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, posFinNumber);
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resSet = unordered_array_set_create(set1.size + set2.size);
    resSet.data = set1.data;
    resSet.size = set1.size;
    for (int i = 0; i < set2.size; ++i)
        unordered_array_set_insert(&resSet, set2.data[i]);
    return resSet;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resSet = set1;
    for (int i = 0; i < set1.size; ++i)
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            unordered_array_set_deleteElement(&resSet, set1.data[i]);
    return resSet;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set resSet = set1;
    for (int i = 0; i < set1.size; ++i)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            unordered_array_set_deleteElement(&resSet, set1.data[i]);
    return resSet;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    assert(!unordered_array_set_isEqual(set1, set2));
    unordered_array_set diff_set1 = unordered_array_set_difference(set1, set2);
    unordered_array_set diff_set2 = unordered_array_set_difference(set2, set1);
    unordered_array_set resSet = unordered_array_set_union(diff_set1, diff_set2);
    unordered_array_set_delete(diff_set1);
    unordered_array_set_delete(diff_set2);
    return resSet;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    assert(unordered_array_set_isSubset(set, universumSet));
    return unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (int i = 0; i < set.size; ++i) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}