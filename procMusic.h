//
//  procMusic.h
//  music
//
//  Created by Lanqsh on 2018/10/6.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#ifndef procMusic_h
#define procMusic_h

#include <stdio.h>
#include "list.h"

void readPlayList(const char *str, Node *root);
void convertMusic(char *musicOrigName, char *musicStoreName);
void procBatchFile(Node *root, const char *cachePath, const char *destPath);

#endif /* procMusic_h */
