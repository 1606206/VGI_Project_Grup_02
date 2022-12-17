#include "Panel.h"
#include "../graphics/Camera.h"

Panel::Panel(Transform transform, Model* model, GLuint shader_id) : InteractableEntity(transform, model, shader_id, InteractionType::CLOSE_UP)
{
	my_model = model;

	btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(.5), btScalar(.5), btScalar(.5))); //definir collider

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(my_transform.position().x, my_transform.position().y, my_transform.position().z));// + Vago::Z_OFFSET)); //posicion donde va el objeto

	btScalar mass(0.);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		groundShape->calculateLocalInertia(mass, localInertia);

	//rigidbody
	//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	body->setUserPointer(this); //cogemos el body
	my_rigid_body = body;

	BulletWorld::WORLD->my_collision_shapes.push_back(groundShape);
	BulletWorld::WORLD->my_dynamics_world->addRigidBody(body);
}

void Panel::interact()
{
	cout << "soy el panel" << endl;

	Camera::MAIN_CAMERA.zoomIn(my_transform);

	/*
	int contra;

	std::cout << "INTRODUCE LA CONTRASEŅA:" << std::endl;

	std::cin >> contra;

	if (contra == 578)
	{
		std::cout << "CORRECTO!!" << std::endl;
	}
	else
	{
		std::cout << "ERROR, VUELVE A INTENTARLO" << std::endl;
	}
	*/
}
