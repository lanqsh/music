//
//  util.c
//  music
//
//  Created by Lanqsh on 2018/10/6.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#include "util.h"
#include "string.h"
#include "stdlib.h"

char *getItem(const char *str, const char *target) {
    char *pos = strstr(str, target);
    if (!pos)
        return NULL;
    while (*pos++ != ':');
    return ++pos;
}

void getOrigFileName(Node *node, char *buffer) {
    char *index = buffer;
    char *playid = getItem(node->data, "playid");
    while (*playid != '_')
        *index++ = *playid++;
    memcpy(index, "-_-_", 4);
    index += 4;
    
    char *bitrate = getItem(node->data, "bitrate");
    memcpy(index, bitrate - 1, 3);
    index += 3;
    memcpy(index, "-_-_", 4);
    index += 4;
    
    char *md5 = getItem(node->data, "md5");
    while (*md5 != '"')
        *index++ = *md5++;
    memcpy(index, ".uc!", 4);
}

void getStoreFileName(Node *node, char *buffer) {
    char *index = buffer;
    char *artistName = getItem(node->data, "artistName");
    while (*artistName != '"') {
        if (*artistName == '/')
            *index = ':';
        else
            *index = *artistName;
        ++index;
        ++artistName;
    }
    memcpy(index, " - ", 3);
    index += 3;

    char *songName = getItem(node->data, "songName");
    while (*songName != '"')
        *index++ = *songName++;
    memcpy(index, ".mp3", 4);
}
