#include "definition.h"
#include "minic.tab.h"

struct AST * makeNode(int num) {
    struct AST * node = (struct AST *)malloc(sizeof(struct AST));
    node->parent = NULL;
    node->child = (struct AST **)malloc(num * sizeof(struct AST *));
    node->ntno = 0;
    node->procno = 0;
    node->multiplicity = 0;
    node->contain_expr = 0;
    return node;
}

struct symbolTable * makeST() {
    struct symbolTable * st = (struct symbolTable *)malloc(sizeof(struct symbolTable));
    st->item = (struct symbolTableItem **)malloc(30 * sizeof(struct symbolTableItem *));
    st->count = 0;
    return st;
}

struct symbolTableItem * makeSTitem() {
    struct symbolTableItem * item = (struct symbolTableItem *)malloc(sizeof(struct symbolTableItem));
    item->pos = 0;
    item->offset = -1;
    return item;
}

void st_add(char *n, int p, int o, int funcno) {
    ALL[funcno]->st->item[ALL[funcno]->st->count] = makeSTitem();
    strcpy(ALL[funcno]->st->item[ALL[funcno]->st->count]->name, n);
    ALL[funcno]->st->item[ALL[funcno]->st->count]->pos = p;
    ALL[funcno]->st->item[ALL[funcno]->st->count]->offset = o;
    ALL[funcno]->st->count++;
}

struct messenger * lookup(char *n, int funcno) {
    struct messenger * m = (struct messenger *)malloc(sizeof(struct messenger));
    char a[10];
    char b[10];
    for (int i = 0; i < ALL[funcno]->st->count; i++) {
        if (!strcmp(ALL[funcno]->st->item[i]->name, n)) {
            if (ALL[funcno]->st->item[i]->pos == 1) {
                strcpy(a, "$a");
                sprintf(b, "%d", ALL[funcno]->st->item[i]->offset);
                m->type = 1;
            } else if (ALL[funcno]->st->item[i]->pos == 2) {
                sprintf(a, "%d", 4 * ALL[funcno]->st->item[i]->offset);
                strcpy(b, "($t9)");
                m->type = 2;
            } else if (ALL[funcno]->st->item[i]->pos == 3) {
                strcpy(a, "$s");
                sprintf(b, "%d", ALL[funcno]->st->item[i]->offset);
                m->type = 1;
            } else if (ALL[funcno]->st->item[i]->pos == 4) {
                sprintf(a, "%d", 4 * ALL[funcno]->st->item[i]->offset);
                strcpy(b, "($sp)");
                m->type = 2;
            }
            strcat(a, b);
            strcpy(m->pos, a);
            return m;
        }
    }
    m->type = 0;
    strcpy(a, "NULL");
    strcpy(m->pos, a);
    return m;
}

int lookup_global(char *n) {
    for (int i = 0; i < gcount; i++) {
        if (strcmp(gVar[i]->name, n) == 0)
            return 1;
    }
    return 0;
}

int checkdup(char *n, int funcno) {
    int t = 0;
    for (int i = 0; i < ALL[funcno]->st->count; i++)
        if (!strcmp(ALL[funcno]->st->item[i]->name, n))
            t++;
    return t;
}

struct stack * init_stack() {
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->len = 0;
    return s;
}

void push(struct stack *s, int item) {
    s->data[s->len++] = item;
}

void pop(struct stack *s) {
    s->len--;
}

int top(struct stack *s) {
    return s->data[s->len - 1];
}

int empty(struct stack *s) {
    if (s->len == 0)
        return 1;
    else
        return 0;
}

void clear(struct stack *s) {
    s->len = 0;
}
