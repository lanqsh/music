//
//  list.h
//  music
//
//  Created by Lanqsh on 2018/10/5.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
typedef struct Node {
    const char *data;
    struct Node *next;
}Node;

void init(Node **root);
void insert(Node *root, const char *str);
void traversal(Node *root);
void destroy(Node *root);
#endif /* list_h */
