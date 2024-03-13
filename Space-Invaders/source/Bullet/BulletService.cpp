#include "../../header/Bullet/BulletService.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Bullet/Controller/FrostBeamController.h"
#include "../../header/Bullet/Controller/LaserBulletController.h"
#include "../../header/Bullet/Controller/TorpedoeController.h"

namespace Bullet
{
	using namespace Controller;

	BulletService::BulletService() { }

	BulletService::~BulletService() { destroy(); }

	void BulletService::initialize() { }

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->update();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++) bullet_list[i]->render();
	}

	BulletController* BulletService::createBullet(BulletType bullet_type)
	{
		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET);

		case::Bullet::BulletType::FROST_BEAM:
			return new FrostBeamController(Bullet::BulletType::FROST_BEAM);

		case::Bullet::BulletType::TORPEDOE:
			return new TorpedoeController(Bullet::BulletType::TORPEDOE);
		}
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++) delete (bullet_list[i]);
	}
	
	BulletController* BulletService::spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(bullet_type);

		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		delete(bullet_controller);
	}
}