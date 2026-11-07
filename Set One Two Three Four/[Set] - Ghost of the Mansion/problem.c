#include <stdio.h>
#include "ghost.h"

/*  TODO: Press the switches in order and stop as soon as every light is OFF.
    - If *lights is already 0 (all dark), return 0 without pressing anything.
    - Pressing switch number s toggles every room in switches[s - 1]
      (switches are numbered from 1, the array starts at 0).
      Toggle = symmetric difference = the ^ operator.
    - After a press, if *lights == 0, return how many presses were made.
    - If the lights never all go dark, return -1.
    *lights must hold the final state when the function ends.                 */

int banishGhost(Set *lights, Set switches[], int presses[], int p) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:
        - Each bit in the array of switches is a room toggled by the switch
        - Every press toggles the switch
            - iterate through array of presses
            - use the toggle formula to toggle the lights after switch press
            - if lights == 0 or all OFF, return the amount of times iterated: i + 1
    */
    if (*lights == 0) {
        return 0;
    }
    
    for (int i = 0; i < p; i++) {
        int s = presses[i];
        *lights ^= switches[s - 1];
        
        if (*lights == 0) {
            return i + 1;
        }
    }
    return -1;
}