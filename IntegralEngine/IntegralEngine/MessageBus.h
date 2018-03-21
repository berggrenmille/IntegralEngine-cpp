#pragma once

class MessageBus
{
private:
	static MessageBus m_instance;
public:
	static MessageBus& GetInstance();
	
	void Subscribe();
	void Unsubscribe();
	void SendMessage();
};
