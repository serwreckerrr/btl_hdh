#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
        if (q == NULL)
                return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: put a new process to queue [q] */
        /* Defensive checks and correct bound test */
        if (q == NULL || proc == NULL)
                return;

        if (q->size >= MAX_QUEUE_SIZE) {
                /* Queue full — print diagnostic and drop the enqueue */
                fprintf(stderr, "enqueue: queue full (MAX_QUEUE_SIZE=%d)\n", MAX_QUEUE_SIZE);
                return;
        }

        q->proc[q->size] = proc;
        q->size++;

        // if(q->size <= MAX_QUEUE_SIZE){
        //         q->proc[q->size] = proc;
        //         q->size++;
        // }      
}

struct pcb_t *dequeue(struct queue_t *q)
{
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */  
        if(q->size == 0 || q == NULL){
                return NULL;
        }
        struct pcb_t * proc = q->proc[0];
        for(int i = 0; i < q->size-1; i++){
                q->proc[i] = q->proc[i+1];
        }
        q->size--;
        q->proc[q->size] = NULL; // Clean up the last slot
        return proc;
}

struct pcb_t *purgequeue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: remove a specific item from queue
         * */
        if(q->size == 0 || q == NULL || proc == NULL){
                return NULL;
        }
        int idx = -1;
        for (int i = 0; i < q->size; i++) {
                if (q->proc[i] == proc) {
                idx = i;
                break;
                }
        }

        if (idx == -1)
                return NULL;

        /* remove the entry and shift */
        struct pcb_t *ret = q->proc[idx];
        for (int i = idx; i < q->size - 1; i++) {
                q->proc[i] = q->proc[i + 1];
        }
        q->size--;
        q->proc[q->size] = NULL;
        return ret;
        //return NULL;
}