#include <XBoxDevice.h>

#include <gamepad/gamepad.h>

namespace cuardrone
{
    XBoxDevice::XBoxDevice()
    {
        GamepadInit();
        if (!GamepadIsConnected(GAMEPAD_0))
        {
            // Exception? How do we handle this
        }
    }

    XBoxDevice::~XBoxDevice()
    {
        GamepadShutdown();
    }

    void XBoxDevice::PollInput()
    {
        GamepadUpdate(); // Update the status of the pad
        
        // Update flags
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_A))
        {
            m_flightParams.flags &= FLAG_TAKEOFF;
        }
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_B))
        {
            m_flightParams.flags &= FLAG_LAND;
        }
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_BACK))
        {
            m_flightParams.flags &= FLAG_EMERGENCY;
        }
        

        // Update thrust
        float positiveThrust = GamepadTriggerLength(GAMEPAD_0, TRIGGER_RIGHT); 
        float negativeThrust = GamepadTriggerLength(GAMEPAD_0, TRIGGER_LEFT);

        m_flightParams.flightDynamics[FLIGHT_THRUST] = positiveThrust - negativeThrust;
        
        // Update pitch, yaw, roll
        float xPos, yPos;
        xPos = yPos = 0.0f;
        GamepadStickNormXY(GAMEPAD_0, STICK_LEFT, &xPos, &yPos);
        m_flightParams.flightDynamics[FLIGHT_PITCH] = yPos;
        m_flightParams.flightDynamics[FLIGHT_ROLL] = xPos;

        GamepadStickNormXY(GAMEPAD_0, STICK_RIGHT, &xPos, &yPos);
        m_flightParams.flightDynamics[FLIGHT_YAW] = xPos;
    }
    
    void XBoxDevice::ProcessVideo()
    {
        
    }

    void XBoxDevice::TrackSensors()
    {
        
    }
}
