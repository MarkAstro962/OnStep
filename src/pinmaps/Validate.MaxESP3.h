// MaxESP v3 specific pins validation

// SERIAL PORTS ------------------------------------------------------------------------------------------------------------
#if SERIAL_B_ESP_FLASHING == ON
  #if AssignAux2 < 0
    #error "Configuration (Config.h): SERIAL_B_ESP_FLASHING enabled but Aux2 is already in use, choose one feature on Aux2."
  #else
    #undef AssignAux2
    #define AssignAux2 -2
    // for the MaxESP3 also undefine the focuser control EN pin since it is in use for other purposes
    #if PINMAP == MaxESP3
      #undef Axis4_EN
      #define Axis4_EN -1
    #endif
  #endif
#endif

// USER FEEDBACK ----------------------------
#if LED_STATUS == ON
  #if AssignAux8 < 0
    #error "Configuration (Config.h): LED_STATUS enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef AssignAux8
    #define AssignAux8 -2
  #endif
#endif

#if LED_STATUS2 == ON
  #if AssignAux8 < 0
    #error "Configuration (Config.h): LED_STATUS2 enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef AssignAux8
    #define AssignAux8 -2
  #endif
#endif

#if LED_RETICLE == ON
  #if AssignAux8 < 0
    #error "Configuration (Config.h): LED_RETICLE enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef AssignAux8
    #define AssignAux8 -2
  #endif
#endif

#if BUZZER == ON
  #if AssignAux8 < 0
    #error "Configuration (Config.h): BUZZER enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef AssignAux8
    #define AssignAux8 -2
  #endif
#endif

// TIME -------------------------------------
#if RTC == DS3231
  #if AssignAux3 < -1 // in use or other than I2C?
    #error "Configuration (Config.h): RTC DS3231 I2C enabled but Aux3 is already in use, choose one feature on Aux3"
  #else
    #undef AssignAux3
    #define AssignAux3 -1
  #endif
  #if AssignAux4 < -1 // in use or other than I2C?
    #error "Configuration (Config.h): RTC DS3231 I2C enabled but Aux4 is already in use, choose one feature on Aux4"
  #else
    #undef AssignAux4
    #define AssignAux4 -1
  #endif
#endif

#if PPS_SENSE == ON
  #if AssignAux7 < 0
    #error "Configuration (Config.h): PPS_SENSE enabled but Aux7 is already in use, choose one feature on Aux7"
  #else
    #undef AssignAux7
    #define AssignAux7 -2
  #endif
#endif

// SENSORS ----------------------------------
#if WEATHER == BME280
  #if AssignAux3 < -1 // in use or other than I2C?
    #error "Configuration (Config.h): BME280 I2C enabled but Aux3 is already in use, choose one feature on Aux3"
  #else
    #undef AssignAux3
    #define AssignAux3 -1
  #endif
  #if AssignAux4 < -1 // in use or other than I2C?
    #error "Configuration (Config.h): BME280 I2C enabled but Aux4 is already in use, choose one feature on Aux4"
  #else
    #undef AssignAux4
    #define AssignAux4 -1
  #endif
#endif

#if TELESCOPE_TEMPERATURE == DS1820
  #if AssignAux8 < 0
    #error "Configuration (Config.h): RTC DS1820 OneWire interface enabled but Aux8 is already in use, choose one feature on Aux8"
  #else
    #undef AssignAux8
    #define AssignAux8 -2
  #endif
#endif

#if PEC_SENSE == ON || PEC_SENSE == ON_PULLUP || PEC_SENSE == ON_PULLDOWN
  // dedicated pin
#endif

#if LIMIT_SENSE != OFF
  #if AssignAux7 < 0
    #error "Configuration (Config.h): LIMIT_SENSE enabled but Aux7 is already in use, choose one feature on Aux7"
  #else
    #undef AssignAux7
    #define AssignAux7 -2
  #endif
#endif

#if HOME_SENSE != OFF
  #if AssignAux3 < 0
    #error "Configuration (Config.h): HOME_SENSE enabled but Aux3 is already in use, choose one feature on Aux3"
  #else
    #undef AssignAux3
    #define AssignAux3 -2
  #endif
  #if AssignAux4 < 0
    #error "Configuration (Config.h): HOME_SENSE enabled but Aux4 is already in use, choose one feature on Aux4"
  #else
    #undef AssignAux4
    #define AssignAux4 -2
  #endif
#endif

// MOTION CONTROL AXIS1/2 -----------------
#if AXIS1_DRIVER_STATUS != OFF
  #if AssignAux1 < 0
    #error "Configuration (Config.h): AXIS1_DRIVER_STATUS enabled but Aux1 is already in use, choose one feature on Aux1"
  #else
    #undef AssignAux1
    #define AssignAux1 -2
  #endif
#endif

#if AXIS2_DRIVER_STATUS != OFF
  // dedicated pin, shared with AXIS1
#endif

// MOTION CONTROL FOCUSERS/ROTATOR --------
#if ROTATOR == ON && AXIS3_DRIVER_POWER_DOWN == ON
  // no EN on Rotator, this is trapped automatically later
#endif

#if FOCUSER1 == ON && (AXIS4_DRIVER_POWER_DOWN == ON || AXIS4_DRIVER_DC_MODE != OFF)
  #if AssignAux2 < 0
    #error "Configuration (Config.h): AXIS4_DRIVER_POWER_DOWN and AXIS4_DRIVER_DC_MODE require ENable signal support but Aux2 is already in use, choose one feature on Aux2"
  #else
    #undef AssignAux2
    #define AssignAux2 -2
  #endif
#endif

#if FOCUSER2 == ON && AXIS5_DRIVER_POWER_DOWN == ON
  // no EN on Focuser2, this is trapped automatically later
#endif
