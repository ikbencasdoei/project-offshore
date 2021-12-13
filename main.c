#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "knoppen.h"
#include "motors.h"
#include "rotoencoder.h"

int main(void)
{
    init_knoppen();
    init_motors();
    init_rotoencoder();

    while(1)
    {
        check_rotoencoder();
        if(rotoencoder_clock > 0){
            zet_motor(40);
        } else if (rotoencoder_clock < 0){
            zet_motor(-40);
        } else {
            zet_motor(0);
        }
    }

    return 0;
}


//cordinaat opgeven waar ton staat
//cordinaat opgeven waar ton naar toe moet
//motor x-as aansturen
//stoppen als afstandsmeter bij eerste x-coordinaat is
//y-as juist aantal keer draaien
//z-as motor aan
//z-as motor uit als drukschakelaar in ingedrukt
//elektromagneet aan

//motor y-as aan adere kant op draaien
//motor x-as draaien
//motor y-as draaien
//motor z-as draaien
//elektromagneet uit
//motor y-as draaien
