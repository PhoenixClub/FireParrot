#ifndef   _DEVICE_MANAGER_H
#define   _DEVICE_MANAGER_H

class DeviceManager
{
        private:
                InputDevice *m_input;
                Drone *m_drone;
                
                vec4_t Convert(vec3_t, vec_t);
                
        public:
                DeviceManager();
                ~DeviceManager();
                
                void Update();
};

#endif /* _DEVICE_MANAGER_H */
