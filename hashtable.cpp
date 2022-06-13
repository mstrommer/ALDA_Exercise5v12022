//
//  hashtable.cpp
//  ALDA_Exercise5v12022
//
//  Created by Michael Strommer on 03.06.22.
//

#include "hashtable.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

hashtable * ht_init(int capacity) {
    int i;
    hashtable * ht = (hashtable *)malloc(sizeof(hashtable));
    ht->capacity = capacity;
    ht->buckets = (list **)malloc(capacity * sizeof(list *));
    for (i = 0; i < capacity; i++) {
        ht->buckets[i] = l_init();
    }
    return ht;
}

int ht_hash(hashtable * ht, char * key) {
    /* TODO: implement a suitable hash function here */
    return 0;
}

void ht_put(hashtable * ht, char * key, char * value) {
    /* TODO: implement insertion into hash table */
}

char * ht_get(hashtable * ht, char * key) {
    /* TODO: implement retrieval of data */
    return NULL;
}

void ht_print_bucket_sizes(hashtable * ht) {
    /* TODO: implement printing of bucket sizes */
}

int readFile(hashtable * ht, const char * filename){
    char line[100]; // keeps one line of the file
    char icao_code[5];
    char station_name[100];
    FILE * fp;
    // try to open the file; in case of an error exit the program
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file %s!\n", filename);
        return 1;
    }
    // read all weather stations from file and add them to the
    // hash table
    while (fgets(line, 100, fp)) {
        // read one line and skip empty and comment lines
        if (line[0] == '#') continue;
        if (isspace(line[0])) continue;
        // delete the newline character
        line[strcspn(line, "\r\n")] = 0;
        // take the first 4 characters as key value
        strncpy(icao_code, line, 4);
        icao_code[4] = '\0';
        // take the rest as value
        strcpy(station_name, strchr(line, ';')+1);
        // add the data to the hash table
        ht_put(ht, icao_code, station_name);
        //printf("added key/value pair: %s / %s\n", icao_code, station_name);
    }
    // close the file
    fclose(fp);
    return 0;
}
