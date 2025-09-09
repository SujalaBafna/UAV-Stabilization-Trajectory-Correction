#ifndef PID_CONFIG_H
#define PID_CONFIG_H

// PID loop timestep in seconds (used when computing dt)
#define PID_DT 0.01f

// PID gains for roll (example, tune as needed)
#define PID_ROLL_KP 1.5f
#define PID_ROLL_KI 0.02f
#define PID_ROLL_KD 0.4f

// PID gains for pitch
#define PID_PITCH_KP 1.2f
#define PID_PITCH_KI 0.015f
#define PID_PITCH_KD 0.35f

// PID gains for yaw
#define PID_YAW_KP 0.9f
#define PID_YAW_KI 0.01f
#define PID_YAW_KD 0.25f

// Output limit in degrees (servo command saturation)
#define PID_OUTPUT_LIMIT 45.0f

#endif // PID_CONFIG_H
