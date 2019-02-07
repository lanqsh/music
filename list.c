//
//  list.c
//  music
//
//  Created by Lanqsh on 2018/10/5.
//  Copyright © 2018年 Lanqsh. All rights reserved.
//

#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void init(Node **root){
    assert(!*root);
    *root = (Node *)malloc(sizeof(Node));
    (*root)->data = NULL;
    (*root)->next = NULL;
}
void insert(Node *root, const char *str) {
    Node *pCur = root;
    while (pCur->next)
        pCur = pCur->next;
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = str;
    tmp->next = NULL;
    pCur->next = tmp;
}
void traversal(Node *root) {
    assert(root);
    Node *pCur = root;
    while (pCur->next) {
        printf("node data:%s\n", pCur->data);
        pCur = pCur->next;
    }
}
void destroy(Node *root) {
    assert(root);
    Node *pCur = root->next;
    Node *pPre = root;
    if (pCur) {
        free(pPre);
        pPre = pCur;
        pCur = pCur->next;
    }
    free(pPre);
}
