#include "control.h"
#include "television/channel/list.h"
#include <stdio.h>

void watch(const int channel) {
    char* title;

    switch (channel) {
        case TENNIS_CHANNEL:
            title = "Wimbledon 2019 Semi-Final, Men's Singles: Roger Federer vs Rafael Nadal!";
            break;
        case NEWS_CHANNEL:
            title = "Seattle area rattled by 4.6 magnitude earthquake.";
            break;
        default:
            title = "<No signal>";
    }

    printf("Channel %d: %s\n", channel, title);
}
