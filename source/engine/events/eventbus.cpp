#include "eventbus.h"

b8 EventBus::registerListener(EventType eventType, std::function<void(Event&)>& eventCallback) 
{
    return true;
}

b8 EventBus::unregisterListener(EventType eventType, std::function<void(Event&)>& eventCallback) 
{
    return true;
}

b8 EventBus::fireEvent(Event& event) 
{
    return true;
}