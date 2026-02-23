#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_USERNAME_LEN 10
#define MIN_LEVEL 1
#define MAX_LEVEL 60
#define NUM_FACTIONS 3

// Factions 
typedef enum Faction {
    FACTION_RED,
    FACTION_BLUE,
    FACTION_GREEN
} Faction;

// User structure
typedef struct User {
    char username[MAX_USERNAME_LEN + 1];
    int level;
    Faction faction;  // Using enum, not char array
} User;

// Node structure
typedef struct Node {
    User data;           // Changed from Data to data (lowercase)
    struct Node* pNext;
} Node;

// Link type (pointer to Node)
typedef Node* link;

// Queue structure
typedef struct Queue {
    link pHead;
    link pTail;
} Queue;

// Queue functions - matching your main.c calls
void InitQueue(Queue* pQueue);
int IsQueueEmpty(const Queue* pQueue);
void Enqueue(Queue* pQueue, Node* pNode);      // Your main.c calls Enqueue
Node* Dequeue(Queue* pQueue);                   // Your main.c calls Dequeue
int AddRandomUsers(Queue* pQueue, int numUsers); // Your main.c calls AddRandomUsers
void PrintUser(const User* pUser);

// Helpers
void GenerateRandomUsername(char* username, int length);
const char* GetFactionName(Faction faction);