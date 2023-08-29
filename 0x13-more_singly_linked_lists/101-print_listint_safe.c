#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("%d", slow->n);
            slow = slow->next;
            count = 1;
            while (slow != fast) {
                printf(", %d", slow->n);
                slow = slow->next;
                count++;
            }
            printf(" -> [%d]", fast->n);
            break;
        }

        printf("%d", slow->n);
        if (fast->next) {
            printf(", ");
        }

        slow = slow->next;
        fast = fast->next;
        count++;
    }

    printf("\n");
    return count;
}
