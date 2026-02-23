#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"


// QUEUE FUNCTIONS
// Initialize queue to set head and tail to NULL
void InitQueue(Queue* q)
{
    if (q == NULL) return;
    q->pHead = NULL;
    q->pTail = NULL;
}

// Check if queue is empty, it return 1 if empty 0 if not
int IsQueueEmpty(const Queue* q)
{
    if (q == NULL) return 1;
    return (q->pHead == NULL);
}

// Add node to end of queue
void Enqueue(Queue* q, Node* pNode)
{
    if (q == NULL || pNode == NULL) return;

    pNode->pNext = NULL;

    if (q->pHead == NULL) {        // Queue empty
        q->pHead = pNode;
        q->pTail = pNode;
    }
    else {                          // Queue has items
        q->pTail->pNext = pNode;
        q->pTail = pNode;
    }
}

// Remove node from front and return it
Node* Dequeue(Queue* q)
{
    if (q == NULL || q->pHead == NULL) return NULL;

    Node* temp = q->pHead;
    q->pHead = q->pHead->pNext;

    if (q->pHead == NULL) {         // Queue now empty
        q->pTail = NULL;
    }

    return temp;
}

//=============================================================================
// RANDOM USER GENERATION
//=============================================================================

// Generate random 10-character username (letters and numbers)
void GenerateRandomUsername(char* username, int length)
{
    const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        username[i] = chars[rand() % 36];
    }
    username[length] = '\0';
}

// Convert faction enum to string for printing
const char* GetFactionName(Faction faction)
{
    switch (faction) {
    case FACTION_RED: return "Red";
    case FACTION_BLUE: return "Blue";
    case FACTION_GREEN: return "Green";
    default: return "Unknown";
    }
}

// Add multiple random users to queue
int AddRandomUsers(Queue* q, int numUsers)
{
    if (q == NULL || numUsers <= 0) return -1;

    // Seed random once
    srand((unsigned int)time(NULL));

    for (int i = 0; i < numUsers; i++) {
        // Create new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) return -2;  // Memory allocation failed

        // Generate random username
        GenerateRandomUsername(newNode->data.username, MAX_USERNAME_LEN);

        // Generate random level (1-60)
        newNode->data.level = (rand() % 60) + 1;

        // Generate random faction
        newNode->data.faction = (Faction)(rand() % 3);

        newNode->pNext = NULL;

        // Add to queue
        Enqueue(q, newNode);
    }

    return 0; // Success
}

// Print a single user
void PrintUser(const User* u)
{
    if (u == NULL) return;
    printf("Username: %-10s | Level: %2d | Faction: %s\n",
        u->username, u->level, GetFactionName(u->faction));
}

// HELPER FUNCTION TO FREE QUEUE (optional, not called by main.c)


void FreeQueue(Queue* q)
{
    if (q == NULL) return;
    Node* temp;
    while (!IsQueueEmpty(q)) {
        temp = Dequeue(q);
        free(temp);
    }
}