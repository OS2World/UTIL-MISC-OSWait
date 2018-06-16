  DOSWAIT!, OSWAIT!, & OSWAITF!  (c) 1994, John M. Warren & ITECH-CIS

    TABLE OF CONTENTS

    ..DISCLAIMER & WARRANTY
    ..REGISTRATION
    ..WHAT THE PROGRAM DOES
    ..HOW TO USE THE PROGRAM
    ..PROGRAM SYNTAX
    ..WHAT THE HECK IS AN ERRORLEVEL?
    ..A SPECIAL NOTE ABOUT BATCH FILES & ERRORLEVELS
    ..SOURCE CODE
    ..A PLUG FOR MY PROGRAMMERS BBS


  DISCLAIMER & WARRANTY

  The author claims no responsibility for the use of this product.

  The source code to this program is provided for educational purposes
  only and may not be duplicated, nor compiled for distribution without
  the written consent of the author, John M. Warren.  However, the
  program itself may freely distributed as shareware, so long as no
  modifications are made to it's content.

  REGISTRATION

  I would like to finish college some day.  Send me $5 and I'll send
  you a registered copy of all three programs along with a list other
  applications and utilities that are available.  Send your check,
  or money order to :

         John M. Warren
         P.O. Box 609
         Vernon, FL. 32462

  Non-U.S. orders please send $10


  WHAT THE PROGRAM DOES

  DOSWAIT!, OSWAIT!, & OSWAITF! are utilities for the DOS and OS/2
  operating systems.  Simply put, each program will delay your
  computer a specified amount of seconds, then continue when the
  timer gets down to 0. However, if the user presses the "Q" key
  the program will terminate with an errorlevel of 1.  Don't worry
  if you don't know anything about errorlevels, your about to learn.


  HOW TO USE THE PROGRAM

  1. If you know what the heck your doing already, and feel this
     documentation is a waste of time for you, check out the 2
     files SAMPLE.BAT, and if you use OS/2 SAMPLE.CMD

  2. If you don't know what errorlevels are, read the "ERRORLEVEL
     TUTORIAL" section first. It will give you a tutor on errorlevel
     andbatch files.


   PROGRAM SYNTAX

   ---------------------------------------------------------------
   DOSWAIT!  [seconds]

   Example :    C:\> DOSWAIT!.EXE 30

   This exmaple will cause a system delay of 30 seconds.

   ---------------------------------------------------------------

   OSWAIT! & OSWAITF!

   1. OSWAIT! is used for OS/2 sessions which are in a window.
   2. OSWAITF! is used for OS/2 sessions which are full screen.

   Example :   C:\> OSWAIT! 30

   This example will cause a system delay of 30 seconds.  If it is
   executed from the OS/2 prompt then an OS/2 windowed session will
   be created.

   Example :   C:\> OSWAITF! 30

   This example will cause a system delay of 30 seconds.  If it is
   executed from the OS/2 prompt then an OS/2 full screen session will
   be created.

*********************** AN ERRORLEVEL TUTORIAL **********************

  WHAT THE HECK IS AN ERRORLEVEL?

  An errorlevel is a numeric value passed to DOS whenever a computer
  application terminates.  If a computer program returns an
  errorlevel of 0 this means that the program terminated normally
  without any errors or any hitches.  If a computer program returns
  an errorlevel other than 0 then that usually means an error occured
  within the program.  Errorlevel values vary from program to program.
  In other words if your running a word processing program and say it
  can't read a bad diskette it may terminate with an errorlevel of 3
  the computer programmers designed the word processor to return this
  value whenever this error is encountered.  In a spreadsheet if the
  diskette can't be read, it may return an errorlevel of 5.  So,
  errorlevel values are specific to whatever application you are running.
  If you look hard in most manuals, you can usually find possible
  errorlevel values and a description of each for whatever application
  you are using.

  USING DOSWAIT!, OSWAIT! and OSWAITF! & ERRORLEVELS

  Look at the following.. (line numbers are for reference only)

  1 @ECHO OFF
  2 DOSWAIT! 20
  3 IF NOT ERRORLEVEL 1 GOTO DONE

  4 Echo User pressed "Q" to terminate.

  5 :DONE

  Line 2 starts the DOSWAIT! program and tells it to delay for 20
  seconds before continuing.  If the time runs out, then the program
  will terminate with an errorlevel of 0, meaning a normal termination.
  However, if you press "Q" before the time runs out then the
  DOS errorlevel will be set to 1, meaning an abnormal event occured.

  Line 3 simply checks the errorlevel value.  If the ERRORLEVEL value
  was not set to 1 then the batch file jumps to DONE and terminates the
  program normally.  However, if the ERRORLEVEL value WAS set to 1 then
  then line 4 is executed.

  A SPECIAL NOTE ABOUT BATCH FILES & ERRORLEVELS

  One rule of thumb that I would like to mention however.  If you are
  using a program which returns multiple ERRORLEVELS you have to check
  then from highest to lowest value (descending order) like so :

        ECHO OFF

        MYAPP.EXE

        IF ERRORLEVEL 200 GOTO BOB
        IF ERRORLEVEL 199 GOTO DICK
        IF ERRORLEVEL  35 GOTO JANE
        IF ERRORLEVEL  14 .........

        ECHO ERRORLEVEL value did not match or was 0

        :BOB
         ECHO BOB
         GOTO DONE

        :DICK
         ECHO DICK
         GOTO DONE

        :JANE
         ECHO JANE

        :DONE


SOURCE CODE

  The 'C' source code for this program is contained within the SOURCE.ZIP
  file.  It was written using Bx++ for OS/2 and Tx++ 3.x for DOS.  It took
  about 3 hours to write, test, and document this program.


A PLUG FOR MY PROGRAMMERS BBS

  Code 3, The Game Programmers Connection
  904-535-1705 14.4 Renegade BBS

  Graphics Utilities & Engines For C/PAS/BASIC/QBASIC
  Example Game Code
  Lots of other programming goodies as well as 1.2G of shareware.

  First time no hassle access, no UL/DL limits, ratios. FREE.

  The only restriction is 60 minutes PER CALL. <g>
