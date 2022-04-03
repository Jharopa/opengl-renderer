#include "application.h"

#include <iostream>

void Application::init()
{
    m_window = std::make_shared<Window>(800, 600, "Application");
    m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
}

void Application::run()
{
    while (!m_window->shouldClose())
    {
        Input::getInstance().update();
        
        m_window->update();
    }
}

void Application::onEvent(Event& e)
{
    if (e.getEventType() == KeyPressedEvent::getStaticType())
    {
        KeyPressedEvent kpe = static_cast<KeyPressedEvent&>(e);
        
        if(!kpe.isRepeat())
        {
            std::cout << kpe.getKey() << " key pressed" << std::endl;
        }
        else
        {
            std::cout << kpe.getKey() << " key repeated" << std::endl;
        }   
    }
    else if (e.getEventType() == KeyReleasedEvent::getStaticType())
    {
        KeyReleasedEvent kre = static_cast<KeyReleasedEvent&>(e);
        std::cout << kre.getKey() << " key released" << std::endl;
    }
}
