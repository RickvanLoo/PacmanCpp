/*
 * main.h
 *
 *  Created on: Feb 18, 2015
 *      Author: frits
 *       Group: TA's
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

// ID of the timer that calls the update function
SDL_TimerID timer_id;

// Callback function of the timer.
Uint32 gameUpdate(Uint32 interval, void *param);


#endif /* SRC_MAIN_H_ */
