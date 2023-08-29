#include "lists.h"
#include <unistd.h>

void print_number(int num)
{
    char buffer[20];
    int index = 0;

    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }

    while (num > 0) {
        buffer[index++] = (num % 10) + '0';
        num /= 10;
    }

    for (int i = index - 1; i >= 0; i--) {
        putchar(buffer[i]);
    }
}

void print_text(const char *text)
{
    for (const char *ptr = text; *ptr != '\0'; ptr++) {
        putchar(*ptr);
    }
}

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            print_number(slow->n);
            slow = slow->next;
            count = 1;
            while (slow != fast) {
                putchar(','); putchar(' ');
                print_number(slow->n);
                slow = slow->next;
                count++;
            }
            print_text(" -> ["); print_number(fast->n); putchar(']');
            break;
        }

        print_number(slow->n);
        if (fast->next) {
            putchar(','); putchar(' ');
        }

        slow = slow->next;
        fast = fast->next;
        count++;
    }

    print_text("\n");
    return count;
}