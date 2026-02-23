#include "queue.h"

int main(int argc, char* argv[])
{
    Queue userQueue;      // Queue for users
    Node* pDequeuedNode;  // Temp pointer for dequeued nodes
    int numUsers = 0;     // Number of users from command line
    int result;           // Result from AddRandomUsers
    int userCount = 0;    // Counter for dequeued users

    // Program header
    printf("========================================================\n");
    printf("FIFO QUEUE IMPLEMENTATION WITH USER STRUCT\n");
    printf("PROG72370 - Data Structures & Algorithms\n");
    printf("========================================================\n\n");

    // Check command line args
    if (argc != 2) {
        printf("Usage: %s <number_of_users>\n", argv[0]);
        return -1;
    }

    numUsers = atoi(argv[1]);
    if (numUsers <= 0) {
        printf("ERROR: Number of users must be positive\n");
        return -2;
    }

    printf("Creating %d users...\n\n", numUsers);

    // Step 1: Initialize queue
    printf("Step 1: Initializing queue...\n");
    InitQueue(&userQueue);
    if (IsQueueEmpty(&userQueue))
        printf("Queue initialized and empty.\n\n");
    else
        printf("WARNING: Queue may not be empty!\n\n");

    // Step 2: Add random users
    printf("Step 2: Adding %d random users...\n", numUsers);
    result = AddRandomUsers(&userQueue, numUsers);
    if (result != 0) {
        printf("ERROR: Failed to add users. Code: %d\n", result);

        // Clean up any nodes added before error
        while (!IsQueueEmpty(&userQueue)) {
            pDequeuedNode = Dequeue(&userQueue);
            if (pDequeuedNode) free(pDequeuedNode);
        }
        return -3;
    }
    printf("Added %d users successfully.\n\n", numUsers);

    // Step 3: Dequeue and print all users
    printf("Step 3: Dequeuing and printing users:\n");
    printf("--------------------------------------------------------\n");

    while (!IsQueueEmpty(&userQueue)) {
        pDequeuedNode = Dequeue(&userQueue);
        if (pDequeuedNode) {
            userCount++;
            printf("%2d: ", userCount);
            PrintUser(&(pDequeuedNode->data)); // print user
            free(pDequeuedNode);                // free memory
        }
    }

    printf("--------------------------------------------------------\n");
    printf("Total users dequeued and printed: %d\n", userCount);

    // Verify queue is empty
    if (IsQueueEmpty(&userQueue))
        printf("Queue is now empty. All done!\n");
    else
        printf("WARNING: Queue should be empty but isn't.\n");

    printf("\nProgram completed successfully.\n");
    return 0;
}