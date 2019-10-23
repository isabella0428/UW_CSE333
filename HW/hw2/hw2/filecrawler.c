/*
 * Copyright 2012 Steven Gribble
 *
 *  This file is part of the UW CSE 333 course project sequence
 *  (333proj).
 *
 *  333proj is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  333proj is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333proj.  If not, see <http://www.gnu.org/licenses/>.
 */

// feature test macro for readdir_r (c.f., Linux Programming Interface p. 63)
#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "libhw1/CSE333.h"
#include "filecrawler.h"
#include "fileparser.h"

// When our crawler finds a directory, it invokes this function to recursively
// descend into the directory to look for files and subdirectories.
static void HandleDir(char *dirpath, DIR *d, DocTable *doctable,
                      MemIndex *index);

// When our crawler finds a file, it invokes this function to read it in,
// parse it, and inject it into the MemIndex. (The MemIndex is the in-memory
// inverted index.)
static void HandleFile(char *fpath, DocTable *doctable, MemIndex *index);


int CrawlFileTree(char *rootdir, DocTable *doctable, MemIndex *index) {
  struct stat rootstat;
  int result;
  DIR *rd;

  // Verify that rootdir is a directory.
  result = stat((char *) rootdir, &rootstat);
  if (result == -1) {
    // We got some kind of error stat'ing the file. Give up
    // and return an error.
    return 0;
  }
  if (!S_ISDIR(rootstat.st_mode)) {
    // It isn't a directory, so give up.
    return 0;
  }

  // Try to open the directory using opendir().  If try but fail, (e.g., we
  // don't have permissions on the directory), return 0. ("man 3 opendir")
  rd = opendir(rootdir);
  if (rd == NULL) {
    return 0;
  }

  // Since we're able to open the directory, go ahead and allocate space for
  // the doctable and memindex.
  *doctable = AllocateDocTable();
  Verify333(*doctable != NULL);
  *index = AllocateMemIndex();
  Verify333(*index != NULL);

  // Begin the recursive handling of the directory.
  HandleDir(rootdir, rd, doctable, index);

  // All done, free up.
  result = closedir(rd);
  Verify333(result == 0);
  return 1;
}


static void HandleDir(char *dirpath, DIR *d, DocTable *doctable,
                     MemIndex *index) {
  // Loop through the directory.
  while (1) {
    char *newfile;
    int res, charsize;
    struct stat nextstat;
    struct dirent *dirent = NULL, entry;

    // STEP 1.
    // Use the "readdir_r()" system call to read the next directory entry. (man
    // 3 readdir_r).  If we hit the end of the directory, return back
    // out of this function.


    // STEP 2.
    // If the directory entry is named "." or "..", ignore it.  (Use the C
    // "continue;" expression to begin the next iteration of the while()
    // loop.) You can find out the name of the directory entry through the
    // "d_name" field of the struct dirent returned by readdir(), and you can
    // use strcmp() to compare it to "." or ".."


    // We need to append the name of the file to the name of the directory
    // we're in to get the full filename. So, we'll malloc space for:
    //
    //     dirpath + "/" + dirent->d_name + '\0'
    charsize = strlen(dirpath) + 1 + strlen(dirent->d_name) + 1;
    newfile = (char *) malloc(charsize);
    Verify333(newfile != NULL);
    if (dirpath[strlen(dirpath)-1] == '/') {
      // no need to add an additional '/'
      snprintf(newfile, charsize, "%s%s", dirpath, dirent->d_name);
    } else {
      // we do need to add an additional '/'
      snprintf(newfile, charsize, "%s/%s", dirpath, dirent->d_name);
    }

    // Use the "stat()" system call to ask the operating system
    // to give us information about the file named by the
    // directory entry.   ("man stat")
    res = stat(newfile, &nextstat);
    if (res == 0) {
      // STEP 3.
      // Test to see if the file is a "regular file" using the S_ISREG() macro
      // described in the stat man page. If so, process the file by invoking
      // the HandleFile() private helper function.
      //
      // On the other hand, if the file turns out to be a directory (which you
      // can find out using the S_ISDIR() macro described on the same page,
      // then you need to open the directory using opendir()  (man 3 opendir)
      // and recursively invoke HandleDir to handle it. Be sure to call the
      // "closedir()" system call when the recursive HandleDir() returns to
      // close the opened directory.

    }

    // Done with this file.  Fall back up to the next
    // iteration of the while() loop.
    free(newfile);
  }
}

static void HandleFile(char *fpath, DocTable *doctable, MemIndex *index) {
  HashTable tab = NULL;
  DocID_t docID;
  HTIter it;

  // STEP 4.
  // Invoke the BuildWordHT() function in fileparser.h/c to
  // build the word hashtable out of the file.


  // STEP 5.
  // Invoke the DTRegisterDocumentName() function in
  // doctable.h/c to register the new file with the
  // doctable.


  // Loop through the hash table.
  it = HashTableMakeIterator(tab);
  while (NumElementsInHashTable(tab) > 0) {
    WordPositions *wp;
    HTKeyValue kv;

    // STEP 6.
    // Use HTIteratorDelete() to extract the next WordPositions structure out
    // of the hashtable. Then, use MIAddPostingList()  (defined in memindex.h)
    // to add the word, document ID, and positions linked list into the
    // inverted index.


    // Since we've transferred ownership of the memory associated with both
    // the "word" and "positions" field of this WordPositions structure, and
    // since we've removed it from the table, we can now free the
    // WordPositions structure!
    free(wp);
  }
  HTIteratorFree(it);

  // We're all done with the word HT for this file, since we've added all of
  // its contents to the inverted index. So, free the word HT and return.
  FreeWordHT(tab);
}
