#include "environment.h"

Environment* Environment::env = nullptr;

Environment::Environment(void) 
	: _entity_manager(nullptr), _event_manager(nullptr), _level_manager(nullptr), _input_manager(nullptr),
	_system_manager(nullptr)
{
	Environment::env = this;
}

Environment::~Environment(void)
{
	delete _entity_manager;
	delete _system_manager;
	delete _level_manager;
	delete _input_manager;
	delete _event_manager;

	env = nullptr;
}

void Environment::set_entity_manager(EntityManager* entity_manager)
{
	_entity_manager = entity_manager;
}

void Environment::set_system_manager(SystemManager* system_manager)
{
	_system_manager = system_manager;
}

void Environment::set_event_manager(EventManager* event_manager)
{
	_event_manager = event_manager;
}

void Environment::set_input_manager(InputManager* input_manager)
{
	_input_manager = input_manager;
}

void Environment::set_level_manager(LevelManager* level_manager)
{
	_level_manager = level_manager;
}

EntityManager* Environment::get_entity_manager(void) const
{
	return _entity_manager;
}

SystemManager* Environment::get_system_manager(void) const
{
	return _system_manager;
}

EventManager* Environment::get_event_manager(void) const
{
	return _event_manager;
}

LevelManager* Environment::get_level_manager(void) const
{
	return _level_manager;
}

InputManager* Environment::get_input_manager(void) const
{
	return _input_manager;
}

const Environment& Environment::get(void)
{
	return *env;
}