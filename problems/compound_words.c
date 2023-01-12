#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define WORD_LEN 16
#define NUM_BITS 17

char* read_line(int size) {
    char* str;
    str = malloc(size);
    if (str == NULL) {
        fprintf(stderr, "fatal: malloc error\n");
        exit(1);
    }

    int ch;
    int len = 0;
    while ((ch = getchar()) != EOF && (ch != '\n')) {
        str[len++] = (char) ch;
        if (len == size) {
            size *= 2;
            str = realloc(str, size);
            if (str == NULL) {
                fprintf(stderr, "fatal: malloc error\n");
                exit(1);
            }
        }
    }
    str[len] = '\0';
    return str;
}

#define hash_size(n) ((unsigned long) 1 << (n))
#define hash_mask(n) (hash_size(n) - 1)

unsigned long hasher(const char* key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;
    for (hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 16);
    return hash & hash_mask(bits);
}

typedef struct WordNode {
    char** word;
    struct WordNode* next;
} WordNode;

int in_table(WordNode* table[], char* key, unsigned key_len) {
    unsigned word_code;
    WordNode* word_ptr;
    word_code = hasher(key, key_len, NUM_BITS);
    word_ptr = table[word_code];
    while (word_ptr) {
        if ((strlen(*(word_ptr->word)) == key_len) && (strncmp(*(word_ptr->word), key, key_len) == 0)) {
            return 1;
        }
        word_ptr = word_ptr->next;
    }
    return 0;
}

void find_compound_words(char* words[], WordNode* table[], int num_words) {
    int i, j;
    unsigned len;
    for (i = 0; i < num_words; i++) {
        len = strlen(words[i]);
        for (j = 1; j < len; j++) {
            if (in_table(table, words[i], j) && in_table(table, &words[i][j], len - j)) {
                printf("%s\n", words[i]);
                break;
            }
        }
    }
}

int main(void) {
    static char* words[1 << NUM_BITS] = {NULL};
    static WordNode* table[1 << NUM_BITS] = {NULL};

    int total = 0;
    WordNode* word_ptr;
    unsigned length, word_code;

    printf("Enter number of words to read:\n");
    unsigned num_words = (unsigned) strtol(read_line(NUM_BITS), NULL, 10);

    printf("Enter the words:\n");
    int i;
    for (i = 0; i < num_words; i++) {
        char* word = read_line(WORD_LEN);
        words[total] = word;
        word_ptr = malloc(sizeof(WordNode));
        if (word_ptr == NULL) {
            fprintf(stderr, "fatal: malloc error\n");
            exit(1);
        }
        length = strlen(word);
        word_code = hasher(word, length, NUM_BITS);
        word_ptr->word = &words[total];
        word_ptr->next = table[word_code];
        table[word_code] = word_ptr;
        total++;
    }

    printf("Compound words:\n");
    find_compound_words(words, table, total);
    return 0;
}
