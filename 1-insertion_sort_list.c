#include "sort.h"

/**
 * first - swap with the first node of the list
 * @list: the list of nodes
 * @temp: pointer on the list
 * @temp3: pointer on the list
 *
 * Return: void
 */
void first(listint_t **list, listint_t *temp, listint_t *temp3)
{
	temp->prev->next = temp->next;
	temp->next->prev = temp3;
	temp->prev->prev = temp;
	temp->next = temp3;
	temp->prev = NULL;
	*list = temp;
	print_list(*list);
}

/**
* mid - swap nodes in the midle of the list
* @list: the list of nodes
* @temp: pointer on the list
* @temp3: pointer on the list
*
* Return: void
*/
void mid(listint_t **list, listint_t *temp, listint_t *temp3)
{
	temp3->prev->next = temp;
	temp->next->prev = temp3;
	temp->prev = temp3->prev;
	temp3->next = temp->next;
	temp3->prev = temp;
	temp->next = temp3;
	print_list(*list);
}

/**
* end - swap with the last node of the list
* @list: the list of nodes
* @temp: pointer on the list
* @temp3: pointer on the list
*
* Return: void
*/
void end(listint_t **list, listint_t *temp, listint_t *temp3)
{
	temp3->prev->next = temp3->next;
	temp3->next = NULL;
	temp->next = temp->prev;
	temp->prev = temp3->prev;
	temp3->prev = temp;
	print_list(*list);
}

/**
* insertion_sort_list - function that sorts the nodes
* @list: the list of nodes
*
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2, *temp3;
	
	if (!list)
		return;
	temp2 = (*list)->next;
	while (temp2 != NULL)
	{
		temp = temp2;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				temp3 = temp->prev;
				if (temp->prev->prev == NULL)
					first(list, temp, temp3);
				else if (temp->prev->prev != NULL && temp->next != NULL)
					mid(list, temp, temp3);
				else
					end(list, temp, temp3);
			}
			else
				temp = temp->prev;
		}
		temp2 = temp2->next;
	}
}
