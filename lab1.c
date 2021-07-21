#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int exitAndWaitTests(void) {
  int pid1, pid2;
  int status;
  int waitPid;

  pid1 = fork();
  // child
  if (pid1 == 0) {
    printf(1, "\n This is the first child with pid number (%d) and it will exit with status %d.\n", getpid(), 0);
    exit(0);
  }
  // parent
  else if (pid1 > 0) {
    waitPid = wait(&status);
    printf(1, "\n This is the parent of the child with pid number (%d). The child exited with status %d.\n", waitPid, status);
  }
  // error
  else {
    printf(1, "\n There was an error creating the fork()!\n");
    exit(-1);
  }

  pid2 = fork();
  // child
  if (pid2 == 0) {
    printf(1, "\n This is the second child with pid number (%d) and it will exit with status %d.\n", getpid(), -1);
    exit(-1);
  }
  // parent
  else if (pid2 > 0) {
    waitPid = wait(&status);
    printf(1, "\n This is the parent of the child with pid number (%d). The child exited with status %d.\n", waitPid, status);
  }
  // error
  else {
    printf(1, "\n There was an error creating the fork()!\n");
    exit(-1);
  }

  return 1;
}

int waitpidTests(void) {
  int pid = fork();
  int status;
  int returnPid;

  if (pid == 0) {
    printf(1, "\nThis is child with pid  number (%d) and it will exit with status %d.\n", getpid(), 0);
    exit(0);
  }

  returnPid = waitpid(pid, &status, 0);
  printf(1, "\n This is the parent of child with pid number (%d) and it has exited with status %d. \n", returnPid, status);

  return 1;
}

int main(int argc, char* argv[]) {
  printf(1, "\n Lab1 Tests!\n");
  printf(1, "\n---------------------\n");


  printf(1, "\nExit Tests!\n");
  printf(1, "\n---------------------\n");
  exitAndWaitTests();

  printf(1, "\nWaitpid Tests!\n");
  printf(1, "\n---------------------\n");
  waitpidTests();

  return 0;
}
