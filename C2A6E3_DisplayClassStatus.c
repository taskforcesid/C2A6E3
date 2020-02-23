//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 23 FEB 2020
// C2A6E3_DisplayClassStatus.c
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// Implements Compare function used by qsort and bsearch
// Implements function to sort students using qsort
// Implements a function to search through two string arrays
// using bsearch
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int Compare(const void *elemA, const void *elemB)
{
    return(strcmp(*(char **)elemA, *(char **)elemB));
}

void SortStudents(const char *studentList[], size_t studentCount)
{
    qsort(studentList, studentCount, sizeof(studentList[0]), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
    const char *attendees[], size_t attendeeCount)
{
    //Display not present 
    void  *searchString = NULL;
    puts("Not present:");
    for (int arrayIndex = 0; arrayIndex < (int)registrantCount; arrayIndex++)
    {
        //iterate through the registrant array
        //search for registrant in the attendees
        searchString = bsearch(&(registrants[arrayIndex]), attendees,
            attendeeCount, sizeof(attendees[0]), Compare);
        //registrant not found, display output
        if (!searchString)
        {
            printf("    %s\n", registrants[arrayIndex]);
        }
    }

    //Display not registed
    searchString = NULL;
    puts("Not registered:");
    for (int arrayIndex = 0; arrayIndex < (int)attendeeCount; arrayIndex++)
    {
        //iterate through the attendees array
        //search for attendee in the registrants
        searchString = bsearch(&(attendees[arrayIndex]), registrants,
            registrantCount, sizeof(registrants[0]), Compare);
        //attendee not found, display to output
        if (!searchString)
        {
            printf("    %s\n", attendees[arrayIndex]);
        }
    }
}
