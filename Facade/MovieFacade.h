#pragma once
#include <iostream>

class Projector
{
public:
	void OpenScreen() 
	{
		std::cout << "Open Screen¡­¡­" << std::endl;
	}

	void SetViewport()
	{
		std::cout << "Set Viewport¡­¡­" << std::endl;
	}

	void CloseScreen()
	{
		std::cout << "Close Screen¡­¡­" << std::endl;
	}
};

class Amplifier
{
public:
	void OpenAmplifier()
	{
		std::cout << "Open Amplifier¡­¡­" << std::endl;
	}

	void CloseAmplifier()
	{
		std::cout << "Close Amplifier¡­¡­" << std::endl;
	}
};

class DVDPlayer
{
public:
	void OpenDVDPlayer()
	{
		std::cout << "Open DVDPlayer¡­¡­" << std::endl;
	}

	void CloseDVDPlayer()
	{
		std::cout << "Close DVDPlayer¡­¡­" << std::endl;
	}
};

class Light
{
public:
	void TurnOnLight()
	{
		std::cout << "Turn on Light¡­¡­" << std::endl;
	}

	void TurnOffLight()
	{
		std::cout << "Turn off Light¡­¡­" << std::endl;
	}
};

class MovieFacade : public Projector, Amplifier, DVDPlayer, Light
{
public:
	MovieFacade()
	{
		m_pProjector = new Projector();
		m_pAmplifier = new Amplifier();
		m_pDVDPlayer = new DVDPlayer();
		m_pLight = new Light();
	}

	void OpenMovie()
	{
		m_pProjector->OpenScreen();
		m_pProjector->SetViewport();
		m_pAmplifier->OpenAmplifier();
		m_pDVDPlayer->OpenDVDPlayer();
		m_pLight->TurnOffLight();
	}

	void CloseMovie()
	{
		m_pProjector->CloseScreen();
		m_pAmplifier->CloseAmplifier();
		m_pDVDPlayer->CloseDVDPlayer();
		m_pLight->TurnOnLight();
	}
private:
	Projector* m_pProjector;
	Amplifier* m_pAmplifier;
	DVDPlayer* m_pDVDPlayer;
	Light*		m_pLight;
};

