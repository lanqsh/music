//
//  util.h
//  music
//
//  Created by Lanqsh on 2018/10/6.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#ifndef util_h
#define util_h

#include <stdio.h>
#include "list.h"

char *getItem(const char *str, const char *target);
void getOrigFileName(Node *node, char *buffer);
void getStoreFileName(Node *node, char *buffer);

#endif /* util_h */
