#include "tennisfanclub/fan/behavior.h"
#include "television/channel/list.h"
#include "television/control/control.h"

int main() {
    watch(TENNIS_CHANNEL);

    cheer_for("Federer", "Federer");
    boo_for("Federer", "Nadal");

    cheer_for("Nadal", "Nadal");
    boo_for("Nadal", "Federer");

    return 0;
}
