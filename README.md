# M5StackDemo1
Program written using Smooth C++ library and LittlevGL Graphics library running on M5Stack

## Description
A program that displays two views; one view is a Greeting in English and another view is a Greeting in French.  The view changes every 2 seconds.  Two tasks are created besides the main task.  LvglTask which handles the LittlevGL graphics and the views and a ChangeViewTask which handles changing the views.  The program uses publish/subscribe for notification between the two tasks.

