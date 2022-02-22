#include "ordered_array_set.h"
#include <malloc.h>
#include <stdlib.h>

ordered_array_set ordered_array_set_create(size_t capacity) {
    assert(capacity > 0);
    int *a = (int *) malloc(capacity * sizeof(int));
    return (ordered_array_set) {a, 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (int i = 0; i < size; ++i)
        if (linearSearch_(set.data, size, a[i]) == size) {
            set.data[set.size] = a[i];
            set.size++;
        }
    qsort(set.data, set.size, sizeof(int), compare_ints);
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (ordered_array_set_isEqual(set, subset))
        return 0;
    size_t i = 0;
    size_t j = 0;
    while (i < set.size && j < subset.size) {
        if (set.data[i] == subset.data[j])
            j++;
        i++;
    }
    return j == subset.size;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size != set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t pos = ordered_array_set_in(set, value);
    if (pos != set->size)
        deleteByPosSaveOrder_(set->data, &set->size, pos);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resSet = ordered_array_set_create(set1.size + set2.size);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < set1.size || j < set2.size) {
        if (j == set2.size || i < set1.size && set1.data[i] < set2.data[j]) {
            resSet.data[count] = set1.data[i];
            i++;
            count++;
        } else if (set1.data[i] != set2.data[j]) {
            resSet.data[count] = set2.data[j];
            j++;
            count++;
        } else {
            i++;
        }
    }
    resSet.size = count;
    return resSet;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resSet = ordered_array_set_create(set1.size);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] == set2.data[j]) {
            resSet.data[count] = set1.data[i];
            count++;
            i++;
            j++;
        } else {
            if (set1.data[i] < set2.data[j])
                i++;
            else
                j++;
        }
    }
    resSet.size = count;
    return resSet;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set resSet = ordered_array_set_create(set1.size);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < set1.size) {
        if (j == set2.size || set1.data[i] < set2.data[j]) {
            resSet.data[count] = set1.data[i];
            i++;
            count++;
        } else if (set1.data[i] == set2.data[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    resSet.size = count;
    return resSet;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set diff1 = ordered_array_set_difference(set1, set2);
    ordered_array_set diff2 = ordered_array_set_difference(set2, set1);
    ordered_array_set resSet = ordered_array_set_union(diff1, diff2);
    ordered_array_set_delete(diff1);
    ordered_array_set_delete(diff2);
    return resSet;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    assert(ordered_array_set_isSubset(set, universumSet));
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (int i = 0; i < set.size; ++i) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}