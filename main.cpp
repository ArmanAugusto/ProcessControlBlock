/* 
 * This program mimics the Process Control Block of an operating system, 
 * specifically, the behavior of the ReadyQueue that holds the processes
 * that are ready to be run.
 */

/* 
 * File:            main.cpp
 * Author:          Arman Augusto
 * Project Name:    Process Control Block
 * Description:     This is the main driver file to test the code
 *
 * Created on January 30, 2019, 11:10 AM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>      
#include <sys/time.h>   // struct timeval
#include "PCB.h"
#include "ReadyQueue.h"

int main(int argc, char** argv) {
    std::cout << "Name:\t\tArman Augusto" << std::endl;
    std::cout << "Date Created:\tSunday, January 30, 2019" << std::endl;
    std::cout << std::endl;
    
    std::cout << "\n********TEST 1********" << std::endl;
    
    PCB pcb_table[20];  // Table of all of the processes in the system.
    int returnValue;    // Returns the PID of process that was removed.
    
    // Initialize the values in the pcb_table
    for (int i = 0; i < 20; i++) { 
        pcb_table[i].priority = i+1;
        pcb_table[i].PID = i+1;
        pcb_table[i].state = "NEW";
    }
    
    // Test 1: Create a ReadyQueue q1. Then do the following tests.
    ReadyQueue q1; // Queue of all of the READY processes in the system
    
    // (a) Add processes 5, 1, 8, and 11 to q1. Display q1.
    q1.insertProc(pcb_table[5]);
    pcb_table[5].state = "READY";
    q1.insertProc(pcb_table[1]);
    pcb_table[1].state = "READY";
    q1.insertProc(pcb_table[8]);
    pcb_table[8].state = "READY";
    q1.insertProc(pcb_table[11]);
    pcb_table[11].state = "READY";
    q1.displayQueue();
    
    // (b) Remove the process with the highest priority from q1 and display q1.
    q1.removeHighestProc(returnValue);
    q1.displayQueue();
    pcb_table[returnValue-1].state = "RUNNING"; // change state to RUNNING
    
    // (c) Remove the process with the highest priority from q1 and display q1.
    q1.removeHighestProc(returnValue);
    q1.displayQueue();
    pcb_table[returnValue-1].state = "RUNNING"; // change state to RUNNING
    
    // (d) Insert processes 3, 7, 2, 12, 9 to q1.
    q1.insertProc(pcb_table[3]);
    pcb_table[3].state = "READY";
    q1.insertProc(pcb_table[7]);
    pcb_table[7].state = "READY";
    q1.insertProc(pcb_table[2]);
    pcb_table[2].state = "READY";
    q1.insertProc(pcb_table[12]);
    pcb_table[12].state = "READY";
    q1.insertProc(pcb_table[9]);
    pcb_table[9].state = "READY";
    
    //(e) One by one remove the process with the highest priority from queue q1 and display it after each removal."
    for (int i = q1.size(); i > 0; i--) {
        q1.removeHighestProc(returnValue);
        q1.displayQueue();
        pcb_table[returnValue-1].state = "RUNNING"; //Removed from the READY queue means that it is now RUNNING.
    }
    
    std::cout << "\n\n*****END OF TEST 1*****\n" << std::endl;
    
    std::cout << "\n\n********TEST 2********\n" << std::endl;  
    
    /*Use q1 and PCBTable from test 1.
     * Randomly select 10 processes from PCBTable, add into q1. But assign each process a random initial priority, 1 to 50.
     * Repeat the following 1,000,000 times:
     * a) Remove one process from q1.
     * b) Decrement priority of all processes still in q1. (Make sure priority >= 1)
     * 3) Randomly select a process which isn't yet in q1, and insert, with a random priority.
     * Measure total time and print the final content. Use gettimeofday to measure time.
     */
    srand(time(NULL));//This is a seed for the random() function, which I use to randomly choose processes and randomly give priority levels
    int randomentry = 0; //This will be the random PCB Table entry.
    
    //This is for getting the time of day at the start of running test 2.
    struct timeval now;
    int rc = gettimeofday(&now, NULL);
    printf("Start time = %u.%06u\n", now.tv_sec, now.tv_usec);
    
    //Test 2: Use the readyqueue q1 and PCB Table from the first test. First, randomly select 10 processes from the PCB Table and add them into q1, but assign each process a random initial priority between 1 and 50.
    for (int i = 0; i < 10; i++) {
        randomentry = rand()%20; //Pick a random number for the table element
        
        while (pcb_table[randomentry].state == "READY") { //If it is going to be a duplicate... 
            randomentry = rand()%20; //...Then pick a different element
	}
        
        //Once there is a unique element, then continue. Change its state, get a random priority, and add it to the queue.
        pcb_table[randomentry].state = "READY";
        PCB newJob = pcb_table[randomentry]; //newJob is an intermediate step between a PCB table entry and the ready queue addition -- because the priority needs to be randomly generated, without disrupting the priority within the table.
        newJob.priority = rand()%50+1; //Random number between 1 and 50
        q1.insertProc(newJob);
    }
    //Repeat the following steps 1,000,000 times and measure the total time of running the loop
    //(a) remove the most urgen process
    //(b) age the remaining processes
    //(c) pick a random job from PCB table, give it a random priority, and insert into q1.
    for (int i = 0; i < 1000000; i++) {
        q1.removeHighestProc(returnValue);
        pcb_table[returnValue-1].state = "RUNNING"; //Once the job has finished executing, it is now ready to be added to the queue eventually.
        
        q1.age();
        
        randomentry = rand()%20; //Pick a random number for the table element
        
        while (pcb_table[randomentry].state == "READY") { //If it is going to be a duplicate...
            randomentry = rand()%20; //...Then pick a different element
        }
        
        //Once there is a unique element, then continue. Change its state, get a random priority, and add it to the queue.
        pcb_table[randomentry].state = "READY";
        PCB newJob = pcb_table[randomentry]; //newJob is an intermediate step between a PCB table entry and the ready queue addition -- because the priority needs to be randomly generated, without disrupting the priority within the table.
        newJob.priority = rand()%50+1; //Random number between 1 and 50
        q1.insertProc(newJob);
    }
    
    //This prints the time after running test 2.
    rc=gettimeofday(&now, NULL);
    printf("Finish time= %u.%06u\n", now.tv_sec, now.tv_usec);
    
    //Print out the final content of readyqueue
    q1.displayQueue();
    
    std::cout << "\n*****END OF TEST 2*****\n" << std::endl;

    return 0;
}

