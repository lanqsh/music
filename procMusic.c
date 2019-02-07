//
//  procMusic.c
//  music
//
//  Created by Lanqsh on 2018/10/6.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#include "procMusic.h"
#include "list.h"
#include <assert.h>
#include "util.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void readPlayList(const char *str, Node *root) {
    FILE *playList = fopen(str, "r");
    if (!playList) {
        perror("read playList error,list no exist");
        return;
    }
    int size = 1024 * 100;
    char *buffer = (char *)malloc(size);
    memset(buffer, 0x00, size);
    while (!feof(playList)) {
        fgets(buffer, size, playList);
        
        //find player._$load, insert into list
        char *start = strstr(buffer, "player._$load");
        char *md5 = strstr(buffer, "md5");
        if (!start || !md5)
            continue;
        start += 17;
        char *end = strchr(start, '}');
        long jsonSize = end - start + 1;
        char *jsonUnit = (char *)malloc(jsonSize);
        memcpy(jsonUnit, start, jsonSize);
        insert(root, jsonUnit);
    }
}

void convertMusic(char *musicOrigName, char *musicStoreName) {
    FILE *inFile = fopen(musicOrigName, "r");
    if (!inFile) {
        perror("fopen inFile error");
        return;
    }
    FILE *outFile = fopen(musicStoreName, "w");
    if (!outFile) {
        perror("fopen outFile error");
        return;
    }
    
    fseek(inFile, 0L, SEEK_END);
    long size = ftell(inFile);
    rewind(inFile);
    
    char *buffer = (char *)malloc(size);
    if (!buffer)
        printf("buffer malloc fail\n");
    memset(buffer, 0x00, size);
    fread(buffer, 1, size, inFile);
    for (int i = 0; i < size; ++i) {
        buffer[i] ^= 0xa3;
    }
    fwrite(buffer, 1, size, outFile);
    
    fclose(inFile);
    fclose(outFile);
}

void procBatchFile(Node *root,const char *cachePath, const char *destPath) {
    static int fileCount = 0;
    assert(root);
    Node *pCur = root->next;
    while (pCur) {
        char *p1 = (char *)cachePath;
        char musicOrigName[256] = {0};
        int i = 0;
        while (*p1)
            musicOrigName[i++] = *p1++;
        getOrigFileName(pCur,musicOrigName+i);
        if (*(musicOrigName+i) == 0)
            continue;
        
        char *p2 = (char *)destPath;
        char musicStoreName[256] = {0};
        int j = 0;
        while (*p2)
            musicStoreName[j++] = *p2++;
        getStoreFileName(pCur, musicStoreName+j);
        
        if (access(musicStoreName, F_OK)) {
            convertMusic(musicOrigName, musicStoreName);
            ++fileCount;
            printf("%03d.%s convert complete\n", fileCount, musicStoreName+j);
        }
        pCur = pCur->next;
    }
}
