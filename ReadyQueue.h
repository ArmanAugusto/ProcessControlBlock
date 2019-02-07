/* 
 * File:            ReadyQueue.h
 * Author:          Arman Augusto
 * Project Name:    Process Control Block
 * Description:     This is the header file for the Ready Queue
 *                  containing all processes in the "READY" state
 *
 * Created on January 30, 2019, 11:29 AM
 */

#ifndef READYQUEUE_H
#define READYQUEUE_H

#include <iostream>
#include "PCB.h"


class ReadyQueue {
protected:
    PCB queue[10];  // the queue of processes
    int endOfQueue; // represents the last index of the queue
public:
    // Error handling classes
    class Underflow{};    // no processes available
    class Overflow{};     // queue overflow
    class Illegal{};      // invalid priority value
    ReadyQueue();
    ~ReadyQueue();
    void insertProc(PCB newProcess);            // adds the PCB of a process into the ReadyQueue. state changes to READY
    void removeHighestProc(int &returnValue);   // removes and returns the PCB with the highest priority from the queue. state changes to RUNNING
    void reorder();                             // reorders ReadyQueue placing highest priority process in front of queue
    void age();                                 // tracks how long processes remain in ReadyQueue
    int size();                                 // returns number of elements in the queue
    void displayQueue();                        // display the IDs and priorities of processes in the queue
    bool isEven(int slot);                      // checks if a number is even or odd for the purpose of reordering the ReadyQueue
};

#endif /* TESTREADYQUEUE_H */

