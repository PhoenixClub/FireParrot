/**
 * InputDevice
 * ============
 *
 * This class is a generic interface which all input devices should implement. 
 * It makes a set of flight parameters available to the InputManager, which 
 * then get transformed into the correct form and sent to the Drone.
 */

#ifndef INPUT_DEVICE_H
#define INPUT_DEVICE_H

/**
 * NOTE: Temporary until Alex gets phi finished
 */
typedef float vec_t;            /* scalar                 */
typedef vec_t vec2_t[2];        /* two-dimensional vector */
typedef vec_t vec3_t[3];        /* three-dimension ...    */

namespace cuardrone
{
    namespace input
    {
        class InputDevice
        {
        private:
            
        public:
            InputDevice() { /* Not implemented */ }
            virtual ~InputDevice() { /* Not implemented */ }

            /**
             * Returns a float between -1 and 1 which represents thrust
             */
            virtual float GetThrust() = 0; /* Pure virtual */
            /**
             * Returns a normalized 3d vector which represents velocity
             * X = pitch, Y = roll, Z = yaw
             */
            virtual vec3_t* GetVelocity() = 0; /* Pure virtual */
        };
    }
}

#endif
