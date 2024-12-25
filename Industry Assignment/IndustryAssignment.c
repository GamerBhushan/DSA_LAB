#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// Create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the Trie
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

// Recursive function to find words matching the pattern
void searchPattern(TrieNode* root, char* pattern, int index, char* currentWord, int wordLength) {
    if (root == NULL) {
        return;
    }

    if (index == wordLength) {
        if (root->isEndOfWord) {
            printf("%s\n", currentWord);
        }
        return;
    }

    if (pattern[index] == '?') {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i] != NULL) {
                currentWord[index] = 'a' + i;
                searchPattern(root->children[i], pattern, index + 1, currentWord, wordLength);
                currentWord[index] = '?'; // Backtrack
            }
        }
    } else {
        int childIndex = pattern[index] - 'a';
        if (root->children[childIndex] != NULL) {
            currentWord[index] = pattern[index];
            searchPattern(root->children[childIndex], pattern, index + 1, currentWord, wordLength);
        }
    }
}

// Load words into the Trie from a predefined dictionary
void loadDictionary(TrieNode* root, const char* dictionary[], int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        insert(root, dictionary[i]);
    }
}

int main() {
    // Predefined dictionary
    const char* dictionary[] = {"frost", "foist", "first", "feast", "feist", "faust", "fast", "fact"};
    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

    // Create the root of the Trie
    TrieNode* root = createNode();

    // Load dictionary into Trie
    loadDictionary(root, dictionary, dictionarySize);

    // User input
    int wordLength;
    char pattern[MAX_WORD_LENGTH];

    printf("Enter the word length: ");
    scanf("%d", &wordLength);

    printf("Enter the pattern (use '?' for unknown letters): ");
    scanf("%s", pattern);

    // Validate input
    if (strlen(pattern) != wordLength) {
        printf("Error: Pattern length does not match the specified word length.\n");
        return 1;
    }

    // Find and display matching words
    printf("Matching words:\n");
    char currentWord[MAX_WORD_LENGTH];
    strcpy(currentWord, pattern);
    searchPattern(root, pattern, 0, currentWord, wordLength);

    // Free memory (optional for small programs, but good practice)
    free(root);

    return 0;
}
