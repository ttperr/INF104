#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "link-types.h"
#include "linked-list.h"

extern int number_of_students;

/********************   read_file_content   ********************
* read file and extract information to store it in array
**************************************************************/

void read_file_content(Student_t *array, FILE *file)
{

  /* TODO: implement this function */
  /* printf("read_file_content: Not Implemented Yet\n");
  exit(-1);
  */
  int ret_lec;
  int i = 0;
  while (1)
  {
    ret_lec = fscanf(file, "%s %s %d", array[i].lastname, array[i].firstname, &array[i].group);
    if (ret_lec != EOF || ret_lec == 3)
    {
      number_of_students++;
      i++;
    }
    else
      break;
  }
}

/********************    new_link   *******************
* Create a new link of type Link_t: the field next is initialized to NULL
* Returns the adress of the new link.
********************************************************/
Link_t *new_link(Student_t student)
{
  Link_t *link;

  /* TODO: implement this function */
  /*printf("new_link: Not Implemented Yet\n");
  exit(-1);
  */

  link = (Link_t *)malloc(sizeof(Link_t));
  link->student = student;
  (*link).next = NULL;
  return link;
}

/********************    chain   *******************
* Add a new link (new_link) at the beginning of an existing
* linked list (beginning).
* Returns the address of the first element of the list.
********************************************************/
Link_t *chain(Link_t *beginning, Link_t *new_link)
{
  /* TODO: implement this function */
  /* printf("chain: Not Implemented Yet\n");
  exit(-1);
  */

  new_link->next = beginning;
  return new_link;
}

/********************   display_linked_list   *******************
* Display (using printf) the information contained in the
* linked list.
********************************************************/
void display_linked_list(Link_t *list)
{

  /* TODO: implement this function */
  /*printf("display_linked_list: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *currentElement = list;
  int i = 1;
  while (currentElement != NULL)
  {
    printf("\nStudent n°%d : %s %s is in group %d\n", i, currentElement->student.firstname,
           currentElement->student.lastname, currentElement->student.group);
    i++;
    currentElement = currentElement->next;
  }
}

/********************   search   *******************
* Search for a link corresponding to a student last
* name
* beginning: first link of the list used for searching
* name_to_search: last name of the student to search
* returns the firts link for which the name equals
* name_to_search
********************************************************/
Link_t *search(Link_t *beginning, char *name_to_search)
{
  Link_t *found_link;

  /* TODO: implement this function */
  /*printf("search: Not Implemented Yet\n");
  exit(-1);
  */

  Link_t *currentElement = beginning;
  while (currentElement->next != NULL)
  {
    if (!strcmp(currentElement->student.lastname, name_to_search))
    {
      return currentElement;
    }
    else
    {
      currentElement = currentElement->next;
    }
  }
  return NULL;
}

/********************   insert   *******************
* Insert a link in a linked list
* beginning: first link of the original list
* new_link: link to insert
* returns the firts link of the list after insertion
********************************************************/
Link_t *insert(Link_t *beginning, Link_t *new_link)
{
  /* TODO: implement this function */
  /*printf("insert: Not Implemented Yet\n");
  exit(-1);
  */
  if (beginning == NULL)
  {
    return chain(beginning, new_link);
  }
  if (strcmp(beginning->student.lastname, new_link->student.lastname) >= 0)
  {
    new_link->next = beginning->next;
    return chain(beginning, new_link);
  }
  return chain(insert(beginning->next, new_link), beginning);
}

/********************   sort   *******************
* Sort the content of the linked list.
********************************************************/
Link_t *sort(Link_t *beginning)
{
  /* TODO: implement this function */
  /*printf("sort: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *sorted_list = NULL;
  Link_t *link = beginning;
  while (link != NULL)
  {
    Link_t *next = link->next;
    sorted_list = insert(sorted_list, link);
    link = next;
  }
  return sorted_list;
}

/********************   free_list   *******************
* Free the memory used by the linked list.
********************************************************/
void free_list(Link_t *list)
{

  /* TODO: implement this function */
  /*printf("free_list: Not Implemented Yet\n");
  exit(-1);
  */
  Link_t *link = list;
  while (link != NULL)
  {
    Link_t *next = link->next;
    free(link);
    link = next;
  }
}
