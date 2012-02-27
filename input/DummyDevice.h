/**
 * DummyDevice
 * ==========
 *
 * This is a dummy implementation of the InputDevice class which provides some 
 * meaningless data output. Used for testing the device interface.
 */

#ifndef DUMMY_DEVICE_H
#define DUMMY_DEVICE_H

#include <input/InputDevice.h>

namespace cuardrone
{
    namespace input
    {
        class DummyDevice : public InputDevice
        {
        private:
            float m_thrust;
            vec3_t m_velocity;

        public:
            DummyDevice();
            virtual ~DummyDevice();

            float GetThrust();
            vec3_t* GetVelocity();
        };
    }
}

#endif
