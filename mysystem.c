/*
 *  mysystem.c : system 関数のクローン
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため
#include "mysystem.h"  // インタフェース

// system関数のクローン
int mysystem(char *command) {
  char *execpath = "/bin/sh";
  int status = 0;

  // ここにプログラムを書く
  int pid = fork(); //分身を作る
  if (pid < 0) status = -1;
  if (pid != 0) {
    while (wait (&status) != pid)
    ;
  } else {
    // system (command);
    execvp (execpath, &command);
    perror (execpath);
    exit(127);
  }
  return status;
}

/* 実行例

ここに実行例を書く
$ make

*/
