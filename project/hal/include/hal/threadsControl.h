#ifndef _THREADCONTROL_H_
#define _THREADCONTROL_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "hal/useJoyStick.h"
#include "hal/readNWrite.h"
#include "hal/useAPI.h"

// Start thread of using udp, accelerometer and Joy stick
void startThreads();

// Stop all threads and joins
void joinThreads();

// signal shutdown to all threads except the audio
void signalShutdown();

// get the state of if the program shut down
bool ifShutdown();

#endif
