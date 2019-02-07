/*************************************************************************
 * File Name: main.c
 * Author: LanQuanshan
 * Mail: lanqsh@hotmail.com
 * Created Time: Fri Oct  5 22:24:12 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "list.h"
#include "util.h"
#include "procMusic.h"
#define MAX 256

int main(int argc, char *argv[]) {
        char *home = getenv("HOME");
        char *playList = malloc(sizeof(char)*MAX);
        memset(playList, 0x00, sizeof(char)*MAX);
        char* cachePath = malloc(sizeof(char)*MAX);
        memset(cachePath, 0x00, sizeof(char)*MAX);
        char* destPath = malloc(sizeof(char)*MAX);
        memset(destPath, 0x00, sizeof(char)*MAX);
        strcat(playList, home);
        strcat(playList, "/Library/Containers/com.netease.163music/Data/Documents/storage/Logs/music.163.log");
        strcat(cachePath, home);
        strcat(cachePath, "/Library/Containers/com.netease.163music/Data/Library/Caches/online_play_cache/");
        strcat(destPath, home);
        strcat(destPath, "/Music/网易云音乐/");
        if (-1 == access(destPath, F_OK)) {
            mkdir(destPath, 0775);
        }

    Node *root = NULL;
    init(&root);
    readPlayList(playList, root);
    procBatchFile(root, cachePath, destPath);
    destroy(root);
    free(playList);
    free(cachePath);
    free(destPath);
    return 0;
}
