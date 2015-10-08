#ifndef _HW_IGNORE_H_
#define _HW_IGNORE_H_

#include "common.h"
#include "file.h"

#define IGNORE_TABLE_SIZE 256

typedef struct _ignore_list_node ignore_list_node;

struct _ignore_list_node {
    char name[MAX_PATH_LENGTH];
    int base_len;
    bool is_root;
    bool is_dir;
    bool is_no_dir;
    int depth;
    ignore_list_node *next;
};

typedef struct _ignore_hash {
    ignore_list_node *path[IGNORE_TABLE_SIZE];
    ignore_list_node *ext[IGNORE_TABLE_SIZE];
    ignore_list_node *glob;
    ignore_list_node *accept;
} ignore_hash;

bool is_ignore(ignore_hash *hash, const char *path, const struct dirent *entry, int depth);
ignore_hash *merge_ignore_hash(ignore_hash *hash, const char *base, const char *path, int depth);
ignore_hash *load_ignore_hash(const char *base, const char *path, int depth);
void free_ignore_hash(ignore_hash *hash, int depth);

#endif // _HW_IGNORE_H_
