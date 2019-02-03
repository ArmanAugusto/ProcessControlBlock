/*
 * Project Name:    Process Control Block
 * Description:     This is the main driver file to test the code
 */

/* 
 * File:            main.cpp
 * Author:          Arman Augusto
 * ID:              004588816
 * Class:           CS 433 - Operating Systems
 * Assignment:      Assignment 1
 *
 * Created on January 30, 2019, 11:10 AM
 */

#include <cstdlib>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <algorithm> // find()
#include <string.h>
#include "PCB.h"
#include "ReadyQueue.h"

int main(int argc, char** argv) {
    std::cout << "Name:\t\tArman Augusto" << std::endl;
    std::cout << "ID:\t\t#004588816" << std::endl;
    std::cout << "Instructor:\tDr. Xiaoyu Zhang" << std::endl;
    std::cout << "Course:\t\tCS 433 - Operating Systems" << std::endl;
    std::cout << "Assignment:\tAssignment 1" << std::endl;
    std::cout << "Date Created:\tSunday, January 30, 2019" << std::endl;
    std::cout << std::endl;
    
    /*
     * Test 1
     */
    
    std::cout << "\n********TEST 1********" << std::endl;
    
    PCB pcb_table[20];
    int highestProc;
    
    for (int i = 0; i < 20; i++) {
        pcb_table[i].PID = i;
        pcb_table[i].state = "NEW";
        pcb_table[i].priority = pcb_table[i].PID;
    }
    
    ReadyQueue q1;
    // (a) add processes 5, 1, 8, 11 to q1. Display the content of q1
    q1.insertProc(pcb_table[5]);
    q1.insertProc(pcb_table[1]);
    q1.insertProc(pcb_table[8]);
    q1.insertProc(pcb_table[11]);
    q1.displayQueue();
    
    // (b) remove the process with the highest priority from q1 and display q1
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    
    // (c) remove the process with the highest priority from q1 and display q1
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    
    // (d) Insert processes 3, 7, 2,12, 9 to q1
    q1.insertProc(pcb_table[3]);
    q1.insertProc(pcb_table[7]);
    q1.insertProc(pcb_table[2]);
    q1.insertProc(pcb_table[12]);
    q1.insertProc(pcb_table[9]);
    
    // (e) One by One remove the process with the highest priority from the
    //  queue q1 and display it after each removal
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    q1.removeHighestProc(highestProc);
    q1.displayQueue();
    
    std::cout << "****END OF TEST1****\n" << std::endl;
    /*
     * end of Test 1
     */
    
    /*
     * Test 2
     */
    
    std::cout << "\n********TEST 2********\n" << std::endl;
    
    srand(time(NULL));
    int randomNum = 0;
    int randomPID = 0;
    
    time_t T = time(NULL); // "epoch time"
    printf("%zd\n", T);
    
    char tm[100];
    strcpy(tm, ctime(&T));
    puts(tm);
    /* test
        std::cout << "\nProcesses in the pcb_table:\n" << std::endl;
        std::cout << " PID\t State\t Priority" << std::endl;
        for (int i = 0; i < 20; i++) {
            std::cout << " " << pcb_table[i].PID << "\t"; 
            std::cout << " " << pcb_table[i].state << "\t";
            std::cout << " " << pcb_table[i].priority << std::endl;
        }
    std::cout << std::endl;
    */
    for (int i = 0; i < 10; i++) {
        randomPID = rand() % 20 + 1; // random PID number from 1 to 20
        PCB newProcess = pcb_table[randomPID];
        newProcess.priority = rand() % 50 + 1; // random priority value from 1 to 50    
        q1.insertProc(newProcess);  
    }
    q1.displayQueue();
    
    // create a random number between 1 and 100
    randomNum = rand() % 100 + 1;
    if ((randomNum % 2) == 0){ // if random number is even
        // remove highest process
        q1.removeHighestProc(highestProc);
    } else {// insert a new random number into the ready queue
        randomPID = rand() % 20 + 1; // random PID number from 1 to 20
        PCB newProcess = pcb_table[randomPID];
        newProcess.priority = rand() % 50 + 1; // random priority value from 1 to 50    
        q1.insertProc(newProcess);  
    }
    q1.displayQueue();
    
    /*
     * randomly decide to remove a process from or add a process to the ready
     * queue with equal probability (50%) chance
     */
    // get a random PID
    
    // get a random priority
    
    // if
        // PID and priority do not match what is already in ready queue
    
        // insert each value in ready queue
    
    // else
        // remove highest priority from ready queue
        
    
    
    
    
    
    /*
     * Remove tests samples
     */
    
    time_t T2 = time(NULL); // "epoch time"
    printf("%zd\n", T2);
    
    char tm2[100];
    strcpy(tm2, ctime(&T2));
    puts(tm2);
    
    return 0;
}

