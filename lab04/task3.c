#include <stdio.h>
#include <stdint.h>

#define VOLTAGE_BITS   12
#define STATE_SHIFT    12
#define CHARGING_SHIFT 15

// Прототипи функцій
uint16_t pack_telemetry(unsigned int voltage, unsigned int state,
                        unsigned int charging);
void unpack_telemetry(uint16_t packet, unsigned int *voltage,
                      unsigned int *state, unsigned int *charging);

int main(void) {
    const unsigned int MAX_VOLTAGE = 4095;
    const unsigned int MAX_STATE = 7;
    const unsigned int MAX_CHARGING = 1;

    unsigned int voltage, state, charging;

    printf("Enter battery voltage in mV (0..%u): ", MAX_VOLTAGE);
    if (scanf("%u", &voltage) != 1 || voltage > MAX_VOLTAGE) {
        printf("Error: voltage must be in range 0..%u.\n", MAX_VOLTAGE);
        return 1;
    }

    printf("Enter charge state (0..%u): ", MAX_STATE);
    if (scanf("%u", &state) != 1 || state > MAX_STATE) {
        printf("Error: state must be in range 0..%u.\n", MAX_STATE);
        return 1;
    }

    printf("Enter charging flag (0..%u): ", MAX_CHARGING);
    if (scanf("%u", &charging) != 1 || charging > MAX_CHARGING) {
        printf("Error: flag must be 0 or 1.\n");
        return 1;
    }

    uint16_t packet = pack_telemetry(voltage, state, charging);

    unsigned int new_voltage, new_state, new_charging;
    unpack_telemetry(packet, &new_voltage, &new_state, &new_charging);

    printf("\nOriginal : voltage = %u, state = %u, charging = %u\n",
           voltage, state, charging);
    printf("Packet   : HEX: 0x%04X\n", (unsigned int)packet);
    printf("Unpacked : voltage = %u, state = %u, charging = %u\n",
           new_voltage, new_state, new_charging);

    if (voltage == new_voltage && state == new_state
        && charging == new_charging) {
        printf("Check: values are identical.\n");
    } else {
        printf("Check: values differ!\n");
    }

    return 0;
}

// Пакування: зсув ліворуч і побітове АБО
uint16_t pack_telemetry(unsigned int voltage, unsigned int state,
                        unsigned int charging) {
    return (uint16_t)(voltage
                      | (state << STATE_SHIFT)
                      | (charging << CHARGING_SHIFT));
}

// Розпакування: маски та зсув праворуч
void unpack_telemetry(uint16_t packet, unsigned int *voltage,
                      unsigned int *state, unsigned int *charging) {
    *voltage = packet & 0x0FFF;
    *state = (packet >> STATE_SHIFT) & 0x07;
    *charging = (packet >> CHARGING_SHIFT) & 0x01;
}