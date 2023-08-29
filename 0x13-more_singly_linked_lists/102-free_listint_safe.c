#include <stdlib.h>
#include "lists.h"

size_t free_listint_safe(listint_t **h)
{
    listint_t *slow = *h, *fast = *h, *prev = NULL;
    size_t count = 0;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            /* Break the loop */
            prev->next = NULL;
            slow = *h;
            while (slow) {
                listint_t *tmp; 
		tmp = slow;
                slow = slow->next;
                free(tmp);
                count++;
                if (tmp == prev) {
                    break;
                }
            }
            break;
        }

	listint_t *tmp;
        tmp = slow;
        slow = slow->next;
        free(tmp);
        count++;
    }

    *h = NULL;
    return count;
}
