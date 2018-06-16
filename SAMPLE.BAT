REM ** (c) 1994, John M. Warren SAMPLE DOS BATCH FILE TO TEST DOSWAIT!

REM ** If you are using a dos version < 5.x then replace the
REM ** @echo off with echo off, in the next line

@echo off

REM ** Wait for 10 seconds, if 10 was not specified then DOSWAIT! defaults to
REM ** 5 seconds.

DOSWAIT! 10

REM ** If "Q" was not pressed then jump to :DONE and terminate.
IF NOT ERRORLEVEL 1 GOTO DONE

REM ** The "Q" key was pressed and DOSWAIT! set the DOS errorlevel to 1

Echo The "Q" (*BREAK*) Key Was Pressed!


:DONE
