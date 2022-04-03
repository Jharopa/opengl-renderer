#pragma once

#include "defines.h"
#include "event.h"
#include "singleton.h"

#include <unordered_map>
#include <vector>
#include <functional>

class EventBus : public Singleton<EventBus>
{
    private:
        std::unordered_map<EventType, std::vector<std::function<void(Event&)>&>> eventRegistar;

    public:
        b8 registerListener(EventType eventType, std::function<void(Event&)>& eventCallback);
        b8 unregisterListener(EventType eventType, std::function<void(Event&)>& eventCallback);
        b8 fireEvent(Event& event);
};
